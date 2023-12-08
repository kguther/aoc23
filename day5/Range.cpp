/*
 * Range.cpp
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#include "Range.h"
#include <algorithm>

Range Range::intersect(const Range &other) const {
	return Range(std::max(start, other.start), std::min(end, other.end));
}

std::vector<Range> Range::remove(const Range &other) const {
	auto intersection = intersect(other);
	std::vector<Range> result;
	if(intersection.empty()){
		result.push_back(Range(start, end));
	}
	else if(intersection.start <= start && intersection.end <= end){
		result.push_back(Range(intersection.end, end));
	}
	else if(intersection.end >= end){
		result.push_back(Range(start, intersection.start));
	}
	else{
		result.push_back(Range(start, intersection.start));
		result.push_back(Range(intersection.end, end));
	}
	return result;
}

bool Range::operator <(const Range &other) const {
	if(empty()){
		return false;
	}
	if(other.empty()){
		return true;
	}
	return lowest() < other.lowest();
}
