/*
 * Hand.h
 *
 *  Created on: Dec 10, 2023
 *      Author: kai
 */

#ifndef HAND_H_
#define HAND_H_

#include <string>

class Hand {
public:
	Hand(): cards(""), bid(0), category(-1) {}
	Hand(std::string const& cards_, long bid_): cards(cards_), bid(bid_) {
		category = get_category();
	};
	virtual ~Hand() {};
	long get_bid() const {return bid;}

	static Hand from_line(std::string const &line);
	friend bool operator<(Hand const &first, Hand const &other);
private:
	std::string cards;
	long bid;
	int get_category() const;
	int category;
};


#endif /* HAND_H_ */
