/// @file cell.cpp
/// @brief Cell Class Source Code 
#include "../include/cell.hpp"

///////////////////////////////////////////////////////
// CLASS MEMBER FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Default Constructor
/// @param row Cell Coordinate X
/// @param column Cell Coordinate Y
Cell::Cell(unsigned row, unsigned column) : row_(row), column_(column), neighborsNumber_(0) {
  if (rand() % 2 == 0)
    state_ = true;
  else
    state_ = false;
}

/// @brief Destructor
Cell::~Cell() {}

/// @brief State Getter
/// @return Cell State, true if alive, false if dead
bool Cell::getState(void) const { return state_; }

/// @brief State Setter
/// @param state Value of cell to change
/// @return Void
void Cell::setState(bool state) { state_ = state; }

/// @brief Neighbor counter Getter
/// @return Nº of Neighbors
unsigned Cell::getNeighbords(void) const { return neighborsNumber_; }

/// @brief Neighbor counter Setter
/// @param neighborsNumber Nº of Neighbors to change
/// @return Void
void Cell::setNeighbords(unsigned neighborsNumber) { neighborsNumber_ = neighborsNumber; }

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream which is going to write the cell
/// @param cell Cell to print
/// @return Information of Cell State
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState())
    return os << "X ";
  else
    return os << "- ";
}