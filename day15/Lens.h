/*
 * Lens.h
 *
 *  Created on: Dec 21, 2023
 *      Author: kai
 */

#ifndef LENS_H_
#define LENS_H_

#include <string>

class Lens {
public:
	Lens(): label(""), focal_length(-1) {};
	Lens(std::string const &label_, int focal_length_): label(label_), focal_length(focal_length_) {}

	bool operator==(Lens const &other) const {return label == other.label;};
	bool operator!=(Lens const &other) const {return !(*this == other);};

	int get_focal_length() const {return focal_length;};
	virtual ~Lens() {};
private:
	std::string label;
	int focal_length;
};

#endif /* LENS_H_ */
