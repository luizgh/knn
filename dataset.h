#ifndef DATASET_H
#define DATASET_H

#include "debug.h"
#include <memory>
#include <cstdio>

class dataset_base;
class matrix_base;


typedef std::shared_ptr<matrix_base> matrix;
typedef std::shared_ptr<dataset_base> dataset;

class matrix_base {
private:
	double *data;
public:
	size_t rows;
	size_t cols;

	double& pos (size_t row, size_t col) {return data[row * cols + col]; }

	matrix_base(size_t rows, size_t cols) { 
		data = new double[rows*cols] ; 
		this->rows = rows; 
		this->cols = cols; 
		DEBUG("allocated double: %lu * %lu in %p\n",rows,cols,data); 

	}
	virtual ~matrix_base() { 
		DEBUG("deleted: %lu x %lu from %p\n",rows,cols,data); 
		delete [] data; 
	}

	virtual void clear();
};

class dataset_base : public matrix_base {
private:
	int *labels;

public:
	size_t numLabels;

	int &label (size_t row) { return labels[row]; }
	
	dataset_base(size_t rows, size_t cols, size_t numLabels) : matrix_base(rows,cols) { 
		labels = new int[rows];
		this->numLabels = numLabels;
		DEBUG("allocated int: %lu in %p\n",rows,labels); 

	}
	virtual ~dataset_base() { 
		DEBUG("deleted: %lu in %p\n",rows,labels); 
		delete [] labels; 
	}

	void splitDataset(dataset &train, dataset &valid, double train_percent);
};


#endif /* DATASET_H */
