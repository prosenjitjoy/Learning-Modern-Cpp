cmake_minimum_required(VERSION 3.31)

project(Design-Patterns LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Design-Patterns main.cpp
    singleton.h
    factory.h
    adapter.h
    composit.h
    observer.h
    command.h
    Product.cpp
    builder.h
    observer_inventory.h
)

include(GNUInstallDirs)
install(TARGETS Design-Patterns
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
