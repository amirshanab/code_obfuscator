cmake_minimum_required(VERSION 3.22)
project(ex4)

set(CMAKE_CXX_STANDARD 14)

add_executable(ex4 main.cpp CommentObfuscator.cpp CommentObfuscator.h LineObfuscator.cpp LineObfuscator.h Obfuscator.cpp Obfuscator.h VarObfuscator.cpp VarObfuscator.h)
