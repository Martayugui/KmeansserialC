#include "read_par_and_img.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>


/*========================================================================

   Global Variable

   ======================================================================*/
static FILE *fp ;
static FILE *fp1;

void readParAndImg (int rows,int columns,int bands,int pixels,float *image,struct parameters *par,char *namefile,char *nameimage) {

	fp = fopen(namefile, "r");
	fp1 = fopen(nameimage, "r");
    int scan = 0;
    char s[10];
    float n;
	int i;
	int j;
    rewind(fp);
    rewind(fp1);
    image = (float *)malloc(pixels * bands * sizeof(float));


/* reads the parameters and populates the corresponding struct */
	while (scan!=EOF) {
		scan=fscanf(fp, "%s", &s);

		if (strcmp(s, "k") == 0) {
			fscanf(fp, "%d", &par->k);
		}else if (strcmp(s, "minErr") == 0) {
			fscanf(fp, "%f", &par->minErr);
		}else if (strcmp(s, "maxIter") == 0) {
			fscanf(fp, "%d", &par->maxIter);
		}else if (strcmp(s, "verbose") == 0) {
			fscanf(fp, "%d", &par->verbose);
		}
	}
	//printf("parameters k: %d\t minErr: %f\t maxIter: %d\n",par->k, par->minErr, par->maxIter);
	fflush(stdout);
/* reads the image and populates the corresponding struct */
	
	for (i = 0; i<pixels; i++) {
		for (j = 0; j < bands; j++) { 
			fscanf(fp1, "%f", &image[bands*i + j]);
		}
	}
	for (i = 0; i<pixels; i++) {
			for (j = 0; j < bands; j++) {
				printf("%f\t", image[bands*i + j]);
			}
			printf("\n");
	}


	fclose(fp);
    fclose(fp1);
}





