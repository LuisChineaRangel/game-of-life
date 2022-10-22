/// @file main.cpp
/// @brief Program Main File 
///
/// Controls all objects, options, errors and exceptions
/// in order to display all features of the program
#include <getopt.h>

#include "../include/board.hpp"

/** @name Main File Functions */
/// @{
void help();
void error();
/// @}

/// @brief Program Options
const option long_options[] = { {"help", 0, 0, 'h'}, {0, 0, 0, 0} };

/// @brief Main Function. Starts Conway's Game of Lige
/// @param argc Argument Counter
/// @param argv Argument Vector
int main(int argc, char* argv[]) {
  // Argument Handler
	int c, option_index;
  while ((c = getopt_long (argc, argv, "h", long_options, &option_index)) != -1) {
   	switch (c) {
  		case 'h':
  			help();
    		return 0;
      case '?':
        break;
      default:
        error();
        return 1;
    }
  }

  unsigned int rowSize, columnSize, turns;
  srand(time(NULL));

  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "WELCOME TO THE GAME OF LIFE!"                                              << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "You can create your own cell culture and see how it evolves through time!" << std::endl;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "Introduce Row Size for your culture: ";
  std::cin >> rowSize;
  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "Introduce Column Size for your culture: ";
  std::cin >> columnSize;
  std::cout << "-------------------------------------------------------------------------" << std::endl;

  Board cellCulture(rowSize, columnSize);
  std::cout << "This is your culture: " << std::endl;
  std::cout << std::endl << cellCulture << std::endl;

  std::cout << "-------------------------------------------------------------------------" << std::endl;
  std::cout << "Introduce the number of turns for the study: ";
  std::cin >> turns;
  std::cout << "-------------------------------------------------------------------------" << std::endl << std::endl;

  for (unsigned i = 1; i <= turns; ++i) {
    std::cin.get();
    cellCulture.turn();
    std::cout << std::endl << "-------------------------------------------------------------------------" << std::endl;
  }

  return 0;
}

/// @brief User Guide
///
/// Shows message explaining all Core Coin features
/// @return Void
void help(void) {
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	std::cout << "Program Execution: ./GameOfLife"                                                      << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

/// @brief Error message
///
/// For unknown commands, displays an error message showing information of all possible options
/// @return Void
void error(void) {
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "./GameOfLife [-h|--help]"            								  				                   << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
  std::cout << "[-h|--help]	Shows User's Guide"												                           << std::endl;
  std::cout << "-------------------------------------------------------------------------------" << std::endl;
}