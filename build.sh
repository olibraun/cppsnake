#!/bin/bash

g++ -c ./src/*.cpp
g++ -c ./src/classes/*.cpp
g++ ./*.o -o ./bin/snake -lsfml-graphics -lsfml-window -lsfml-system
rm *.o