#!/bin/bash

lang="$1"

case "$lang" in
  rs)
    template_file="skeleton.rs"
    output_file="problem.rs"
    ;;
  py)
    template_file="skeleton.py"
    output_file="problem.py"
    ;;
  sql)
    template_file="skeleton.sql"
    output_file="problem.sql"
    ;;
  cc)
    template_file="skeleton.cc"
    output_file="problem.cc"
    ;;
  *)
    echo "Usage: $0 {rs|cc|py|sql}"
    exit 1
    ;;
esac

# Inode-safe overwrite (Neovim-friendly)
cat "$template_file" > "$output_file"
