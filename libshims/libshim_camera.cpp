#include <binder/IMemory.h>
#include <binder/IServiceManager.h>

// android::hardware::ICameraService::asInterface(android::sp<android::IBinder> const&)
extern "C" int _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(android::sp<android::IBinder> const& service);

// android::ICameraService::asInterface(android::sp<android::IBinder> const&)
extern "C" void _ZN7android14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(android::sp<android::IBinder> const& service) {
    _ZN7android8hardware14ICameraService11asInterfaceERKNS_2spINS_7IBinderEEE(service);
}
