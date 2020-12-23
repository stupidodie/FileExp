cmake_minimum_required(VERSION 3.5)
SET(CMAKE_C_COMPILER /usr/local/Cellar/gcc/10.2.0/bin/gcc-10)
SET(CMAKE_CXX_COMPILER /usr/local/Cellar/gcc/10.2.0/bin/g++-10)

project(CompressApp LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)
SET(CMAKE_C_COMPILER /usr/local/Cellar/gcc/10.2.0/bin/gcc-10)
SET(CMAKE_CXX_COMPILER /usr/local/Cellar/gcc/10.2.0/bin/g++-10)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 COMPONENTS Widgets  REQUIRED)

#build a lib file of filepakc
add_library(filepack STATIC
    algorithm/Huffman.cpp
    algorithm/Pack.cpp

    )
target_link_directories(
        filepack
        PUBLIC
        algorithm
)



target_link_libraries(filepack PRIVATE  stdc++fs )

add_executable(CompressApp
    main.cpp
    mainwindow.cpp
    utils.cpp
    mainwindow.h
    mainwindow.ui
  )


target_link_libraries(CompressApp PRIVATE Qt5::Widgets filepack)
#link_libraries(CompressApp  stdc++fs )
