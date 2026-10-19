cmake_minimum_required(VERSION 3.16)
project(MyIDE VERSION 1.0 LANGUAGES CXX)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)
set(SOURCES 
	src/main.cpp
	src/core/File.cpp
	src/window/MainWindow.cpp
	src/window/AboutWindow.cpp
)
set(UIS src/window/AboutWindow.ui)
add_executable(MyIDE ${SOURCES} ${UIS})

target_include_directories(MyIDE PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src/window
)
target_link_libraries(MyIDE PRIVATE Qt6::Widgets)
