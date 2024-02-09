cmake_minimum_required(VERSION 3.10)
project(NewYear)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)
find_library(SDL2_GFX_LIBRARIES NAMES SDL2_gfx)
find_library(SDL2_IMAGE_LIBRARIES NAMES SDL2_image)
find_library(SDL2_TTF_LIBRARIES NAMES SDL2_ttf)

add_subdirectory(Z_UI)

include_directories(${SDL2_INCLUDE_DIRS} ${PROJECT_SOURCE_DIR}/include/)

file(GLOB SOURCES_DIR "src/*.cpp")

add_executable(NewYear main.cpp ${SOURCES_DIR})

target_link_libraries(NewYear ${SDL2_GFX_LIBRARIES})
target_link_libraries(NewYear ${SDL2_LIBRARIES})
target_link_libraries(NewYear ${SDL2_IMAGE_LIBRARIES})
target_link_libraries(NewYear ${SDL2_TTF_LIBRARIES})
target_link_libraries(NewYear Z_UI)