#ifndef _BASICSEARCH_HPP
#define _BASICSEARCH_HPP

#include <vector>

#include "coordinate.hpp"
#include "resultmap.hpp"
#include "field.hpp"

/*
 * Base class for all search algorithms.
 */

class BasicSearch
{
public:
	BasicSearch(const std::vector<bool>& map);
	virtual ~BasicSearch() {}

	virtual bool findShortestPath(const Coordinate& startPosition, const Coordinate& endPosition, std::list<unsigned int>& path);
	const ResultMap getResultMap(const std::list<unsigned int>& path) const;

protected:
	const std::vector<bool>& map;
};

#endif // _BASICSEARCH_HPP