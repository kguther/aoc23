/*
 * Hand.cpp
 *
 *  Created on: Dec 10, 2023
 *      Author: kai
 */

#include "Hand.h"
#include <vector>
#include <algorithm>
#include <sstream>

std::string ORDER = "23456789TJQKA";

bool value_compare(char a, char b){
	int value_a = ORDER.find(a);
	int value_b = ORDER.find(b);
	return value_a < value_b;
}

bool operator<(Hand const &first, Hand const &other) {
	if(first.category != other.category){
		return first.category < other.category;
	}
	for(int i = 0; i < first.cards.size(); ++i){
		if(first.cards[i] != other.cards[i]){
			return value_compare(first.cards[i], other.cards[i]);
		}
	}
	return false;
}

int Hand::get_category() const {
	std::vector<int> multiplicity(5);
	std::transform(cards.begin(), cards.end(), multiplicity.begin(),
			[this](char c){return std::count(cards.begin(), cards.end(), c);}
	);
	std::sort(multiplicity.begin(), multiplicity.end(), std::greater<int>());
	switch(multiplicity[0]){
	case 1:
		return 0;
	case 2:
		if(multiplicity[2] == 2){
			return 2;
		}
		return 1;
	case 3:
		if(multiplicity[3] == 2){
			return 4;
		}
		return 3;
	case 4:
		return 5;
	case 5:
		return 6;
	default:
		return 0;
	}
}

Hand Hand::from_line(const std::string &line) {
	std::string cards;
	long bid;
	std::stringstream linestream(line);
	linestream >> cards;
	linestream >> bid;
	return Hand(cards, bid);
}
