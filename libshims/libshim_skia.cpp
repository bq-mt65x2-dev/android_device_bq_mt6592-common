#include <inttypes.h>
#include <stdio.h>
#include <stdint.h>

#include <SkBitmap.h>
#include <SkCanvas.h>
#include <SkPaint.h>
#include <SkStream.h>
#include <SkImageDecoder.h>

using namespace android;

enum Config {
    kNo_Config,         //!< bitmap has not been configured
    kA8_Config,         //!< 8-bits per pixel, with only alpha specified (0 is transparent, 0xFF is opaque)
    kIndex8_Config,     //!< 8-bits per pixel, using SkColorTable to specify the colors
    kRGB_565_Config,    //!< 16-bits per pixel, (see SkColorPriv.h for packing)
    kARGB_4444_Config,  //!< 16-bits per pixel, (see SkColorPriv.h for packing)
    kARGB_8888_Config,  //!< 32-bits per pixel, (see SkColorPriv.h for packing)
};

static const SkColorType gCT[] = {
    kUnknown_SkColorType,   // kNo_Config
    kAlpha_8_SkColorType,   // kA8_Config
    kIndex_8_SkColorType,   // kIndex8_Config
    kRGB_565_SkColorType,   // kRGB_565_Config
    kARGB_4444_SkColorType, // kARGB_4444_Config
    kN32_SkColorType,       // kARGB_8888_Config
};

// SkImageDecoder::DecodeFile(char const*, SkBitmap*, SkColorType, SkImageDecoder::Mode, SkImageDecoder::Format*)
extern "C" bool _ZN14SkImageDecoder10DecodeFileEPKcP8SkBitmap11SkColorTypeNS_4ModeEPNS_6FormatE(const char file[], SkBitmap* bm, SkColorType pref, SkImageDecoder::Mode mode,
    SkImageDecoder::Format* format);

// SkImageDecoder::DecodeFile(char const*, SkBitmap*, SkBitmap::Config, SkImageDecoder::Mode, SkImageDecoder::Format*)
extern "C" bool _ZN14SkImageDecoder10DecodeFileEPKcP8SkBitmapNS2_6ConfigENS_4ModeEPNS_6FormatE(const char file[], SkBitmap* bm, Config pref, SkImageDecoder::Mode mode,
    SkImageDecoder::Format* format) {
        return _ZN14SkImageDecoder10DecodeFileEPKcP8SkBitmap11SkColorTypeNS_4ModeEPNS_6FormatE(file, bm, gCT[pref], mode, format);
}

// SkBitmap::setConfig(SkBitmap::Config, int, int, unsigned int)
extern "C" void _ZN8SkBitmap9setConfigENS_6ConfigEiij(Config config, int width, int height, uint32_t rowBytes) {
	// no-op, the explicit function was deprecaated;
}

// SkBitmap::eraseARGB(unsigned int, unsigned int, unsigned int, unsigned int)
extern "C" void _ZNK8SkBitmap9eraseARGBEjjjj(uint8_t a, uint8_t r, uint8_t g, uint8_t b) {
    // no-op, the explicit function was deprecaated;
}

// SkBitmap::tryAllocPixels(SkBitmap::Allocator*, SkColorTable*)
extern "C" bool _ZN8SkBitmap14tryAllocPixelsEPNS_9AllocatorEP12SkColorTable(SkBitmap::Allocator* allocator, SkColorTable* ctable);

// SkBitmap::allocPixels(SkBitmap::Allocator*, SkColorTable*)
extern "C" bool _ZN8SkBitmap11allocPixelsEPNS_9AllocatorEP12SkColorTable(SkBitmap::Allocator* allocator, SkColorTable* ctable) {
    return _ZN8SkBitmap14tryAllocPixelsEPNS_9AllocatorEP12SkColorTable(allocator, ctable);
}

// SkCanvas::drawBitmapMatrix(SkBitmap const&, SkMatrix const&, SkPaint const*)
extern "C" void _ZN8SkCanvas16drawBitmapMatrixERK8SkBitmapRK8SkMatrixPK7SkPaint(const SkBitmap& bitmap, const SkMatrix& matrix, const SkPaint* paint) {
   // no-op, the explicit function was deprecaated;
}
