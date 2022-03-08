vpath %.c src
vpath %.h include
vpath %.o bin

CC = clang
CFLAGS = -O3 -std=c18 -Wall -Wextra -Wpedantic

.PHONY: all
all: Cipher.o Numeric.o Search.o Sort.o Text.o Utilities.o 
	make --directory=bin/

Cipher.o: Cipher.c Cipher.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)
Numeric.o: Numeric.c Numeric.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)
Search.o: Search.c Search.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)
Sort.o: Sort.c Sort.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)
Text.o: Text.c Text.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)
Utilities.o: Utilities.c Utilities.h
	$(CC) -c $< -o bin/$@ $(CFLAGS)

