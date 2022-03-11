Start:Compile	Run

Compile:Bst	Node	Main
	g++	./lib/node.o	./lib/bst.o	./lib/main.o	-o	./bin/program.exe
Node:
	g++	-I	"./include"	-c	./src/Node.cpp	-o	./lib/node.o
Bst:
	g++	-I	"./include"	-c	./src/Bst.cpp	-o	./lib/bst.o
Main:
	g++	-I	"./include"	-c	./src/main.cpp	-o	./lib/main.o
Run:
	./bin/program