CFLAGS=-Wall -pedantic -std=c11 -I../../utils -L../../lib
LIBS=-lutils -lcurl

all: testPushEmptyStack testPush2Stack testPush100Stack testOpenCloseStack testApplySingleStack testPop1Stack testPop5Stack

testPushEmptyStack:
										gcc $(CFLAGS) testPushEmptyStack.c $(LIBS) -o $@

testPush2Stack:
										gcc $(CFLAGS) testPush2Stack.c $(LIBS) -o $@

testPush100Stack:
										gcc $(CFLAGS) testPush100Stack.c $(LIBS) -o $@

testOpenCloseStack:
										gcc $(CFLAGS) testOpenCloseStack.c $(LIBS) -o $@

testApplySingleStack:
										gcc $(CFLAGS) testApplySingleStack.c $(LIBS) -o $@

testPop1Stack:
										gcc $(CFLAGS) testPop1Stack.c $(LIBS) -o $@

testPop5Stack:
										gcc $(CFLAGS) testPop5Stack.c $(LIBS) -o $@

clean:
			rm -f testPushEmptyStack testPush2Stack testPush100Stack testOpenCloseStack testApplySingleStack testPop1Stack testPop5Stack *.o
