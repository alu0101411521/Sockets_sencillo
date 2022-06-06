#include <functional>
#include <iostream>
#include <vector>

// {1 2 3 4 5 6 7} -> fun(numero) numero < 4;
// {1 2 3} -> vector resultante de filtrar

// Realizar la funcion de filtrar
std::vector<int> Filtrar(const std::vector<int>& v,
                         std::function<bool(int)> callback) {
  std::vector<int> resultado;
  for (int i = 0; i < v.size(); ++i) {
    if (callback(v[i])) {
      resultado.push_back(v[i]);
    }
  }

  return resultado;
}

void Mostrar(std::vector<int>& v) {
  for (auto e : v) {
    std::cout << e << " ";
  }
  std::cout << std::endl;
}

// Probar la funcion filtrar con varios filtros
int main() {
  std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};
  auto filtrar_par = [](int numero) { return numero % 2 == 0; };
  auto filtrar_impar = [](int numero) { return numero % 2 != 0; };
  auto filtrar_menor_4 = [](int numero) { return numero < 4; };

  std::cout << "Filtrar par: ";
  auto par = Filtrar(v, filtrar_par);
  Mostrar(par);

  std::cout << "Filtrar impar: ";
  auto impar = Filtrar(v, filtrar_impar);
  Mostrar(impar);

  std::cout << "Filtrar menor a 4: ";
  auto menor_4 = Filtrar(v, filtrar_menor_4);
  Mostrar(menor_4);

  return 0;
}
