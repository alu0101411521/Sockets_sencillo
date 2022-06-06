
#include <functional>
#include <iostream>
#include <string>
#include <vector>

class Persona {
 public:
  // contructores
  Persona(){};
  Persona(std::string nombre, int edad) : nombre(nombre), edad(edad) {}

  // atributos
  std::string nombre;
  int edad;
};

// Generar una funcion que ordene un vector de la clase Persona en
// funcion de la callback que se le pase. Se modifica el vector que se le pasa

std::vector<Persona>& Ordenar(std::vector<Persona>& persona,
                             std::function<bool(Persona&, Persona&)> callback);

void Mostrar(std::vector<Persona>& persona);

int main() {
  // Generar pruebas
  std::vector<Persona> t1 = {Persona("Juan", 20), Persona("Pedro", 30),
                             Persona("Ana", 40)};
  std::vector<Persona> t2 = {Persona("Juan", 20), Persona("Pedro", 30),
                             Persona("Ana", 40)};

  // Ordenar por nombre ascendente
  auto ordenar_nombre = [](Persona& persona, Persona& persona2) {
    return persona.nombre > persona2.nombre;
  };

  // Ordene por edad descendente
  auto ordenar_edad = [](Persona& persona, Persona& persona2) {
    return persona.edad < persona2.edad;
  };
  std::cout << "Ordenar nombre ascendentemente: ";
  auto nombre = Ordenar(t1, ordenar_nombre);
  Mostrar(nombre);
  std::cout << "=========" << std::endl;
  std::cout << "Ordenar edad descendentemente: ";
  auto edad = Ordenar(t2, ordenar_edad);
  Mostrar(edad);

  return 0;
}

std::vector<Persona>& Ordenar(std::vector<Persona>& persona,
                             std::function<bool(Persona&, Persona&)> callback) {
// [3, 2, 1, 0, 10]
  // [0, 3, 2, 1, 10]
  // [0, 1, 3, 2, 10]
  // [0, 1, 2, 3, 10]
  // [0, 1, 2, 3, 10]

  for (int i = 0; i < persona.size() - 1; ++i) {
    for (int j = i + 1; j < persona.size(); ++j) {
      if (callback(persona[i], persona[j])) {
        std::swap(persona[i], persona[j]);
      }
    }
  }

  return persona;
}

void Mostrar(std::vector<Persona>& persona) {
  for (auto e : persona) {
    std::cout << e.nombre << " | " << e.edad << " ";
  }
  std::cout << std::endl;
}