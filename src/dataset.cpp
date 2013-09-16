#include <memory>
#include <algorithm>
#include "dataset.h"
#include "debug.h"
#include <cstdio>

dataset_base::dataset_base(size_t rows, size_t cols, size_t numLabels) : matrix_base(rows,cols) {
	labels = new int[rows];
	this->numLabels = numLabels;
	DEBUGMEM("dataset: allocated int: %lu in %p\n",rows,labels);
}

 dataset_base::~dataset_base() {
	 DEBUGMEM("dataset: deleting: %lu in %p\n",rows,labels);
	 delete [] labels;
}

void fillWithRandomIndices(int *indices, size_t nIndices) {
 	for(size_t i = 0; i< nIndices; i++) indices[i] = i;
 	std::random_shuffle(indices, indices + nIndices);
 }

void dataset_base::splitDataset(DatasetPointer &train, DatasetPointer &valid, double train_percent) {
	int randomIndices[rows];
	fillWithRandomIndices(randomIndices, rows);

	size_t threshold = (size_t) (train_percent * rows);

	train = DatasetPointer(new dataset_base(threshold, cols, numLabels));
	valid = DatasetPointer(new dataset_base(rows - threshold, cols, numLabels));

	size_t currentRowTrain=0;
	size_t currentRowValid=0;
	for(size_t i =0; i< rows; i++)
	{
		if (i < threshold) {
			for (size_t j=0; j < cols; j++)
				train->pos(currentRowTrain, j) = pos(randomIndices[i],j);
			train->label(currentRowTrain) = label(randomIndices[i]);
			currentRowTrain++;
		}
		else {
			for (size_t j=0; j < cols; j++)
				valid->pos(currentRowValid, j) = pos(randomIndices[i],j);
			valid->label(currentRowValid) = label(randomIndices[i]);
			currentRowValid++;
		}
	}
}


