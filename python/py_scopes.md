# Python Scopes

Python does not have block-level scope. Instead, it uses function-level or module-level scope for variables. In other words, any variable declared inside an if, for, while, or similar block is still part of the surrounding function or module's scope.

### 1. **Local Scope**

- Variables declared inside a function are **local** to that function and can only be accessed within it.
- Once the function finishes execution, the local variables are destroyed and cannot be accessed anymore.

Example:

```python
def my_function():
    x = 10  # x is local to my_function
    print(x)

my_function()  # prints 10
# print(x) would raise an error, because x is not defined outside the function
```

### 2. **Enclosing Scope (Nonlocal)**

- This refers to the scope of nested functions. If a variable is defined in an outer (enclosing) function, it is accessible to any inner (nested) functions, but it is not local to the nested function.
- You can modify the value of such variables using the `nonlocal` keyword.

Example:

```python
def outer_function():
    x = 5  # Enclosing scope

    def inner_function():
        nonlocal x  # Refers to the x in the outer_function
        x = 10      # If not use `nonlocal` it create `x` with value `10`
        print(x)

    inner_function()
    print(x)  # prints 10, because inner_function modified x

outer_function()
```

### 3. **Global Scope**

- Variables defined at the top level of a script or module are in the **global** scope. They can be accessed from anywhere in the same script/module.
- To modify a global variable inside a function, you need to use the `global` keyword.

Example:

```python
x = 20  # Global scope

def my_function():
    global x
    x = 30  # Modifies the global x
    print(x)

my_function()  # prints 30
print(x)  # prints 30, because x was modified globally
```

### 4. **Built-in Scope**

- This is the scope of Python’s built-in names, such as `len()`, `range()`, `print()`, etc.
- You can access built-in functions from anywhere in your program.

Example:

```python
print(len([1, 2, 3]))  # prints 3, using the built-in len function
```

### Scope Resolution: LEGB Rule

Python resolves variable names by searching through these scopes in a specific order, known as the **LEGB** rule:

1. **L**ocal: The innermost scope, which contains local variables.
2. **E**nclosing: The scope of any enclosing functions.
3. **G**lobal: The module-level (global) scope.
4. **B**uilt-in: The built-in scope, where Python’s built-in functions and constants are stored.

If Python cannot find the variable in the local scope, it checks the enclosing scope, then global, and finally built-in. If the variable is not found in any of these, it raises a `NameError`.
