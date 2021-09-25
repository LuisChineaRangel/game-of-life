/// @file cell.hpp
/// @brief Cell Header
#pragma once

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

/// @class Cell
/// @brief Represents a board cell, surrounded by others, whose state can be alive or dead.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Cell eukaryotic;
/// eukaryotic.setNeighbords(10);
/// eukaryotic.setState(false);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Cell {
  private:
    // Cell Coordinates
    unsigned row_, column_;
    // Nº of Cells surrounding
    unsigned neighborsNumber_;
    // Cell State (dead/alive)
    bool state_;

  public:
    /** @name Constructors and Destructor */
    /// @{
    Cell(unsigned = 0, unsigned = 0);
    ~Cell();
    /// @}

    /** @name Getters and Setters */
    /// @{
    bool getState(void) const;
    void setState(bool);
    unsigned getNeighbords(void) const;
    void setNeighbords(unsigned);
    /// @}
};

std::ostream& operator<<(std::ostream&, const Cell&);