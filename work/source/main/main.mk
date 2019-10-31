#
# METAL GEAR SOLID
# Test Makefile for "Main"
#

TOP    = ../..
COMMON = $(TOP)/common
MODULE = $(TOP)/module
SOURCE = $(TOP)/source

INCDIRS = \
-I$(COMMON)         \
-I$(MODULE)/include \
-I$(MODULE)/libsio  \
-I$(MODULE)/mts     \
-I$(MODULE)/sound   \
-I$(SOURCE)/include \
-I$(SOURCE)/game    \
-I$(SOURCE)/font    \
-I$(SOURCE)/libdg   \
-I$(SOURCE)/libfs   \
-I$(SOURCE)/libgcl  \
-I$(SOURCE)/libgv   \
-I$(SOURCE)/libhzd  \
-I$(SOURCE)/libmc

BUILDFLAG = SLPM86247
BUILDCONF = -DBUILD_$(BUILDFLAG)

DEFINES = $(BUILDCONF) -DDEBUG
CFLAGS  = -Wall -O2 -c $(INCDIRS) $(DEFINES)

all: psx

psx: main.c
	ccpsx $(CFLAGS) $^

clean:
	-rm *.obj
