CFLAGS=-Wall -pedantic -std=c11 -I../../utils -L../../lib
LIBS=-lutils

all: llTestOpenClose

llTestOpenClose: llTestOpenClose.c
								 gcc $(CFLAGS) llTestOpenClose.c $(LIBS) -o $@

clean:
			rm -f *.o llTestOpenClose
