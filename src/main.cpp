#include <iostream>
#include "knn.h"
#include "ReadDataset.h"
#include "dataset.h"
#include "Preprocessing.h"
#include <new>

using namespace std;

void tryRunningKNN() {
	int nLabels = 10;
	cout << "Reading train" <<endl;
	DatasetPointer train = ReadDataset::read("CCtrain", nLabels);
	cout << "Reading test1" <<endl;
	DatasetPointer test1 = ReadDataset::read("CCtest1", nLabels);

	DatasetPointer newTrain, valid, newTest;
	train->splitDataset(newTrain, valid, 0.5);
	test1->splitDataset(newTest, valid, 0.1);

	printf ("New train: %lu\n", newTrain->rows);

	MatrixPointer meanData = MeanNormalize(newTrain);

	KNN knn(newTrain);

	cout << "Running KNN on test1. " << newTest->numLabels <<endl;

	ApplyMeanNormalization(newTest, meanData);

	KNNResults res1 = knn.run(4, newTest);
	cout << "Consolidating results";
	SingleExecutionResults r1 = res1.top1Result();
	printf("CCTest1: Success Rate: %lf, Rejection Rate: %lf\n", r1.successRate(), r1.rejectionRate());
	//printf("CCTest2: Success Rate: %lf, Rejection Rate: %lf\n", r2.successRate(), r2.rejectionRate());
}



int main()
{
	try {
		tryRunningKNN();
	} catch (bad_alloc &e) {
		cerr << "Error Running KNN. Not enough memory: " << e.what();
	}

}

