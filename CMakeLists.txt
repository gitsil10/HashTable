cmake_minimum_required(VERSION 3.24)
project(HashTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashTable main.cpp HashTable.h ChainingHashTable.h OpenAddressingHashTable.h LinearProbingHashTable.h QuadraticProbingHashTable.h DoubleHashingHashTable.h)
