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
#include <unordered_map>

class SpringRow {
public:
	SpringRow(): defect_info(""), contiguous_defects(std::vector<int>(0)){init_key();};
	SpringRow(std::string const &defect_info_, std::vector<int> const &contigous_defects_): defect_info(defect_info_), contiguous_defects(contigous_defects_) {init_key();};
	virtual ~SpringRow() {};

	long get_options() const;

	static SpringRow from_line(std::string const &line);
private:
	std::string defect_info;
	std::vector<int> contiguous_defects;
	std::string key;
	static std::unordered_map<std::string, long> cache;
	void init_key();
};

#endif /* SPRINGROW_H_ */
