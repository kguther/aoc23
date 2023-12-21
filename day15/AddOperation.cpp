/*
 * AddOperation.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#include <algorithm>
#include "SplitString.h"
#include "AddOperation.h"
#include "Lens.h"

AddOperation::AddOperation(std::string const &operation): Operation(operation) {
	auto parts = split_string(operation, '=');
	label = parts.first;
	focal_length = std::stoi(parts.second);
}

void AddOperation::execute(Box &box) const {
	Lens new_lens(label, focal_length);
	auto lens_position = std::find(box.begin(), box.end(), new_lens);
	if(lens_position == box.end()){
		box.push_back(new_lens);
	}
	else{
		*lens_position = new_lens;
	}
}
