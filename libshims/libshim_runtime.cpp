#include <jni.h>
#include <GraphicsJNI.h>
#include <SkDevice.h>
#include <SkImageDecoder.h>

// GraphicsJNI::getNativeBitmapColorType(_JNIEnv*, _jobject*)
extern "C" void _ZN11GraphicsJNI24getNativeBitmapColorTypeEP7_JNIEnvP8_jobject(JNIEnv* env, jobject jconfig);

// GraphicsJNI::getNativeBitmapConfig(_JNIEnv*, _jobject*)
extern "C" void _ZN11GraphicsJNI21getNativeBitmapConfigEP7_JNIEnvP8_jobject(JNIEnv* env, jobject jconfig) {
    _ZN11GraphicsJNI24getNativeBitmapColorTypeEP7_JNIEnvP8_jobject(env, jconfig);
}

// GraphicsJNI::createBitmap(_JNIEnv*, android::Bitmap*, int, _jbyteArray*, _jobject*, int)
extern "C" void _ZN11GraphicsJNI12createBitmapEP7_JNIEnvPN7android6BitmapEiP11_jbyteArrayP8_jobjecti(JNIEnv* env, android::Bitmap* bitmap, int bitmapCreateFlags, jbyteArray ninePatchChunk, jobject ninePatchInsets, int density);

// GraphicsJNI::createBitmap(_JNIEnv*, SkBitmap*, int, _jbyteArray*, int)
extern "C" void _ZN11GraphicsJNI12createBitmapEP7_JNIEnvP8SkBitmapiP11_jbyteArrayi(JNIEnv* env, android::Bitmap* bitmap, int bitmapCreateFlags, jbyteArray ninepatch, int density) {
    _ZN11GraphicsJNI12createBitmapEP7_JNIEnvPN7android6BitmapEiP11_jbyteArrayP8_jobjecti(env, bitmap, bitmapCreateFlags, ninepatch, nullptr, density);
}

// _ZN14SkImageDecoder7FactoryEP18SkStreamRewindable
extern "C" void _ZN14SkImageDecoder7FactoryEP18SkStreamRewindable(SkStreamRewindable* stream);

// SkImageDecoder::Factory(SkStream*)
extern "C" void _ZN14SkImageDecoder7FactoryEP8SkStream(SkStreamRewindable* stream) {
    _ZN14SkImageDecoder7FactoryEP18SkStreamRewindable(stream);
}

//SkImageDecoder::decode(SkStream*, SkBitmap*, SkColorType, SkImageDecoder::Mode)
extern "C" void _ZN14SkImageDecoder6decodeEP8SkStreamP8SkBitmap11SkColorTypeNS_4ModeE(SkStream* stream, SkBitmap* bm, SkColorType pref, SkImageDecoder::Mode mode);

// SkImageDecoder::decode(SkStream*, SkBitmap*, SkBitmap::Config, SkImageDecoder::Mode)
extern "C" void _ZN14SkImageDecoder6decodeEP8SkStreamP8SkBitmapNS2_6ConfigENS_4ModeE(SkStream* stream, SkBitmap* bm, SkColorType pref, SkImageDecoder::Mode mode) {
    _ZN14SkImageDecoder6decodeEP8SkStreamP8SkBitmap11SkColorTypeNS_4ModeE(stream, bm, pref, mode);
}
