cmake_minimum_required(VERSION 3.18)

project(matrix
	VERSION 1.0.0
	DESCRIPTION "C++ library with class Matrix"
	LANGUAGES CXX)

file(GLOB
	source "*.cpp")

add_library(${PROJECT_NAME}_lib ${source})
