/*
 * BuildOperation.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#include "BuildOperation.h"
#include "AddOperation.h"
#include "RemoveOperation.h"

std::unique_ptr<Operation> build_operation(std::string const &operation_string){
	auto add_operation_marker = operation_string.find('=');
	if(add_operation_marker == operation_string.npos){
		return std::unique_ptr<Operation>(new RemoveOperation(operation_string));
	}
	return std::unique_ptr<Operation>(new AddOperation(operation_string));
}


