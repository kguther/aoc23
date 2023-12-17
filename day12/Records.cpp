/*
 * Records.cpp
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#include <fstream>
#include "Records.h"
#include <iostream>

Records Records::from_file(std::string const &filename) {
	std::ifstream ifile(filename);
	std::vector<SpringRow> rows;
	std::string line;
	while(std::getline(ifile, line)){
		rows.push_back(SpringRow::from_line(line));
	}
	return Records(rows);
}

int Records::get_options() const {
	long options = 0;
	for(int i = 0; i < rows.size(); ++i){
		options += rows[i].get_options();
		std::cout << "Handled row " << i + 1 << " of " << rows.size() << std::endl;
	}
	return options;
}
