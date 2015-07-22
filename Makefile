
STATICLIB=libgraphicsff.a
BUILD_ARCH=$(shell uname -m)

ifdef DEBUG
CFLAGS+=-g
CPPFLAGS+=-D_DEBUG
else
CFLAGS+=-O3
CPPFLAGS+=-D_DEBUG
endif

CFLAGS+=-Wall -std=c99
# c99 necessary to use the inline keyword.
# But note from https://gcc.gnu.org/onlinedocs/gcc/Inline.html#Inline:
#  GCC does not inline any functions when not optimizing unless you specify
#  the ‘always_inline’ attribute for the function, like this: 
#  // Prototype.
#  inline void foo (const char) __attribute__((always_inline));

############################################################################

OBJECTS=pgm.o \
	png.o \
	pnm.o

############################################################################
# Rules

all : $(STATICLIB)

# Following object dependencies use GNU make's implicit rules.

# Core modules.

# Helper/accessory modules

$(STATICLIB) : $(OBJECTS)
	$(AR) rcs $@ $^ 

############################################################################
# For future reference
# To statically link one library (e.g. libgsl.a) and dynamic for remainder
#	$(CC) ... $^ -Wl,-Bstatic -L$(HOME)/lib -lgsl -Wl,-Bdynamic -lm -lpthread
############################################################################

############################################################################
# Unit tests

UNITTESTS=$(addprefix ut-,pgm)

allunit : $(UNITTESTS)

ut-pgm : pgm.c
	$(CC) -o $@ $(CFLAGS) -DUNIT_TEST_PGM $^

############################################################################

clean : 
	rm -f *.o ut-* $(STATICLIB)

$(DEPLOYMENT_ARCHIVE).tar.gz : *.c *.h Makefile
	mkdir $(DEPLOYMENT_ARCHIVE)
	cp -L $^ "$(DEPLOYMENT_ARCHIVE)/"
	tar cfz $@ "$(DEPLOYMENT_ARCHIVE)/"
	rm -rf $(DEPLOYMENT_ARCHIVE)

.PHONY : all allunit clean

