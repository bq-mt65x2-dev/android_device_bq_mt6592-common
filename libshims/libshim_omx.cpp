#include <OMX_AsString.h>
#include <OMX_Component.h>
#include <OMX_Core.h>
#include <OMX_VideoExt.h>

#include <OMX.h>
#include <OMXNodeInstance.h>

#include <ui/GraphicBuffer.h>

#include <media/IMediaSource.h>
#include <media/stagefright/SurfaceUtils.h>

using namespace android;

// android::OMX::OnFillBufferDone(unsigned int, unsigned int, OMX_BUFFERHEADERTYPE*, int)
extern "C" OMX_ERRORTYPE _ZN7android3OMX16OnFillBufferDoneEjjP20OMX_BUFFERHEADERTYPEi(android::BnOMX::node_id node, android::BnOMX::buffer_id buffer, OMX_IN OMX_BUFFERHEADERTYPE *pBuffer, int fenceFd);

// android::OMX::OnFillBufferDone(void*, OMX_BUFFERHEADERTYPE*)
extern "C" OMX_ERRORTYPE _ZN7android3OMX16OnFillBufferDoneEPvP20OMX_BUFFERHEADERTYPE(android::BnOMX::node_id node, OMX_IN OMX_BUFFERHEADERTYPE *pBuffer) {
    return _ZN7android3OMX16OnFillBufferDoneEjjP20OMX_BUFFERHEADERTYPEi(node, -1, pBuffer, -1); // invalid fence
}

// android::OMX::OnEmptyBufferDone(unsigned int, unsigned int, OMX_BUFFERHEADERTYPE*, int)
extern "C" OMX_ERRORTYPE _ZN7android3OMX17OnEmptyBufferDoneEjjP20OMX_BUFFERHEADERTYPEi(android::BnOMX::node_id node, android::BnOMX::buffer_id buffer, OMX_IN OMX_BUFFERHEADERTYPE *pBuffer, int fenceFd);

// android::OMX::OnEmptyBufferDone(void*, OMX_BUFFERHEADERTYPE*)
extern "C" OMX_ERRORTYPE _ZN7android3OMX17OnEmptyBufferDoneEPvP20OMX_BUFFERHEADERTYPE(android::BnOMX::node_id node, OMX_IN OMX_BUFFERHEADERTYPE *pBuffer) {
    return _ZN7android3OMX17OnEmptyBufferDoneEjjP20OMX_BUFFERHEADERTYPEi(node, -1, pBuffer, -1); // invalid fence
}

// android::OMX::OnEvent(unsigned int, OMX_EVENTTYPE, unsigned int, unsigned int, void*)
extern "C" OMX_ERRORTYPE _ZN7android3OMX7OnEventEj13OMX_EVENTTYPEjjPv(android::BnOMX::node_id node, OMX_IN OMX_EVENTTYPE eEvent, OMX_IN OMX_U32 nData1, OMX_IN OMX_U32 nData2, OMX_IN OMX_PTR pEventData);

// android::OMX::OnEvent(void*, OMX_EVENTTYPE, unsigned long, unsigned long, void*)
extern "C" OMX_ERRORTYPE _ZN7android3OMX7OnEventEPv13OMX_EVENTTYPEmmS1_(android::BnOMX::node_id node, OMX_IN OMX_EVENTTYPE eEvent, OMX_IN OMX_U32 nData1, OMX_IN OMX_U32 nData2, OMX_IN OMX_PTR pEventData) {
    return _ZN7android3OMX7OnEventEj13OMX_EVENTTYPEjjPv(node, eEvent, nData1, nData2, pEventData);
}

// android::GraphicBufferSource::GraphicBufferSource(android::OMXNodeInstance*, unsigned int, unsigned int, unsigned int, unsigned int, android::sp<android::IGraphicBufferConsumer> const&)
extern "C" void _ZN7android19GraphicBufferSourceC1EPNS_15OMXNodeInstanceEjjjjRKNS_2spINS_22IGraphicBufferConsumerEEE(void *thisptr, OMXNodeInstance* nodeInstance, uint32_t bufferWidth, uint32_t bufferHeight, uint32_t bufferCount, uint32_t consumerUsage, const sp<IGraphicBufferConsumer> &consumer);

// android::GraphicBufferSource::GraphicBufferSource(android::OMXNodeInstance*, unsigned int, unsigned int, unsigned int)
extern "C" void _ZN7android19GraphicBufferSourceC1EPNS_15OMXNodeInstanceEjjj(void *thisptr, OMXNodeInstance* nodeInstance, uint32_t bufferWidth, uint32_t bufferHeight, uint32_t bufferCount) {
    _ZN7android19GraphicBufferSourceC1EPNS_15OMXNodeInstanceEjjjjRKNS_2spINS_22IGraphicBufferConsumerEEE(thisptr, nodeInstance, bufferWidth, bufferHeight, bufferCount, -1, nullptr);
}

// android::GraphicBufferSource::codecBufferEmptied(OMX_BUFFERHEADERTYPE*, int)
extern "C" void _ZN7android19GraphicBufferSource18codecBufferEmptiedEP20OMX_BUFFERHEADERTYPEi(OMX_BUFFERHEADERTYPE* header, int fenceFd);

// android::GraphicBufferSource::codecBufferEmptied(OMX_BUFFERHEADERTYPE*)
extern "C" void _ZN7android19GraphicBufferSource18codecBufferEmptiedEP20OMX_BUFFERHEADERTYPE(OMX_BUFFERHEADERTYPE* header) {
    _ZN7android19GraphicBufferSource18codecBufferEmptiedEP20OMX_BUFFERHEADERTYPEi(header, -1); // invalid fence
}

// android::OMX::invalidateNodeID(unsigned int)
extern "C" void _ZN7android3OMX16invalidateNodeIDEj(android::BnOMX::node_id node);

// android::OMX::invalidateNodeID(void*)
extern "C" void _ZN7android3OMX16invalidateNodeIDEPv(android::BnOMX::node_id node) {
    _ZN7android3OMX16invalidateNodeIDEj(node);
}

// android::SimpleDecodingSource::Create(android::sp<android::IMediaSource> const&, unsigned int, android::sp<ANativeWindow> const&, char const*)
extern "C" void _ZN7android20SimpleDecodingSource6CreateERKNS_2spINS_12IMediaSourceEEEjRKNS1_I13ANativeWindowEEPKc(const sp<IMediaSource> &source, uint32_t flags, const sp<ANativeWindow> &nativeWindow, const char *desiredCodec);

// android::OMXCodec::Create(android::sp<android::IOMX> const&, android::sp<android::MetaData> const&, bool, android::sp<android::MediaSource> const&, char const*, unsigned int, android::sp<ANativeWindow> const&)
extern "C" void _ZN7android8OMXCodec6CreateERKNS_2spINS_4IOMXEEERKNS1_INS_8MetaDataEEEbRKNS1_INS_11MediaSourceEEEPKcjRKNS1_I13ANativeWindowEE(const sp<IOMX> &omx, const sp<MetaData> &meta, bool createEncoder, const sp<IMediaSource> &source, const char *matchComponentName, uint32_t flags, const sp<ANativeWindow> &nativeWindow) {
    _ZN7android20SimpleDecodingSource6CreateERKNS_2spINS_12IMediaSourceEEEjRKNS1_I13ANativeWindowEEPKc(source, flags, nativeWindow, nullptr);
}

// android::MPEG4Writer::getMaxDurationUs()
extern "C" int64_t _ZN7android11MPEG4Writer16getMaxDurationUsEv() {
    return 0;
}
