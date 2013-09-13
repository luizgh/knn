/*
 * testUtils.h
 *
 *  Created on: 12/09/2013
 *      Author: gustavo
 */

#ifndef TESTUTILS_H_
#define TESTUTILS_H_

#include <iostream>

using namespace std;

template <typename T>
void assertEquals(T expected, T actual) {
	if (expected  != actual) {
		cout << "Error: Expected: " << expected << "; Actual: " << actual << "\n";
		exit(1);
	}
}
void assertDoubleEquals(double expected, double actual, double maxError = 1e-3) {
	if (fabs(expected-actual) > maxError) {
		cout << "Error: Expected: " << expected << "; Actual: " << actual << "\n";
		exit(1);
	}
}

MatrixPointer makeMatrix(int rows, int cols, double *sampleData)
{
	MatrixPointer matrix = MatrixPointer (new matrix_base(rows,cols));
	for(int i=0;i<rows;i++)
			for (int j =0;j<cols;j++)
				matrix->pos(i,j) = sampleData[i *cols +j];

	return matrix;
}


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



#endif /* TESTUTILS_H_ */
