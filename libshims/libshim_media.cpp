#include <sys/types.h>
#include <unistd.h>

#include <binder/IPCThreadState.h>
#include <media/AudioRecord.h>
#include <system/audio.h>

using namespace android;

extern "C" ssize_t _ZN7android11AudioRecord4readEPvjb(void* buffer, size_t userSize, bool blocking);

extern "C" ssize_t _ZN7android11AudioRecord4readEPvj(void* buffer, size_t userSize) {
    return _ZN7android11AudioRecord4readEPvjb(buffer, userSize, false);
}

extern "C" status_t _ZN7android11AudioRecord5startENS_11AudioSystem12sync_event_tE15audio_session_t(AudioSystem::sync_event_t event, audio_session_t triggerSession);

extern "C" status_t _ZN7android11AudioRecord5startENS_11AudioSystem12sync_event_tEi(AudioSystem::sync_event_t event, int triggerSession) {
    return _ZN7android11AudioRecord5startENS_11AudioSystem12sync_event_tE15audio_session_t(event, static_cast<audio_session_t>(triggerSession));
}

// android::AudioRecord::AudioRecord(audio_source_t, unsigned int, audio_format_t, unsigned int, android::String16 const&, unsigned int, void (*)(int, void*, void*), void*, unsigned int, audio_session_t, android::AudioRecord::transfer_type, audio_input_flags_t, int, int, audio_attributes_t const*)
extern "C" void _ZN7android11AudioRecordC2E14audio_source_tj14audio_format_tjRKNS_8String16EjPFviPvS6_ES6_j15audio_session_tNS0_13transfer_typeE19audio_input_flags_tiiPK18audio_attributes_t(void *thisptr, audio_source_t inputSource, uint32_t sampleRate, audio_format_t format, audio_channel_mask_t channelMask, const String16& opPackageName, size_t frameCount, android::AudioRecord::callback_t cbf, void* user, uint32_t notificationFrames, audio_session_t sessionId, android::AudioRecord::transfer_type transferType, audio_input_flags_t flags, int uid, pid_t pid, const audio_attributes_t* pAttributes);

// android::AudioRecord::AudioRecord(audio_source_t, unsigned int, audio_format_t, unsigned int, int, void (*)(int, void*, void*), void*, int, int, android::AudioRecord::transfer_type, audio_input_flags_t)
extern "C" void _ZN7android11AudioRecordC1E14audio_source_tj14audio_format_tjiPFviPvS3_ES3_iiNS0_13transfer_typeE19audio_input_flags_t(void *thisptr, audio_source_t inputSource, uint32_t sampleRate, audio_format_t format, audio_channel_mask_t channelMask, int frameCount, android::AudioRecord::callback_t cbf, void* user, int notificationFrames, int sessionId, android::AudioRecord::transfer_type transferType, audio_input_flags_t flags) { 
    static String16 sAStaticEmptyString(String16::kEmptyString);
    _ZN7android11AudioRecordC2E14audio_source_tj14audio_format_tjRKNS_8String16EjPFviPvS6_ES6_j15audio_session_tNS0_13transfer_typeE19audio_input_flags_tiiPK18audio_attributes_t(thisptr, inputSource, sampleRate, format, channelMask, sAStaticEmptyString, frameCount, cbf, user, notificationFrames, static_cast<audio_session_t>(sessionId), transferType, flags, -1, -1, nullptr);
}

// android::AudioTrack::set(audio_stream_type_t, unsigned int, audio_format_t, unsigned int, unsigned int, audio_output_flags_t, void (*)(int, void*, void*), void*, int, android::sp<android::IMemory> const&, bool, audio_session_t, android::AudioTrack::transfer_type, audio_offload_info_t const*, int, int, audio_attributes_t const*, bool, float)
extern "C" status_t _ZN7android10AudioTrack3setE19audio_stream_type_tj14audio_format_tjj20audio_output_flags_tPFviPvS4_ES4_iRKNS_2spINS_7IMemoryEEEb15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tiiPK18audio_attributes_tbf(audio_stream_type_t streamType, uint32_t sampleRate, audio_format_t format, audio_channel_mask_t channelMask, size_t frameCount, audio_output_flags_t flags, android::AudioRecord::callback_t cbf, void* user, int32_t notificationFrames, const sp<IMemory>& sharedBuffer, bool threadCanCallJava, audio_session_t sessionId, android::AudioRecord::transfer_type transferType, const audio_offload_info_t *offloadInfo, int uid, pid_t pid, const audio_attributes_t* pAttributes, bool doNotReconnect, float maxRequiredSpeed);

// android::AudioTrack::set(audio_stream_type_t, unsigned int, audio_format_t, unsigned int, int, audio_output_flags_t, void (*)(int, void*, void*), void*, int, android::sp<android::IMemory> const&, bool, int, android::AudioTrack::transfer_type, audio_offload_info_t const*, int)
extern "C" status_t _ZN7android10AudioTrack3setE19audio_stream_type_tj14audio_format_tji20audio_output_flags_tPFviPvS4_ES4_iRKNS_2spINS_7IMemoryEEEbiNS0_13transfer_typeEPK20audio_offload_info_ti(audio_stream_type_t streamType, uint32_t sampleRate, audio_format_t format, audio_channel_mask_t channelMask, int frameCountInt, audio_output_flags_t flags, android::AudioRecord::callback_t cbf, void* user, int notificationFrames, const sp<IMemory>& sharedBuffer, bool threadCanCallJava, int sessionId, android::AudioRecord::transfer_type transferType, const audio_offload_info_t *offloadInfo, int uid) {
    return _ZN7android10AudioTrack3setE19audio_stream_type_tj14audio_format_tjj20audio_output_flags_tPFviPvS4_ES4_iRKNS_2spINS_7IMemoryEEEb15audio_session_tNS0_13transfer_typeEPK20audio_offload_info_tiiPK18audio_attributes_tbf(streamType, sampleRate, format, channelMask, static_cast<size_t>(frameCountInt), flags, cbf, user, notificationFrames, sharedBuffer, threadCanCallJava, static_cast<audio_session_t>(sessionId), transferType, offloadInfo, uid, -1, nullptr, false, -1);
}
