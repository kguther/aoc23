/*
 * Operation.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef OPERATION_H_
#define OPERATION_H_

#include <string>
#include <vector>
#include "Hash.h"
#include "Box.h"

class Operation {
public:
	Operation(): operation_string("") {};
	Operation(std::string const &operation): operation_string(operation) {};

	void execute(std::vector<Box> &boxes) const {
		int box_index = operation_hash();
		Box& box = boxes[box_index];
		execute(box);
	}

	std::string string() const {return operation_string;};
	int total_hash() const {return hash(string());};
	virtual ~Operation() {};
private:
	std::string operation_string;
	virtual int operation_hash() const = 0;
	virtual void execute(Box &box) const = 0;
};

#endif /* OPERATION_H_ */
