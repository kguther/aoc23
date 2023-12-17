/*
 * main.cpp
 *
 *  Created on: Dec 17, 2023
 *      Author: kai
 */

#include "Records.h"
#include <iostream>

int main(int argc, char* argv[]){
	auto records = Records::from_file("input");
	long options = records.get_options();
	std::cout << options << std::endl;
}


