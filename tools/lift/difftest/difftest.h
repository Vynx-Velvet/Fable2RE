// Shared declarations of the differential tester (driver.cpp, generated stubs.cpp / table_N.cpp).
#pragma once

#include <rex/ppc/context.h>

#include <cstddef>
#include <cstdint>

namespace f2t {
// A function called from the code under test: replaced by a recording stub.
struct CalleeInfo {
  uint32_t addr;
  uint32_t gin, gwide, fin;  // integer arguments read (and which of them as 64-bit), float arguments
  uint64_t vin;              // vector arguments v0..v63
  uint32_t gmod, fmod;       // registers it may change
  uint64_t vmod;
  uint32_t crmod;            // condition register fields it may change (4 bits per field)
  uint32_t xermod;           // may change xer.ca
  // (run.py --relaxed --outputs) registers it passes on to calls whose arguments are unknown without reading
  // them itself (summaries 'fwd'): compared where the caller passes its own argument through unchanged
  uint32_t gfwd = 0, ffwd = 0;
};
void OnCall(const CalleeInfo& c, PPCContext& ctx);
extern const CalleeInfo kIndirectCallee;

// A function under test.
struct TestFunc {
  uint32_t addr;
  PPCFunc* original;  // __imp__sub_X
  PPCFunc* lifted;    // sub_X (lifted wrapper)
  uint32_t gout, gwide, fout, crout;  // results callers read (and which integer ones as 64-bit)
};
extern const TestFunc kTests[];
extern const size_t kTestCount;

#define F2T_REG(n) &PPCContext::n
inline PPCRegister& Gpr(PPCContext& c, int i) {
  static PPCRegister PPCContext::*const m[32] = {
      F2T_REG(r0), F2T_REG(r1), F2T_REG(r2), F2T_REG(r3), F2T_REG(r4), F2T_REG(r5), F2T_REG(r6), F2T_REG(r7),
      F2T_REG(r8), F2T_REG(r9), F2T_REG(r10), F2T_REG(r11), F2T_REG(r12), F2T_REG(r13), F2T_REG(r14), F2T_REG(r15),
      F2T_REG(r16), F2T_REG(r17), F2T_REG(r18), F2T_REG(r19), F2T_REG(r20), F2T_REG(r21), F2T_REG(r22), F2T_REG(r23),
      F2T_REG(r24), F2T_REG(r25), F2T_REG(r26), F2T_REG(r27), F2T_REG(r28), F2T_REG(r29), F2T_REG(r30), F2T_REG(r31)};
  return c.*m[i];
}
inline PPCRegister& Fpr(PPCContext& c, int i) {
  static PPCRegister PPCContext::*const m[32] = {
      F2T_REG(f0), F2T_REG(f1), F2T_REG(f2), F2T_REG(f3), F2T_REG(f4), F2T_REG(f5), F2T_REG(f6), F2T_REG(f7),
      F2T_REG(f8), F2T_REG(f9), F2T_REG(f10), F2T_REG(f11), F2T_REG(f12), F2T_REG(f13), F2T_REG(f14), F2T_REG(f15),
      F2T_REG(f16), F2T_REG(f17), F2T_REG(f18), F2T_REG(f19), F2T_REG(f20), F2T_REG(f21), F2T_REG(f22), F2T_REG(f23),
      F2T_REG(f24), F2T_REG(f25), F2T_REG(f26), F2T_REG(f27), F2T_REG(f28), F2T_REG(f29), F2T_REG(f30), F2T_REG(f31)};
  return c.*m[i];
}
inline PPCVRegister& Vr(PPCContext& c, int i) {
  static PPCVRegister PPCContext::*const m[64] = {
      F2T_REG(v0), F2T_REG(v1), F2T_REG(v2), F2T_REG(v3), F2T_REG(v4), F2T_REG(v5), F2T_REG(v6), F2T_REG(v7),
      F2T_REG(v8), F2T_REG(v9), F2T_REG(v10), F2T_REG(v11), F2T_REG(v12), F2T_REG(v13), F2T_REG(v14), F2T_REG(v15),
      F2T_REG(v16), F2T_REG(v17), F2T_REG(v18), F2T_REG(v19), F2T_REG(v20), F2T_REG(v21), F2T_REG(v22), F2T_REG(v23),
      F2T_REG(v24), F2T_REG(v25), F2T_REG(v26), F2T_REG(v27), F2T_REG(v28), F2T_REG(v29), F2T_REG(v30), F2T_REG(v31),
      F2T_REG(v32), F2T_REG(v33), F2T_REG(v34), F2T_REG(v35), F2T_REG(v36), F2T_REG(v37), F2T_REG(v38), F2T_REG(v39),
      F2T_REG(v40), F2T_REG(v41), F2T_REG(v42), F2T_REG(v43), F2T_REG(v44), F2T_REG(v45), F2T_REG(v46), F2T_REG(v47),
      F2T_REG(v48), F2T_REG(v49), F2T_REG(v50), F2T_REG(v51), F2T_REG(v52), F2T_REG(v53), F2T_REG(v54), F2T_REG(v55),
      F2T_REG(v56), F2T_REG(v57), F2T_REG(v58), F2T_REG(v59), F2T_REG(v60), F2T_REG(v61), F2T_REG(v62), F2T_REG(v63)};
  return c.*m[i];
}
inline PPCCRRegister& Cr(PPCContext& c, int i) {
  static PPCCRRegister PPCContext::*const m[8] = {F2T_REG(cr0), F2T_REG(cr1), F2T_REG(cr2), F2T_REG(cr3),
                                                  F2T_REG(cr4), F2T_REG(cr5), F2T_REG(cr6), F2T_REG(cr7)};
  return c.*m[i];
}
#undef F2T_REG
}  // namespace f2t
