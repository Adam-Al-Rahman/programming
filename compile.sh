#!/bin/bash

# Name of the source file (default: main.cpp)
SOURCE_FILE="${1:-main.cpp}"

# Name of the output executable (default: a.out)
OUTPUT_FILE="${2:-a.out}"

# Compile with clang++ and define ONLINE_JUDGE
clang++ -std=c++20 -D ONLINE_JUDGE "$SOURCE_FILE" -o "$OUTPUT_FILE"

# Check if compilation was successful
if [ $? -eq 0 ]; then
	echo -e "Compilation \033[0;32msuccessful\033[0m."
	echo -e "Executing: \033[0;32m$OUTPUT_FILE\033[0m"
	echo "" # Adds a new line
	./$OUTPUT_FILE
else
	echo -e "Compilation \033[0;31mfailed\033[0m."
fi
