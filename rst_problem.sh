#!/bin/bash

lang="$1"

case "$lang" in
  rs)
    template_file="skeleton.rs"
    output_file="problem.rs"
    ;;
  cc)
    template_file="skeleton.cc"
    output_file="problem.cc"
    ;;
  py)
    template_file="skeleton.py"
    output_file="problem.py"
    ;;
  *)
    echo "Usage: $0 {rs|cc|py}"
    exit 1
    ;;
esac

# Inode-safe overwrite (Neovim-friendly)
cat "$template_file" > "$output_file"
