#include <iostream>
#include <cstdio>
#include "dataset.h"
#include "knn.h"



int main() 
{
	double sampleData[] = { 5, 4, 4,5, 8,10,9,11, 15,5,16,6 };
	int labels[] = { 0,0, 1, 1, 2, 2 };

	srand(time(0));
	DatasetPointer data = DatasetPointer(new dataset_base(6,2, 3));
	for(int i=0;i<5;i++)
		for (int j =0;j<2;j++)
			data->pos(i,j) = sampleData[i *2 +j];
	for(int i=0;i<5;i++)
		data->label(i) = labels[i];


	DatasetPointer train, valid;
	data->splitDataset(train, valid, 0.7 );

	KNN knn(train);

}
