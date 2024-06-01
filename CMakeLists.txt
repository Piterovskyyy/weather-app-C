cmake_minimum_required(VERSION 3.16)
project(untitled1 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "C:\\Qt\\6.7.1\\mingw_64") # Zmień na rzeczywistą ścieżkę do instalacji Qt

find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Dodanie makr do automatycznego uruchamiania MOC, RCC i UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Dodaj nagłówki do listy plików źródłowych
set(SOURCES
        SourceFiles/main.cpp
        SourceFiles/MainWindow.cpp
        SourceFiles/Search.cpp
)

set(HEADERS
        headerFiles/MainWindow.h
        headerFiles/Search.h
)

add_executable(untitled1 ${SOURCES} ${HEADERS})

target_link_libraries(untitled1 PRIVATE Qt6::Widgets)

# Dodaj ten fragment, aby uruchomić windeployqt po zbudowaniu projektu
add_custom_command(TARGET untitled1 POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/windeployqt.exe $<TARGET_FILE:untitled1>
)
