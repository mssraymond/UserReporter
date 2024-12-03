#!/bin/bash

if [ "$1" = "docker" ]; then
    clear
    echo $1
    docker build -t user-reporter .
    docker run --rm -it --name user-reporter user-reporter
elif [ "$1" = "python" ]; then
    clear
    echo $1
    rm -rf build
    cmake -S src -B build && cmake --build build
    black .
    python main.py
else
    clear
    rm -rf build
    cmake -S src -B build
    cmake --build build && ./build/main
fi