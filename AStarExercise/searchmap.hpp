#ifndef _SEARCHMAP_HPP
#define _SEARCHMAP_HPP

#include <vector>
#include <list>

#include "searchfield.hpp"
#include "coordinate.hpp"


/*
 * This class holds the map data and basic map functions.
 */

// Note that the actual map is 126x126, for optimization purposes we add an artificial wall around the map resulting in a 128x128 map.
// For proper use within an actual program these constants have to be replaced by variables and some caching needs to be done.
#define MAP_WIDTH 128
#define MAP_HEIGHT 128
#define MAP_SIZE (128*128)

#define NORTH_WEST -129
#define NORTH -128
#define NORTH_EAST -127
#define EAST 1
#define SOUTH_EAST 129
#define SOUTH 128
#define SOUTH_WEST 127
#define WEST -1

#define SMALL_MAP_WIDTH 126
#define SMALL_MAP_HEIGHT 126
#define SMALL_MAP_SIZE (126*126)


class SearchMap
{
public:
	SearchMap(std::vector<bool> contents, const Coordinate& endPosition);
	~SearchMap() { }

	std::vector<SearchField>& getData() {return data;}

	static unsigned int getIndex(const Coordinate& coordinate);
	
private:
	static unsigned int calculateDistance(const unsigned int index, const Coordinate& endPosition);
	std::vector<SearchField> data;
};

inline unsigned int SearchMap::getIndex(const Coordinate& coordinate) {
	return coordinate.getX() + coordinate.getY() * MAP_WIDTH;
}

#endif // _SEARCHMAP_HPP