#
# Copyright 2020 The LineageOS Project.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

COMMON_PATH := device/bq/mt6592-common

# Platform
TARGET_BOARD_PLATFORM := mt6592
TARGET_BOARD_PLATFORM_GPU := mali-450mp4

# Bootloader
TARGET_NO_BOOTLOADER := true
TARGET_BOOTLOADER_BOARD_NAME := mt6592

# Architecture
ARCH_ARM_HAVE_NEON := true
ARCH_ARM_HAVE_VFP := true
TARGET_ARCH := arm
TARGET_ARCH_VARIANT := armv7-a-neon
TARGET_ARCH_VARIANT_CPU := cortex-a7
TARGET_CPU_ABI := armeabi-v7a
TARGET_CPU_ABI2 := armeabi
TARGET_CPU_VARIANT := cortex-a7

# Bluetooth
BOARD_HAVE_BLUETOOTH := true
BOARD_BLUETOOTH_DOES_NOT_USE_RFKILL := true
BOARD_BLUETOOTH_BDROID_BUILDCFG_INCLUDE_DIR := $(COMMON_PATH)/bluetooth

# Boot animation
TARGET_BOOTANIMATION_MULTITHREAD_DECODE := true

# Camera
TARGET_HAS_LEGACY_CAMERA_HAL1 := true

# Connectivity
BOARD_CONNECTIVITY_VENDOR := MediaTek
BOARD_CONNECTIVITY_MODULE := conn_soc

# Display
BOARD_EGL_CFG := $(COMMON_PATH)/configs/graphics/egl.cfg
BOARD_EGL_NEEDS_HANDLE_VALUE := true
BOARD_EGL_WORKAROUND_BUG_10194508 := true
USE_OPENGL_RENDERER := true
TARGET_RUNNING_WITHOUT_SYNC_FRAMEWORK := true
TARGET_FORCE_HWC_FOR_VIRTUAL_DISPLAYS := true
NUM_FRAMEBUFFER_SURFACE_BUFFERS := 3

# Disable memcpy opt (for audio libraries)
TARGET_CPU_MEMCPY_OPT_DISABLE := true

# Enable Minikin text layout engine (will be the default soon)
USE_MINIKIN := true

# Fonts
EXTENDED_FONT_FOOTPRINT := true

# Malloc
MALLOC_SVELTE := true

# MTK Header
BOARD_CUSTOM_BOOTIMG := true
BOARD_CUSTOM_BOOTIMG_MK := $(COMMON_PATH)/mkbootimg.mk

# MTK Flags
BOARD_USES_MTK_HARDWARE := true

# Offline Charging
BOARD_CHARGING_MODE_BOOTING_LPM := /sys/class/BOOT/BOOT/boot/boot_mode
BOARD_CHARGER_DISABLE_INIT_BLANK := true

# OTA
BLOCK_BASED_OTA := true

# Partitions
TARGET_USERIMAGES_USE_F2FS := true

# Power
TARGET_TAP_TO_WAKE_NODE := "/sys/devices/platform/mtk-tpd/control_double_tap"

# Recovery
TARGET_RECOVERY_FSTAB := $(COMMON_PATH)/rootdir/etc/fstab.mt6592
BOARD_USE_CUSTOM_RECOVERY_FONT := \"roboto_15x24.h\"
TARGET_RECOVERY_PIXEL_FORMAT := "RGBA_8888"

# RIL
BOARD_PROVIDES_RILD := true
BOARD_PROVIDES_LIBREFERENCE_RIL := true
BOARD_PROVIDES_LIBRIL := true
BOARD_PROVIDES_LIBRILUTILS := true

# Shims
TARGET_LDPRELOAD += libaudioextras.so:libxlog.so
LINKER_FORCED_SHIM_LIBS := \
    /system/lib/libutils.so|libshim_utils.so \
    /system/lib/libstagefright.so|libshim_stagefright.so \
    /system/lib/libgui.so|libshim_gui.so \
    /system/lib/libui.so|libshim_ui.so \
    /system/lib/libicuuc.so|libshim_icuuc.so \
    /system/lib/libvtmal.so|libshim_vtmal.so \
    /system/lib/libskia.so|libshim_skia.so \
    /system/lib/libssl.so|libshim_crypto.so \
    /system/lib/libcrypto.so|libshim_crypto.so \
    /system/lib/libcamera_client.so|libshim_camera.so \
    /system/lib/libbinder.so|libshim_binder.so \
    /system/lib/libmedia.so|libshim_media.so \
    /system/lib/libstagefright_omx.so|libshim_omx.so \
    /system/lib/libandroid_runtime.so|libshim_runtime.so \
    /system/lib/libatvctrlservice.so|libatvwrapper.so \
    /system/lib/libmnl.so|libshim_mnld.so \
    /system/lib/libcam_utils.so|libshim_ui.so \
    /system/lib/libMtkOmxVenc.so|libshim_ui.so \
    /system/lib/libaudio.primary.default.so|libshim_fakelog.so \
    /system/lib/hw/hwcomposer.mt6592.so|libshim_fakelog.so \
    /system/bin/mtk_agpsd|libshim_fakelog.so

# System Properties
TARGET_SYSTEM_PROP := $(COMMON_PATH)/system.prop

# Vold
TARGET_USE_CUSTOM_LUN_FILE_PATH := "/sys/devices/virtual/android_usb/android0/f_mass_storage/lun%d/file"

# Extended filesystem support
TARGET_KERNEL_HAVE_EXFAT := true

# Headers
TARGET_SPECIFIC_HEADER_PATH := $(COMMON_PATH)/include

# Wi-Fi
WPA_SUPPLICANT_VERSION := VER_0_8_X
BOARD_HOSTAPD_DRIVER := NL80211
BOARD_HOSTAPD_PRIVATE_LIB := lib_driver_cmd_mt66xx
BOARD_WPA_SUPPLICANT_DRIVER := NL80211
BOARD_WPA_SUPPLICANT_PRIVATE_LIB := lib_driver_cmd_mt66xx
WIFI_DRIVER_FW_PATH_PARAM := "/dev/wmtWifi"
WIFI_DRIVER_FW_PATH_STA := STA
WIFI_DRIVER_FW_PATH_AP := AP
WIFI_DRIVER_FW_PATH_P2P := P2P

# Media Extractors
BOARD_SECCOMP_POLICY := \
    $(COMMON_PATH)/configs/seccomp-policy

# Hack to build with prebuilt kernel
$(shell mkdir -p $(OUT)/obj/KERNEL_OBJ/usr)
