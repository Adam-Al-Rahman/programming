/**
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 */

/**
If you don't explicitly flush the buffer in C++, the output will be buffered
until certain conditions are met. The buffered data is then automatically sent
to the output device. The conditions under which the buffer is flushed depend on
the implementation and can include factors like:

- The buffer becoming full: When the buffer reaches its capacity, it is
automatically flushed.

- A newline character ('\n') is encountered: Some implementations automatically
flush the buffer when a newline character is encountered in the output.

- The program exits: When a C++ program exits normally, the output streams are
usually flushed automatically.


Example 1:
int main() {
  std::cout << "Hello, world, within the sovereign bounds of my domain.";
  while (true) {}
}

The above example does not print the output because
i. The buffer is not full.
ii. No new line encounterd and no flush
iii. The program does not exit.

Example 2:
int main() {
  std::cout << "Hello, world, within the sovereign bounds of my domain."
            << std::flush;
  std::cout << "Hello world";
  while (true) {
  }
}

For example 2 the first line print but the second line wont because
- The first line got flushed
  - "Hello, world, within the sovereign bounds of my domain." >> send to buffer
>> buffer flush >> data send to console

- The second wont be printed same reason as Example 1


*/

#include <iostream>

int main() {
  std::cout << "Hello world,"
            << "\n"
            << std::flush;  // Manully flush the buffer

  // The next line won't be buffered, and the data will be
  // immediately sent to the output device
  std::cout << "within the sovereign bounds of my domain.";
}
