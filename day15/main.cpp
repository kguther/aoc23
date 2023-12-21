/*
 * main.cpp
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */
#include <iostream>
#include "Manual.h"

long total_focusing_power(std::vector<Box> const &boxes){
	long total_power = 0l;
	for(int box_number = 0; box_number < boxes.size(); ++box_number){
		Box const& box = boxes[box_number];
		for(int slot = 0; slot < box.size(); ++slot){
			total_power += ((1+box_number) * (1+slot) * box[slot].get_focal_length());
		}
	}
	return total_power;
}

int main(int argc, char *argv[]){
	auto manual = Manual::from_file("input");
	int hash_sum = manual.hash_sum();
	std::cout << hash_sum << std::endl;
	std::vector<Box> boxes(256);
	manual.apply(boxes);
	std::cout << total_focusing_power(boxes) << std::endl;
}


