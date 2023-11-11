cmake_minimum_required(VERSION 3.5)

project(intermediate2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(intermediate2 main.cpp mylibrary.h mylibrary.cpp)

install(TARGETS intermediate2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
