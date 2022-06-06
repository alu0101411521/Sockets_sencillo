cmake_minimum_required(VERSION 3.1)

project(sockets)

add_subdirectory(core)

add_executable(sockets conexionApp/socket_main.cc)

target_link_libraries(sockets core)
