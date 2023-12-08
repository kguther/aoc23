/*
 * AlmanacMap.cpp
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#include "AlmanacMap.h"
#include <sstream>

std::vector<long> line_as_longs(std::string const &string){
	std::vector<long> row(0);
	std::stringstream istream(string);
	long number;
	while(istream >> number){
		row.push_back(number);
	}
	return row;
}

AlmanacMap::AlmanacMap(std::vector<std::string> const &source) {
	sub_maps = std::vector<RangeMap>();
	for(auto line: source){
		auto values = line_as_longs(line);
		sub_maps.push_back(RangeMap(values[0], values[1], values[2]));
	}
}

std::vector<Range> AlmanacMap::operator ()(std::vector<Range> source) const {
	std::vector<Range> results(0);
	std::vector<Range> remainder_ranges(0);
	for(auto map: sub_maps){
		remainder_ranges.clear();
		for(auto range: source){
			auto result = map(range);
			auto transformed = std::get<0>(result);
			if(!transformed.empty()){
				results.push_back(transformed);
			}
			auto remainder = std::get<1>(result);
			remainder_ranges.insert(remainder_ranges.begin(), remainder.begin(), remainder.end());
		}
		source = remainder_ranges;
	}
	results.insert(results.end(), source.begin(), source.end());
	return results;
}
