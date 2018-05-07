CFLAGS = -Wall -fpic -coverage -lm

testme.o: testme.c
	gcc -c testme.c -g $(CFLAGS)

test: testme.o
	gcc -o testme testme.o -g $(CFLAGS)

testAll: test
	./testme

clean:
	rm -f *.o testme *.out *.gcno *.gcda
