/*
 * RemoveOperation.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef REMOVEOPERATION_H_
#define REMOVEOPERATION_H_

#include "Hash.h"
#include "Operation.h"

class RemoveOperation: public Operation {
public:
	RemoveOperation(std::string const &operation);
	virtual ~RemoveOperation() {};

private:
	void execute(Box &box) const;
	std::string label;
	int operation_hash() const {return hash(label);}
};

#endif /* REMOVEOPERATION_H_ */
