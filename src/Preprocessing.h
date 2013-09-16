/*
 * Preprocessing.h
 *
 *  Created on: 16/09/2013
 *      Author: gustavo
 */

#ifndef PREPROCESSING_H_
#define PREPROCESSING_H_

#include "dataset.h"

MatrixPointer MeanNormalize(DatasetPointer data);
void ApplyMeanNormalization(DatasetPointer data, MatrixPointer meanData);

#endif /* PREPROCESSING_H_ */
