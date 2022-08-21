#include <binder/IMemory.h>
#include <binder/IServiceManager.h>

#include <ui/DisplayInfo.h>

#include <gui/IGraphicBufferAlloc.h>

// android::SurfaceComposerClient::unblankDisplay(android::sp<android::IBinder> const&)
extern "C" void _ZN7android21SurfaceComposerClient14unblankDisplayERKNS_2spINS_7IBinderEEE(const android::sp<android::IBinder>& display) {
    // no-op, the explicit function was replaced with setPowerMode()
}

// android::SurfaceComposerClient::blankDisplay(android::sp<android::IBinder> const&)
extern "C" void _ZN7android21SurfaceComposerClient12blankDisplayERKNS_2spINS_7IBinderEEE(const android::sp<android::IBinder>& display) {
    // no-op, the explicit function was replaced with setPowerMode()
}

// android::BufferQueue::BufferQueue(android::sp<android::IGraphicBufferAlloc> const&)
extern "C" void _ZN7android11BufferQueueC1ERKNS_2spINS_19IGraphicBufferAllocEEE(void *thisptr, const android::sp<android::IGraphicBufferAlloc>& allocator) {
    // no-op, the explicit constructor was replaced with = default;
}

// android::IGraphicBufferConsumer::BufferItem::BufferItem()
extern "C" void _ZN7android22IGraphicBufferConsumer10BufferItemC1Ev(void *thisptr) {
    // no-op, the explicit constructor was replaced with = default;
}

// android::SurfaceControl::setLayer(unsigned int)
extern "C" void _ZN7android14SurfaceControl8setLayerEj(uint32_t layer);

// android::SurfaceControl::setLayer(int)
extern "C" void _ZN7android14SurfaceControl8setLayerEi(int32_t layer) {
    _ZN7android14SurfaceControl8setLayerEj(static_cast<uint32_t>(layer));
}
