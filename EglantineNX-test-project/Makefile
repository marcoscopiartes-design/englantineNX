.PHONY: all clean

# Requer devkitPro + devkitA64 + libnx instalados.
ifeq ($(strip $(DEVKITPRO)),)
$(error DEVKITPRO nao definido. Instale/configure o devkitPro com libnx.)
endif

include $(DEVKITPRO)/libnx/switch_rules

TARGET := EglantineNX
BUILD := build
SOURCES := source
INCLUDES :=

CFLAGS := -g -Wall -O2 -ffunction-sections -fdata-sections
CFLAGS += $(INCLUDES) -D__SWITCH__
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
LDFLAGS := -specs=$(DEVKITPRO)/libnx/switch.specs -g
LIBS := -lnx

EXTRA_TARGETS := $(BUILD)/$(TARGET).nro
include $(DEVKITPRO)/libnx/switch_rules
