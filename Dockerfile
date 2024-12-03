# Ubuntu base image
FROM ubuntu:22.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install essential packages
RUN apt-get update && apt-get install -y \
    build-essential \
    cmake \
    curl \
    git \
    ninja-build \
    pkg-config \
    tar \
    unzip \
    zip \
    && rm -rf /var/lib/apt/lists/*

# Create working directory
WORKDIR /app

# Copy project files
RUN mkdir src
COPY ./src /app/src

# Remove Python-specific lines from CMakeLists.txt
RUN sed -i '/find_package(pybind11 REQUIRED)/d' /app/src/CMakeLists.txt \
    && sed -i '/set(PYBIND11_FINDPYTHON ON)/d' /app/src/CMakeLists.txt \
    && sed -i '/find_package(Python COMPONENTS Interpreter Development REQUIRED)/d' /app/src/CMakeLists.txt \
    && sed -i '/pybind11_add_module(userReporter userReporter_pybind.cpp)/d' /app/src/CMakeLists.txt \
    && sed -i '/target_link_libraries(userReporter PRIVATE userReporter_lib)/d' /app/src/CMakeLists.txt

# Build
RUN cmake -B build -S src
RUN cmake --build build

CMD ["./build/main"]