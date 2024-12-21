cmake_minimum_required(VERSION 3.31)

project(Memory LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Memory main.cpp
    product.h product.cpp)

include(GNUInstallDirs)
install(TARGETS Memory
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
