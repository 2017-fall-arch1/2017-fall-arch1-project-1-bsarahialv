all:BDemo

CFLAGS=-g -O3

# Symbols helpful for understanding the productions
#   $@ is the production's target
#   $^ are the production's prerequisites

BDemo: BTree.o BDemo.o
	cc -o $@ $^

BTree.o: BDemo.c BTree.h
	cc -c $(CFLAGS) BTree.c

BDemo.o: BDemo.c BTree.h
	cc -c $(CFLAGS) BDemo.c

clean:
	rm -f *.o BDemo

demo: BDemo
	./BDemo

