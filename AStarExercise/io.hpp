#ifndef _IO_HPP
#define _IO_HPP

#include <string>
#include <iostream>
#include <vector>

/*
 * This class handles loading a file with binary contents with error checking.
 */

class IO
{
	public:
		static void loadBinaryFile(std::vector<bool>& contents, const std::string& fileName, const char zero, const char one);

	private:
		static void checkStreamForFailure(std::ifstream& stream, const std::string& functionName, const std::string& fileName);
		static void checkStreamIsOpen(std::ifstream& stream, const std::string& functionName, const std::string& fileName);

		IO();
		~IO();
};

#endif // _IO_HPP