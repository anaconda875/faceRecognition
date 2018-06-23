LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

OPENCVROOT := C:\work\OpenCV-android-sdk
OPENCV_CAMERA_MODULES := on
OPENCV_INSTALL_MODULES := on
OPENCV_LIB_TYPE := SHARED
include $(OPENCVROOT)/sdk/native/jni/OpenCV.mk

#FLAGS := -fno-exceptions
LOCAL_CPP_FEATURES += exceptions
cppFlags := -"frtti"

LOCAL_MODULE := native-lib
LOCAL_LDLIBS += -llog
LOCAL_SRC_FILES := ./native-lib.cpp
LOCAL_CFLAGS := $(cppFlags)

NDK_MODULE_PATH := $(call my-dir)

include $(BUILD_SHARED_LIBRARY)