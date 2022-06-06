#include <iostream>

class Padre {
  public:
    virtual void Correr() {
      std::cout << "Corriendo normal!" << std::endl;
    }
};

class Hijo : public Padre {
  public:
    void Correr() override {
      std::cout << "Corriendo en silla de ruedas!" << std::endl;
    }
};

int main() {
  Padre* padre = new Padre();
  Padre* hijo = new Hijo();

  padre->Correr();
  hijo->Correr();

  Hijo hijo2;
  hijo2.Correr();
}