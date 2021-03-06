/********************************************************************
 * Tasmota lib
 * 
 * To use: `import tasmota`
 *******************************************************************/
#include "be_object.h"

extern int l_getFreeHeap(bvm *vm);
extern int l_publish(bvm *vm);
extern int l_cmd(bvm *vm);
extern int l_getoption(bvm *vm);
extern int l_millis(bvm *vm);
extern int l_timereached(bvm *vm);
extern int l_yield(bvm *vm);

extern int l_respCmnd(bvm *vm);
extern int l_respCmndStr(bvm *vm);
extern int l_respCmndDone(bvm *vm);
extern int l_respCmndError(bvm *vm);
extern int l_respCmndFailed(bvm *vm);

// #if !BE_USE_PRECOMPILED_OBJECT
#if 1           // TODO we will do pre-compiled later

be_native_module_attr_table(tasmota_ntv) {
    be_native_module_function("getfreeheap", l_getFreeHeap),
    be_native_module_function("publish", l_publish),
    be_native_module_function("cmd", l_cmd),
    be_native_module_function("getoption", l_getoption),
    be_native_module_function("millis", l_millis),
    be_native_module_function("timereached", l_timereached),
    be_native_module_function("yield", l_yield),

    be_native_module_function("respcmnd", l_respCmnd),
    be_native_module_function("respcmndstr", l_respCmndStr),
    be_native_module_function("respcmnd_done", l_respCmndDone),
    be_native_module_function("respcmnd_error", l_respCmndError),
    be_native_module_function("respcmnd_failed", l_respCmndFailed),

    be_native_module_str("_operators",  "=<>!|"),
};

be_define_native_module(tasmota_ntv, NULL);
#else
/* @const_object_info_begin
module tasmota (scope: global, depend: 1) {
    getfreeheap, func(l_getFreeHeap)
}
@const_object_info_end */
#include "../generate/be_fixed_tasmota.h"
#endif
