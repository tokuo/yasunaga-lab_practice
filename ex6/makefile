.SUFFIXES: .c .o .a 

SOURCE= analysis.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex6

ex6: ex6.o libex6.a
	gcc -g -Wall -o $@ $@.o -lm -L./ -lex6

libex6.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run:
	./ex6 no1.txt

clean:
	rm -rf *.o *.a ex4

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
