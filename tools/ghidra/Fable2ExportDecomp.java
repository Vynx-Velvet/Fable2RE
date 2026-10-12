// Decompiles every function of the Fable II program in parallel and writes C pseudo-code grouped by
// 64 KB of address space (decomp_XXXX.c, XXXX = upper 16 address bits) plus index.tsv
// (entry, name, file, line, status) for lookups.
// Usage (headless post-script): Fable2ExportDecomp.java <out dir> [threads] [timeout seconds] [limit]
// (limit > 0: only the first <limit> functions - a quick test)
// @category Fable2RE
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.util.task.TaskMonitor;

import java.io.BufferedWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;
import java.util.concurrent.atomic.AtomicInteger;

public class Fable2ExportDecomp extends GhidraScript {
  @Override
  public void run() throws Exception {
    String[] args = getScriptArgs();
    Path out = Paths.get(args.length > 0 ? args[0] : "decomp_out");
    int threads = args.length > 1 ? Integer.parseInt(args[1]) : 6;
    int timeout = args.length > 2 ? Integer.parseInt(args[2]) : 60;
    int limit = args.length > 3 ? Integer.parseInt(args[3]) : 0;
    Files.createDirectories(out);

    // Group functions by 64 KB block (one output file each).
    Map<Long, List<Function>> groups = new TreeMap<>();
    int taken = 0;
    for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
      if (limit > 0 && taken++ >= limit) break;
      long a = f.getEntryPoint().getOffset();
      groups.computeIfAbsent(a >>> 16, k -> new ArrayList<>()).add(f);
    }
    int total = 0;
    for (List<Function> g : groups.values()) total += g.size();
    println("decompiling " + total + " functions in " + groups.size() + " files on " + threads + " threads");

    AtomicInteger done = new AtomicInteger(), failed = new AtomicInteger();
    ThreadLocal<DecompInterface> decomp = ThreadLocal.withInitial(() -> {
      DecompInterface d = new DecompInterface();
      DecompileOptions o = new DecompileOptions();
      d.setOptions(o);
      d.toggleCCode(true);
      d.toggleSyntaxTree(false);
      d.setSimplificationStyle("decompile");
      d.openProgram(currentProgram);
      return d;
    });
    List<String> index = java.util.Collections.synchronizedList(new ArrayList<>());
    ExecutorService pool = Executors.newFixedThreadPool(threads);
    List<Future<?>> futures = new ArrayList<>();
    final int totalF = total;
    for (Map.Entry<Long, List<Function>> e : groups.entrySet()) {
      futures.add(pool.submit(() -> {
        String file = String.format("decomp_%04X.c", e.getKey());
        StringBuilder sb = new StringBuilder();
        sb.append("// Ghidra decompilation of Fable II (GOTY disc, media ID 716F0A0D) default.xex, generated from the user's own copy.\n");
        sb.append("// Reference only (not compiled). Addresses are guest addresses.\n\n");
        int line = 4;
        DecompInterface d = decomp.get();
        for (Function f : e.getValue()) {
          String body;
          String status = "ok";
          try {
            DecompileResults r = d.decompileFunction(f, timeout, TaskMonitor.DUMMY);
            if (r != null && r.decompileCompleted() && r.getDecompiledFunction() != null) {
              body = r.getDecompiledFunction().getC();
            } else {
              status = "failed: " + (r == null ? "null" : r.getErrorMessage().replace('\n', ' ').trim());
              body = "// decompilation failed: " + status + "\n";
              failed.incrementAndGet();
            }
          } catch (Exception ex) {
            status = "exception: " + ex.getMessage();
            body = "// decompilation exception: " + ex.getMessage() + "\n";
            failed.incrementAndGet();
          }
          String header = String.format("// ---- %s @ %08X (%d bytes)\n", f.getName(), f.getEntryPoint().getOffset(),
                                        f.getBody().getNumAddresses());
          index.add(String.format("%08X\t%s\t%s\t%d\t%s", f.getEntryPoint().getOffset(), f.getName(), file, line, status));
          sb.append(header).append(body).append('\n');
          line += 1 + body.split("\n", -1).length;
          int n = done.incrementAndGet();
          if (n % 2000 == 0) println("  " + n + " / " + totalF + " (" + failed.get() + " failed)");
        }
        try {
          Files.write(out.resolve(file), sb.toString().getBytes(StandardCharsets.UTF_8));
        } catch (Exception ex) {
          println("write failed " + file + ": " + ex);
        }
      }));
    }
    for (Future<?> f : futures) f.get();
    pool.shutdown();
    java.util.Collections.sort(index);
    try (BufferedWriter w = Files.newBufferedWriter(out.resolve("index.tsv"), StandardCharsets.UTF_8)) {
      w.write("entry\tname\tfile\tline\tstatus\n");
      for (String s : index) w.write(s + "\n");
    }
    println("done: " + done.get() + " functions, " + failed.get() + " failed -> " + out);
  }
}
