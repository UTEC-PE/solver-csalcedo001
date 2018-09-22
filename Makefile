all: main

main: main.cpp btree.h node.h functions.h
	g++ -std=c++11 main.cpp -o main
