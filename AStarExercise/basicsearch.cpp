#include "basicsearch.hpp"

BasicSearch::BasicSearch(const std::vector<bool>& map):
	map(map)
{ }

bool BasicSearch::findShortestPath(const Coordinate& startPosition, const Coordinate& endPosition, std::list<unsigned int>& path)
{
	return false;
}

const ResultMap BasicSearch::getResultMap(const std::list<unsigned int>& path) const {
	ResultMap resultMap(map);
	resultMap.addPath(path);
	return resultMap;
}