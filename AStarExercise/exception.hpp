#ifndef _EXCEPTION_HPP
#define _EXCEPTION_HPP

#include <stdexcept>
#include <string>

class AStarException : public std::runtime_error {
public:
	AStarException(const std::string& msg = "") : std::runtime_error(msg) {}
};

#endif // _EXCEPTION_HPP