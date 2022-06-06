#include <exception>
#include <iostream>
#include <vector>
#include <string>

class ExceptionMessage : public std::exception { 
  public:
    ExceptionMessage(std::string msg) : msg(msg) {}
    
    virtual const char* what() const throw() {
      return msg.c_str();
    }
  
  protected:
    std::string msg;
};

class IndexError : public ExceptionMessage {
  public:
  IndexError(std::string error) : ExceptionMessage(error) {}
};

class MathError : public ExceptionMessage {
  public:
  MathError(std::string error) : ExceptionMessage(error) {}
};

// Funcion que acceda a un indice de un vector pasado por parametros.
// En caso de fallar lanzara una excepcion invalid argument
int Acceder(const std::vector<int>& prueba, int num);

// Funcion dividir. En caso de que el divisor sea 0,
// lanzara una excepcion de runtime_error
int Dividir(int num1, int num2);

int main() {
  // Ejecutar las funciones de forma segura, en caso de fallar reintentar
  // la funcion con otros parametros para que no falle el programa
  std::vector<int> prueba = {1, 2, 3, 4};
  int num1, num2, pos;
  bool booleano = false;

  while (!booleano) {
    try {
      std::cout << "Introduzca num1, num2, pos: ";
      std::cin >> num1 >> num2 >> pos;
      int resultado = Acceder(prueba, pos);
      int resultado2 = Dividir(num1, num2);
      booleano = true;
    } catch (ExceptionMessage& e) {
      std::cout << e.what() << std::endl;
    }
  }

  return 0;
}

int Acceder(const std::vector<int>& prueba, int num) {
  int resultado{0};
  if (prueba.size() < num) throw IndexError("Indice fuera de rango");
  resultado = prueba[num];
  return resultado;
}

int Dividir(int num1, int num2) {
  int resultado{0};
  if (num2 == 0) throw MathError("Divisor inválido");
  resultado = num1 / num2;
  return resultado;
}