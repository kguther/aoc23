/*
 * Manual.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#include <fstream>
#include <numeric>
#include "Manual.h"
#include "BuildOperation.h"
#include <iostream>
Manual Manual::from_file(std::string const &filename) {
	std::vector<std::unique_ptr<Operation> > instructions;
	std::ifstream input_file(filename);
	std::string input_instructions;
	std::getline(input_file, input_instructions);
	auto separator_position = input_instructions.find(',');
	while(separator_position != input_instructions.npos){
		instructions.push_back(std::move(build_operation(input_instructions.substr(0, separator_position))));
		input_instructions = input_instructions.substr(separator_position+1, input_instructions.size());
		separator_position = input_instructions.find(',');
	}
	instructions.push_back(std::move(build_operation(input_instructions)));
	return Manual(instructions);
}

int Manual::hash_sum() const {
	return std::accumulate(
			operations.begin(),
			operations.end(),
			0,
			[](int acc, std::unique_ptr<Operation> const &value){return acc + value->total_hash();}
	);
}

void Manual::apply(std::vector<Box> &boxes) const {
	for(auto &operation: operations){
		operation->execute(boxes);
	}
}
