.SUFFIXES: .c .o .a 

SOURCE= analysis.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex5

ex5: ex5.o libex5.a
	gcc -g -Wall -o $@ $@.o -lm -L./ -lex5

libex5.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run:
	./ex5 no1.txt no2.txt 3

clean:
	rm -rf *.o *.a ex5

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
