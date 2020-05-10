cmake_minimum_required(VERSION 3.15)
project(snake_sfml)

set(CMAKE_CXX_STANDARD 14)

file (GLOB src_dir src/*.c++)
file (GLOB src_classes classes/*.cpp)
link_libraries(sfml-graphics)
link_libraries(sfml-audio)
link_libraries(sfml-system)
link_libraries(sfml-window)
add_executable(snake_sfml ${src_classes} ${src_dir} include/all_includes.h
        classes/game.hpp
        classes/snake.hpp classes/button.hpp classes/textbox.cpp classes/textbox.hpp)