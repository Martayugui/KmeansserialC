/*
 * read_par_and_img.h
 *
 *  Created on: Jul 20, 2019
 *      Author: gdem
 */

#ifndef READ_PAR_AND_IMG_H_
#define READ_PAR_AND_IMG_H_

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

void readParAndImg (int rows,int columns,int bands,int pixels,float *image,parameters *par, char * namefile, char *nameimage);


#endif /* READ_PAR_AND_IMG_H_ */
