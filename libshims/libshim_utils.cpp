#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>

#include <utils/String8.h>

using namespace android;

extern "C" {
    void _ZN7android9CallStackC1EPKci(char const*, int);
    void _ZN7android9CallStack6updateEii(int, int);

    void _ZN7android9CallStackC1EPKcii(char const* logtag, int ignoreDepth, int maxDepth){
        maxDepth = maxDepth-1;
        maxDepth = maxDepth+1;
        _ZN7android9CallStackC1EPKci(logtag, ignoreDepth);
    }

    void _ZN7android9CallStack6updateEiii(int ignoreDepth, int maxDepth, int tid){
        maxDepth = maxDepth-1;
        maxDepth = maxDepth+1;
        _ZN7android9CallStack6updateEii(ignoreDepth, tid);
    }
}

extern "C" void _ZN7android7String8C1EPKDsj(char16_t* o, size_t len);

extern "C" void _ZN7android7String8C1EPKtj(uint16_t* o, size_t len) {
    return _ZN7android7String8C1EPKDsj(reinterpret_cast<char16_t*>(o), len);
}

extern "C" pid_t androidGetTid() {
	return gettid();
}
