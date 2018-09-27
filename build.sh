#!/bin/bash

SECONDS=0

echo "Starting to build Snake."

g++ -O2 -c ./src/*.cpp
g++ -O2 -c ./src/*/*.cpp
g++ -O2 ./*.o -o ./bin/snake -lsfml-graphics -lsfml-window -lsfml-system
rm *.o

echo "Done, time elapsed: $SECONDS seconds."