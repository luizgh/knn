/*
 * testReadDataset.cpp
 *
 *  Created on: 11/09/2013
 *      Author: gustavo
 */

#include "dataset.h"
#include "ReadDataset.h"
#include <cassert>
#include <iostream>
#include <cmath>
#include "testUtils.h"

using namespace std;

int main()
{
	DatasetPointer data = ReadDataset::read("CCtrain", 10);
	assertDoubleEquals(0, data->pos(0,0));
	assertDoubleEquals(0.102757, data->pos(0,131));

	assertEquals(0, data->label(0));

	assertDoubleEquals(0.052755, data->pos(149999,4));
	assertDoubleEquals(0.093357, data->pos(149999,131));

	assertEquals(9, data->label(149999));

	printf("%s OK!\n", __FILE__);
}
