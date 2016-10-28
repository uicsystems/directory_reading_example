TARGETS=example

CFLAGS=-Wall -g -O0

all: $(TARGETS)

example: example.c
	gcc $(CFLAGS) -o example example.c

clean:
	rm -f $(TARGETS)
