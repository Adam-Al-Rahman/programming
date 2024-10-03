# Funtion in python are first class citizens

# Required: Function as variable
def hello() -> str:
    return "Hello!!!!"


greet = hello()
print(greet)

greet_fn = hello
print(greet_fn())


# Required: Higher Order Functions (HOC)
# Required: Passing Function as input
def input_fn():
    return "Function As Parameter"


def output_fn(input_fn):  # input a function
    return input_fn()


io_fn = output_fn(input_fn)
print(io_fn)


# OR (Also HOC)
def outter_fn():
    outter_info = "Outter Function"

    def inner_fn():
        return "Inner Function"

    return outter_info + " " + inner_fn()


# Decorator: Enhances the functions | methods
def decor_fn(param_fn):
    def wrapper_fn(*args, **kwargs):
        print("*******************************")
        param_fn(*args, **kwargs)
        print("*******************************")

    return wrapper_fn  # return wrapper_fn reference


@decor_fn
def msg(msg: str, emoji="🤖"):
    print(emoji + " " + msg)


msg("Decorator enhances the function")
