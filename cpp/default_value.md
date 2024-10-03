# Default Values

The default value of variables depends on whether they are declared at global scope or local scope. Here’s a breakdown of the default values for different types at both scopes

### 1. **Global Scope**

Variables declared at global scope (outside any function) are automatically **zero-initialized** or **default-initialized**. This means:

- **Primitive types** like `int`, `float`, `double`, `bool`, and pointers are **zero-initialized**.
- **Class types** like `std::string` are **default-initialized** using their constructor.

### 2. **Local Scope (Function Scope)**

Variables declared inside a function (local scope) are **not initialized by default** unless explicitly initialized. They have an **indeterminate value**, which can lead to undefined behavior if used without being initialized.

### Default Values by Type

| Type              | Global Default Value            | Local Default Value                                                    |
| ----------------- | ------------------------------- | ---------------------------------------------------------------------- |
| **`int`**         | `0`                             | **Indeterminate**                                                      |
| **`float`**       | `0.0f`                          | **Indeterminate**                                                      |
| **`double`**      | `0.0`                           | **Indeterminate**                                                      |
| **`bool`**        | `false` (`0`)                   | **Indeterminate**                                                      |
| **`char`**        | `'\0'` (null character, `0`)    | **Indeterminate**                                                      |
| **`pointer`**     | `nullptr`                       | **Indeterminate**                                                      |
| **`std::string`** | Empty string (`""`)             | Empty string (`""`)                                                    |
| **Arrays**        | Each element initialized to `0` | **Indeterminate**                                                      |
| **Structs**       | Each member initialized to `0`  | **Indeterminate**                                                      |
| **Classes**       | Default constructor is called   | Default constructor is called if present; otherwise, **indeterminate** |
