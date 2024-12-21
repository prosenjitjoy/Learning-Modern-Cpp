cmake_minimum_required(VERSION 3.31)

project(Threads LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 26)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Threads main.cpp
    threadpool.h threadpool.cpp
    safestack.h safestack.cpp
    lockfreestack.h lockfreestack.cpp
    lockfreequeue.h lockfreequeue.cpp
    lockfreehashtable.h lockfreehashtable.cpp
    lockfreeset.h lockfreeset.cpp)

include(GNUInstallDirs)
install(TARGETS Threads
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
