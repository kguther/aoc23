/*
 * Almanac.h
 *
 *  Created on: Dec 8, 2023
 *      Author: kai
 */

#ifndef ALMANAC_H_
#define ALMANAC_H_

#include <vector>
#include "AlmanacMap.h"

class Almanac {
public:
	Almanac(std::vector<AlmanacMap> const &maps_, std::vector<Range> const &seeds_): maps(maps_), seeds(seeds_) {};
	virtual ~Almanac(){};
	std::vector<Range> get_locations() const;

	static Almanac from_file(std::string const &filename);
private:
	std::vector<AlmanacMap> maps;
	std::vector<Range> seeds;
};

#endif /* ALMANAC_H_ */
