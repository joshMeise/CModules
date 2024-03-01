CFLAGS=-Wall -pedantic -std=c11 -I. -g
OFILES=stack.o queue.o hash.o

all:  $(OFILES)
			ar cr ../lib/libutils.a $(OFILES)

%.o:  %.c %.h
			gcc $(CFLAGS) -c $<

clean:
			rm -f *.o ../lib/libutils.a
