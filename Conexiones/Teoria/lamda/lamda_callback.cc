#include <functional>
#include <iostream>
#include <vector>

void f() { std::cout << "hola mundo!" << std::endl; }

int f_int() { return 42; }

int f_parametros(int a) { return a; }

void Operar(std::vector<int>& vector, std::function<int(int)> funcion);

int main() {
  std::string nombre = "Endika";
  int multiplicador = 3;

  void (*funcion)() = f;
  std::function<void()> funcion2 = f;

 // 
  std::function<int()> funcion3 = f_int;

  std::function<int(int)> funcion4 = f_parametros;

  // retorno (parametros) {ambito}
  std::function<void(int)> funcion5 = [](int numero) {
    std::cout << "hola: " << numero << std::endl;
  };

  std::function<void()> funcion6 = [nombre]() {
    std::cout << "hola: " << nombre << std::endl;
  };

  std::function<int(int)> multiplicar = [multiplicador](int numero) -> int {
    return numero * multiplicador;
  };

 
  funcion();
  funcion2();
  std::cout << funcion3() << std::endl;
  std::cout << funcion4(10) << std::endl;
  funcion5(10);

  std::vector<int> vector = {1, 2, 3, 4, 5};
  // Operar(vector, multiplicar);

  // Tarea generar una callback que sea capaz de imprimir los elementos del
  // vector pasandosela a Operar

  std::function<int(int)> mostrar = [](int numero) {
    std::cout << numero << " ";
    return numero;
  };

  // Tarea general una callback que sea capaz de cambiar todos los valores 
  // al valor de la variable valor
  int valor = 0;
  std::function<int(int)> cambiar = [=](int numero){
    return valor;
  };



  Operar(vector, mostrar);
  Operar(vector, multiplicar);
  std::cout << std::endl;
  Operar(vector, mostrar);
  std::cout << std::endl;
  Operar(vector, cambiar);
  Operar(vector, mostrar);
  std::cout << std::endl;

  return 0;
}

void Operar(std::vector<int>& vector, std::function<int(int)> funcion) {
  for (size_t i = 0; i < vector.size(); i++) {
    vector[i] = funcion(vector[i]);
  }
}
