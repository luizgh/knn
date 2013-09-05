#ifndef DATASET_H
#define DATASET_H

#include "matrix.h"
#include <memory>
#include <cstdio>

class dataset_base;

typedef std::shared_ptr<dataset_base> DatasetPointer;

class dataset_base : public matrix_base {
private:
	int *labels;

public:
	size_t numLabels;

	int &label (size_t row) { return labels[row]; }
	
	dataset_base(size_t rows, size_t cols, size_t numLabels);
	virtual ~dataset_base();

	void splitDataset(DatasetPointer &train, DatasetPointer &valid, double train_percent);
};


#endif /* DATASET_H */
