#include "knn.h"
#include <cassert>
#include <algorithm>
#include "dataset.h"
#include <iostream>
#include "debug.h"

double GetSquaredDistance(DatasetPointer train, size_t trainExample, DatasetPointer target, size_t targetExample) {
	assert(train->cols == target->cols);
	double sum = 0;
	double difference;
	for(size_t col = 0; col < train->cols; col++) {
		difference = train->pos(trainExample, col) - target->pos(targetExample, col);
		sum += difference * difference;
	}
	return sum;
}

KNNResults KNN::run(int k, DatasetPointer target) {


	DatasetPointer results(new dataset_base(target->rows,target->numLabels, target->numLabels));
	results->clear();

	//squaredDistances: first is the distance; second is the trainExample row
	std::pair<double, int> squaredDistances[data->rows];

	for(size_t targetExample = 0; targetExample < target->rows; targetExample++) {

#ifdef DEBUG_KNN
		if (targetExample % 100 == 0)
				DEBUGKNN("Target %lu of %lu\n", targetExample, target->rows);
#endif
		//Find distance to all examples in the training set
		for (size_t trainExample = 0; trainExample < data->rows; trainExample++) {
				squaredDistances[trainExample].first = GetSquaredDistance(data, trainExample, target, targetExample);
				squaredDistances[trainExample].second = trainExample;
		}

		//sort by closest distance
		sort(squaredDistances, squaredDistances + data->rows);
		
		//count classes of nearest neighbors
		size_t nClasses = target->numLabels;
		int countClosestClasses[nClasses];
		for(size_t i = 0; i< nClasses; i++)
			 countClosestClasses[i] = 0;

		for (int i = 0; i < k; i++)
		{

			int currentClass = data->label(squaredDistances[i].second);
			countClosestClasses[currentClass]++;
		}

		//result: probability of class K for the example X
		for(size_t i = 0; i < nClasses; i++)
		{
			results->pos(targetExample, i) = ((double)countClosestClasses[i]) / k;
		}
	}

	//copy expected labels:
	for (size_t i = 0; i < target->rows; i++)
		results->label(i) = target->label(i);

	return KNNResults(results);
}
