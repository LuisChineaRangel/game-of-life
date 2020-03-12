#pragma once

#include "../include/Celula.hpp"

/// @class Tablero
/// @brief Representa un tablero de dimensiones m*n relleno de células vivas o muertas.
class Tablero {
  private:
    Celula*** tabla;
    unsigned int m_; //Filas
    unsigned int n_; //Columnas
    unsigned int turno_;
  public:
    Tablero(const unsigned int = 0, const unsigned int = 0);
    ~Tablero();

    unsigned int getFilas() const;
    unsigned int getColumnas() const;

    void turno();
    void contarVecinas(Tablero&) const;
    void actualizarEstado();

    Celula& operator()(const unsigned int, const unsigned int) const;
    friend std::ostream& operator<<(std::ostream&, const Tablero&);
};