TARGET := EglantineNX
BUILD := build
SOURCES := source
DATA :=
INCLUDES :=

APP_TITLE := Eglantine NX
APP_AUTHOR := KG Games
APP_VERSION := 0.1.0

ICON := icon.jpg

CFLAGS := -g -Wall -O2 -ffunction-sections -fdata-sections
CFLAGS += $(INCLUDES) -D__SWITCH__
CXXFLAGS := $(CFLAGS) -fno-rtti -fno-exceptions
LDFLAGS := -specs=$(DEVKITPRO)/libnx/switch.specs -g
LIBS := -lnx

include $(DEVKITPRO)/libnx/switch_rules
