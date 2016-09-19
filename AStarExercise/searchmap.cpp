#include <math.h>
#include <stdlib.h>

#include "searchmap.hpp"
#include "exception.hpp"

unsigned int SearchMap::calculateDistance(const unsigned int index, const Coordinate& endPosition) {
	unsigned int x = index%MAP_WIDTH;
	unsigned int y = index/MAP_WIDTH;

	int distx = abs((int)(x - endPosition.getX()));
	int disty = abs((int)(y - endPosition.getY()));

	return distx + disty;
}

SearchMap::SearchMap(std::vector<bool> contents, const Coordinate& endPosition):
	data(MAP_SIZE)
{
	if(contents.size() != SMALL_MAP_SIZE) {
		throw AStarException("ERROR (SearchMap::SearchMap()): Not enough data given for construction of map.");
	}

	unsigned int index = 0;
	unsigned int index_small = 0;
	for(unsigned int y = 0; y < SMALL_MAP_HEIGHT; y++) {
		// 1 + in order to correct for the added walls
		index = 1 + y*MAP_WIDTH;
		for(unsigned int x = 0; x < SMALL_MAP_WIDTH; x++) {
			data[index] = SearchField(contents[index_small]?WALL_FIELD:EMPTY_FIELD, calculateDistance(index, endPosition));
			index++;
			index_small++;
		}
	}

	// add wall
	for(unsigned int i = 0; i < MAP_WIDTH; i++) {
		data[i].setType(WALL_FIELD);
		data[i+(MAP_HEIGHT-1)*MAP_WIDTH].setType(WALL_FIELD);
	}

	for(unsigned int i = 0; i < MAP_HEIGHT; i++) {
		data[i*MAP_WIDTH].setType(WALL_FIELD);
		data[i*MAP_WIDTH+(MAP_WIDTH-1)].setType(WALL_FIELD);
	}
}