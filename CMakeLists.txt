cmake_minimum_required(VERSION 3.16)
project(untitled1 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_PREFIX_PATH "D:\\Programy\\qt\\6.7.1\\mingw_64") # Zmień na rzeczywistą ścieżkę do instalacji Qt

find_package(Qt6 REQUIRED COMPONENTS Widgets Network) # Dodaj Network do wymaganych komponentów

# Dodanie makr do automatycznego uruchamiania MOC, RCC i UIC
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

# Dodaj nagłówki do listy plików źródłowych
set(SOURCES
        SourceFiles/main.cpp
        SourceFiles/MainWindow.cpp
        SourceFiles/Search.cpp
        SourceFiles/list.cpp
        SourceFiles/mainpanel.cpp
        SourceFiles/weatherbar.cpp
        SourceFiles/details.cpp
        SourceFiles/date.cpp
        SourceFiles/WeaterData.cpp
)

set(HEADERS
        headerFiles/MainWindow.h
        headerFiles/Search.h
        headerFiles/list.h
        headerFiles/mainpanel.h
        headerFiles/weatherbar.h
        headerFiles/details.h
        headerFiles/date.h
        SourceFiles/WeaterData.cpp
        headerFiles/WeaterData.h
        headerFiles/WeaterData.h
        headerFiles/firebase.h
        SourceFiles/firebase.cpp
)

add_executable(untitled1 ${SOURCES} ${HEADERS})

target_link_libraries(untitled1 PRIVATE Qt6::Widgets Qt6::Network) # Dodaj również Qt6::Network

# Dodaj ten fragment, aby uruchomić windeployqt po zbudowaniu projektu
add_custom_command(TARGET untitled1 POST_BUILD
        COMMAND ${Qt6_DIR}/../../../bin/windeployqt.exe $<TARGET_FILE:untitled1>
)
