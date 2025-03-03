from collections import Counter

# Example list
elements = ['apple', 'banana', 'apple', 'orange', 'banana', 'banana']

# Create Counter object
counter = Counter(elements)

print(counter)  # Output: Counter({'banana': 3, 'apple': 2, 'orange': 1})

# Access count of a specific element
print(counter['apple'])  # Output: 2

# Access count of a non-existent element (returns 0)
print(counter['grape'])  # Output: 0

# Get the n most common elements
print(counter.most_common(2))  # Output: [('banana', 3), ('apple', 2)]

# Get a list of elements repeated according to their counts
print(list(counter.elements()))  # Output: ['apple', 'apple', 'banana', 'banana', 'banana', 'orange']

# Update counts with another iterable
counter.update(['apple', 'orange', 'orange'])
print(counter)  # Output: Counter({'banana': 3, 'orange': 3, 'apple': 3})

# Subtract counts with another iterable
counter.subtract(['banana', 'orange'])
print(counter)  # Output: Counter({'banana': 2, 'orange': 2, 'apple': 3})

# Addition
counter1 = Counter(a=3, b=1)
counter2 = Counter(a=1, b=2)
print(counter1 + counter2)  # Output: Counter({'a': 4, 'b': 3})

# Subtraction
print(counter1 - counter2)  # Output: Counter({'a': 2})

# Intersection (min of counts)
print(counter1 & counter2)  # Output: Counter({'a': 1, 'b': 1})

# Union (max of counts)
print(counter1 | counter2)  # Output: Counter({'a': 3, 'b': 2})