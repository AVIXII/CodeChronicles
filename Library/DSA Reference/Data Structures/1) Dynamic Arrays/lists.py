"""
    ============================================================
    ARRAYS CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA dynamic-array type: list

    Access            O(1)
    Update            O(1)
    Search            O(n)
    Append            O(1) amortized
    Insert middle     O(n)
    Delete middle     O(n)
    Pop last          O(1)
    Min / Max         O(n)
    Reverse           O(n)
    Sort              O(n log n)
    Binary search     O(log n) with bisect on sorted data

    EXTRAS / REFERENCE
    ------------------
    Slicing, comprehensions, aliasing, shallow/deep copy,
    bisect, reverse iteration, nested lists, slice assignment,
    manual binary search, prefix sums, etc.
"""

from bisect import bisect_left, bisect_right
from copy import deepcopy


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION / CREATION
# ------------------------------------------------

a = []                           # Empty list
ls = [1, 2, 3, 4]               # Literal
zeros = [0] * 10                # Repeated values
values = [2] * 15

from_range = list(range(5))     # From iterable
copy_of_a = a.copy()            # Shallow copy

# List comprehension:
squares = [x * x for x in range(10)]


# ------------------------------------------------
# 2. SIZE / EMPTY
# ------------------------------------------------

size = len(ls)                  # O(1)
is_empty = not ls               # O(1)

print("Size:", size)
print("Empty:", is_empty)


# ------------------------------------------------
# 3. ACCESS
# ------------------------------------------------

if ls:
    first = ls[0]               # O(1)
    last = ls[-1]               # O(1)

print("First:", first)
print("Last:", last)

# Python supports negative indexing.
# ls[-1] = last element


# ------------------------------------------------
# 4. UPDATE
# ------------------------------------------------

if ls:
    ls[0] = 99                  # O(1)


# ------------------------------------------------
# 5. INSERTION
# ------------------------------------------------

ls.append(2)                    # End; O(1) amortized

ls.insert(2, 45)                # Index; O(n)

# Insert a range using slice assignment:
ls[2:2] = [7, 8, 9]

# Append another iterable:
additional = [10, 11, 12]
ls.extend(additional)           # O(k)


# ------------------------------------------------
# 6. DELETION
# ------------------------------------------------

if ls:
    ls.pop()                    # Last; O(1)

if len(ls) > 2:
    ls.pop(2)                   # Index; O(n)

if ls:
    del ls[0]                   # Index; O(n)

if len(ls) >= 2:
    del ls[1:2]                 # Range; O(n)

# Delete first occurrence:
if 45 in ls:
    ls.remove(45)               # O(n)

# Clear:
ls.clear()                      # O(n)


# ------------------------------------------------
# 7. SEARCH
# ------------------------------------------------

a = [1, 2, 3, 2, 4]
target = 2

found = target in a             # O(n)
count = a.count(target)         # O(n)

try:
    index = a.index(target)     # O(n)
except ValueError:
    index = -1

print("Found:", found)
print("Count:", count)
print("Index:", index)


# ------------------------------------------------
# 8. TRAVERSAL
# ------------------------------------------------

print("Index traversal:")
for i in range(len(a)):
    print(i, a[i])

print("Value traversal:")
for x in a:
    print(x)

print("Index + value:")
for i, x in enumerate(a):
    print(i, x)

print("Reverse traversal:")
for x in reversed(a):
    print(x)


# ------------------------------------------------
# 9. MIN / MAX / SUM
# ------------------------------------------------

mn = min(a)                     # O(n)
mx = max(a)                     # O(n)
total = sum(a)                  # O(n)

print("Min:", mn)
print("Max:", mx)
print("Sum:", total)


# ------------------------------------------------
# 10. REVERSE
# ------------------------------------------------

a.reverse()                     # O(n), in-place

# Reverse copy:
reversed_copy = a[::-1]         # O(n), O(n) space


# ------------------------------------------------
# 11. SORT
# ------------------------------------------------

a.sort()                        # O(n log n), in-place
a.sort(reverse=True)            # Descending

# New sorted list:
sorted_copy = sorted(a)         # O(n log n), O(n) result

# Key:
people = [("A", 20), ("B", 18), ("C", 25)]
people.sort(key=lambda x: x[1])


# ------------------------------------------------
# 12. CLEAR
# ------------------------------------------------

a.clear()                       # Mutates existing list

# IMPORTANT:
# a = [] only rebinds the variable.
# a.clear() removes elements from the existing list object.


# ------------------------------------------------
# 13. BINARY SEARCH — BISect
# ------------------------------------------------

sorted_data = [1, 2, 2, 3, 5, 7, 9]

target = 2

lb = bisect_left(sorted_data, target)
ub = bisect_right(sorted_data, target)

found = (
    lb < len(sorted_data)
    and sorted_data[lb] == target
)

print("lower_bound:", lb)
print("upper_bound:", ub)
print("Found:", found)

# TC: O(log n)
# Requires sorted input.
# bisect searches; it does NOT sort the list.


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 14. NESTED LISTS
# ------------------------------------------------

n = 3
m = 4

matrix = [[0] * m for _ in range(n)]   # Correct: independent rows

# Avoid:
# matrix = [[0] * m] * n
#
# That creates multiple references to the SAME inner list.

matrix[0][0] = 99

# TC: O(n*m)
# SC: O(n*m)


# ------------------------------------------------
# 15. SLICING
# ------------------------------------------------

a = [0, 1, 2, 3, 4, 5]

sub = a[1:4]                    # [1,2,3]
step = a[::2]
reverse = a[::-1]

# TC for slice: O(k)
# SC: O(k)

# Slice assignment can change length:
a[1:4] = [10, 11]

# Insert:
a[2:2] = [20, 21]

# Delete:
del a[2:4]


# ------------------------------------------------
# 16. COPY / ALIASING
# ------------------------------------------------

original = [1, 2, 3]

alias = original                # Same list object
shallow = original.copy()       # New outer list
shallow_2 = original[:]         # New outer list

alias[0] = 99

print("Original after alias:", original)


# ------------------------------------------------
# 17. SHALLOW VS DEEP COPY
# ------------------------------------------------

nested = [[1, 2], [3, 4]]

shallow = nested.copy()

# Inner lists are still shared:
shallow[0][0] = 99

deep = deepcopy(nested)

# deepcopy creates independent nested objects.

# TC / SC: proportional to copied data.


# ------------------------------------------------
# 18. CONCATENATION
# ------------------------------------------------

x = [1, 2, 3]
y = [4, 5, 6]

combined = x + y               # O(n+m), creates result

# Repetition:
repeated = x * 3               # O(n*k), creates result


# ------------------------------------------------
# 19. FILL
# ------------------------------------------------

n = 10
filled = [0] * n               # O(n)

# Fill an existing list:
filled[:] = [5] * len(filled)   # O(n), same list object


# ------------------------------------------------
# 20. LOWER / UPPER BOUND
# ------------------------------------------------

data = [1, 2, 2, 2, 3, 5]

lb = bisect_left(data, 2)      # First index >= 2
ub = bisect_right(data, 2)     # First index > 2

equal_range = (lb, ub)

# Number of occurrences:
occurrences = ub - lb

# TC: O(log n)
# Requires sorted data.


# ------------------------------------------------
# 21. MANUAL LINEAR SEARCH
# ------------------------------------------------

def find_index(arr, target):
    for i, value in enumerate(arr):
        if value == target:
            return i
    return -1


print("Manual search:",
      find_index([10, 20, 30], 20))

# TC: O(n)
# SC: O(1)


# ------------------------------------------------
# 22. MANUAL BINARY SEARCH
# ------------------------------------------------

def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            return mid

        if arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


print(
    "Manual binary search:",
    binary_search(sorted_data, 7)
)

# TC: O(log n)
# SC: O(1)


# ------------------------------------------------
# 23. MANUAL REVERSE — TWO POINTERS
# ------------------------------------------------

two_pointer = [1, 2, 3, 4, 5]

left, right = 0, len(two_pointer) - 1

while left < right:
    two_pointer[left], two_pointer[right] = (
        two_pointer[right],
        two_pointer[left]
    )
    left += 1
    right -= 1

# TC: O(n)
# SC: O(1)


# ------------------------------------------------
# 24. PREFIX SUM
# ------------------------------------------------

nums = [1, 2, 3, 4]

prefix = [0] * len(nums)

if nums:
    prefix[0] = nums[0]

for i in range(1, len(nums)):
    prefix[i] = prefix[i - 1] + nums[i]

# prefix = [1,3,6,10]
# TC: O(n)
# SC: O(n)


# ------------------------------------------------
# 25. COMMON DSA IDIOMS
# ------------------------------------------------

a = [1, 2, 3]

if a:
    print("non-empty")

if not a:
    print("empty")

last = a[-1] if a else None

# Copy
b = a.copy()

# Sorted copy
b = sorted(a)

# Reverse copy
b = a[::-1]

# Index + value
for i, x in enumerate(a):
    pass


# ------------------------------------------------
# 26. IMPORTANT EDGE CASES
# ------------------------------------------------

empty = []

# empty[0]       -> IndexError
# empty[-1]      -> IndexError
# empty.pop()    -> IndexError
# empty.remove(1)-> ValueError
# empty.index(1) -> ValueError
# min(empty)     -> ValueError
# max(empty)     -> ValueError

print("Empty membership:", 1 in empty)


# ------------------------------------------------
# 27. CORE COMPLEXITY MEMORY
# ------------------------------------------------

"""
Access             O(1)
Update             O(1)
Search             O(n)
Append             O(1) amortized
Insert beginning   O(n)
Insert middle      O(n)
Delete last        O(1)
Delete beginning   O(n)
Delete middle      O(n)
Min / Max          O(n)
Reverse            O(n)
Sort               O(n log n)
Binary search      O(log n), sorted
Copy               O(n)
Slice              O(k)
"""


# ------------------------------------------------
# 28. PYTHON LIST IMPLEMENTATION NOTE
# ------------------------------------------------

"""
Python list is a dynamic-array implementation in CPython.

Important practical consequences:
    - indexing is O(1)
    - append is O(1) amortized
    - insertion/deletion away from the end is O(n)
    - slicing creates a new list
    - lists store references to Python objects
"""
