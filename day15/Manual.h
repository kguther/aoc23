/*
 * Manual.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef MANUAL_H_
#define MANUAL_H_

#include <string>
#include <vector>
#include <memory>
#include "Box.h"
#include "Operation.h"

class Manual {
public:
	Manual(std::vector<std::unique_ptr<Operation> > &operations_): operations(std::move(operations_)) {};
	virtual ~Manual() {};

	Manual(Manual &other) = delete;
	Manual(Manual &&other) = default;

	int hash_sum() const;
	void apply(std::vector<Box> &boxes) const;

	Manual static from_file(std::string const &filename);
private:
	std::vector<std::unique_ptr<Operation> > operations;
};

#endif /* MANUAL_H_ */
