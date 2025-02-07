cmake_minimum_required(VERSION 3.28)

project(3D-Renderer)

set(CMAKE_CXX_STANDARD 17)

include_directories("eigen")

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.0
    GIT_SHALLOW ON
    EXCLUDE_FROM_ALL
    SYSTEM)
FetchContent_MakeAvailable(SFML)

add_executable(3D-Renderer main.cpp application.cpp except.cpp world.cpp renderer.cpp object.cpp screen.cpp)

target_link_libraries(3D-Renderer PRIVATE SFML::Graphics)
