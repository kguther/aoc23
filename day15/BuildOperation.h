/*
 * BuildOperation.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef BUILDOPERATION_H_
#define BUILDOPERATION_H_

#include "Operation.h"
#include <string>
#include <memory>

std::unique_ptr<Operation> build_operation(std::string const &operation_string);


#endif /* BUILDOPERATION_H_ */
