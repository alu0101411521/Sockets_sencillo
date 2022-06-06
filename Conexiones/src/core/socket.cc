#include <core/socket.h>

// constructores
Socket::Socket(const std::string& ip, int port) {
  descriptor_ = socket(AF_INET, SOCK_DGRAM, 0);
  if (descriptor_ == -1) {
    std::cerr << "Error al crear el socket" << std::endl;
  }

  sockaddr_in estructura_socket;
  estructura_socket.sin_family = AF_INET;
  inet_aton(ip.c_str(),
            &estructura_socket.sin_addr);  // generamos la ip en formato teXto´
  estructura_socket.sin_port = htons(port);
  int resultado = bind(descriptor_, (sockaddr*)&estructura_socket,
                       sizeof(estructura_socket));

  // Comprobamos casos de fallos
  if (resultado == -1) {
    if (errno == EADDRINUSE) std::cerr << "Ip " << ip << " cogida" << std::endl;
    if (errno == EADDRNOTAVAIL)
      std::cerr << "Ip " << ip << " no es correcta" << std::endl;
    if (errno == EBADF)
      std::cerr << "Descriptor " << descriptor_ << " no valido" << std::endl;
  }
}

// destructores
Socket::~Socket() {
  int resultado{0};
  resultado = close(descriptor_);
  if (resultado == 0) {
    std::cout << "Succesfull" << std::endl;
  } else {
    std::cout << "Not succesfull" << std::endl;
  }
}

// metodos
ssize_t Socket::SendTo(std::array<char, BUFFER_SIZE> message,
                       sockaddr_in receptor) {
  ssize_t resultado;

  resultado = sendto(descriptor_, &message, sizeof(message), 0,
                     (sockaddr*)&receptor, sizeof(receptor));
  if (resultado < 0) {
    std::cout << "Message could not be send." << std::endl;
  }
  return resultado;
}

ssize_t Socket::RecvFrom(std::array<char, BUFFER_SIZE>& message,
                         sockaddr_in& transmiter) {
  socklen_t size = sizeof(transmiter);
  ssize_t resultado;
  resultado = recvfrom(descriptor_, &message, sizeof(message), MSG_DONTWAIT,
                       (sockaddr*)&transmiter, &size);
  if (resultado < 0){
    if (errno == EAGAIN) return 0;
    std::cerr << "Fallo al recibir el mensaje" << std::endl;
  }
  

  return resultado;
}
