/*
 * ReadDataset.cpp
 *
 *  Created on: 11/09/2013
 *      Author: gustavo
 */

#include "ReadDataset.h"
#include "dataset.h"

#include <iostream>
#include <fstream>
#include <stdexcept>

using namespace std;

DatasetPointer ReadDataset::read(std::string filename, int nLabels) {
	ifstream myFile(filename);

	if (!myFile.is_open()) {
		throw invalid_argument("filename");
	}

	size_t nExamples, nDim;

	myFile >> nExamples >> nDim;

	DatasetPointer result = DatasetPointer(new dataset_base(nExamples,nDim,nLabels));

	for(size_t i = 0; i < nExamples; i++) {
		for (size_t j = 0; j < nDim; j++)
			myFile >> result->pos(i,j);

		myFile>> result->label(i);
	}

	return result;
}

