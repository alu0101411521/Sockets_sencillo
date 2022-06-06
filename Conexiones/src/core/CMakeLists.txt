add_library(core STATIC
  socket.cc
  "include/core/socket.h"
)

target_include_directories(core PUBLIC
  ${CMAKE_CURRENT_LIST_DIR}/include
)