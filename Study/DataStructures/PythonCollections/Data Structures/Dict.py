# Dictionaries maintain the insertion order of keys. This means that when you iterate over a dictionary, items will be returned in the order they were added.
# Keys must be hashable, which means they must be immutable types like strings, numbers, or tuples (containing only immutable elements).
# Dictionary operations like insertion, deletion, and lookup are generally O(1) on average due to the underlying hash table implementation.

# Initialisation

# Using curly braces
my_dict = {
    1: "One",
    2: "Two",
    3: "Three"
}

# Using the dict constructor
my_dict = dict([(1, "One"), (2, "Two"), (3, "Three")])

# Using dictionary comprehension
my_dict = {i: f"Number {i}" for i in range(1, 4)}

# Insertion and updation
my_dict = {}
my_dict[1] = "One"  # Adding a new key-value pair
my_dict[2] = "Two"
my_dict[1] = "Uno"  # Updating the value of an existing key
print(my_dict)

# Access elements
value = my_dict[523]  # Direct access - Dangerous! Not recommended if key does not exist in dictionary. Throws a KeyError if the key does not exist
value = my_dict.get(3, 0)  # Access with default
print(value)

# Removing elements
del my_dict[1]  # Removes the key 1 and its value
value = my_dict.pop(2)  # Removes key 2 and returns its value
print(my_dict)
print(value)

# Iterating over dictionary
my_dict = {1: "One", 2: "Two", 3: "Three"}

# Iterating over keys
for key in my_dict.keys():
    print(key, end=' ')  # 1 2 3
        # or
for key in my_dict:
    print(key, end=' ')  # 1 2 3

# Iterating over values
for value in my_dict.values():
    print(value, end=' ')  # One Two Three

# Iterating over key-value pairs
for key, value in my_dict.items():
    print(f"Key: {key}, Value: {value}")

# Checking if a Key Exists:
if 2 in my_dict:
    print("Key 2 is in the dictionary")

# Number of key value pairs
length = len(my_dict)
print(length)  # Output: 3
