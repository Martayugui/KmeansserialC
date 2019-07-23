#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <string.h>

void pepito(int rows, int columns, int bands,int pixels,float *image, struct parameters *par, int *assignedCluster);

void initializeCluster(float *clusterCentroids, int k, int pixels, int bands, float *image);

float computeError(float *clusterCentroids, float *previousCentroids, int r, int c);

void computeDistance(int *assignedCluster, float *centroidDistances, float *clusterCentroids, float *image, int pixels, int bands, int k);

int findMinimum(float *vet, int size);

void updateClusterCentroids(float *clusterCentroids, int *assignedCluster, float *image, int bands, int pixels, int k);


