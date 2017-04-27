#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

typedef struct stock{
	double value;
    struct stock* nextValue;
}stock;

extern void yamlGet(FILE *fpt,void* a);
extern void yamlPut(FILE *fpt,char* term,void* value,int type,int mode);
