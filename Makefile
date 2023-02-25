CC=gcc
CFLAGS=--std=c11 -Wall -pedantic -Isrc/ -ggdb -Wextra -Werror -DDEBUG
WIN32CC=i686-w64-mingw32-gcc

BUILDDIR=build
SRCDIR=src
RSRC=resources

PROGRAM=hello_world.c
INPUT=app.exe
INFO=info

.PHONY: all clean run

all: $(BUILDDIR)/main.o $(BUILDDIR)/file_manager.o $(BUILDDIR)/headers.o $(BUILDDIR)/section.o $(BUILDDIR)/seeking.o
	$(CC) -o $(BUILDDIR)/main $^

build:
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/file_manager.o: $(SRCDIR)/file_manager.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/headers.o: $(SRCDIR)/headers.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/section.o: $(SRCDIR)/section.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/seeking.o: $(SRCDIR)/seeking.c build
	$(CC) -c $(CFLAGS) $< -o $@

$(BUILDDIR)/main.o: $(SRCDIR)/main.c build
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -rf $(BUILDDIR)

run: clean all
	$(WIN32CC) -o $(RSRC)/$(INPUT) $(RSRC)/$(PROGRAM)
	build/main $(RSRC)/$(INPUT) $(RSRC)/$(INFO)
