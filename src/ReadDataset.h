/*
 * ReadDataset.h
 *
 *  Created on: 11/09/2013
 *      Author: gustavo
 */

#ifndef READDATASET_H_
#define READDATASET_H_

#include <string>
#include "dataset.h"

class ReadDataset {
public:
	static DatasetPointer read(std::string filename, int nLabels);
};

#endif /* READDATASET_H_ */
