#pragma once

#include "cell.hpp"

/// @class Board
/// @brief Represents a board in the game of life, to study the state of cells.\n
/// Boards have dead edges to ensure the isolation of cells.
class Board {
  private:
    Cell*** grid_;
    unsigned rowSize_, columnSize_;

  public:

    /** @name Constructors and Destructor */
    /// @{
    Board(unsigned = 0, unsigned = 0);
    ~Board();
    /// @}

    /** @name Getters */
    /// @{
    unsigned getRowSize(void) const;
    unsigned getColumSize(void) const;
    /// @}

    /** @name Auxiliar Public Functions */
    /// @{
    void turn(void);
    void countNeighbors(void) const;
    void updateCells(void);
    /// @}

    /** @name Operator Overloads */
    /// @{
    Cell& operator()(unsigned int, unsigned int) const;
    /// @}
};

std::ostream& operator<<(std::ostream&, const Board&);