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
	dataset getConfusionMatrix();
	
	KNNResults(matrix results) { this->results = results;}

private:
	matrix results;

};
	

class KNN {
public:
	KNN (dataset train) { this->data = train; }
	
	KNNResults run(int k, dataset target);

private: 
	dataset data;
};

#endif /* KNN_H */
