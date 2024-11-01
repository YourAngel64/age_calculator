cmake_minimum_required(VERSION 3.5.0)
project(ageCalculator VERSION 0.1.0 LANGUAGES C CXX)
set (CMAKE_CXX_STANDARD 20)


add_executable(ageCalculator main.cpp app.cpp menu.cpp calculateAge.cpp button.cpp )


set(SFML_DIR ".\\vcpkg_installed\\x64-windows\\share\\sfml")
find_package(SFML COMPONENTS system window graphics CONFIG REQUIRED)
target_link_libraries(ageCalculator PRIVATE sfml-system sfml-network sfml-graphics sfml-window)

# If you want SFML to provide an implementation of main():
target_link_libraries(ageCalculator PRIVATE sfml-main)
