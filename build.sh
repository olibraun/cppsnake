#!/bin/bash

SECONDS=0

echo "Starting to build Snake."

# Compile primary folder in one process
(
  g++ -O2 -c ./src/*.cpp
)&

# Compile subfolders in parallel processes
(
  g++ -O2 -c ./src/*/*.cpp
)&

# Wait for all compiles to finish
wait

# Link
g++ -O2 ./*.o -o ./bin/snake -lsfml-graphics -lsfml-window -lsfml-system

# Remove object files
rm *.o

echo "Done, time elapsed: $SECONDS seconds."