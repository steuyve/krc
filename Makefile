CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c89

all:
	mkdir -p bin
	make eof
	make count-whitespace
	make char-freq
	make rm-trailing
	make entab
	make bits
	make escape

eof: src/eof.c
	$(CC) -o bin/$@ $< $(CFLAGS)

count-whitespace: src/count-whitespace.c
	$(CC) -o bin/$@ $< $(CFLAGS)

char-freq: src/char-freq.c
	$(CC) -o bin/$@ $< $(CFLAGS)

rm-trailing: src/rm-trailing.c
	$(CC) -o bin/$@ $< $(CFLAGS)

entab: src/entab.c
	$(CC) -o bin/$@ $< $(CFLAGS)

bits: src/bits.c
	$(CC) -o bin/$@ $< $(CFLAGS)

escape: src/escape.c
	$(CC) -o bin/$@ $< $(CFLAGS)

clean:
	rm -rfI bin/
