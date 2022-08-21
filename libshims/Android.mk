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
