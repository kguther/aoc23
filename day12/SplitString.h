/*
 * split_string.h
 *
 *  Created on: Dec 4, 2022
 *      Author: kai
 */

#ifndef SPLITSTRING_H_
#define SPLITSTRING_H_

#include <utility>
#include <string>

inline std::pair<std::string, std::string> split_string(std::string const &input, char sep){
	auto separator = input.find(sep, 0);
	return std::make_pair(input.substr(0, separator), input.substr(separator+1, input.size()));
}


#endif /* SPLITSTRING_H_ */
