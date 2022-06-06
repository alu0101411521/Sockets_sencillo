#include <signal.h>
#include <iostream>

bool terminal = false;

void TerminacionModificada(int signal){
  if (SIGINT == signal) {
    terminal = true;
    std::cout << "  Terminacion Crt + C capturada " << std::endl;
  }
}

class Ejemplo {
  public:
    ~Ejemplo() {
      std::cout << "  Destructor de Ejemplo" << std::endl;
    }
};


int main(){
  Ejemplo ejemplo;
  signal(SIGINT, TerminacionModificada);
  while(!terminal){
    
  }

  std::cout << "Terminando programa de forma ordenada" << std::endl;
  return 0;
}
