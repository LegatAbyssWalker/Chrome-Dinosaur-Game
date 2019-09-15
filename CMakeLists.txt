cmake_minimum_required(VERSION 3.0.2)
project(Dinosaur)

find_package(SFML COMPONENTS graphics audio REQUIRED)

add_executable(Dinosaur ./State.cpp
./StateMachine.cpp
./Game.cpp
./PlayingState.cpp
./MainMenuState.cpp
./Button.cpp
./Main.cpp
./Text.cpp
./Player.cpp
./FPSCounter.cpp
./PlaySound.cpp
./Animation.cpp
./OStringText.cpp
./ToggleKey.cpp
./Bird.cpp
./Entity.cpp
./Cacti.cpp
./Cloud.cpp
./EnemyManager.cpp
./BackgroundManager.cpp)
target_link_libraries(Dinosaur sfml-graphics sfml-audio)

file(COPY res/ DESTINATION ${CMAKE_BINARY_DIR}/res)
