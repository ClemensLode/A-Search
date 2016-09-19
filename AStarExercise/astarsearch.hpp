#ifndef _ASTARSEARCH_HPP
#define _ASTARSEARCH_HPP

#include <list>

#include "basicsearch.hpp"
#include "searchmap.hpp"
#include "searchfield.hpp"


/*
 * Implementation of a BasicSearch class, providing functionality for A* search.
 */

class AStarSearch : public BasicSearch
{
public:
	AStarSearch(const std::vector<bool>& map, const Coordinate& endPosition);
	~AStarSearch();
	
	bool findShortestPath(const Coordinate& startPosition, const Coordinate& endPosition, std::list<unsigned int>& path);
	const SearchMap& getSearchMap() const;

private:
	static void process(SearchField& searchField, unsigned int index, unsigned int length);
	SearchMap searchMap;
};

inline const SearchMap& AStarSearch::getSearchMap() const {
	return searchMap;
}

#endif // _ASTARSEARCH_HPP