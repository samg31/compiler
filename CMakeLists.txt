cmake_minimum_required(VERSION 2.8)
project(compiler)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1z")

#add_executable(expr_unit expr_ut.cpp expr.cpp eval.cpp check.cpp)

#add_executable(lexer_unit lexer_ut.cpp symbol.cpp token.cpp lexer.cpp)

#add_executable(parser_unit parser_ut.cpp parser.cpp lexer.cpp token.cpp
#						   expr.cpp eval.cpp check.cpp symbol.cpp
#						   translator.cpp )
						   
add_executable(var_unit var_ut.cpp decl.cpp stmt.cpp parser.cpp lexer.cpp 
						token.cpp expr.cpp eval.cpp check.cpp symbol.cpp
						translator.cpp)
