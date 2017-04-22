.SUFFIXES: .c .o .a 

SOURCE= number.c average.c

.c.o:
	gcc -g -Wall -c $*.c -o $*.o

all: ex1

ex1: ex1.o libex1.a
	gcc -g -Wall -o $@ ex1.o -lm -L./ -lex1 $(LIBS)

libex1.a: $(SOURCE:.c=.o)
	ar r $@ $(SOURCE:.c=.o)

run1:
	./ex1 no1.txt no2.txt no3.txt

clean:
	rm -rf *.o *.a ex1

depend: $(SOURCE)
	gcc -M *.c > dependency

-include "dependency"
