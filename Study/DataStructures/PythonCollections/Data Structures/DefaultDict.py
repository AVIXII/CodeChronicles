from collections import defaultdict

# Create a defaultdict with int as the default factory
int_dict = defaultdict(int)

int_dict['a'] += 1  # This will set int_dict['a'] to 1, as the default value is 0
int_dict['b'] += 2  # This will set int_dict['b'] to 2

print(int_dict)  # Output: defaultdict(<class 'int'>, {'a': 1, 'b': 2})


list_dict = defaultdict(list)

list_dict['a'].append(1)  # Adds 1 to the list at key 'a'
list_dict['b'].append(2)  # Adds 2 to the list at key 'b'

print(list_dict)  # Output: defaultdict(<class 'list'>, {'a': [1], 'b': [2]})


str_dict = defaultdict(str)

str_dict['a'] += 'hello'  # Adds 'hello' to the string at key 'a'
str_dict['b'] += 'world'  # Adds 'world' to the string at key 'b'

print(str_dict)  # Output: defaultdict(<class 'str'>, {'a': 'hello', 'b': 'world'})


def default_value():
    return 'default'

custom_dict = defaultdict(default_value)
print(custom_dict['a'])  # Output: 'default'
print(custom_dict['b'])  # Output: 'default'

