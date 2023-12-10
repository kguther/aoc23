/*
 * main.cpp
 *
 *  Created on: Dec 10, 2023
 *      Author: kai
 */

#include "Game.h"
#include <iostream>

int main(int argc, char *argv[]){
	auto game = Game::from_file("input");
	long total_score = game.rank();
	std::cout << total_score << std::endl;
}

