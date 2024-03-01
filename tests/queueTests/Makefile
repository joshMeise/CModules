CFLAGS=-Wall -pedantic -std=c11 -I../../utils -L../../lib
LIBS=-lutils -lcurl

all: testRemoveMiddle testConcatEmpty2Empty testConcat2Empty testConcatEmpty2 testRemoveMiddleThenApply testRemoveEmpty testPutEmpty testApplyEmpty testGetEmpty testSearchEmpty testRemoveFirst testRemoveLast testGetOne

testRemoveMiddle:	
									gcc $(CFLAGS) testRemoveMiddle.c $(LIBS) -o $@

testRemoveFirst:	
									gcc $(CFLAGS) testRemoveFirst.c $(LIBS) -o $@

testRemoveLast:	
								gcc $(CFLAGS) testRemoveLast.c $(LIBS) -o $@

testConcatEmpty2Empty:
											gcc $(CFLAGS) testConcatEmpty2Empty.c $(LIBS) -o $@

testConcat2Empty:			
											gcc $(CFLAGS) testConcat2Empty.c $(LIBS) -o $@

testConcatEmpty2:			
											gcc $(CFLAGS) testConcatEmpty2.c $(LIBS) -o $@

testRemoveMiddleThenApply:  
														gcc $(CFLAGS) testRemoveMiddleThenApply.c $(LIBS) -o $@

testRemoveEmpty:  
									gcc $(CFLAGS) testRemoveEmpty.c $(LIBS) -o $@

testPutEmpty: 
							gcc $(CFLAGS) testPutEmpty.c $(LIBS) -o $@

testApplyEmpty: 
							  gcc $(CFLAGS) testApplyEmpty.c $(LIBS) -o $@

testGetEmpty: 
							gcc $(CFLAGS) testGetEmpty.c $(LIBS) -o $@

testGetOne: 
						gcc $(CFLAGS) testGetOne.c $(LIBS) -o $@

testSearchEmpty:  
							  	gcc $(CFLAGS) testSearchEmpty.c $(LIBS) -o $@

clean:
					rm -f *.o test testRemoveMiddle testConcatEmpty2Empty testConcat2Empty testConcatEmpty2 testRemoveMiddleThenApply testRemoveEmpty testPutEmpty testApplyEmpty testGetEmpty testSearchEmpty testRemoveLast testRemoveFirst testGetOne
