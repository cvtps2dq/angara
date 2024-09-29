cmake_minimum_required(VERSION 3.29)
project(angara)

set(CMAKE_CXX_STANDARD 20)

add_executable(angara main.cpp
        angara.core/lexer/token.h
        angara.core/lexer/Lexer.cpp
        angara.core/lexer/Lexer.h
)
