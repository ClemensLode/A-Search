#ifndef _COORDINATE_HPP
#define _COORDINATE_HPP

#include <string>

/*
 * Basic class providing a place holder for two ints forming an X/Y coordinate.
 */

class Coordinate
{
public:
	Coordinate(const unsigned int x, const unsigned int y):x(x),y(y) {}
	~Coordinate() {}

	unsigned int getX() const { return x;}
	unsigned int getY() const { return y;}
	std::string toString() const;

	bool operator==(const Coordinate& other) const;

private:
	const unsigned int x;
	const unsigned int y;
};

inline bool Coordinate::operator==(const Coordinate& other) const {
	return x == other.x && y == other.y;
}

#endif // _COORDINATE_HPP