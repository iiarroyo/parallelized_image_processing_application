COMPILER = g++
FLAGS = -lpthread -lX11 -ljpeg
BUILDDIR = build
SRCDIR = src
LIBDIR = lib
INCLUDEDIR = include
default:
	$(COMPILER) $(SRCDIR)/main.cpp -o $(BUILDDIR)/read_img $(FLAGS) -I$(LIBDIR) -I$(INCLUDEDIR)
clean:
	@rm -rf $(BUILDDIR)/*