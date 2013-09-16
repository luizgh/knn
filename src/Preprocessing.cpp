/*
 * Preprocessing.cpp
 *
 *  Created on: 16/09/2013
 *      Author: gustavo
 */

#include "Preprocessing.h"
#include <cmath>

using namespace std;

MatrixPointer MeanNormalize(DatasetPointer data) {
	/*
	 X =    X - X_min   /
	      X_max - X_min

	Returns a matrix: first row contains the "min" for each column. second row contains the "max" for each column
	*/
	MatrixPointer results = MatrixPointer(new matrix_base(2, data->cols));
	results->clear();

	for(size_t i = 0; i < data->rows; i++) {
		for(size_t j = 0; j < data->cols; j++) {
			results->pos(0,j) = min(results->pos(0,j), data->pos(i,j));
			results->pos(1,j) = max(results->pos(1,j), data->pos(i,j));
		}
	}

	for(size_t i = 0; i < data->rows; i++) {
		for(size_t j = 0; j < data->cols; j++) {
			data->pos(i,j) = (data->pos(i,j) - results->pos(0,j)) / (results->pos(1,j) - results->pos(0,j));
		}
	}
	return results;
}

void ApplyMeanNormalization(DatasetPointer data, MatrixPointer meanData) {
	for(size_t i = 0; i < data->rows; i++) {
			for(size_t j = 0; j < data->cols; j++) {
				data->pos(i,j) = (data->pos(i,j) - meanData->pos(0,j)) / (meanData->pos(1,j) - meanData->pos(0,j));
			}
		}
}


MatrixPointer ZScore(DatasetPointer data) {
	/*
	 X =    X - X_mean   /
	         X_std

	Returns a matrix: first row contains the "mean" for each column. second row contains the "standard deviation" for each column
	*/
	MatrixPointer results = MatrixPointer(new matrix_base(2, data->cols));
	results->clear();

	//Sum all values
	for(size_t i = 0; i < data->rows; i++) {
		for(size_t j = 0; j < data->cols; j++) {
			results->pos(0,j) = results->pos(0,j) + data->pos(i,j);
		}
	}

	//Calculate mean
	for(size_t j = 0; j < data->cols; j++) {
		results->pos(0,j) = results->pos(0,j) / data->rows;
	}

	//Calculate standard deviation
	for(size_t i = 0; i < data->rows; i++) {
		for(size_t j = 0; j < data->cols; j++) {
			double data_minus_mean = data->pos(i,j) - data->pos(0,j);
			data->pos(1,j) = data->pos(1,j) +  data_minus_mean  * data_minus_mean;
		}
	}
	for(size_t j = 0; j < data->cols; j++) {
		results->pos(1,j) = sqrt(results->pos(1,j) / data->rows);
	}


	//Apply to data
	for(size_t i = 0; i < data->rows; i++) {
		for(size_t j = 0; j < data->cols; j++) {
			data->pos(i,j) = (data->pos(i,j) - results->pos(0,j)) / (results->pos(1,j));
		}
	}
	return results;
}
