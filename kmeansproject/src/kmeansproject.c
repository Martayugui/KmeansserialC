#include "read_par_and_img.h"


/* 3 struct are used:
preProcessedImage contains the image to analyze
parameters contains the details necessary for the analysis
kMeansCluster contains the results, that is the cluster to which each pixel belongs, content of assignedCluster */


int main() {

	int pixels;
	int bands;
	int columns;
	int rows;
	bands=128;
	rows=270;
	columns=233;
	pixels= columns*rows; //62910
	float *img;
	img = (float *)malloc(pixels * bands * sizeof(float));
	struct parameters par;
	int *assignedCluster;
	int i;
	int j;

    readParAndImg (rows,columns,bands,pixels,img,&par,"Parameters.txt","Op4C3.txt");
    for (i = 0; i<pixels; i++) {
    		for (j = 0; j < bands; j++) {
    			printf("%f\t", img[bands*i + j]);
    		}
    printf("\n");
    }
    pepito(rows, columns, bands,pixels,img, &par, &assignedCluster);

exit(0);
}
