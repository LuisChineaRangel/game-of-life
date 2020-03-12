#include "../include/Tablero.hpp"

/// @brief Función main.
/// @param argc Número de Argumentos
/// @param argv Vector de Argumentos
int main(int argc, char* argv[]) {
  srand(time(NULL));
  Tablero planta(5, 5);
  std::cout << planta << std::endl;

  std::cin.get();
  planta.turno();
  std::cout << std::endl;

  std::cin.get();
  planta.turno();
  std::cout << std::endl;

  return 0;
}