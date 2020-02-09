#
# "METAL GEAR SOLID"
# Test Makefile for main.c
#

TOP    = ../..
COMMON = $(TOP)/common
MODULE = $(TOP)/module
SOURCE = $(TOP)/source

INCDIRS = \
-I$(COMMON)/include \
-I$(MODULE)/include \
-I$(SOURCE)/include

VERSION ?= SLPM86247

DEFINES = -DBUILD_$(VERSION) -DDEBUG -DPSX
CFLAGS  = -Wall -O2 -c $(INCDIRS) $(DEFINES)

all: psx

psx: main.c
	ccpsx $(CFLAGS) $^

clean:
	-rm *.obj
