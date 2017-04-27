#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stock{
	double value;
    struct stock* nextValue;
}stock;