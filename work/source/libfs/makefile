#
# Makefile for LibFS
# ver.METAL GEAR SOLID
#
# ref. beatmania APPEND 5thMIX
#  1998.06.19 : work.5th/libfs/makefile
#

#---------------------- Rules and defines

TOP     = ..
LIBDIR  = $(TOP)/lib

CCPSX   = ccpsx
CFGPSX  = @../options
TRGPSX  = ${LIBDIR}/libfs.lib
OBJPSX1 = fsdb.obj fshd.obj fscd.obj cdbios.obj srchfile.obj cdstage.obj moviesys.obj
OBJPSX2 = memfile.obj stageld.obj stream.obj streamhd.obj
OBJPSX  = ${OBJPSX1} ${OBJPSX2}

SELECTOBJS = hd.obj cd.obj db.obj cdd.obj

%.obj: %.c
	${CCPSX} ${CFGPSX} $<

#---------------------- How to make

all:
	cd ..
	make

#psx: ${TRGPSX}
psx: ${TRGPSX} $(SELECTOBJS)

${TRGPSX}: ${OBJPSX} makefile
	-rm $@
#	psylib /a $@ ${OBJPSX1} > NUL
#	psylib /a $@ ${OBJPSX2} > NUL
	psylib /a $@ ${OBJPSX1}
	psylib /a $@ ${OBJPSX2}

$(SELECTOBJS) : select.c file.cnf
#$(SELECTOBJS) : select.c
	$(CCPSX) $(CFGPSX) -D$(*F) $< -o $@

#---------------------- Operations

clean:
	-rm *.obj
