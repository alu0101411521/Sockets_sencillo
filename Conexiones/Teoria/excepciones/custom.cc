#include <exception>
#include <iostream>
#include <string>


class MiException : public std::exception {
  public:
    MiException(const char* error) : mensaje(error) {}

    const char* what() const noexcept  override {
      return mensaje;
    }

    const char* mensaje;
};

int main() {
  try {

    throw MiException("Error en el programa");

  } catch (const MiException& e) {
    std::cerr << e.what() << std::endl;
  }
}