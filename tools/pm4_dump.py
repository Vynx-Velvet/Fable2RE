"""Decode PM4 command bytes (big-endian) into a readable list. Used on capture command blobs."""
import struct
OPS = {0x48:'ME_INIT',0x10:'NOP',0x3f:'INDIRECT_BUFFER',0x37:'INDIRECT_BUFFER_PFD',0x26:'WAIT_FOR_IDLE',
 0x3c:'WAIT_REG_MEM',0x21:'REG_RMW',0x3e:'REG_TO_MEM',0x3d:'MEM_WRITE',0x44:'COND_EXEC',0x45:'COND_WRITE',
 0x46:'EVENT_WRITE',0x58:'EVENT_WRITE_SHD',0x59:'EVENT_WRITE_CFL',0x5a:'EVENT_WRITE_EXT',0x5b:'EVENT_WRITE_ZPD',
 0x22:'DRAW_INDX',0x36:'DRAW_INDX_2',0x23:'VIZ_QUERY',0x25:'SET_STATE',0x2d:'SET_CONSTANT',0x55:'SET_CONSTANT2',
 0x2f:'LOAD_ALU_CONSTANT',0x27:'IM_LOAD',0x2b:'IM_LOAD_IMMEDIATE',0x2e:'LOAD_CONSTANT_CONTEXT',
 0x3b:'INVALIDATE_STATE',0x4a:'SET_SHADER_BASES',0x5e:'CONTEXT_UPDATE',0x54:'INTERRUPT',0x60:'SET_BIN_MASK_LO',
 0x61:'SET_BIN_MASK_HI',0x62:'SET_BIN_SELECT_LO',0x63:'SET_BIN_SELECT_HI',0x50:'SET_BIN_MASK',0x51:'SET_BIN_SELECT'}
def decode(b, regnames=None):
    out=[]; i=0; n=len(b)//4
    w=[struct.unpack_from('>I',b,4*k)[0] for k in range(n)]
    while i<n:
        h=w[i]; t=h>>30
        if t==0:
            cnt=((h>>16)&0x3FFF)+1; reg=h&0x7FFF
            nm=(regnames or {}).get(reg,'%04X'%reg)
            out.append('T0 %s x%d: %s'%(nm,cnt,' '.join('%08X'%x for x in w[i+1:i+1+min(cnt,6)])))
            i+=1+cnt
        elif t==3:
            cnt=((h>>16)&0x3FFF)+1; op=(h>>8)&0x7F
            out.append('T3 %s%s: %s'%(OPS.get(op,'op%02X'%op),' (pred)' if h&1 else '',' '.join('%08X'%x for x in w[i+1:i+1+min(cnt,6)])))
            i+=1+cnt
        elif t==2:
            i+=1
        else:
            out.append('T1 %08X'%h); i+=1
    return out
