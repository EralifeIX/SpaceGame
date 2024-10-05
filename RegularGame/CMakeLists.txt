cmake_minimum_required(VERSION 3.28)
project(RegularGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(RegularGame main.cpp
        src/Window.cpp
        include/Window.h
        src/Game.cpp
        include/Game.h
        src/Player.cpp
        include/Player.h
        include/GameObject.h
        src/ObjectConstructor.cpp
        include/ObjectConstructor.h
        src/Bullet.cpp
        include/Bullet.h
        src/Enemy.cpp
        include/Enemy.h
        src/Menu.cpp
        include/Menu.h

)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR /home/eralife/libraries/SFML-2.6.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(/home/eralife/libraries/SFML-2.6.1/include/SFML/)
target_link_libraries(RegularGame sfml-system sfml-window sfml-graphics sfml-audio)