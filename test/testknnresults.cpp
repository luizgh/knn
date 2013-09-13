#include <iostream>
#include <cstdio>
#include "dataset.h"
#include "knn.h"
#include <cassert>
#include <cmath>
#include "testUtils.h"


int main() 
{
	double rawData[] = {5.0/11, 4.0/11, 2.0 / 11, //top 1: 0 ; expected: 0 - Acertar
						5.0/11, 4.0/11, 2.0 / 11, //top 1: 0 ; expected: 0 - Acertar
						 5.0/11, 4.0/11, 2.0 / 11, //top 1: 0 ; expected: 1 - Errar
					 	 5.0/11, 5.0/11, 1.0 / 11}; //Empatados em 2o - rejeitar

	int labels[] = {0,0,1,1};
	DatasetPointer sampleData = makeDataset(4, 3, 2, rawData, labels);

	KNNResults target(sampleData);

	SingleExecutionResults actual = target.top1Result();

	assertEquals(2, actual.nSuccess);
	assertEquals(1, actual.nRejected);


	double MAX_ERROR = 1e-4;

	printf("%s OK!\n", __FILE__);

}
