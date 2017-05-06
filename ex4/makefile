.SUFFIXES: .c .o .a 

SOURCE= analysis.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex4

ex4: ex4.o libex4.a
	gcc -g -Wall -o $@ $@.o -lm -L./ -lex4

libex4.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run:
	./ex4 no1.txt no2.txt 2

clean:
	rm -rf *.o *.a ex4

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
