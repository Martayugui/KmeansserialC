#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

typedef  struct parameters {
	int k;
	float minErr;
	int maxIter;
	int verbose;
}parameters;

void readParAndImg (int rows,int columns,int bands,int pixels,float *image,struct parameters *par,char *namefile,char *nameimage);
