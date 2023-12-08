/*
 * Almanac.cpp
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#include "Almanac.h"
#include <fstream>
#include <sstream>
#include <numeric>

std::vector<Range> Almanac::get_locations() const {
	std::vector<Range> locations(0);
	for(auto seed: seeds){
		std::vector<Range> values(1, seed);
		for(auto map: maps){
			values = map(values);
		}
		locations.insert(locations.end(), values.begin(), values.end());
	}
	return locations;
}

Almanac Almanac::from_file(const std::string &filename) {
	std::ifstream inputfile(filename);
	std::string line;
	std::vector<Range> seeds_(0);
	std::vector<AlmanacMap> maps_(0);
	std::vector<std::string> current_lines(0);
	for(std::string line; std::getline(inputfile, line);){
		if(line.compare(0, 7, "seeds: ") == 0){
			std::stringstream linestream(line.substr(7, line.size() - 7));
			long seed_begin;
			long seed_range;
			while(linestream >> seed_begin && linestream >> seed_range){
				seeds_.push_back(Range(seed_begin, seed_begin + seed_range));
			}
		}
		else if(line.find_first_of("-")!= std::string::npos){
			if(!current_lines.empty()){
				maps_.push_back(AlmanacMap(current_lines));
				current_lines.clear();
			}
		}
		else if(!line.empty()){
			current_lines.push_back(line);
		}
	}
	if(!current_lines.empty()){
		maps_.push_back(AlmanacMap(current_lines));
	}
	return Almanac(maps_, seeds_);
}
