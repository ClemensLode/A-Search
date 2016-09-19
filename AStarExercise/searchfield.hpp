#ifndef _SEARCHFIELD_HPP
#define _SEARCHFIELD_HPP

#include "field.hpp"


/*
 * This class extends a single field by several place holders required for the A* search.
 */
class SearchField : public Field
{
public:

	SearchField():Field(EMPTY_FIELD), length(0), estimatedDistance(0), score(0), previousIndex(0) {}
	SearchField(const eFieldType fieldType, const unsigned int estimatedDistance):Field(fieldType), length(0), estimatedDistance(estimatedDistance), score(0) {}
	~SearchField() {}

	void updateLength(const unsigned int length);
	void updatePreviousIndex(const unsigned int index);
	unsigned int getScore() const;
	unsigned int getLength() const;

	unsigned int getPreviousIndex() const;

private:
	// 'length' denotes the current (or respectively final) length of the shortest path from the starting field to this field found so far. 
	// The longest theoretical route ist 126*126 so a simple integer (2 bytes) will suffice.
	unsigned int length;
	unsigned int estimatedDistance;
	unsigned int score;

	// previous index, to determine the actual path
	unsigned int previousIndex;
};

inline void SearchField::updateLength(const unsigned int length) {
	this->length = length;
	score = length + estimatedDistance;
}

inline void SearchField::updatePreviousIndex(const unsigned int previousIndex) {
	this->previousIndex = previousIndex;
}

inline unsigned int SearchField::getScore() const {
	return score;
}

inline unsigned int SearchField::getLength() const {
	return length;
}

inline unsigned int SearchField::getPreviousIndex() const {
	return previousIndex;
}

#endif // _SEARCHFIELD_HPP