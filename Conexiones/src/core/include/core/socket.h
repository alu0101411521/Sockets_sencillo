#pragma once

#include <arpa/inet.h>
#include <errno.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <exception>

#include <array>
#include <iostream>
#include <string>

// AF_INET
// SOCK_DGRAM
// SOCK_DGRAM


#define BUFFER_SIZE 40

class Socket {
 public:
  // constructores
  Socket(const std::string& ip, int port);

  // destructores
  ~Socket();

  // metodos
  ssize_t SendTo(std::array<char, BUFFER_SIZE> message, sockaddr_in receptor);
  ssize_t RecvFrom(std::array<char, BUFFER_SIZE>& message,
                   sockaddr_in& transmiter);

  // Sobrecarga de operadores

 private:
  std::string ip_;
  int port_;
  int descriptor_;
};