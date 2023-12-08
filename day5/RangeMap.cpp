/*
 * RangeMap.cpp
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#include "RangeMap.h"

RangeMap::RangeMap(long target_start, long source_start, long range) {
	offset = target_start - source_start;
	source_range = Range(source_start, source_start + range);
}

std::pair<Range, std::vector<Range> > RangeMap::operator()(Range source) const {
	auto affected_range = source_range.intersect(source);
	affected_range.offset(offset);
	auto remainder = source.remove(source_range);
	return std::pair<Range, std::vector<Range> >(affected_range, remainder);
}

