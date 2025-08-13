#!/bin/bash
template_file="template.cc"
output_file="problem.cc"

# Overwrite contents without replacing the file (inode-safe for Neovim)
cat "$template_file" > "$output_file"
