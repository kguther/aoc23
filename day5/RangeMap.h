/*
 * RangeMap.h
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#ifndef RANGEMAP_H_
#define RANGEMAP_H_

#include "Range.h"
#include <vector>
#include <utility>

class RangeMap {
public:
	RangeMap(): source_range(0,0), offset(0){};
	RangeMap(long target_start, long source_start, long range);
	virtual ~RangeMap(){};
	std::pair<Range, std::vector<Range> > operator()(Range source) const;
private:
	Range source_range;
	long offset;
};

#endif /* RANGEMAP_H_ */
