#pragma once

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <ctime>

/// @class Celula
/// @brief Representa una célula que puede estar viva o muerta.
class Celula {
  private:
    unsigned int i_, j_, estado_, numVecinas_;

  public:
    Celula(unsigned int = 0, unsigned int = 0);
    ~Celula();

    unsigned int getEstado() const;
    unsigned int setEstado(const unsigned int);
    unsigned int getNumVecinas() const;
    unsigned int setNumVecinas(const unsigned int);

    friend std::ostream& operator<<(std::ostream&, const Celula&);
};