#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stock{
	int num;
    double score;
    int ana;
    int vec;
    int bio;
    struct stock* nextValue;
}stock;

typedef struct AVE{
    int numP;
    double ana;
    double vec;
    double bio;
}AVE;