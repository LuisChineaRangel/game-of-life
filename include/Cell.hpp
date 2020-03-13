#ifndef CELL_HPP
#define CELL_HPP

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

/// @class Cell
/// @brief Represents a board cell, surrounded by others, whose state can be alive or dead.
class Cell {
  private:
    unsigned int row_, column_;
    unsigned int neighborsNumber_;
    bool state_;

  public:
    Cell(unsigned int = 0, unsigned int = 0);
    ~Cell();

    bool getState() const;
    bool setState(bool);
    unsigned int getNeighbords() const;
    unsigned int setNeighbords(unsigned int);

    friend std::ostream& operator<<(std::ostream&, const Cell&);
};

#endif 