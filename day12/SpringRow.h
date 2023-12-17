/*
 * SpringRow.h
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#ifndef SPRINGROW_H_
#define SPRINGROW_H_

#include <string>
#include <vector>

class SpringRow {
public:
	SpringRow(): defect_info(""), contigous_defects(std::vector<int>(0)){};
	SpringRow(std::string const &defect_info_, std::vector<int> const &contigous_defects_): defect_info(defect_info_), contigous_defects(contigous_defects_) {};
	virtual ~SpringRow() {};

	long get_options() const;
	bool is_possible() const;

	static SpringRow from_line(std::string const &line);
private:
	std::string defect_info;
	std::vector<int> contigous_defects;
};

#endif /* SPRINGROW_H_ */
