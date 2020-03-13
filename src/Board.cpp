#include "../include/Board.hpp"

/// @brief Board Default Constructor
Board::Board(unsigned int rowSize, unsigned int columnSize) :
rowSize_(rowSize),
columnSize_(columnSize)
{
  grid_ = new Cell**[rowSize_ + 2];
  
  for (unsigned int i = 0; i <= rowSize_ + 1; ++i)
    grid_[i] = new Cell*[columnSize + 2];

  for (unsigned int i = 0; i <= rowSize_ + 1; ++i)
    for (int j = 0; j <= columnSize + 1; ++j)
      grid_[i][j] = new Cell(i, j);
  
  // --------------------------------------------
  // DEAD EDGES
  // --------------------------------------------

  for (unsigned int i = 0; i <= rowSize_ + 1; ++i) 
    (*this)(i, 0).setState(false);

  for (unsigned int j = 0; j <= columnSize + 1; ++j) 
    (*this)(0, j).setState(false);
  
  for (unsigned int i = 0; i <= rowSize_ + 1; ++i) 
    (*this)(i, columnSize + 1).setState(false);

  for (unsigned int j = 0; j <= columnSize + 1; ++j)
    (*this)(rowSize_ + 1, j).setState(false);
}

/// @brief Board Destructor
Board::~Board()
{
  delete[] grid_;
}

/// @brief Row Size Getter
unsigned int Board::getRowSize() const
{
  return rowSize_;
}

/// @brief Column Size Getter
unsigned int Board::getColumSize() const
{
  return columnSize_;
}

/// @brief Execute board turns, updating grid's cells state
void Board::turn()
{
  countNeighbors();
  updateCells();
  std::cout << (*this);
}

/// @brief Analyzes each cell and counts the living ones around it
void Board::countNeighbors() const
{
  for (unsigned int i = 1; i <= getRowSize(); i++)
  {
    for (unsigned int j = 1; j <= getColumSize(); j++ )
    {
      unsigned int neighborsNumber_ = 0;
      for (unsigned int neighbor_i_ = i - 1; neighbor_i_ <= i + 1; ++neighbor_i_)
      {
        for (unsigned int neighbor_j_ = j - 1; neighbor_j_ <= j + 1; ++neighbor_j_)
        {
          if ((i != neighbor_i_) || (j != neighbor_j_))
          { 
            if ((*this)(neighbor_i_, neighbor_j_).getState() == true)
            {
              ++neighborsNumber_;
            }
          }
        }
      }
      (*this)(i, j).setNeighbords(neighborsNumber_);
    }
  }
}

/// @brief Update Cells state depending on the neighbords of each one
void Board::updateCells()
{
  for (unsigned int i = 1; i <= getRowSize(); i++)
  {
    for (unsigned int j = 1; j <= getColumSize(); j++ )
    {
      if((*this)(i, j).getNeighbords() == 3)
      { 
        (*this)(i, j).setState(true);
      }
      else if (((*this)(i, j).getNeighbords() == 2) && ((*this)(i, j).getState() == 1))
      {
        (*this)(i, j).setState(true);
      }
      else
      {
        (*this)(i, j).setState(false);
      }
    }
  }
}

/// @brief Parenthesis operator overload. Access a cell from grid
Cell& Board::operator()(unsigned int row, unsigned int column) const
{
  assert(row <= getRowSize() + 1 && column <= getColumSize() + 1);
  return *grid_[row][column];
}

/// @brief Stream Insertion overload. Shows Info about Board
std::ostream& operator<<(std::ostream& os, const Board& board)
{
  for (unsigned int i = 0; i <= board.getRowSize() + 1; i++)
  {
    for (unsigned int j = 0; j <= board.getColumSize() + 1; j++ )
    {
      os << board(i,j);
    }
    os << std::endl;
  }
  return os;
}