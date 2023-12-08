/*
 * main.cpp
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */
#include "Almanac.h"
#include <iostream>
#include <algorithm>

int main(int argc, char *argv[]){
	auto almanac = Almanac::from_file("input");
	auto locations = almanac.get_locations();
	std::cout << (*std::min_element(locations.begin(), locations.end())).lowest() << std::endl;
}

