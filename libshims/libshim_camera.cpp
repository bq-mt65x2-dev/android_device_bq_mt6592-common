#include <binder/IMemory.h>
#include <binder/IServiceManager.h>

using namespace android;

// android::hardware::ICameraService::asInterface(android::sp<android::IBinder> const&)
extern "C" int _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(android::sp<android::IBinder> const& service);

// android::ICameraService::asInterface(android::sp<android::IBinder> const&)
extern "C" void _ZN7android14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(android::sp<android::IBinder> const& service) {
    _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(service);
}

// android::Camera::connect(int, android::String16 const&, int, int)
extern "C" status_t _ZN7android6Camera7connectEiRKNS_8String16Eii(void *, int, void **, int, int);

// android::Camera::connect(int, android::String16 const&, int)
extern "C" status_t _ZN7android6Camera7connectEiRKNS_8String16Ei(void *thiz, int cameraId, void **str16P, int clientUid) {
    return _ZN7android6Camera7connectEiRKNS_8String16Eii(thiz, cameraId, str16P, clientUid, 1000);
}
