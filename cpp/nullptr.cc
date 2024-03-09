/*
 * @copyright
 * Copyright 2024 Adam-Al-Rahman
 *
 * @question: nullptr
 * @brief: How nullptr workds
 * @source:
 * @tags: ["topics/nullptr", "algorithms/", "methods/"]
 * @status: solved
 */

/**
`nullptr` is a keyword introduced in C++11 to represent a null pointer. It
was introduced to address some of the issues and ambiguities associated with the
use of `NULL` in C++. `nullptr` is of type `std::nullptr_t`, which is a distinct
type specifically designed to hold the null pointer value.
Here's a brief overview of how `nullptr` works internally:

1. **Type Safety:**
   - `nullptr` has its own type, `std::nullptr_t`, which makes it distinct from
other pointer types.
   - This type safety helps prevent some common mistakes and ambiguities that
can occur when using `NULL`, which is often defined as `0` or `0L` and can be
implicitly converted to other pointer types.

2. **Avoiding Ambiguities:**
   - Prior to C++11, `NULL` was often defined as `0`, and this could lead to
ambiguities when overloaded functions or constructors were involved.
   - `nullptr` was introduced to eliminate such ambiguities, providing a clear
and unambiguous representation of a null pointer.

3. **Implicit Conversions:**
   - Unlike `NULL`, which might be implicitly converted to integral types,
`nullptr` is not implicitly convertible to integer types, avoiding potential
issues where a null pointer might be mistakenly used as an integer.

   ```cpp
   int* ptr = nullptr;  // OK
   // int* ptr2 = NULL;  // Error: Cannot convert NULL to int*
   ```

4. **Compatibility:**
   - `nullptr` is designed to be compatible with older code. It can be assigned
to pointers of any type, and it can be compared with other pointer types, making
it suitable for use in a wide range of scenarios.

   ```cpp
   int* ptr = nullptr;
   double* ptr2 = nullptr;
   bool isNull = (ptr == nullptr);
   ```

5. **Syntax Simplicity:**
   - The use of `nullptr` also simplifies syntax, providing a more explicit and
readable representation of a null pointer.

   ```cpp
   if (ptr == nullptr) {
       // Do something
   }
   ```

In summary, `nullptr` is designed to provide a safer and more explicit
representation of a null pointer in C++. Its introduction in C++11 aimed to
improve type safety, eliminate ambiguities, and enhance overall code clarity
when working with null pointers.
*/
