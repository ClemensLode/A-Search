#include <set>
#include <queue>

#include "astarsearch.hpp"
#include "searchmap.hpp"
#include "searchfield.hpp"
#include "prioritylistentry.hpp"

AStarSearch::AStarSearch(const std::vector<bool>& map, const Coordinate& endPosition):
BasicSearch(map),
	searchMap(SearchMap(map, endPosition))
{ }

AStarSearch::~AStarSearch() {}



bool AStarSearch::findShortestPath(const Coordinate& startPosition, const Coordinate& endPosition, std::list<unsigned int>& path) {

	std::set<unsigned int> openList;
	std::set<unsigned int> closedList;
	std::priority_queue<PriorityListEntry, std::vector<PriorityListEntry> > priorityListQueue;

	unsigned int startIndex = SearchMap::getIndex(startPosition);
	unsigned int endIndex = SearchMap::getIndex(endPosition);
	std::vector<SearchField>& data = searchMap.getData(); 

	// initialize with the start position
	openList.insert(startIndex);
	priorityListQueue.push(PriorityListEntry(data[startIndex].getScore(), openList.begin()));
	
	
	int direction[8];
	direction[0] = NORTH_WEST;
	direction[1] = NORTH;
	direction[2] = NORTH_EAST;
	direction[3] = EAST;
	direction[4] = SOUTH_EAST;
	direction[5] = SOUTH;
	direction[6] = SOUTH_WEST;
	direction[7] = WEST;
	

	while(openList.size() > 0) {

		// acquire the best node (i.e. the node with the smallest length) from the open list.
		std::set<unsigned int>::iterator best_index = priorityListQueue.top().getIndex();

		// we have calculated the best entry
		unsigned int index = *best_index;

		// is this entry already our goal?
		if(endIndex == index) {
			path.push_front(index);
			while(index != startIndex) {
				// reconstruct the path by calculating it in reverse starting from the end point
				path.push_front(index);
				index = data[index].getPreviousIndex();
			}
			return true;
		}
		// otherwise mark this entry as closed (i.e. we are finished with this node)
		closedList.insert(index);
		openList.erase(best_index);
		priorityListQueue.pop();

		// increase the distance
		unsigned int length = 1 + data[index].getLength();

		// look through all 8 neighbors
		for(int d = 0; d < 8; d++) {
			unsigned int neighbor_index = index + direction[d];
			// ignore closed and occupied fields
			if(data[neighbor_index].getType() == WALL_FIELD || closedList.find(neighbor_index) != closedList.end()) {
				continue;
			}

			// visited fields are updated if the new path is better
			if(data[neighbor_index].getLength() > length) {
				data[neighbor_index].updatePreviousIndex(index);
				data[neighbor_index].updateLength(length);
				while(!priorityListQueue.empty()) {
					priorityListQueue.pop();
				}
				for(std::set<unsigned int>::const_iterator j = openList.begin(); j != openList.end(); j++) {
					priorityListQueue.push(PriorityListEntry(data[*j].getScore(), j));
				}
			} else
			// unvisited fields are reinitialized
			if(openList.find(neighbor_index) == openList.end()) {
				openList.insert(neighbor_index);
				data[neighbor_index].updatePreviousIndex(index);
				data[neighbor_index].updateLength(length);
				priorityListQueue.push(PriorityListEntry(data[neighbor_index].getScore(), openList.find(neighbor_index)));
			} 
		}
	}
	return false;
}

