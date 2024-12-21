cmake_minimum_required(VERSION 3.31)

project(Classes LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Classes main.cpp rectangle.h
    Product.h
    Product.cpp
    Warehouse.h
    money.h
    inheritance.h
    polymorphism.h
    compositepattern.h
    decoratorpattern.h)

include(GNUInstallDirs)
install(TARGETS Classes
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
