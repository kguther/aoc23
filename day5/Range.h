/*
 * Range.h
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#ifndef RANGE_H_
#define RANGE_H_

#include <vector>

class Range {
public:
	Range(): start(0), end(-1) {};
	Range(long start_, long end_): start(start_), end(end_) {};
	virtual ~Range(){};
	Range intersect(Range const &other) const;
	std::vector<Range> remove(Range const &other) const;
	bool empty() const {return end <= start;};
	long lowest() const {return start;};
	bool operator<(Range const& other) const;

	void offset(long offset) {start+=offset; end+=offset;};
private:
	long start, end;
};

#endif /* RANGE_H_ */
