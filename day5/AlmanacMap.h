/*
 * AlmanacMap.h
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#ifndef ALMANACMAP_H_
#define ALMANACMAP_H_

#include <vector>
#include <string>
#include "RangeMap.h"

class AlmanacMap {
public:
	AlmanacMap(){};
	AlmanacMap(std::vector<std::string> const &source);
	virtual ~AlmanacMap() {};
	std::vector<Range> operator()(std::vector<Range> source) const;
private:
	std::vector<RangeMap> sub_maps;
};

#endif /* ALMANACMAP_H_ */
