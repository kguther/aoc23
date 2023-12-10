/*
 * Game.cpp
 *
 *  Created on: Dec 10, 2023
 *      Author: kai
 */

#include "Game.h"
#include <fstream>
#include <algorithm>

long Game::rank() {
	std::sort(hands.begin(), hands.end());
	long score = 0;
	for(int i = 0; i < hands.size(); ++i){
		score += (i+1) * hands[i].get_bid();
	}
	return score;
}

Game Game::from_file(const std::string &filename) {
	std::ifstream inputfile(filename);
	std::vector<Hand> hands(0);
	for(std::string line; std::getline(inputfile, line);){
		hands.push_back(Hand::from_line(line));
	}
	return Game(hands);
}
