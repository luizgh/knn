#ifndef KNN_H
#define KNN_H

#include "dataset.h"

class SingleExecutionResults {
public:
	SingleExecutionResults(int nExamples, int nSuccess, int nRejected) {
		this->nExamples = nExamples;
		this->nSuccess = nSuccess;
		this->nRejected = nRejected;
	}

	double successRate() { return nSuccess / (nExamples - nRejected);}
	double rejectionRate() { return nRejected / nExamples; }

private:
	int nExamples;
	int nSuccess;
	int nRejected;
};


class KNNResults {
public:
	SingleExecutionResults top1Result() { return topXResult(1); }
	SingleExecutionResults topXResult(int n);
	DatasetPointer getConfusionMatrix();
	
	MatrixPointer getRawResults() {return results;}

	KNNResults(MatrixPointer results) { this->results = results;}

private:
	MatrixPointer results;

};


class KNN {
public:
	KNN (DatasetPointer train) { this->data = train; }

	KNNResults run(int k, DatasetPointer target);

private:
	DatasetPointer data;
};

#endif /* KNN_H */
