# Use Ubuntu 24.04 
FROM ubuntu:24.04

# Prevent interactive prompts during package installation
ENV DEBIAN_FRONTEND=noninteractive

# Install C++ compiler, Make, GDB, and Valgrind 
RUN apt-get update && apt-get install -y \
    build-essential \
    gdb \
    valgrind \
    && rm -rf /var/lib/apt/lists/*

# Set the working directory inside the container
WORKDIR /usr/src/app

# Copy all project files (including the Makefile and C++ source files) into the container
COPY . .


RUN make

# Define the default command to run your executable 
CMD ["./CampusGuard"]