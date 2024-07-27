all: lockbox test

test: test.o
	gcc lockbox.o test.o -o test -Wall -O2

test.o: test.c
	gcc -c -O2 -Wall test.c 

lockbox: lockbox.o
	gcc lockbox.o -o lockbox.so -O2 -Wall -fPIC -shared -ldl -D_GNU_SOURCE

lockbox.o: lockbox.c
	gcc -c -O2 -Wall lockbox.c

clean:
	rm -f *.o *.so test