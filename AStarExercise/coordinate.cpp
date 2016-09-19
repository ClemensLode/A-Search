#include <sstream>

#include "coordinate.hpp"

std::string Coordinate::toString() const {
	std::ostringstream os;
	os << "(" << x << ", " << y << ")";
	return os.str();
}

