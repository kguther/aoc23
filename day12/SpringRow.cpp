/*
 * SpringRow.cpp
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#include "SpringRow.h"
#include "SplitString.h"
std::string DETERMINED = "#.";

long SpringRow::get_options() const {
	std::vector<std::string> defect_options = {defect_info};
	std::vector<std::string> valid_options(0);
	std::vector<std::string> new_defect_options(0);
	std::string option_variant;
	while(true){
		new_defect_options.clear();
		for(auto option: defect_options){
			auto pos = option.find('?');
			if(pos == option.npos){
				return static_cast<long>(defect_options.size());
			}
			else{
				for(auto variant : DETERMINED){
					option_variant = option;
					option_variant[pos] = variant;
					if(SpringRow(option_variant, contigous_defects).is_possible()){
						new_defect_options.push_back(option_variant);
					}
				}
			}
		}
		defect_options = new_defect_options;
	}
}

bool SpringRow::is_possible() const {
	int chunk_size = 0;
	int chunk_index = 0;
	for(auto spring: defect_info){
		if(spring == '#'){
			++chunk_size;
		}
		if(spring == '.'){
			if(chunk_size > 0){
				if(chunk_size != contigous_defects[chunk_index]){
					return false;
				}
				++chunk_index;
				chunk_size = 0;
			}
		}
		if(spring == '?'){
			return chunk_size == 0 or chunk_size <= contigous_defects[chunk_index];
		}
	}
	if(chunk_size > 0){
		if(chunk_size == contigous_defects.back()){
			++chunk_index;
		}
		else{
			return false;
		}
	}
	return chunk_index == contigous_defects.size();
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
	return SpringRow(defect_info, contigous_defects);
}
