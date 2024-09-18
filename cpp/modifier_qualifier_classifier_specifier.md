# C++ Language Properties

## 1. **Modifier**

A modifier changes the properties or behavior of a variable, function, or type in some way. In C++, the most common examples are storage class specifiers or other keywords that modify access or storage behavior.

- **Storage class modifiers**:

  - `static`: Preserves the value of a variable between function calls or makes a class member variable shared across all instances.
  - `extern`: Specifies that a variable is defined elsewhere.
  - `mutable`: Allows a member of a `const` object to be modified.

- **Access modifiers** (for classes):
  - `public`, `private`, `protected`: Define access control for class members.

## 2. **Classifier**

This term is less common in C++ terminology, but it generally refers to elements that classify or categorize types, such as type specifiers or type modifiers. C++ uses type classifiers to define or refine types.

- **Type classifiers**:
  - `class`, `struct`, `union`: Define composite types.
  - `enum`: Defines an enumeration type.
  - `typename`: Used to declare a dependent type within templates.

## 3. **Qualifier**

Qualifiers in C++ are keywords that restrict or qualify how a variable or object can be used. They are typically used to control whether an object can be modified or where it is stored.

- **Type qualifiers**:

  - `const`: Indicates that a variable cannot be modified after initialization.
  - `volatile`: Tells the compiler not to optimize a variable, as its value may change unexpectedly (e.g., from hardware).
  - `restrict` (C++11): A pointer qualifier that hints that the pointer is the only reference to the memory it points to, allowing the compiler to optimize code better.
  - `std::atomic` It is used to declare variables that are accessed atomically, meaning that operations on them are indivisible or cannot be interrupted.

- **Function qualifiers**:
  - `const` (for member functions): Ensures that the function does not modify the object it is called on.
  - `noexcept`: Specifies that a function does not throw exceptions.

## 4. **Specifier**

Specifiers in C++ are used to declare types or modify properties of variables, functions, or types. Some of these overlap with modifiers or qualifiers, but the key difference is that specifiers are often part of the type system and define the nature of the type or function.

- **Type specifiers**:

  - `int`, `float`, `double`, `char`, `void`: These are fundamental type specifiers.
  - `signed`, `unsigned`: Modify the signedness of integer types.
  - `short`, `long`: Modify the size of integer types.

- **Function specifiers**:
  - `inline`: Suggests that the compiler should expand the function at the point of call, rather than generating a call to it.
  - `virtual`: Specifies that a function can be overridden in derived classes.
  - `explicit`: Used to prevent implicit type conversions, typically for constructors or conversion operators.
  - `constexpr`: Indicates that a function or variable can be evaluated at compile time.
  - `friend`: Declares a function or another class as having access to private and protected members of the class.
  - `static_assert`: Asserts conditions at compile time.

---

## Summary of Related Keywords

- **Modifiers**: `static`, `extern`, `mutable`, `public`, `private`, `protected`
- **Classifiers**: `class`, `struct`, `union`, `enum`, `typename`
- **Qualifiers**: `const`, `volatile`, `restrict`, `const` (for member functions), `noexcept`
- **Specifiers**: `int`, `float`, `unsigned`, `inline`, `virtual`, `explicit`, `constexpr`, `signed`, `friend`, `static_assert`

Each of these categories influences how C++ objects, functions, and types are declared, defined, and used, contributing to flexibility in design and optimization.
