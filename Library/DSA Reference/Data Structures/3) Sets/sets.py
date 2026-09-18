"""
    ============================================================
    SETS CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA set type: set

    Membership         O(1) average, O(n) worst
    Add                O(1) average, O(n) worst
    Remove             O(1) average, O(n) worst
    Discard            O(1) average, O(n) worst
    Length             O(1)
    Iteration          O(n)

    Python sets:
        - contain unique hashable elements
        - are unordered
        - do not support indexing or slicing

    EXTRAS / REFERENCE
    ------------------
    frozenset, subset/superset/disjoint checks, set comprehensions,
    update variants, Counter as a multiset-like tool, etc.
"""

from collections import Counter


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION
# ------------------------------------------------

my_set = {1, 2, 3, 4, 5}

# Constructor:
my_set2 = set([1, 2, 3, 4, 5])

# IMPORTANT:
empty_set = set()

# {} creates an empty DICTIONARY, not an empty set.
empty_dict = {}

fruits = {"apple", "banana", "cherry"}


# ------------------------------------------------
# 2. ADD
# ------------------------------------------------

fruits.add("orange")

# Adding an existing value does nothing:
fruits.add("orange")


# ------------------------------------------------
# 3. MEMBERSHIP
# ------------------------------------------------

if "apple" in fruits:
    print("Apple is in the set.")

present = "banana" in fruits
missing = "mango" not in fruits

# Average TC: O(1)
# Worst TC: O(n)


# ------------------------------------------------
# 4. REMOVE
# ------------------------------------------------

# remove():
# Raises KeyError if the element is absent.

if "banana" in fruits:
    fruits.remove("banana")

# discard():
# Safe if absent; does nothing.

fruits.discard("mango")

# Both: average O(1), worst O(n)


# ------------------------------------------------
# 5. LENGTH / EMPTY
# ------------------------------------------------

n = len(fruits)                # O(1)
is_empty = not fruits          # O(1)

print("Size:", n)
print("Empty:", is_empty)


# ------------------------------------------------
# 6. ITERATION
# ------------------------------------------------

for fruit in fruits:
    print(fruit)

# TC: O(n)

# IMPORTANT:
# No guaranteed sorted order.
# Do not build logic that depends on set iteration order.


# ------------------------------------------------
# 7. CLEAR
# ------------------------------------------------

fruits.clear()

# TC: O(n)


# ------------------------------------------------
# 8. UNION
# ------------------------------------------------

set1 = {1, 2, 3}
set2 = {3, 4, 5}

union_set = set1 | set2

# Method form:
union_set_2 = set1.union(set2)

print("Union:", union_set)

# TC: O(len(set1) + len(set2))


# ------------------------------------------------
# 9. INTERSECTION
# ------------------------------------------------

intersection_set = set1 & set2

# Method:
intersection_set_2 = set1.intersection(set2)

print("Intersection:", intersection_set)

# TC: O(min(len(set1), len(set2)))
# Under normal set/set use.


# ------------------------------------------------
# 10. DIFFERENCE
# ------------------------------------------------

difference_set = set1 - set2

difference_set_2 = set1.difference(set2)

print("Difference:", difference_set)

# Typical TC: O(len(set1))


# ------------------------------------------------
# 11. SYMMETRIC DIFFERENCE
# ------------------------------------------------

sym_diff = set1 ^ set2

sym_diff_2 = set1.symmetric_difference(set2)

print("Symmetric Difference:", sym_diff)

# Typical TC: O(len(set1) + len(set2))


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 12. SET COMPREHENSION
# ------------------------------------------------

squares = {x * x for x in range(10)}

even_squares = {
    x * x
    for x in range(10)
    if x % 2 == 0
}


# ------------------------------------------------
# 13. UPDATE
# ------------------------------------------------

a = {1, 2, 3}
b = {3, 4, 5}

a.update(b)                  # Mutates a
# a |= b                     # Equivalent operator form

# TC: O(len(b)) average-oriented


# ------------------------------------------------
# 14. INTERSECTION UPDATE
# ------------------------------------------------

a = {1, 2, 3}
b = {2, 3, 4}

a.intersection_update(b)
# a &= b

# Mutates a.


# ------------------------------------------------
# 15. DIFFERENCE UPDATE
# ------------------------------------------------

a = {1, 2, 3}
b = {2, 3, 4}

a.difference_update(b)
# a -= b

# Mutates a.


# ------------------------------------------------
# 16. SYMMETRIC DIFFERENCE UPDATE
# ------------------------------------------------

a = {1, 2, 3}
b = {2, 3, 4}

a.symmetric_difference_update(b)
# a ^= b

# Mutates a.


# ------------------------------------------------
# 17. SUBSET / SUPERSET
# ------------------------------------------------

a = {1, 2}
b = {1, 2, 3, 4}

print(a.issubset(b))
print(a <= b)

print(b.issuperset(a))
print(b >= a)

# Proper subset:
print(a < b)

# Proper superset:
print(b > a)


# ------------------------------------------------
# 18. DISJOINT
# ------------------------------------------------

a = {1, 2}
b = {3, 4}

print(a.isdisjoint(b))
# True

# No common element.


# ------------------------------------------------
# 19. SET COMPARISON
# ------------------------------------------------

a = {1, 2, 3}
b = {3, 2, 1}

print(a == b)                 # True

# Set equality depends on members, not iteration order.

# Set ordering is about subset relationships, not lexicographic
# ordering like strings/lists.


# ------------------------------------------------
# 20. COPY
# ------------------------------------------------

a = {1, 2, 3}

b = a.copy()
c = set(a)

# Shallow copy.
# For immutable/hashable elements, this is normally all you need.

# TC: O(n)


# ------------------------------------------------
# 21. POP
# ------------------------------------------------

a = {1, 2, 3}

x = a.pop()

print("Popped:", x)

# IMPORTANT:
# pop() removes and returns an ARBITRARY element.
# It is NOT "remove the first" or "remove the last".

# Raises KeyError if the set is empty.


# ------------------------------------------------
# 22. HASHABLE ELEMENTS
# ------------------------------------------------

valid = {
    1,
    "hello",
    (1, 2)
}

# Lists are unhashable:
#
# invalid = {[1, 2]}          # TypeError

# Mutable set is also unhashable:
#
# invalid = {{1,2}}            # TypeError

# Use frozenset for a set-like hashable value.


# ------------------------------------------------
# 23. FROZENSET
# ------------------------------------------------

frozen_set = frozenset([1, 2, 3, 4])

# Cannot mutate:
# frozen_set.add(5)            # AttributeError

# Can perform set operations:
other = frozenset([3, 4, 5])

print(frozen_set | other)
print(frozen_set & other)

# frozenset is immutable and hashable.


# ------------------------------------------------
# 24. FROZENSET AS SET ELEMENT
# ------------------------------------------------

nested_sets = {
    frozenset({1, 2}),
    frozenset({3, 4})
}

print(nested_sets)


# ------------------------------------------------
# 25. COUNTER — MULTISET-LIKE DSA TOOL
# ------------------------------------------------

from collections import Counter

# Create Counter
elements = [
    'apple', 'banana', 'apple',
    'orange', 'banana', 'banana'
]

counter = Counter(elements)
print(counter)
# Counter({'banana': 3, 'apple': 2, 'orange': 1})

# Access count
print(counter['apple'])          # 2

# Missing key -> 0
print(counter['grape'])          # 0

# n most common elements
print(counter.most_common(2))
# [('banana', 3), ('apple', 2)]

# Elements repeated according to their counts
print(list(counter.elements()))
# ['apple', 'apple', 'banana', 'banana', 'banana', 'orange']

# Add counts
counter.update(['apple', 'orange', 'orange'])
print(counter)
# Counter({'banana': 3, 'orange': 3, 'apple': 3})

# Subtract counts
counter.subtract(['banana', 'orange'])
print(counter)
# Counter({'banana': 2, 'orange': 2, 'apple': 3})


# ============================================================
# Counter arithmetic
# ============================================================

counter1 = Counter(a=3, b=1)
counter2 = Counter(a=1, b=2)

# Addition → add counts
print(counter1 + counter2)
# Counter({'a': 4, 'b': 3})

# Subtraction → subtract counts, discard zero/negative results
print(counter1 - counter2)
# Counter({'a': 2})

# Intersection → minimum count
print(counter1 & counter2)
# Counter({'a': 1, 'b': 1})

# Union → maximum count
print(counter1 | counter2)
# Counter({'a': 3, 'b': 2})

# Counter is often the Python replacement for:
# C++ multiset / frequency-map style problems,
# depending on what the problem actually needs.


# ------------------------------------------------
# 26. REMOVE DUPLICATES
# ------------------------------------------------

arr = [1, 2, 2, 3, 3, 4]

unique = set(arr)

print("Unique:", unique)

# TC: O(n) average
# SC: O(n)


# Preserve original order while deduplicating:
unique_ordered = list(dict.fromkeys(arr))

print("Unique preserving order:", unique_ordered)

# This is a Python-specific idiom.


# ------------------------------------------------
# 27. SET OPERATIONS WITH ITERABLES
# ------------------------------------------------

a = {1, 2, 3}

# Method forms can accept any iterable:
print(a.union([3, 4, 5]))
print(a.intersection([2, 3, 4]))
print(a.difference([2]))

# Operator forms expect set-like operands:
# a | [3,4]                # TypeError


# ------------------------------------------------
# 28. MANUAL MEMBERSHIP
# ------------------------------------------------

def contains(s, x):
    return x in s

# Average TC: O(1)
# Worst TC: O(n)


# ------------------------------------------------
# 29. SET RELATION QUICK TESTS
# ------------------------------------------------

A = {1, 2, 3}
B = {1, 2, 3, 4, 5}
C = {7, 8}

subset = A <= B
proper_subset = A < B
superset = B >= A
proper_superset = B > A
disjoint = A.isdisjoint(C)

print(subset)
print(proper_subset)
print(superset)
print(proper_superset)
print(disjoint)


# ------------------------------------------------
# 30. CORE COMPLEXITY MEMORY
# ------------------------------------------------

"""
Python set / frozenset:

Membership      O(1) average, O(n) worst
Add             O(1) average, O(n) worst
Remove          O(1) average, O(n) worst
Discard         O(1) average, O(n) worst
Length          O(1)
Iteration       O(n)
Copy            O(n)

Union           O(n+m) average-oriented
Intersection    O(min(n,m)) average-oriented for set/set
Difference      O(n) where n = len(left operand)
Symmetric diff  O(n+m)

No indexing.
No slicing.
No meaningful first/last element.
"""


# ------------------------------------------------
# 31. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. set stores UNIQUE hashable elements.
2. set is unordered; do not rely on iteration order.
3. {} creates an empty dict, NOT an empty set.
4. Use set() for an empty set.
5. add() inserts one element.
6. remove() raises KeyError if absent.
7. discard() safely removes if present.
8. pop() removes an arbitrary element.
9. set elements must be hashable.
10. frozenset is immutable and hashable.
11. Sets support membership and mathematical set operations.
12. Sets do NOT support indexing or slicing.
"""
