#include <iostream>
#include <cstdio>
#include "dataset.h"
#include "knn.h"
#include <cassert>
#include <cmath>

DatasetPointer makeDataset(int rows, int cols, int nLabels, double *sampleData, int *labels)
{
	DatasetPointer dataset = DatasetPointer(new dataset_base(rows,cols,nLabels));
	for(int i=0;i<rows;i++)
			for (int j =0;j<cols;j++)
				dataset->pos(i,j) = sampleData[i *cols +j];
		for(int i=0;i<rows;i++)
			dataset->label(i) = labels[i];

	return dataset;
}


int main() 
{
	srand(time(0));

	double sampleData[] = {5,4, 4,5, 5,5, 8,10, 9,11, 9,10, 15,5, 16,6, 16,5};
	int labels[] = {0, 0, 1, 1, 1, 2, 2, 2, 0};
	DatasetPointer train = makeDataset(9, 2, 3, sampleData, labels);

	double testData[] = {4,4, 8,10, 15,6};
	int testLabels[] = {0, 1, 2};

	DatasetPointer test = makeDataset(3, 2, 3, testData, testLabels);

	KNN knn(train);
	
	MatrixPointer results =  knn.run(3, test).getRawResults();

	double expected[] = { 2.0/3, 1.0/3, 0,
						  0, 2.0/3, 1.0/3,
						  1.0/3, 0, 2.0/3 };

	int expectedIndex=0;

	double MAX_ERROR = 1e-4;

	for(size_t i = 0; i< results->rows; i++)
		for (size_t j =0; j< results->cols; j++)
		{
			if(fabs(results->pos(i,j) - expected[expectedIndex]) > MAX_ERROR)
			{
				printf("Error in position %lu, %lu. Expected: %lf; Got: %lf\n",i,j, expected[expectedIndex], results->pos(i,j));
				exit(1);
			}
			expectedIndex++;
		}

	printf("%s OK!\n", __FILE__);

}
