cmake_minimum_required(VERSION 3.5)

project(intermediate3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(myfile.txt
    ${CMAKE_CURRENT_BINARY_DIR} COPYONLY
)

add_executable(intermediate3 main.cpp)

install(TARGETS intermediate3
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
