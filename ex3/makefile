.SUFFIXES: .c .o .a 

SOURCE= analysis.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex3

ex3: ex3.o libex3.a
	gcc -g -Wall -o $@ $@.o -lm -L./ -lex3

libex3.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run:
	./ex3 no1.txt no2.txt 2

clean:
	rm -rf *.o *.a ex3

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
