/*
 * hash.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#include "Hash.h"

int hash(std::string const &value){
	int hash_value = 0;
	for(auto character: value){
		hash_value += int(character);
		hash_value *= 17;
		hash_value = hash_value % 256;
	}
	return hash_value;
}



