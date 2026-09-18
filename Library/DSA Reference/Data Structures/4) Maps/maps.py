"""
    ============================================================
    MAPS / DICTIONARIES CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA map type: dict

    dict:
        unique keys
        insertion order preserved
        hash-based
        lookup / insert / delete: O(1) average, O(n) worst

    EXTRAS / REFERENCE
    ------------------
    defaultdict, OrderedDict, Counter, dict views,
    setdefault, update, popitem, comprehensions, etc.
"""

from collections import OrderedDict, defaultdict, Counter


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION
# ------------------------------------------------

my_dict = {
    1: "One",
    2: "Two",
    3: "Three"
}

# Constructor:
my_dict2 = dict([
    (1, "One"),
    (2, "Two"),
    (3, "Three")
])

# Dictionary comprehension:
my_dict3 = {
    i: f"Number {i}"
    for i in range(1, 4)
}

# Empty dictionary:
empty = {}

# ------------------------------------------------
# 2. INSERT / UPDATE
# ------------------------------------------------

my_dict = {}

my_dict[1] = "One"              # Insert
my_dict[2] = "Two"              # Insert
my_dict[1] = "Uno"              # Update existing key

print(my_dict)


# ------------------------------------------------
# 3. ACCESS
# ------------------------------------------------

value = my_dict[1]              # Direct access

# If key is missing:
# my_dict[523]                  # KeyError

# Safe access with default:
value = my_dict.get(3, 0)

print(value)

# IMPORTANT:
# get() does NOT insert a missing key.


# ------------------------------------------------
# 4. SIZE / EMPTY
# ------------------------------------------------

n = len(my_dict)                # O(1)
is_empty = not my_dict         # O(1)

print("Size:", n)
print("Empty:", is_empty)


# ------------------------------------------------
# 5. KEY MEMBERSHIP
# ------------------------------------------------

if 2 in my_dict:
    print("Key 2 is present.")

present = 5 in my_dict
missing = 5 not in my_dict

# Average TC: O(1)
# Worst TC: O(n)


# ------------------------------------------------
# 6. REMOVE
# ------------------------------------------------

my_dict = {
    1: "One",
    2: "Two",
    3: "Three"
}

del my_dict[1]                  # Raises KeyError if absent

value = my_dict.pop(2)          # Removes + returns value

print(my_dict)
print(value)

# Safe deletion with default:
value = my_dict.pop(100, None)  # No KeyError


# ------------------------------------------------
# 7. ITERATION
# ------------------------------------------------

my_dict = {
    1: "One",
    2: "Two",
    3: "Three"
}

# Keys:
for key in my_dict:
    print(key)

for key in my_dict.keys():
    print(key)

# Values:
for value in my_dict.values():
    print(value)

# Key-value pairs:
for key, value in my_dict.items():
    print(key, value)


# ------------------------------------------------
# 8. INSERTION ORDER
# ------------------------------------------------

ordered = {
    "apple": 3,
    "banana": 2,
    "cherry": 5
}

for key, value in ordered.items():
    print(key, value)

# Iteration follows insertion order in modern Python dicts.


# ------------------------------------------------
# 9. CLEAR
# ------------------------------------------------

ordered.clear()

# O(n)


# ------------------------------------------------
# 10. UPDATE
# ------------------------------------------------

a = {"A": 1, "B": 2}
b = {"B": 20, "C": 3}

a.update(b)

# Result:
# {"A":1, "B":20, "C":3}

# New keys are inserted; existing values are overwritten.


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 11. DICTIONARY COMPREHENSION
# ------------------------------------------------

squares = {
    i: i * i
    for i in range(1, 6)
}

even_squares = {
    i: i * i
    for i in range(1, 11)
    if i % 2 == 0
}


# ------------------------------------------------
# 12. setdefault
# ------------------------------------------------

d = {}

d.setdefault("a", 0)
d["a"] += 1

print(d)

# IMPORTANT:
# setdefault(key, default) inserts default if key is absent,
# then returns the value associated with the key.

# It is useful for grouping:
groups = {}

for key, value in [
    ("a", 1),
    ("a", 2),
    ("b", 3)
]:
    groups.setdefault(key, []).append(value)

print(groups)

# TC: O(1) average per dictionary operation.


# ------------------------------------------------
# 13. defaultdict
# ------------------------------------------------

int_dict = defaultdict(int)

int_dict["a"] += 1
int_dict["b"] += 2

print(int_dict)

list_dict = defaultdict(list)

list_dict["a"].append(1)
list_dict["b"].append(2)

print(list_dict)

str_dict = defaultdict(str)

str_dict["a"] += "hello"
str_dict["b"] += "world"

print(str_dict)


# Custom default:
def default_value():
    return "default"

custom_dict = defaultdict(default_value)

print(custom_dict["a"])
print(custom_dict["b"])

# IMPORTANT:
# Accessing a missing defaultdict key CREATES the key
# using the default factory.


# ------------------------------------------------
# 14. OrderedDict
# ------------------------------------------------

ordered_dict = OrderedDict()

ordered_dict["apple"] = 3
ordered_dict["banana"] = 2
ordered_dict["cherry"] = 5

for key, value in ordered_dict.items():
    print(key, value)

# Modern normal dicts already preserve insertion order.
# OrderedDict is mainly useful for its additional ordering APIs.


# ------------------------------------------------
# 15. move_to_end
# ------------------------------------------------

ordered_dict.move_to_end("banana")
print(ordered_dict)

ordered_dict.move_to_end("apple", last=False)
print(ordered_dict)

# Raises KeyError if key is missing.


# ------------------------------------------------
# 16. popitem
# ------------------------------------------------

# Last item:
item = ordered_dict.popitem()
print(item)

# First item:
item = ordered_dict.popitem(last=False)
print(item)

# NOTE:
# Normal Python dict also supports dict.popitem(),
# but it removes the LAST inserted item and has no `last=False` option.


# ------------------------------------------------
# 17. Counter
# ------------------------------------------------

freq = Counter([
    "apple",
    "banana",
    "apple",
    "grape",
    "banana"
])

print(freq)

print("apple:", freq["apple"])

print(freq.most_common(2))

freq.update(["apple", "kiwi"])
freq.subtract(["banana"])

# Counter is extremely useful for frequency counting in DSA.


# ------------------------------------------------
# 18. FREQUENCY MAP — CORE DSA PATTERN
# ------------------------------------------------

values = [1, 2, 2, 3, 3, 3]

freq = {}

for x in values:
    freq[x] = freq.get(x, 0) + 1

print("Frequency:", freq)

# Average TC: O(n)
# SC: O(number of distinct keys)


# ------------------------------------------------
# 19. FREQUENCY WITH defaultdict
# ------------------------------------------------

freq = defaultdict(int)

for x in values:
    freq[x] += 1

print("Frequency:", freq)


# ------------------------------------------------
# 20. GROUPING WITH defaultdict(list)
# ------------------------------------------------

words = [
    ("fruit", "apple"),
    ("fruit", "banana"),
    ("animal", "cat"),
    ("animal", "dog")
]

groups = defaultdict(list)

for category, word in words:
    groups[category].append(word)

print(groups)


# ------------------------------------------------
# 21. DICT VIEWS
# ------------------------------------------------

d = {
    "a": 1,
    "b": 2,
    "c": 3
}

keys = d.keys()
values_view = d.values()
items = d.items()

# These are dynamic view objects, not independent lists.

# Convert if a real list is needed:
keys_list = list(d.keys())
values_list = list(d.values())
items_list = list(d.items())


# ------------------------------------------------
# 22. COPY
# ------------------------------------------------

a = {
    "x": 1,
    "y": 2
}

b = a.copy()
c = dict(a)

# Shallow copies.


# ------------------------------------------------
# 23. MERGE DICTIONARIES
# ------------------------------------------------

a = {"x": 1, "y": 2}
b = {"y": 20, "z": 3}

merged = a | b

# In a key collision, right-hand value wins.

a |= b

# Updates a in place.

# Traditional:
merged2 = {**a, **b}


# ------------------------------------------------
# 24. FILTER A DICTIONARY
# ------------------------------------------------

d = {
    "a": 1,
    "b": 2,
    "c": 3,
    "d": 4
}

filtered = {
    key: value
    for key, value in d.items()
    if value % 2 == 0
}

print(filtered)


# ------------------------------------------------
# 25. SORTED MAP-LIKE VIEWS
# ------------------------------------------------

d = {
    "banana": 2,
    "apple": 3,
    "cherry": 1
}

# Sort by key:
by_key = dict(sorted(d.items()))

# Sort by value:
by_value = dict(
    sorted(d.items(), key=lambda item: item[1])
)

# NOTE:
# A normal dict remains insertion-ordered.
# Sorting creates a new dict whose insertion order is sorted.


# ------------------------------------------------
# 26. FIRST / LAST KEY IN PYTHON DICT
# ------------------------------------------------

d = {
    "a": 1,
    "b": 2,
    "c": 3
}

first_key = next(iter(d))
last_key = next(reversed(d))

# Python dict preserves insertion order, so these mean:
# first inserted key / last inserted key.


# ------------------------------------------------
# 27. SAFE TRAVERSAL WHILE DELETING
# ------------------------------------------------

d = {
    0: "zero",
    1: "one",
    2: "two",
    3: "three"
}

# Do NOT mutate a dict's size directly while iterating:
#
# for key in d:
#     del d[key]      # RuntimeError

# Safe pattern:
for key in list(d):
    if key % 2 == 0:
        del d[key]

print(d)


# ================================================================
# 28. CORE COMPLEXITY MEMORY
# ================================================================

"""
Python dict:

Lookup            O(1) average, O(n) worst
Insert / update   O(1) average, O(n) worst
Delete            O(1) average, O(n) worst
Membership        O(1) average, O(n) worst
len()             O(1)
Iteration         O(n)

Important:
    Keys must be hashable.
    Iteration preserves insertion order.
    Dict has unique keys.
"""


# ------------------------------------------------
# 29. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. dict is the primary map/hash-map structure in Python.
2. Keys must be hashable.
3. Keys are unique.
4. Assigning an existing key updates its value.
5. dict preserves insertion order in modern Python.
6. d[key] raises KeyError when the key is absent.
7. d.get(key, default) does not insert the key.
8. d.pop(key) removes and returns the value.
9. d.pop(key, default) avoids KeyError if absent.
10. defaultdict creates missing keys when accessed.
11. Counter is useful for frequency counting.
12. OrderedDict is still useful for move_to_end/popitem(last=False)
    even though normal dict already preserves insertion order.
"""
