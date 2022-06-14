#
# Mixer.app Makefile
#

DESTDIR =
GNUSTEP_BINDIR = /usr/local/GNUstep/Apps/PulseMixer.app
X11_BINDIR = /usr/bin

CXX=c++
CXXFLAGS += -Wall -pedantic -fno-rtti -fno-exceptions -O2 -fexceptions
LDFLAGS += -lXpm -lXext -lX11 -lpulse

OBJECTS = Main.o Mixer.o Xpm.o PMixer/pulse.o

all: PulseMixer.app

PulseMixer.app: $(OBJECTS)
	$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)

.PHONY:	install clean distclean

install: install-gnustep

install-gnustep: all
	install -d  $(DESTDIR)$(GNUSTEP_BINDIR)
	install -m 0755 PulseMixer.app $(DESTDIR)$(GNUSTEP_BINDIR)/AlsaMixer

install-x11: all
	install -d  $(DESTDIR)$(X11_BINDIR)
	install -m 0755 PulseMixer.app $(DESTDIR)$(X11_BINDIR)/PulseMixer.app

clean:
	rm -f *~ $(OBJECTS) PulseMixer.app

# End of file
