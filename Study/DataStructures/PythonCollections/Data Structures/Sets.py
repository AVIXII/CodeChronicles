# Sets 

# Initialisation
# Using curly braces
my_set = {1, 2, 3, 4, 5}

# Using the set() constructor
my_set = set([1, 2, 3, 4, 5])

# An empty set must be created using the set() constructor
empty_set = set()

# Creating a set
fruits = {"apple", "banana", "cherry"}

# Adding an element to the set
fruits.add("orange")
print(fruits)  # Output will include "orange"

# Removing an element from the set
# Always check before removing from the set. Else it will raise an error. Use discard instead as it does not raise an error if element not found.
if "banana" in fruits: fruits.remove("banana")
print(fruits)  # Output will not include "banana"

# Checking if an element is in the set
if "apple" in fruits:
    print("Apple is in the set.")

# Iterating over a set
for fruit in fruits:
    print(fruit)

# Union
set1 = {1, 2, 3}
set2 = {3, 4, 5}
union_set = set1 | set2  # or set1.union(set2)
print(union_set)  # Output: {1, 2, 3, 4, 5}

# Intersection
intersection_set = set1 & set2  # or set1.intersection(set2)
print(intersection_set)  # Output: {3}

# Difference
difference_set = set1 - set2  # or set1.difference(set2)
print(difference_set)  # Output: {1, 2}

# Symmetric Difference
difference_set = set1 ^ set2  # or set1.difference(set2)
print(difference_set)  # Output: {1, 2}





# Frozen Sets
frozen_set = frozenset([1, 2, 3, 4])
# Trying to modify frozen_set will raise an error
# frozen_set.add(5)  # AttributeError: 'frozenset' object has no attribute 'add'

# Creating two sets
set_a = {1, 2, 3, 4, 5}
set_b = {4, 5, 6, 7, 8}

# Union of set_a and set_b
union = set_a | set_b
print("Union:", union)  # Output: Union: {1, 2, 3, 4, 5, 6, 7, 8}

# Intersection of set_a and set_b
intersection = set_a & set_b
print("Intersection:", intersection)  # Output: Intersection: {4, 5}

# Difference of set_a and set_b
difference = set_a - set_b
print("Difference:", difference)  # Output: Difference: {1, 2, 3}

# Symmetric Difference of set_a and set_b
sym_diff = set_a ^ set_b
print("Symmetric Difference:", sym_diff)  # Output: Symmetric Difference: {1, 2, 3, 6, 7, 8}
