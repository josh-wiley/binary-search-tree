# Variables.
CC = g++
STD = -std=c++14
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)
OFLAGS = -o PA06


# Executable.
PA06: PA06.o data_generator.o BinarySearchTree.o
	$(CC) $(STD) $(LFLAGS) PA06.o data_generator.o BinarySearchTree.o $(OFLAGS)


# PA06.
PA06.o: src/PA06.cpp src/utils/data_generator.h
	$(CC) $(STD) $(CFLAGS) src/PA06.cpp


# Data generator.
data_generator.o: src/utils/data_generator.h src/utils/data_generator.cpp
	$(CC) $(STD) $(CFLAGS) src/utils/data_generator.cpp


# Binary search tree.
BinarySearchTree.o: src/BinarySearchTree/BinarySearchTree.h src/BinarySearchTree/BinarySearchTree.cpp
	$(CC) $(STD) $(CFLAGS) src/BinarySearchTree/BinarySearchTree.cpp


# Clean.
clean:
	rm -rf *.o PA06
