LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_utils.cpp
LOCAL_SHARED_LIBRARIES := libutils
LOCAL_MODULE := libshim_utils
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_stagefright.cpp
LOCAL_SHARED_LIBRARIES := libstagefright libstagefright_foundation libmedia
LOCAL_MODULE := libshim_stagefright
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_gui.cpp
LOCAL_SHARED_LIBRARIES := libui libgui libbinder
LOCAL_MODULE := libshim_gui
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_icuuc.cpp
LOCAL_SHARED_LIBRARIES := libicuuc libicui18n
LOCAL_MODULE := libshim_icuuc
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_vtmal.cpp
LOCAL_MODULE := libshim_vtmal
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_ui.cpp
LOCAL_SHARED_LIBRARIES := libui libgui
LOCAL_MODULE := libshim_ui
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_skia.cpp
LOCAL_SHARED_LIBRARIES := libskia libandroid_runtime
LOCAL_MODULE := libshim_skia
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_crypto.cpp
LOCAL_SHARED_LIBRARIES := libssl libcrypto
LOCAL_MODULE := libshim_crypto
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_camera.cpp
LOCAL_SHARED_LIBRARIES := libcamera_client libandroid_runtime libbinder
LOCAL_MODULE := libshim_camera
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_binder.cpp
LOCAL_SHARED_LIBRARIES := libcutils libutils libbinder
LOCAL_MODULE := libshim_binder
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_media.cpp
LOCAL_SHARED_LIBRARIES := libmedia libcutils libutils libbinder
LOCAL_MODULE := libshim_media
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_omx.cpp
LOCAL_SHARED_LIBRARIES := libstagefright libstagefright_omx libutils
LOCAL_C_INCLUDES += $(TOP)/frameworks/av/media/libstagefright $(TOP)/frameworks/av/media/libstagefright/include $(TOP)/frameworks/native/include/media/hardware $(TOP)/frameworks/native/include/media/openmax
LOCAL_MODULE := libshim_omx
include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_SRC_FILES := libshim_runtime.cpp
LOCAL_SHARED_LIBRARIES := libandroid_runtime libskia
LOCAL_C_INCLUDES += $(TOP)/external/skia/include/android $(TOP)/external/skia/include/codec $(TOP)/external/skia/include/core $(TOP)/frameworks/base/core/jni/android/graphics $(TOP)/frameworks/base/libs/hwui $(TOP)/libnativehelper/include/nativehelper
LOCAL_MODULE := libshim_runtime
include $(BUILD_SHARED_LIBRARY)
