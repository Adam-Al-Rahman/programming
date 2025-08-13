#!/bin/bash

# Name of the source file (default: problem.cc)
SOURCE_FILE="${1:-problem.cc}"

# Name of the output executable (default: a.out)
OUTPUT_FILE="${2:-a.out}"

# Compile with clang++ and define ONLINE_JUDGE
clang++ -std=c++20 "$SOURCE_FILE" -o "$OUTPUT_FILE"

# Check if compilation was successful
if [ $? -eq 0 ]; then
	echo -e "Compilation successful"
	echo -e "Executing: $OUTPUT_FILE"
	echo "" # Adds a new line
	./$OUTPUT_FILE
else
	echo -e "Compilation: Failed"
fi
