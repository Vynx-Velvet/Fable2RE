// Seeds the Fable II image (raw binary at 0x82000000, PowerPC:BE:64:A2ALT-32addr) with what the
// recompiler and our research know: every function entry point (disassembled from there, bodies
// found by Ghidra's flow analysis), our names, and the ASCII strings outside the code.
// Usage (headless post-script): Fable2Prepare.java <dir with functions.tsv and strings.tsv>
// @category Fable2RE
import ghidra.app.cmd.disassemble.DisassembleCommand;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class Fable2Prepare extends GhidraScript {
  private static final long CODE_BEGIN = 0x82170000L, CODE_END = 0x832C2A3CL;

  @Override
  public void run() throws Exception {
    String dir = getScriptArgs().length > 0 ? getScriptArgs()[0] : askDirectory("inputs", "OK").getPath();
    AddressSpace space = currentProgram.getAddressFactory().getDefaultAddressSpace();
    Listing listing = currentProgram.getListing();

    // The raw image is one block: mark it writable data + code (the decompiler then treats globals
    // as variables, not constants).
    for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
      b.setRead(true);
      b.setWrite(true);
      b.setExecute(true);
    }

    List<String[]> funcs = new ArrayList<>();
    for (String line : Files.readAllLines(Paths.get(dir, "functions.tsv"))) {
      String[] f = line.split("\t");
      if (f.length >= 3) funcs.add(f);
    }
    println("functions: " + funcs.size());

    // Disassemble from every entry point (one command: flow-following, shared work).
    AddressSet entries = new AddressSet();
    for (String[] f : funcs) {
      long a = Long.parseLong(f[0], 16);
      if (a >= CODE_BEGIN && a < CODE_END) entries.add(space.getAddress(a));
    }
    monitor.setMessage("Disassembling " + entries.getNumAddresses() + " entry points");
    DisassembleCommand dis = new DisassembleCommand(entries, null, true);
    dis.applyTo(currentProgram, monitor);

    int created = 0, renamed = 0, failed = 0;
    monitor.initialize(funcs.size());
    for (String[] f : funcs) {
      if (monitor.isCancelled()) break;
      monitor.incrementProgress(1);
      long a = Long.parseLong(f[0], 16);
      Address addr = space.getAddress(a);
      String name = f[2];
      Function fn = listing.getFunctionAt(addr);
      try {
        if (fn == null) {
          fn = createFunction(addr, name);
          if (fn != null) ++created; else ++failed;
        } else if (!fn.getName().equals(name)) {
          fn.setName(name, SourceType.USER_DEFINED);
          ++renamed;
        }
      } catch (Exception e) {
        ++failed;
      }
    }
    println("functions created " + created + ", renamed " + renamed + ", failed " + failed);

    int strings = 0;
    for (String line : Files.readAllLines(Paths.get(dir, "strings.tsv"))) {
      String[] f = line.split("\t");
      if (f.length < 2) continue;
      Address addr = space.getAddress(Long.parseLong(f[0], 16));
      try {
        if (listing.getDefinedDataAt(addr) == null && listing.getInstructionContaining(addr) == null) {
          createAsciiString(addr);
          ++strings;
        }
      } catch (Exception e) {
        // overlaps existing data
      }
    }
    println("strings created " + strings);
  }
}
