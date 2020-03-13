#include "../include/Board.hpp"

/// @brief Main Function
/// @param argc Argument Counter
/// @param argv Argument Vector
int main(int argc, char* argv[])
{
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

  for (unsigned int i = 1; i <= turns; ++i)
  {
    std::cin.get();
    cellCulture.turn();
    std::cout << std::endl << "-------------------------------------------------------------------------" << std::endl;
  }

  return 0;
}