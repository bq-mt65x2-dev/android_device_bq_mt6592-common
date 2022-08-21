#include <stdlib.h>
#include <stdint.h>

#include <media/IMediaSource.h>
#include <media/stagefright/MediaBuffer.h>
#include <media/stagefright/MediaBufferGroup.h>

using namespace android;

// android::MPEG4Writer::MPEG4Writer(char const*)
extern "C" void _ZN7android11MPEG4WriterC1EPKc(void *thisptr, const char *filename) {
    // no-op, the explicit constructor was replaced with = default;
}

// android::IMediaSource::ReadOptions::getSeekTo(long long*, android::IMediaSource::ReadOptions::SeekMode*)
extern "C" void _ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode);

// android::IMediaSource::ReadOptions::getNonBlocking()
extern "C" bool _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();

// android::IMediaSource::ReadOptions::ReadOptions()
extern "C" void _ZN7android12IMediaSource11ReadOptionsC1Ev(void *thisptr);

// android::IMediaSource::ReadOptions::clearSeekTo()
extern "C" void _ZN7android12IMediaSource11ReadOptions11clearSeekToEv();

// android::MediaSource::ReadOptions::setSeekTo(long long, android::MediaSource::ReadOptions::SeekMode)
extern "C" void _ZN7android12IMediaSource11ReadOptions9setSeekToExNS1_8SeekModeE(int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode);

// android::MediaSource::ReadOptions::getSeekTo(long long*, android::MediaSource::ReadOptions::SeekMode*)
extern "C" void _ZNK7android11MediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode) {
	_ZNK7android12IMediaSource11ReadOptions9getSeekToEPxPNS1_8SeekModeE(time_us, mode);
}

// android::MediaSource::ReadOptions::getNonBlocking()
extern "C" bool _ZNK7android11MediaSource11ReadOptions14getNonBlockingEv() {
	return _ZNK7android12IMediaSource11ReadOptions14getNonBlockingEv();
}

// android::MediaSource::ReadOptions::ReadOptions()
extern "C" void _ZN7android11MediaSource11ReadOptionsC1Ev(void *thisptr) {
    _ZN7android12IMediaSource11ReadOptionsC1Ev(thisptr);
}

// android::MediaSource::ReadOptions::clearSeekTo()
extern "C" void _ZN7android11MediaSource11ReadOptions11clearSeekToEv() {
    _ZN7android12IMediaSource11ReadOptions11clearSeekToEv();
}

// android::MediaSource::ReadOptions::setSeekTo(long long, android::MediaSource::ReadOptions::SeekMode)
extern "C" void _ZN7android11MediaSource11ReadOptions9setSeekToExNS1_8SeekModeE(int64_t *time_us, android::IMediaSource::ReadOptions::SeekMode *mode) {
    _ZN7android12IMediaSource11ReadOptions9setSeekToExNS1_8SeekModeE(time_us, mode);
}

// android::AwesomePlayer::mtk_omx_get_current_time(long long*)
extern "C" void _ZN7android13AwesomePlayer24mtk_omx_get_current_timeEPx(long long* time){
    time = (long long*)-1;
}

// android::MediaBufferGroup::acquire_buffer(android::MediaBuffer**, bool, unsigned int)
extern "C" status_t _ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferEbj(MediaBuffer **out, bool nonBlocking, size_t requestedSize);

// android::MediaBufferGroup::acquire_buffer(android::MediaBuffer**)
extern "C" status_t _ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferE(MediaBuffer **out) {
    return _ZN7android16MediaBufferGroup14acquire_bufferEPPNS_11MediaBufferEbj(out, false, -1);
}
