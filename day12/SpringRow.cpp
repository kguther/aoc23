/*
 * SpringRow.cpp
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#include <algorithm>
#include "SpringRow.h"
#include "SplitString.h"

int NON_CHUNK = -100;

std::unordered_map<std::string, long> SpringRow::cache = {};

long SpringRow::get_options() const {
	auto cache_hit = cache.find(key);
	if(cache_hit != cache.end()){
		return cache_hit->second;
	}
	long options = 0;
	if(defect_info.empty()){
		if(contiguous_defects.size() == 1 && (contiguous_defects.back() == NON_CHUNK or contiguous_defects.back() == 0)){
			return 1L;
		}
		return 0L;
	}
	else{
		if(defect_info.front() == '.' or defect_info.front() == '?'){
			std::vector<int> contiguous_defects_options = contiguous_defects;
			if(contiguous_defects_options.back() == 0 or contiguous_defects_options.back() == NON_CHUNK){
				contiguous_defects_options.back() = NON_CHUNK;
				auto option_row = SpringRow(defect_info.substr(1), contiguous_defects_options);
				options += option_row.get_options();
			}
		}
		if(defect_info.front() == '#' or defect_info.front() == '?'){
			if(!contiguous_defects.empty()){
				std::vector<int> contiguous_defects_options = contiguous_defects;
				if(contiguous_defects_options.back() == NON_CHUNK and contiguous_defects_options.size() > 1){
					contiguous_defects_options.pop_back();
				}
				--contiguous_defects_options.back();
				if(contiguous_defects_options.back() >= 0){
					auto option_row = SpringRow(defect_info.substr(1), contiguous_defects_options);
					options += option_row.get_options();
				}
			}
		}
	}
	cache[key] = options;
	return options;
}


SpringRow SpringRow::from_line(std::string const &line) {
	auto parts = split_string(line, ' ');
	auto defect_info = std::get<0>(parts);

	auto contigous_info = std::get<1>(parts);
	std::vector<int> contigous_defects(0);
	while(contigous_info.find(',') != contigous_info.npos){
		parts = split_string(contigous_info, ',');
		contigous_defects.push_back(std::stoi(std::get<0>(parts)));
		contigous_info = std::get<1>(parts);
	}
	contigous_defects.push_back(std::stoi(contigous_info));
	auto single_contigous_defects = contigous_defects;
	auto single_defects = defect_info;
	for(int i = 0; i < 4; ++i){
		defect_info += "?";
		defect_info += single_defects;
		contigous_defects.insert(contigous_defects.end(), single_contigous_defects.begin(), single_contigous_defects.end());
	}
	std::reverse(contigous_defects.begin(), contigous_defects.end());
	contigous_defects.push_back(NON_CHUNK);
	return SpringRow(defect_info, contigous_defects);
}

void SpringRow::init_key() {
	key = defect_info;
	for(auto value: contiguous_defects){
		key += ',';
		key += std::to_string(value);
	}
}
