"""
In Python, cooperative inheritance is a concept used in object-oriented programming,
specifically when dealing with multiple inheritance.
It ensures that all classes in the inheritance chain cooperate correctly when methods are called,
especially when the `super()` function is used.

### How Cooperative Inheritance Works:
Cooperative inheritance is based on the idea of the Method Resolution Order (MRO),
which determines the order in which classes are searched when a method is called.
The `super()` function plays a crucial role here,
allowing you to call the next method in the MRO chain without explicitly naming the superclass.

"""


class A(object):
    def __init__(self):
        print("A.__init__")
        super().__init__()


class B(A):
    def __init__(self):
        print("B.__init__")
        super().__init__()


class C(A):
    def __init__(self):
        print("C.__init__")
        super().__init__()


class D(B, C):
    def __init__(self):
        print("D.__init__")
        super().__init__()


d = D()

"""
### Output Explanation:
- `D.__init__` is called first since `D` is instantiated.
- `super().__init__()` in `D.__init__` calls `B.__init__` because of the MRO.
- `B.__init__` calls `super().__init__()`, which then calls `C.__init__` according to the MRO.
- `C.__init__` calls `super().__init__()`, which calls `A.__init__`.
- Finally, `A.__init__` is called, and it finishes the chain.

### The Method Resolution Order (MRO):
You can check the MRO of a class using the `__mro__` attribute
or the `mro()` method:

```python
print(D.__mro__)
```

This will display the order in which the classes are looked up:

```python
(<class '__main__.D'>, <class '__main__.B'>, <class '__main__.C'>, <class '__main__.A'>, <class 'object'>)
```

### Why Cooperative Inheritance?
Cooperative inheritance ensures that all the classes in the hierarchy get
properly initialized and that their methods are executed in the correct order.
This is particularly important when working with complex
class hierarchies involving multiple inheritance.

### Key Points:
- **Use `super()`**: Always use `super()` to ensure the next class in the MRO is called.
- **MRO**: Understand the MRO of your classes to predict and control the behavior.
- **Avoid Conflicts**: Design your classes carefully to avoid conflicts in the MRO, which can lead to unexpected results.

Cooperative inheritance is a powerful feature in Python, but it requires a good understanding of MRO and `super()` to use it effectively.
"""
