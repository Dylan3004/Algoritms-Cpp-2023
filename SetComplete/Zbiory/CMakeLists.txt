cmake_minimum_required(VERSION 3.21)
project(Zbiory)

set(CMAKE_CXX_STANDARD 20)

add_executable(Zbiory main.cpp Container.cpp Container.h Set.cpp Set.h SetAsArray.cpp SetAsArray.h Visitor.cpp Visitor.h AddingVisitor.cpp AddingVisitor.h EvenVisitor.cpp EvenVisitor.h Iterator.cpp Iterator.h)
