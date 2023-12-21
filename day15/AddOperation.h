/*
 * AddOperation.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef ADDOPERATION_H_
#define ADDOPERATION_H_

#include <string>
#include "Operation.h"
#include "Hash.h"

class AddOperation: public Operation {
public:
	AddOperation(std::string const &operation);
	virtual ~AddOperation() {};
private:
	std::string label;
	int focal_length;

	void execute(Box &box) const;
	int operation_hash() const {return hash(label);};
};

#endif /* ADDOPERATION_H_ */
