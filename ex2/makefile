.SUFFIXES: .c .o .a 

SOURCE= analysis.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex2

ex2: ex2.o libex2.a
	gcc -g -Wall -o $@ $@.o -lm -L./ -lex2

libex2.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run:
	./ex2 no1.txt no2.txt

clean:
	rm -rf *.o *.a ex2

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
