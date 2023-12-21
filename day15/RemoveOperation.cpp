/*
 * RemoveOperation.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#include <algorithm>
#include "SplitString.h"
#include "RemoveOperation.h"

RemoveOperation::RemoveOperation(std::string const &operation): Operation(operation) {
	auto parts = split_string(operation, '-');
	label = parts.first;
}

void RemoveOperation::execute(Box &box) const {
	Lens lens(label, 0);
	auto lens_position = std::find(box.begin(), box.end(), lens);
	if(lens_position != box.end()){
		box.erase(lens_position);
	}
}
