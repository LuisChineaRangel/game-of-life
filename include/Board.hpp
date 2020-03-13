#ifndef BOARD_HPP
#define BOARD_HPP

#include "../include/Cell.hpp"

/// @class Board
/// @brief Represents a board in the game of life, to study the state of cells.\n
/// Boards have dead edges to to ensure the isolation of cells.
class Board {
  private:
    Cell*** grid_;
    unsigned int rowSize_, columnSize_;

  public:
    Board(unsigned int = 0, unsigned int = 0);
    ~Board();

    unsigned int getRowSize() const;
    unsigned int getColumSize() const;

    void turn();
    void countNeighbors() const;
    void updateCells();

    Cell& operator()(unsigned int, unsigned int) const;
    friend std::ostream& operator<<(std::ostream&, const Board&);
};

#endif