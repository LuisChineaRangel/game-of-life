#include "../include/Celula.hpp"

/// @brief Constructor de la célula, recibe su posición y su estado
/// @param i Fila de la célula
/// @param j Columna de la célula
Celula::Celula(unsigned int i, unsigned int j) : i_(i), j_(j), estado_(rand() % 2), numVecinas_(0) {}

/// @brief Destructor de la célula
Celula::~Celula() {}

/// @brief Getter del estado
unsigned int Celula::getEstado() const { return estado_; }

/// @brief Setter del estado
unsigned int Celula::setEstado(const unsigned int estado) {
  estado_ = estado;
  return estado_;
}

/// @brief Getter de las vecinas
unsigned int Celula::getNumVecinas() const { return numVecinas_; }

/// @brief Setter de las vecinas
unsigned int Celula::setNumVecinas(const unsigned int vecinas) {
  numVecinas_ = vecinas;
  return numVecinas_;
}

/// @brief Sobrecarga del operador de salida. Muestra información de la célula
/// @param os Flujo de Salida
/// @param celula Célula a imprimir
std::ostream& operator<<(std::ostream& os, const Celula& celula) {
  return os << celula.getEstado();
}