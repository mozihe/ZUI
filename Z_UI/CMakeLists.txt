cmake_minimum_required(VERSION 3.27)

add_library(Z_UI Button.cpp Button.h Text.cpp Text.h)

target_include_directories(Z_UI PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})