#include "../include/Tablero.hpp"

/// @brief Constructor del Tablero. Recibe sus dimensiones y crea la estructura de punteros.
/// @param m Filas del tablero.
/// @param n Columnas del tablero.
Tablero::Tablero(const unsigned int m, const unsigned int n) : m_(m), n_(n) {
  tabla = new Celula**[m_ + 2];
  
  for (int i = 0; i < m_ + 2; ++i)
    tabla[i] = new Celula*[n_ + 2];

  for (int i = 0; i < n_ + 2; ++i)
    for (int j = 0; j < m_ + 2; ++j)
      tabla[i][j] = new Celula[i, j];
  
  // Primera Columna
  for (int i = 0; i < m_ + 2; ++i) {
    (*this)(i, 0).setEstado(0);
  }

  // Primera Fila
  for (int j = 0; j < n_ + 2; ++j) {
    (*this)(0, j).setEstado(0);
  }

  // Última Columna
  for (int i = 0; i < m_ + 2; ++i) {
    (*this)(i, n_ + 1).setEstado(0);
  }

  // Última Fila
  for (int j = 0; j < n_ + 2; ++j) {
    (*this)(m_ + 1, j).setEstado(0);
  }
}

/// @brief Destructor del Tablero. Elimina la estructura de punteros
Tablero::~Tablero() {
  delete[] tabla;
}

/// @brief Getter de las filas
unsigned int Tablero::getFilas() const { return m_; }

/// @brief Getter de las columnas
unsigned int Tablero::getColumnas() const { return n_; }

/// @brief Ejecuta los turnos para comprobar el estado de las células
void Tablero::turno() {
  contarVecinas(*this);
  actualizarEstado();
  std::cout << (*this);
}

/// @brief Cuenta las vecinas de la célula indicada del tablero.
/// @param tablero Tablero a contar vecinas
void Tablero::contarVecinas(Tablero& tablero) const {
  for (unsigned int i = 1; i <= tablero.getFilas(); i++) {
    for (unsigned int j = 1; j <= tablero.getColumnas(); j++ ) {
      unsigned int NumVecinas = 0;
      for (unsigned int i_ = i - 1; i_ <= i + 1; ++i_) 
        for (unsigned int j_ = j - 1; j_ <= j + 1; ++j_) 
          if ((i != i_) || (j != j_)) 
            if (tablero(i_, j_).getEstado() == true) 
              ++NumVecinas;
      tablero(i, j).setNumVecinas(NumVecinas);
    }
  }
}

/// @brief Actualiza el estado de las células en un turno
void Tablero::actualizarEstado() {
  for (unsigned int i = 1; i <= getFilas(); i++)
    for (unsigned int j = 1; j <= getColumnas(); j++ )
      // Si tiene 3 vecinas, vive
      if((*this)(i, j).getNumVecinas() == 3) 
        (*this)(i, j).setEstado(1);
      // Si está viva y tiene 2 vecinas, vive
      else if (((*this)(i, j).getNumVecinas() == 2) && ((*this)(i, j).getEstado() == 1))
        (*this)(i, j).setEstado(1);
      // Cualquier otro caso, muere
      else
        (*this)(i, j).setEstado(0);
}

/// @brief Sobrecarga de los (). Devuelve la célula del tablero en la posición indicada
/// @param i Fila de la célula.
/// @param j Columna de la célula.
Celula& Tablero::operator()(const unsigned int i, unsigned const int j) const {
  assert(i <= m_ + 1 && j <= n_ + 1);
  // Devolvemos la posición dentro de la zona útil del tablero
  return *tabla[i][j];
}

/// @brief Sobrecarga operador de salida
/// @param os Flujo de Salida
/// @param tablero Tablero
std::ostream& operator<<(std::ostream& os, const Tablero& tablero) {
  for (unsigned int i = 0; i <= tablero.getFilas() + 1; i++) {
    for (unsigned int j = 0; j <= tablero.getColumnas() + 1; j++ ) {
      os << tablero(i,j).getEstado();
    }
    os << std::endl;
  }
  return os;
}