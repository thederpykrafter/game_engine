# use @<command> to supress make echoing command
CC = g++
LANG = cpp
CFLAGS = -g
CLIBS = -lSDL2

OUT_FILE = Hello

default: build

install: build copy

test: build run

build: src/main.$(LANG)
	@if [ ! -d bin ]; then mkdir bin; fi
	$(CC) $(CFLAGS) src/main.$(LANG) $(CLIBS) -o bin/$(OUT_FILE)

copy: bin/$(OUT_FILE)
	cp -rf bin/$(OUT_FILE) /usr/bin

uninstall: bin/$(OUT_FILE)
	rm -f /usr/bin/$(OUT_FILE)

run:
	./bin/$(OUT_FILE)

clean veryclean:
	rm -f bin/*
