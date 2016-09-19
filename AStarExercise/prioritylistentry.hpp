#ifndef _PRIORITYLISTENTRY_HPP
#define _PRIORITYLISTENTRY_HPP

/*
 * This class is used in a priority queue for optimization purposes in connection with the A* search.
 */

class PriorityListEntry
{
public:
	PriorityListEntry(const unsigned int score, const std::set<unsigned int>::const_iterator index):score(score),index(index) {}
	~PriorityListEntry() {}

	std::set<unsigned int>::const_iterator getIndex() const { return index;}

	friend bool operator<(const PriorityListEntry& x, const PriorityListEntry& y)
	{
		return x.score > y.score;
	};
private:
	unsigned int score;
	std::set<unsigned int>::const_iterator index;
};

#endif // _PRIORITYLISTENTRY_HPP