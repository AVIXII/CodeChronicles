# Miscellaneous Python — DSA / Competitive Programming Toolbox
# Runnable reference file.
#
# A companion to the C++ miscellaneous sheet: small tricks, useful
# standard-library helpers, conversions, and Python-specific gotchas.

import math
import sys
from functools import reduce
from itertools import permutations
from collections import Counter, defaultdict, deque


def section(title: str) -> None:
    print(f"\n===== {title} =====")


# ============================================================
# CORE / MUST KNOW
# ============================================================

# ------------------------------------------------------------
# 1. String replacement / conversion
# ------------------------------------------------------------
section("1. String helpers")

s = "rishabh"
s = s.replace("rishabh", "ahdskfa ")
print(s)

print(str(42))
print(str(3.141590))
print(str(2.718280))

# String -> number
print(int("123"))
print(int("1010", 2))
print(float("3.14"))

# Character-like conversions
print(ord("A"))
print(chr(65))

# ------------------------------------------------------------
# 2. f-strings
# ------------------------------------------------------------
section("2. f-strings")

name = "Rishabh"
age = 20
print(f"{name} is {age} years old")

x = 3.1415926
print(f"{x:.2f}")

# ------------------------------------------------------------
# 3. divmod and division traps
# ------------------------------------------------------------
section("3. Division / modulo")

print(7 // 2)       # 3
print(7 / 2)        # 3.5
print(7 % 2)        # 1
print(divmod(17, 5))  # (3, 2)

# Python floor division differs from C++ truncation for negatives.
print(-7 // 3)      # -3
print(-7 % 3)       # 2

# ------------------------------------------------------------
# 4. Multiple assignment / swapping
# ------------------------------------------------------------
section("4. Assignment tricks")

a, b = 10, 20
a, b = b, a
print(a, b)

x, y, z = (1, 2, 3)
print(x, y, z)

first, *middle, last = [1, 2, 3, 4, 5]
print(first, middle, last)

# ------------------------------------------------------------
# 5. zip / enumerate
# ------------------------------------------------------------
section("5. zip / enumerate")

names = ["A", "B", "C"]
scores = [10, 20, 30]

for name, score in zip(names, scores):
    print(name, score)

for index, value in enumerate(scores):
    print(index, value)

# ------------------------------------------------------------
# 6. any / all
# ------------------------------------------------------------
section("6. any / all")

vals = [2, 4, 6, 8]

print(all(x % 2 == 0 for x in vals))
print(any(x > 7 for x in vals))

# ------------------------------------------------------------
# 7. min / max / sum with key
# ------------------------------------------------------------
section("7. min / max / sum")

words = ["cat", "elephant", "dog"]

print(min(words, key=len))
print(max(words, key=len))
print(sum([1, 2, 3, 4]))

# ------------------------------------------------------------
# 8. sorted with key
# ------------------------------------------------------------
section("8. sorted / custom key")

pairs = [(2, 5), (1, 9), (2, 3), (1, 4)]

print(sorted(pairs))
print(sorted(pairs, key=lambda p: (p[0], -p[1])))

# ------------------------------------------------------------
# 9. Slicing tricks
# ------------------------------------------------------------
section("9. Slicing")

arr = [1, 2, 3, 4, 5]

print(arr[::-1])       # reverse
print(arr[::2])        # every second item
print(arr[1:4])        # subrange
print(arr[:])          # shallow copy for a list

# ------------------------------------------------------------
# 10. Shallow copy / aliasing
# ------------------------------------------------------------
section("10. Aliasing")

a = [1, 2, 3]
b = a

b.append(4)

print(a)
print(b)
print(a is b)

c = a.copy()
c.append(5)

print(a)
print(c)
print(a is c)

# ------------------------------------------------------------
# 11. Nested-list aliasing trap
# ------------------------------------------------------------
section("11. Nested list trap")

bad = [[0] * 3] * 3
bad[0][0] = 99
print(bad)  # all rows changed

good = [[0] * 3 for _ in range(3)]
good[0][0] = 99
print(good)

# ------------------------------------------------------------
# 12. dict helpers
# ------------------------------------------------------------
section("12. dict helpers")

d = {"a": 1}

print(d.get("missing"))
d.setdefault("b", 0)
d.update({"c": 3})
print(d)

value = d.pop("a")
print(value, d)

# Dictionary merge (Python 3.9+)
left = {"a": 1, "b": 2}
right = {"b": 20, "c": 30}
print(left | right)

# ------------------------------------------------------------
# 13. set helpers
# ------------------------------------------------------------
section("13. sets")

s1 = {1, 2, 3}
s2 = {3, 4, 5}

print(s1 | s2)
print(s1 & s2)
print(s1 - s2)
print(s1 ^ s2)

print(s1.issubset({1, 2, 3, 4}))
print(s1.isdisjoint({7, 8}))

# ------------------------------------------------------------
# 14. Counter
# ------------------------------------------------------------
section("14. Counter")

elements = ["apple", "banana", "apple", "orange", "banana", "apple"]
counter = Counter(elements)

print(counter)
print(counter["apple"])
print(counter["grape"])       # 0
print(counter.most_common(2))

counter.update(["banana", "banana"])
print(counter)

counter.subtract(["apple"])
print(counter)

# ------------------------------------------------------------
# 15. defaultdict
# ------------------------------------------------------------
section("15. defaultdict")

freq = defaultdict(int)
freq["apple"] += 1
freq["apple"] += 1

groups = defaultdict(list)
groups["even"].append(2)
groups["even"].append(4)

print(freq)
print(groups)

# ------------------------------------------------------------
# 16. gcd / lcm
# ------------------------------------------------------------
section("16. gcd / lcm")

print(math.gcd(24, 18))
print(math.lcm(6, 8))

# ------------------------------------------------------------
# 17. reduce
# ------------------------------------------------------------
section("17. reduce")

nums = [1, 2, 3, 4]
print(reduce(lambda acc, x: acc + x, nums, 0))
print(reduce(lambda acc, x: acc * x, nums, 1))

# For simple sums/products, prefer sum() / math.prod().
print(math.prod(nums))

# ------------------------------------------------------------
# 18. Prefix sums with accumulate
# ------------------------------------------------------------
section("18. Prefix sums")

from itertools import accumulate

values = [1, 2, 3, 4]
prefix = list(accumulate(values))
print(prefix)

# ------------------------------------------------------------
# 19. permutations
# ------------------------------------------------------------
section("19. permutations")

for p in permutations("123"):
    print("".join(p), end=" ")
print()

# ------------------------------------------------------------
# 20. Fast I/O pattern
# ------------------------------------------------------------
section("20. Fast I/O")

# In actual large-input problems:
# data = sys.stdin.buffer.read().split()
#
# This gives byte tokens and is often faster than repeated input().
#
# For line-based input:
# sys.stdin.readline

# ------------------------------------------------------------
# 21. Recursion limit
# ------------------------------------------------------------
section("21. Recursion limit")

print("default recursion limit:", sys.getrecursionlimit())

# In a problem that genuinely requires deep recursion:
# sys.setrecursionlimit(1_000_000)
#
# Do not blindly increase it: Python recursion still consumes stack/memory.

# ------------------------------------------------------------
# 22. Infinity
# ------------------------------------------------------------
section("22. Infinity")

INF = float("inf")
NEG_INF = float("-inf")

print(INF)
print(NEG_INF)
print(INF > 10**1000)

# A practical integer sentinel can also be:
BIG = 10**18
print(BIG)

# ------------------------------------------------------------
# 23. Membership / identity
# ------------------------------------------------------------
section("23. == vs is")

a = [1, 2]
b = [1, 2]

print(a == b)  # same value
print(a is b)  # same object?

value = None
print(value is None)

# Use == for value equality and is for identity checks.


# ============================================================
# EXTRAS / REFERENCE
# ============================================================

# ------------------------------------------------------------
# 24. Walrus operator
# ------------------------------------------------------------
section("EXTRAS: walrus operator")

if (n := 5) > 3:
    print(n)

# ------------------------------------------------------------
# 25. Chained comparisons
# ------------------------------------------------------------
section("EXTRAS: chained comparisons")

x = 5
print(1 < x < 10)
print(1 < x and x < 10)

# ------------------------------------------------------------
# 26. Star unpacking in function calls / literals
# ------------------------------------------------------------
section("EXTRAS: star unpacking")

a = [1, 2]
b = [3, 4]
print([*a, *b])

d1 = {"a": 1}
d2 = {"b": 2}
print({**d1, **d2})

def add3(x, y, z):
    return x + y + z

args = [1, 2, 3]
print(add3(*args))

# ------------------------------------------------------------
# 27. Sorting dictionaries / custom keys
# ------------------------------------------------------------
section("EXTRAS: sorting dict items")

d = {"a": 3, "b": 1, "c": 2}
print(sorted(d.items(), key=lambda item: item[1]))

# ------------------------------------------------------------
# 28. Matrix transpose with zip
# ------------------------------------------------------------
section("EXTRAS: transpose")

matrix = [
    [1, 2, 3],
    [4, 5, 6],
]

transpose = [list(col) for col in zip(*matrix)]
print(transpose)

# ------------------------------------------------------------
# 29. map / filter
# ------------------------------------------------------------
section("EXTRAS: map / filter")

print(list(map(lambda x: x * 2, [1, 2, 3])))
print(list(filter(lambda x: x % 2 == 0, [1, 2, 3, 4])))

# In modern Python, comprehensions are often clearer.

# ------------------------------------------------------------
# 30. Mutable default argument trap
# ------------------------------------------------------------
section("EXTRAS: mutable default argument trap")

def bad_append(x, bucket=[]):
    bucket.append(x)
    return bucket

print(bad_append(1))
print(bad_append(2))  # same default list reused

def good_append(x, bucket=None):
    if bucket is None:
        bucket = []
    bucket.append(x)
    return bucket

print(good_append(1))
print(good_append(2))

# ------------------------------------------------------------
# 31. bool is an int
# ------------------------------------------------------------
section("EXTRAS: bool subclass")

print(True == 1)
print(False == 0)
print(isinstance(True, int))

# ------------------------------------------------------------
# 32. Arbitrary-precision integers
# ------------------------------------------------------------
section("EXTRAS: big integers")

huge = 10**100
print(len(str(huge)))

# ------------------------------------------------------------
# 33. Matrix / list multiplication trap
# ------------------------------------------------------------
section("EXTRAS: nested list aliasing")

matrix = [[0] * 4 for _ in range(3)]
matrix[0][0] = 1
print(matrix)

# [[0] * 4] * 3 creates three references to the same row.
wrong_matrix = [[0] * 4] * 3
wrong_matrix[0][0] = 1
print(wrong_matrix)

print("\nMiscellaneous Python examples completed.")
