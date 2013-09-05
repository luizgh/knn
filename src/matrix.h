/*
 * matrix.h
 *
 *  Created on: 05/09/2013
 *      Author: gustavo
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include <memory>

class matrix_base;

typedef std::shared_ptr<matrix_base> MatrixPointer;


class matrix_base {
private:
	double *data;
public:
	size_t rows;
	size_t cols;

	double& pos (size_t row, size_t col) {return data[row * cols + col]; }

	matrix_base(size_t rows, size_t cols);
	virtual ~matrix_base();

	virtual void clear();
};


#endif /* MATRIX_H_ */
