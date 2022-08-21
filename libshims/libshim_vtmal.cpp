#include <stdio.h>
#include <stdint.h>

#include <sys/types.h>

/* As a convenience, if a callback is supplied, a handler thread
 * is automatically created with the appropriate priority. This thread
 * invokes the callback when a new buffer becomes availlable or an underrun condition occurs.
 * Parameters:
 *
 * event:   type of event notified (see enum AudioTrack::event_type).
 * user:    Pointer to context for use by the callback receiver.
 * info:    Pointer to optional parameter according to event type:
 *          - EVENT_MORE_DATA: pointer to AudioTrack::Buffer struct. The callback must not write
 *          more bytes than indicated by 'size' field and update 'size' if less bytes are
 *          written.
 *          - EVENT_UNDERRUN: unused.
 *          - EVENT_LOOP_END: pointer to an int indicating the number of loops remaining.
 *          - EVENT_MARKER: pointer to an uin32_t containing the marker position in frames.
 *          - EVENT_NEW_POS: pointer to an uin32_t containing the new position in frames.
 *          - EVENT_BUFFER_END: unused.
 */
typedef void (*callback_t)(int event, void *user, void *info);

/*
 * Default destructor
 */
extern "C" void _ZN7android12AudioPCMxWayD1Ev() {}

/*
 * Default constructor
 */
extern "C" void _ZN7android12AudioPCMxWayC1EiPFviPvS1_ES1_(void *thisptr, int streamType, callback_t cbf, void *user) {}

/* After it's created the track is not active. Call start() to
 * make it active. If set, the callback will start being called.
 */
extern "C" void _ZN7android12AudioPCMxWay5startEv() {}

/* Stop a track. If set, the callback will cease being called and
 * obtainBuffer returns STOPPED. Note that obtainBuffer() still works
 * and will fill up buffers until the pool is exhausted.
 */
extern "C" void _ZN7android12AudioPCMxWay4stopEv() {}

/* As a convenience we provide a read() interface to the audio buffer.
 * This is implemented on top of lockBuffer/unlockBuffer.
 */
extern "C" void _ZN7android12AudioPCMxWay4readEPvj(void *buffer, size_t size) {}
