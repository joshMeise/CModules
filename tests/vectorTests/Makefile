CFLAGS=-Wall -pedantic -std=c11 -I../../utils -L../../lib
LIBS=-lutils

all: testOpenClose testInsertOneBack testInsertTwoBack testInsertMultipleBack testContainsFound testContainsNotFound testGetSize testGetElement

testOpenClose: testOpenClose.c
							 gcc $(CFLAGS) testOpenClose.c $(LIBS) -o $@

testInsertOneBack: testInsertOneBack.c	
									 gcc $(CFLAGS) testInsertOneBack.c $(LIBS) -o $@

testInsertTwoBack: testInsertTwoBack.c	
									 gcc $(CFLAGS) testInsertTwoBack.c $(LIBS) -o $@

testGetSize: testGetSize.c
							gcc $(CFLAGS) testGetSize.c $(LIBS) -o $@

testGetElement: testGetElement.c
							gcc $(CFLAGS) testGetElement.c $(LIBS) -o $@

testInsertMultipleBack: testInsertOneBack.c	
									 gcc $(CFLAGS) testInsertMultipleBack.c $(LIBS) -o $@

testContainsFound: testContainsFound.c
									gcc $(CFLAGS) testContainsFound.c $(LIBS) -o $@

testContainsNotFound: testContainsNotFound.c
									gcc $(CFLAGS) testContainsNotFound.c $(LIBS) -o $@

clean:
					rm -f *.o testOpenClose testInsertOneBack testInsertTwoBack testInsertMultipleBack testContainsFound testContainsNotFound testGetSize testGetElement
