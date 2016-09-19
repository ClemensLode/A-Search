#include <sstream>

#include "exception.hpp"
#include "resultmap.hpp"

ResultMap::ResultMap(std::vector<bool> contents):
	data(SMALL_MAP_SIZE)
{
	if(contents.size() != SMALL_MAP_SIZE) {
		throw AStarException("ERROR (ResultMap::ResultMap()): Not enough data given for construction of map.");
	}

	unsigned int index = 0;
	for(unsigned int i = 0; i < SMALL_MAP_SIZE; i++) {
		data[index].setType(contents[index]?WALL_FIELD:EMPTY_FIELD);
		index++;
	}
}

std::string ResultMap::toString() const {
	std::ostringstream os;
	int index = 0;
	for(unsigned int y = 0; y < SMALL_MAP_HEIGHT; y++) {
		for(unsigned int x = 0; x < SMALL_MAP_WIDTH; x++) {
			switch(data[index].getType()) {
				case EMPTY_FIELD:os << ".";break;
				case WALL_FIELD:os << "*";break;
				case PATH_FIELD:os << "+";break;
			}
			index++;
		}
		os << std::endl;
	}

	return os.str();
}

void ResultMap::addPath(const std::list<unsigned int>& path)
{
	for(std::list<unsigned int>::const_iterator i = path.begin(); i != path.end(); i++) {
		// calculate down to small map
		unsigned int x = *i % MAP_WIDTH - 1;
		unsigned int y = *i / MAP_WIDTH;
		data[x + y * SMALL_MAP_WIDTH] = PATH_FIELD;
	}	
}