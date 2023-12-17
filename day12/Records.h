/*
 * Records.h
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#ifndef RECORDS_H_
#define RECORDS_H_

#include <vector>
#include <string>
#include "SpringRow.h"

class Records {
public:
	Records(): rows(std::vector<SpringRow>(0)) {};
	Records(std::vector<SpringRow> const &rows_): rows(rows_) {};
	virtual ~Records() {};

	int get_options() const;

	static Records from_file(std::string const &filename);
private:
	std::vector<SpringRow> rows;

};

#endif /* RECORDS_H_ */
