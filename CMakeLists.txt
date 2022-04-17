cmake_minimum_required(VERSION 3.23.1)
project (2048)

add_executable(2048 src/main.cpp src/Game.cpp)

SET(SFML_INCLUDE_PATH "/usr/local/include/SFML")
SET(SFML_SYSTEM_LIBS "/usr/local/lib/libsfml-system.so.3.0")
SET(SFML_WINDOW_LIBS "/usr/local/lib/libsfml-window.so.3.0")
SET(SFML_GRAPHICS_LIBS "/usr/local/lib/libsfml-graphics.so.3.0")

target_include_directories(2048 PUBLIC ${SFML_INCLUDE_PATH})
target_link_libraries(2048 ${SFML_SYSTEM_LIBS})
target_link_libraries(2048 ${SFML_WINDOW_LIBS})
target_link_libraries(2048 ${SFML_GRAPHICS_LIBS})