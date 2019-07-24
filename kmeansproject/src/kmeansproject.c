#include "read_par_and_img.h"


/* 3 struct are used:
preProcessedImage contains the image to analyze
parameters contains the details necessary for the analysis
kMeansCluster contains the results, that is the cluster to which each pixel belongs, content of assignedCluster */


int main() {

	clock_t start, stop;
	double time;
	int pixels;
	int bands;
	int columns;
	int rows;
	bands=128;
	rows=270;
	columns=233;
	pixels= columns*rows; //62910
	int p=pixels*bands;
	struct parameters par;
	int assignedCluster[pixels];
	int i;
	int j;
	char namefile[15]= "Parameters.txt";
	char nameimage[15]= "Op4C3.txt";

	float *img;
    img = (float *)malloc(pixels * bands * sizeof(float));
    readParAndImg (rows,columns,bands,pixels,img,&par,namefile,nameimage);
   /*for (i = 0; i<pixels; i++) {
    		for (j = 0; j < bands; j++) {
    			printf("%f\t", img[bands*i + j]);
    		}
    printf("\n");
    } */
    start = clock();
    kmeansfunction(rows, columns, bands,pixels,img, &par, assignedCluster);
    stop = clock();
    time = ((double)stop - start) / CLOCKS_PER_SEC;
    printf("Time of execution file %s with %d pixel e %d bands: %lf", namefile, pixels, bands, time);
    writeResults (rows, columns, assignedCluster);
exit(0);
}
