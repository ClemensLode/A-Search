#include <string>
#include <list>
#include <stdio.h>
#include <cstdlib>

#include "io.hpp"
#include "coordinate.hpp"
#include "astarsearch.hpp"
#include "resultmap.hpp"

#include "hr_time.hpp"

int main(int argc, char *argv[])
{
	const std::string parameterHelpString("Call 'astar <MapFileName> <StartX> <StartY> <EndX> <EndY> [showmap]'\
		 (the map file name, the start and end coordinates and an optional 'showmap' option for text output of the shortest path).");
	
	// ---- Parsing parameters ----
	if(argc < 6) {
		std::cout << std::endl << "ERROR: Additional parameters needed. " << parameterHelpString << std::endl;
		return EXIT_FAILURE;
	}

	std::vector<std::string> arguments;
	for(int i = 1; i < argc; ++i) {
		arguments.push_back(argv[i]);
	}

	// ---- Loading map file name ----
	std::string mapFileName = arguments[0];
	std::vector<bool> contents;
	IO::loadBinaryFile(contents, mapFileName, '.', '*');

	// ---- Loading start and end coordinates ----
	int sx = atoi(arguments[1].c_str());
	int sy = atoi(arguments[2].c_str());
	int ex = atoi(arguments[3].c_str());
	int ey = atoi(arguments[4].c_str());

	Coordinate startPosition(sx, sy);
	Coordinate endPosition(ex, ey);

	std::cout << std::endl << "Start position: " << startPosition.toString() << std::endl << std::endl;
	std::cout << "End position:   " << endPosition.toString() << std::endl << std::endl;
	
	if(sx < 0 || sx >= SMALL_MAP_WIDTH || sy < 0 || sy >= SMALL_MAP_HEIGHT) {
		std::cout << std::endl << "ERROR: Start position out of range, must be within [(0,0);(" << SMALL_MAP_WIDTH << "," << SMALL_MAP_HEIGHT << ")]." << std::endl;
		return EXIT_FAILURE;
	}

	if(ex < 0 || ex >= SMALL_MAP_WIDTH || ey < 0 || ey >= SMALL_MAP_HEIGHT) {
		std::cout << std::endl << "ERROR: End position out of range, must be within [(0,0);(" << SMALL_MAP_WIDTH << "," << SMALL_MAP_HEIGHT << ")]." << std::endl;
		return EXIT_FAILURE;
	}

	// ---- Loading optional parameter for text output ----
	bool doShowResultMap = false;
	if(argc == 7) {
		if(arguments[5] != "showmap") {
			std::cout << std::endl << "ERROR: Unknown parameter " << arguments[5] << ". " << parameterHelpString << std::endl;
			return EXIT_FAILURE;
		}
		doShowResultMap = true;
	}

	
	// ---- Start timer ----
#ifdef WIN32
	CStopWatch cStopWatch;
	cStopWatch.startTimer();
#endif
	AStarSearch searchModule(contents, endPosition);
	std::list<unsigned int> shortestPath;
	
	// ---- Actual calculation ----
	bool pathFound = searchModule.findShortestPath(startPosition, endPosition, shortestPath);
	

	std::cout << "Path found:     " << (pathFound?"true":"false") << std::endl << std::endl;

	// ---- End timer ----
#ifdef WIN32
	cStopWatch.stopTimer();
	std::cout << "Total duration: " << (cStopWatch.getElapsedTime()*1000.0) << " ms" << std::endl << std::endl;
#endif
	// ---- Printing result map ----
	if(doShowResultMap) {
		std::cout << searchModule.getResultMap(shortestPath).toString() << std::endl;
	}	

	return EXIT_SUCCESS;
}