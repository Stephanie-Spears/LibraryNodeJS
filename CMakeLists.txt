cmake_minimum_required(VERSION 3.10)
project(LibraryNodeJS)

set(CMAKE_CXX_STANDARD 11)

add_executable(LibraryNodeJS main.cpp Song.cpp Song.h InputTools.cpp InputTools.h UserInterface.cpp UserInterface.h SongList.cpp SongList.h)