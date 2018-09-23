#!/bin/bash

g++ -O2 -c ./src/*.cpp
g++ -O2 -c ./src/*/*.cpp
g++ -O2 ./*.o -o ./bin/snake -lsfml-graphics -lsfml-window -lsfml-system
rm *.o