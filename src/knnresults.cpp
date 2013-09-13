#include "knn.h"
#include <vector>
#include <algorithm>

using namespace std;

SingleExecutionResults KNNResults::topXResult(int n) {
	int nSuccess = 0;
	int nRejected = 0;

	for (size_t currentExample = 0; currentExample < results->rows; currentExample++) {
		pair<double, int> resultsForExample[results->cols];

		for(size_t j = 0; j < results->cols; j++)
			resultsForExample[j] = make_pair(results->pos(currentExample,j), j);

		sort(resultsForExample, resultsForExample + results->cols, greater<pair<double,int> >());

		for(int j = 0; j < n; j++) {
			if (resultsForExample[j].second == results->label(currentExample))
			{
				if (n == results->cols) {
					nSuccess++;
					break;
				}
				else {
					if (resultsForExample[n].first == resultsForExample[j].first)
						nRejected++;
					else
						nSuccess++;
					break;
				}
			}
		}
	}

	return SingleExecutionResults(results->rows, nSuccess, nRejected);
}
