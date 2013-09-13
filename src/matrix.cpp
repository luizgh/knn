/*
 * matrix.cpp
 *
 *  Created on: 05/09/2013
 *      Author: gustavo
 */

#include "matrix.h"
#include "debug.h"
#include <cstdio>

matrix_base::matrix_base(size_t rows, size_t cols) {
	    DEBUGMEM("matrix: allocating double: %lu * %lu \n",rows,cols);
		data = new double[rows*cols] ;
		this->rows = rows;
		this->cols = cols;
		DEBUGMEM("matrix: allocated double: %lu * %lu in %p\n",rows,cols,data);
}

matrix_base::~matrix_base() {
	DEBUGMEM("matrix: deleting: %lu x %lu from %p\n",rows,cols,data);
	delete [] data;
}

void matrix_base::clear() {
	for (size_t i = 0; i<rows;i++)
		for(size_t j =0; j<cols; j++)
			pos(i,j) = 0;
}
