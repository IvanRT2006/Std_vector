#!/bin/bash


cmake -S . -B build


if [ $? -ne 0 ]; then
  echo "CMake configuration failed."
  exit 1
fi


cmake --build build


if [ $? -ne 0 ]; then
  echo "CMake build failed."
  exit 1
fi


./build/test


if [ $? -eq 0 ]; then
  echo "Tests passed successfully!"
else
  echo "Tests failed."
  exit 1
fi
