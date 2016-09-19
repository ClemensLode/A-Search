#ifndef _FIELD_HPP
#define _FIELD_HPP

/*
 * This class holds the data of a single cell of the map. 
 */

#include "enums/fieldtype.hpp"

class Field
{
public:
	Field():type(EMPTY_FIELD) {}
	Field(const eFieldType fieldType):type(fieldType) {}
	~Field() {}

	eFieldType getType() const;
	void setType(const eFieldType type);
private:
	eFieldType type;
};

inline eFieldType Field::getType() const {
	return type;
}

inline void Field::setType(const eFieldType type) {
	this->type = type;
}

#endif // _FIELD_HPP