#include <fstream>
#include <sstream>
#include <vector>
#include <stdio.h>
#include <string.h>

#include "exception.hpp"
#include "io.hpp"

void IO::checkStreamIsOpen(std::ifstream& stream, const std::string& functionName, const std::string& fileName)
{
	if(!stream.is_open())
	{
		std::ostringstream os;
		os << "ERROR (IO::" << functionName << "()): File " << fileName << " not found or cannot be opened => cancelling request.";
		throw AStarException(os.str());
	}
}

void IO::checkStreamForFailure(std::ifstream& stream, const std::string& functionName, const std::string& fileName)
{
	if(stream.bad())
	{
		std::stringstream os;
		os << "ERROR (IO::" << functionName << "()): Fatal error while accessing file " << fileName << " => cancelling request.";
		throw AStarException(os.str());
	}
	if(stream.fail())
	{
		std::stringstream os;
		os << "ERROR (IO::" << functionName << "()): Error while reading from file " << fileName << " => cancelling request.";
		stream.clear(stream.rdstate() & ~std::ios::failbit);
		throw AStarException(os.str());
	}
}

void IO::loadBinaryFile(std::vector<bool>& contents, const std::string& fileName, const char zero, const char one) {
	std::ifstream pFile(fileName.c_str());

	try {
		IO::checkStreamIsOpen(pFile, "loadFile", fileName);
		char line[1024];

		while(pFile.getline(line, sizeof line))
		{
			IO::checkStreamForFailure(pFile, "loadFile", fileName);
			unsigned int size = strlen(line);
			for(unsigned int i = 0; i < size; i++) {
				if(line[i] == zero) {
					contents.push_back(false);
				} else if(line[i] == one) {
					contents.push_back(true);
				} else {
					std::stringstream os;
					os << "ERROR (IO::loadBinaryFile()): Unknown character found in " << fileName << " => cancelling request.";
					throw AStarException(os.str());
				}
			}
		}
	} catch(std::exception& e) {
		pFile.close();
		throw e;
	}
	pFile.close();
}