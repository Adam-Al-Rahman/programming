#!/bin/bash

# Default value for line_number
line_number=6

# Check if the -f, -l, and -d flags are provided
while getopts "f:l:u:" opt; do
	case ${opt} in
	f)
		filename="$OPTARG"
		;;
	l)
		line_number="$OPTARG"
		;;
	u)
		data="$OPTARG"
		;;
	\?)
		echo "Usage: cmd [-f filename] [-l line_number] [-u data]"
		exit 1
		;;
	esac
done

# Check if filename is provided
if [ -z "$filename" ]; then
	echo "Error: Filename is required."
	echo "Usage: cmd [-f filename] [-l line_number] [-u data]"
	exit 1
fi

# Create the file with .cc extension in the zero/ directory
output_file="zero/${filename}.cc"
cp zero/template.cc "$output_file"
echo "File '$output_file' created successfully."

# Insert data into the file if -u flag is provided
if [ ! -z "$data" ]; then
	sed -i "${line_number}i // Q: ${data}" "$output_file"
	echo "Data inserted successfully in $output_file at line $line_number."
fi
