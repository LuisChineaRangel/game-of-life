#include "../include/Cell.hpp"

/// @brief Cell Default Constructor
Cell::Cell(unsigned int row, unsigned int column) :
row_(row),
column_(column),
neighborsNumber_(0)
{
  if (rand() % 2 == 0)
    state_ = true;
  else
    state_ = false;
}

/// @brief Cell Destructor
Cell::~Cell() {}

/// @brief State Getter
bool Cell::getState() const
{
  return state_;
}

/// @brief State Setter
bool Cell::setState(bool state)
{
  state_ = state;
  return state_;
}

/// @brief Neighbor counter Getter
unsigned int Cell::getNeighbords() const
{
  return neighborsNumber_;
}

/// @brief Neighbor counter Setter
unsigned int Cell::setNeighbords(unsigned int neighborsNumber) {
  neighborsNumber_ = neighborsNumber;
  return neighborsNumber_;
}

/// @brief Stream Insertion overload. Shows Info about Cell
std::ostream& operator<<(std::ostream& os, const Cell& cell) {
  if (cell.getState())
    return os << "X ";
  else
    return os << "- ";
}