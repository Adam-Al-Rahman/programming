/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question:
 * @brief: Caesar Cipher Encryptor
 * @source:
 * @tags: ["topics/string", "algorithms/", "methods/"]
 * @status: unsolved
 */

#include <iostream>
#include <string>

std::string caesar_cipher_encryptor(const std::string &str, int key) {
  std::string encrypt_str;

  char base = 'a';
  for (const char &character : str) {
    encrypt_str += ((character - base + key) % 26 + base);
  }

  return encrypt_str;
}

int main() {
  std::string str = "xyz";
  int key = 2;

  std::cout << "Encrypt: " << caesar_cipher_encryptor(str, key);
}
