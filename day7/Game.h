/*
 * Game.h
 *
 *  Created on: Dec 10, 2023
 *      Author: kai
 */

#ifndef GAME_H_
#define GAME_H_

#include <vector>
#include "Hand.h"
#include <string>

class Game {
public:
	Game(std::vector<Hand> const& hands_): hands(hands_) {};
	virtual ~Game() {};

	long rank();

	static Game from_file(std::string const &filename);
private:
	std::vector<Hand> hands;
};

#endif /* GAME_H_ */
