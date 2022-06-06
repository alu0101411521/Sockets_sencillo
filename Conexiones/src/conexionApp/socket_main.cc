#include <core/socket.h>
#include <signal.h>

#include <array>
#include <cstring>
#include <iostream>
#include <string>

#define PUERTO_SERVIDOR 8080
#define IP_SERVIDOR "127.0.0.4"

#define PUERTO_CLIENTE 3030
#define IP_CLIENTE "127.0.0.6"

int contador = 3;
bool terminal = false;

// SIGINT -> macro a utilizar

// Excepciones -> Errores de sockets
class SocketError : public std::exception {
 public:
  SocketError(std::string error) : msg(error) {}

  virtual const char* what() const noexcept { return msg.c_str(); }

 protected:
  std::string msg;
};

// Excepciones -> Errores de aplicacion
class AppError : public std::exception {
 public:
  AppError(std::string error) : msg(error) {}

  virtual const char* what() const noexcept { return msg.c_str(); }

 protected:
  std::string msg;
};

// metodos
void Cliente();
void Servidor();

// metodos signal
void TerminacionModificada(int signal);

int main() {
  signal(SIGINT, TerminacionModificada);
  int opcion = 1;
  std::cout << "Elige una opcion: (1) cliente | (2) servidor: " << std::endl;
  std::cin >> opcion;
  switch (opcion) {
    case 1:
      try {
        Cliente();
      } catch (AppError& e) {
        std::cout << e.what() << std::endl;
      }
      break;

    case 2:
      try {
        Servidor();
      } catch (AppError& e) {
        std::cout << e.what() << std::endl;
      }
      break;
  }

  return 0;
}

// metodos
void Cliente() {
  Socket socket_cl(IP_CLIENTE, PUERTO_CLIENTE);
  sockaddr_in direccion_servidor;
  direccion_servidor.sin_family = AF_INET;
  inet_aton(IP_SERVIDOR, &direccion_servidor.sin_addr);
  direccion_servidor.sin_port = htons(PUERTO_SERVIDOR);

  // Si el usuario envia un mensaje que sea EXIT se para el bucle
  while (!terminal) {
    std::array<char, BUFFER_SIZE> buffer;
    std::string message;
    std::cout << "Su mensaje :\t";
    std::getline(std::cin, message);

    strcpy(buffer.data(), message.c_str());
    if (socket_cl.SendTo(buffer, direccion_servidor) != 0) {
      std::cout << "Mensaje enviado!\n";
    }
  }
}

void Servidor() {
  Socket socket_sv(IP_SERVIDOR, PUERTO_SERVIDOR);
  sockaddr_in direccion_receptor;
  contador = 3;
  std::array<char, BUFFER_SIZE> buffer;
  strcpy(buffer.data(), "Hola");

  while (!terminal) {
    size_t bytes = socket_sv.RecvFrom(buffer, direccion_receptor);
    if (bytes != 0)
      std::cout << "Mensaje recibido: " << buffer.data() << std::endl;
    buffer.fill('\0');
  }
}

// Metodo para signal
void TerminacionModificada(int signal) {
  if (SIGINT == signal) {
    terminal = true;
    throw AppError("Fallo en aplicacion");
  }
}