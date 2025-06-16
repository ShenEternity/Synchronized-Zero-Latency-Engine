LOCAL_PATH:= $(call my-dir)

include $(CLEAR_VARS)

LOCAL_SRC_FILES := $(LOCAL_PATH)/../../main.cpp
LOCAL_MODULE := core


COMMAND := -Wall -Oz -g0 -ffat-lto-objects -flto -fdata-sections -ffunction-sections -finline-functions -fomit-frame-pointer

LOCAL_CFLAGS += $(COMMAND) $(OPT)
LOCAL_CPPFLAGS += $(COMMAND) $(OPT) -std=c++20
LOCAL_LDFLAGS += $(COMMAND)

include $(BUILD_EXECUTABLE)