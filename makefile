CC=gcc
LIBS=-lraylib

make: main.c
	$(CC) -o output main.c $(LIBS)
