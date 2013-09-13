#include <iostream>
#include "knn.h"
#include "ReadDataset.h"
#include "dataset.h"
#include <new>

using namespace std;

void tryRunningKNN() {
	int nLabels = 10;
	cout << "Reading train" <<endl;
	DatasetPointer train = ReadDataset::read("CCtrain", nLabels);
	cout << "Reading test1" <<endl;
	DatasetPointer test1 = ReadDataset::read("CCtest1", nLabels);
	cout << "Reading test2" <<endl;
	DatasetPointer test2 = ReadDataset::read("CCtest2", nLabels);

	KNN knn(train);

	cout << "Running KNN on test1" <<endl;
	KNNResults res1 = knn.run(4, test1);
	cout << "Running KNN on test2" <<endl;
	KNNResults res2 = knn.run(4, test2);
}



int main()
{
	try {
		tryRunningKNN();
	} catch (bad_alloc &e) {
		cerr << "Error Running KNN. Not enough memory: " << e.what();
	}

}

