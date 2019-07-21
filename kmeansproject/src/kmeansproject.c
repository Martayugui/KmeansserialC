#include "read_par_and_img.h"


/* 3 struct are used:
preProcessedImage contains the image to analyze
parameters contains the details necessary for the analysis
kMeansCluster contains the results, that is the cluster to which each pixel belongs, content of assignedCluster */

int main(int argc, char **argv) {

	float *image;
	int pixels;
	int bands;
	int columns;
	int rows;
	bands=128;
	rows=270;
	columns=233;
	pixels= columns*rows;
	struct parameters par;



    readParAndImg (rows,columns,bands,pixels,&image,&par,"Parameters.txt","Op4C3.txt");

	return 0;
}
