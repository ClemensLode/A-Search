#ifndef _RESULTMAP_HPP
#define _RESULTMAP_HPP

/*
 * This class holds the map data and basic map functions.
 */


// the actual map is 126x126, for optimization purposes we add an artificial wall around the map resulting in a 128x128 map
#define MAP_WIDTH 128
#define MAP_HEIGHT 128
#define MAP_SIZE (128*128)

#define SMALL_MAP_WIDTH 126
#define SMALL_MAP_HEIGHT 126
#define SMALL_MAP_SIZE (126*126)

#include "field.hpp"
#include "coordinate.hpp"
#include <vector>
#include <list>

/*
 * Helper class to construct the text output out of a given map and the path. 
 * Note that ResultMap does not contain a wall around a given map.
 */

class ResultMap
{
public:
	ResultMap(std::vector<bool> contents);
	~ResultMap() {}

	void addPath(const std::list<unsigned int>& path);

	std::string toString() const;

private:
	std::vector<Field> data;
};

#endif // _RESULTMAP_HPP