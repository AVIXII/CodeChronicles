# Algorithms in Python 3 — DSA / Competitive Programming Reference
#
# Python does not have a single module corresponding exactly to C++ <algorithm>.
# The closest toolbox is spread across built-ins, list methods, bisect,
# itertools, heapq, functools, math, and small idioms.

from bisect import bisect_left, bisect_right, insort_left, insort_right
from functools import reduce
from itertools import (
    accumulate,
    combinations,
    combinations_with_replacement,
    chain,
    compress,
    groupby,
    islice,
    permutations,
    product,
    pairwise,
    zip_longest,
)
import heapq
import math
import operator
import random


def section(title: str) -> None:
    print(f"\n===== {title} =====")


# ============================================================
# CORE / MUST KNOW
# ============================================================

# 1) find / membership / index
section("1. find / membership")

v = [1, 2, 3, 4, 5]

print(4 in v)           # membership, O(n) for list
print(v.index(4))       # first index, O(n)
print(v.count(2))       # count value, O(n)

# For strings:
s = "hello world"
print(s.find("world"))  # index or -1
print(s.count("l"))

# For hash containers:
st = {1, 2, 3, 4, 5}
d = {1: "one", 2: "two"}

print(4 in st)          # average O(1)
print(2 in d)           # average O(1)

# 2) any / all
section("2. any / all")

print(all(x > 0 for x in v))
print(any(x > 4 for x in v))
print(not any(x < 0 for x in v))  # none_of-style pattern

# Short-circuiting: stops as soon as the result is known.

# 3) min / max / sum
section("3. min / max / sum")

print(min(v))
print(max(v))
print(sum(v))

words = ["cat", "elephant", "dog"]
print(min(words, key=len))
print(max(words, key=len))

# 4) sorted / list.sort
section("4. sorting")

a = [5, 1, 4, 2, 3]

print(sorted(a))
print(sorted(a, reverse=True))

a.sort()
print(a)

pairs = [(2, 5), (1, 9), (2, 3), (1, 4)]
print(sorted(pairs))
print(sorted(pairs, key=lambda p: (p[0], -p[1])))

# sorted() returns a new list; list.sort() modifies the list in place.
# TC O(n log n) worst-case for Python's Timsort; .sort() is stable.

# 5) reverse / reversed
section("5. reverse / reversed")

a = [1, 2, 3, 4, 5]

a.reverse()                 # in-place
print(a)

print(list(reversed(a)))   # iterator
print(a[::-1])             # slicing creates a new list

# TC O(n); reversed() itself returns an iterator, materializing list is O(n).

# 6) replace
section("6. replace")

s = "banana"
print(s.replace("a", "x"))

# str.replace() returns a new string because strings are immutable.

# 7) fill-style operations
section("7. fill-style")

a = [0] * 5
print(a)

a = [7 for _ in range(5)]
print(a)

# There is no direct built-in exactly equivalent to std::fill for arbitrary
# list ranges; slice assignment can be useful.
a[1:4] = [9] * 3
print(a)

# 8) map / transform
section("8. map / transform")

a = [1, 2, 3, 4]
print(list(map(lambda x: x * x, a)))

# List comprehensions are often more readable:
print([x * x for x in a])

# Two-input transform:
b = [10, 20, 30, 40]
print([x + y for x, y in zip(a, b)])

# 9) filter / remove_if-style
section("9. filter / remove_if")

a = [1, 2, 3, 4, 5, 6]

print(list(filter(lambda x: x % 2 == 0, a)))
print([x for x in a if x % 2 != 0])

# Comprehension is often preferred for clarity.

# 10) lower_bound / upper_bound
section("10. binary search family")

sorted_v = [1, 2, 2, 2, 4, 6, 8]

lb = bisect_left(sorted_v, 2)
ub = bisect_right(sorted_v, 2)

print("lower_bound:", lb)
print("upper_bound:", ub)
print("frequency:", ub - lb)

# Exact membership:
x = 4
i = bisect_left(sorted_v, x)
print(i < len(sorted_v) and sorted_v[i] == x)

# Search is O(log n).
# insort search is O(log n), but the actual list insertion is O(n).

# 11) reverse / rotate
section("11. rotate")

a = [1, 2, 3, 4, 5]
k = 2

rotated = a[k:] + a[:k]
print(rotated)

# Right rotation:
k %= len(a)
right_rotated = a[-k:] + a[:-k]
print(right_rotated)

# 12) permutations / combinations
section("12. permutations / combinations")

for p in permutations([1, 2, 3]):
    print(p)

print(list(combinations([1, 2, 3, 4], 2)))
print(list(combinations_with_replacement([1, 2, 3], 2)))

# Number of permutations: P(n,r) = n!/(n-r)!
# Number of combinations: C(n,r)

# 13) accumulate / prefix sums
section("13. accumulate")

a = [1, 2, 3, 4]
print(list(accumulate(a)))

print(list(accumulate(a, operator.mul)))
print(list(accumulate(a, max)))

# 14) gcd / lcm
section("14. gcd / lcm")

print(math.gcd(24, 18))
print(math.lcm(6, 8))

# 15) enumerate / zip
section("15. enumerate / zip")

for i, x in enumerate(a):
    print(i, x)

b = [10, 20, 30, 40]
for x, y in zip(a, b):
    print(x, y)

# 16) heapq basics
section("16. heap algorithms")

heap = [5, 1, 4, 2, 3]
heapq.heapify(heap)
print(heap)

heapq.heappush(heap, 0)
print(heap)

print(heapq.heappop(heap))
print(heap)

# Python heapq is a min-heap.

# 17) nsmallest / nlargest
section("17. nsmallest / nlargest")

values = [8, 1, 5, 2, 9, 3]
print(heapq.nsmallest(3, values))
print(heapq.nlargest(3, values))

# For small n these can be useful; for large n, sorted() may be preferable.

# 18) merge sorted inputs
section("18. merge")

x = [1, 3, 5]
y = [2, 4, 6]

print(list(heapq.merge(x, y)))

# heapq.merge assumes each input is already sorted and returns an iterator.

# 19) tuple/list lexicographical comparison
section("19. lexicographical comparison")

print((1, 5) < (2, 1))
print("apple" < "apply")

# This is useful for custom sorting keys and pair-like data.

# ============================================================
# EXTRAS / REFERENCE
# ============================================================

# 20) find-style substring helpers
section("EXTRAS: substring search")

s = "abracadabra"

print(s.find("cad"))
print(s.rfind("a"))
print(s.startswith("abra"))
print(s.endswith("bra"))

# 21) is-sorted helper
section("EXTRAS: is_sorted")

def is_sorted(seq):
    return all(a <= b for a, b in zip(seq, seq[1:]))

print(is_sorted([1, 2, 3, 4]))
print(is_sorted([1, 3, 2, 4]))

# 22) is_permutation via sorted
section("EXTRAS: is_permutation")

a = [1, 2, 3, 2]
b = [2, 3, 2, 1]

print(sorted(a) == sorted(b))

# O(n log n). Counter can make this O(n) average for hashable values:
from collections import Counter
print(Counter(a) == Counter(b))

# 23) unique / consecutive duplicate removal
section("EXTRAS: unique")

a = [1, 1, 2, 2, 2, 3, 1]

unique_all = list(dict.fromkeys(a))
print(unique_all)

def unique_consecutive(seq):
    return [x for i, x in enumerate(seq)
            if i == 0 or x != seq[i - 1]]

print(unique_consecutive(a))

# C++ std::unique removes only consecutive duplicates.
# Python does not have a direct built-in equivalent.

# 24) set operations
section("EXTRAS: set algorithms")

a = {1, 2, 3}
b = {2, 3, 4}

print(a | b)
print(a & b)
print(a - b)
print(a ^ b)

print(a.issubset({1, 2, 3, 4}))
print(a.issuperset({1, 2}))
print(a.isdisjoint({7, 8}))

# C++ set algorithms operate on sorted ranges and preserve multiplicity
# according to multiset-style sequence rules; Python set operations are
# mathematical sets and discard duplicates.

# 25) partition-style split
section("EXTRAS: partition-style")

a = [1, 2, 3, 4, 5, 6]

evens = [x for x in a if x % 2 == 0]
odds = [x for x in a if x % 2 != 0]

print(evens, odds)

# Unlike C++ partition(), this creates separate outputs rather than
# rearranging one list in place.

# 26) nth element / kth smallest
section("EXTRAS: kth selection")

a = [7, 1, 9, 2, 6, 3, 8]

k = 3  # zero-based index of desired element

# Simple Python reference implementation using sorted().
print(sorted(a)[k])

# For one-off CP problems this is often perfectly adequate.
# There is no direct built-in equivalent of C++ std::nth_element.

# 27) pairwise
section("EXTRAS: pairwise")

a = [1, 2, 4, 7]

print(list(pairwise(a)))

# 28) sliding / consecutive chunks with islice + zip
section("EXTRAS: consecutive windows")

a = [1, 2, 3, 4, 5]
k = 3

windows = zip(*(islice(a, i, None) for i in range(k)))
print([tuple(w) for w in windows])

# 29) chain
section("EXTRAS: chain")

print(list(chain([1, 2], [3, 4], [5])))

# 30) compress
section("EXTRAS: compress")

data = ["A", "B", "C", "D"]
selectors = [1, 0, 1, 0]

print(list(compress(data, selectors)))

# 31) product
section("EXTRAS: Cartesian product")

print(list(product([1, 2], ["a", "b"])))

# 32) groupby
section("EXTRAS: groupby")

data = [
    ("A", 1),
    ("A", 2),
    ("B", 3),
    ("B", 4),
]

for key, group in groupby(data, key=lambda x: x[0]):
    print(key, list(group))

# IMPORTANT: groupby groups consecutive equal keys.
# Sort first if you want all equal keys grouped.

# 33) insort
section("EXTRAS: sorted insertion")

a = [1, 2, 4, 5]
insort_left(a, 3)
print(a)

insort_right(a, 4)
print(a)

# Search is O(log n), but list insertion is O(n).

# 34) heap merge / custom key
section("EXTRAS: heapq.merge")

x = [(1, "a"), (4, "b")]
y = [(2, "c"), (3, "d")]

print(list(heapq.merge(x, y, key=lambda p: p[0])))

# 35) stable sorting / records
section("EXTRAS: stable sort")

records = [
    ("A", 2),
    ("B", 1),
    ("C", 2),
]

print(sorted(records, key=lambda x: x[1]))

# Python's sort is stable: records with equal keys retain relative order.

# 36) reduce
section("EXTRAS: reduce")

a = [1, 2, 3, 4]

print(reduce(operator.add, a, 0))
print(reduce(operator.mul, a, 1))

# Prefer sum()/math.prod() for simple standard operations.

# 37) random shuffle / sample
section("EXTRAS: randomness")

a = [1, 2, 3, 4, 5]
random.shuffle(a)
print(a)
print(random.sample(a, 3))

# 38) copy / deep copy
section("EXTRAS: copying")

import copy

a = [[1, 2], [3, 4]]
b = copy.copy(a)
c = copy.deepcopy(a)

b[0].append(99)
print("shallow:", a, b)
print("deep:", c)

# ============================================================
# QUICK ALGORITHM MAPPING
# ============================================================

section("Quick mapping")

mapping = {
    "C++ find": "x in list / list.index / str.find",
    "C++ count": "list.count / str.count / Counter",
    "C++ all_of": "all(...)",
    "C++ any_of": "any(...)",
    "C++ none_of": "not any(...)",
    "C++ sort": "sorted(...) / list.sort()",
    "C++ reverse": "reversed(...) / [::-1]",
    "C++ lower_bound": "bisect_left",
    "C++ upper_bound": "bisect_right",
    "C++ next_permutation": "itertools.permutations (different iteration model)",
    "C++ accumulate": "itertools.accumulate",
    "C++ heap": "heapq",
    "C++ merge": "heapq.merge for sorted inputs",
    "C++ unique": "no direct equivalent; custom consecutive pass",
    "C++ nth_element": "no direct built-in equivalent",
    "C++ set_union": "set | set",
    "C++ transform": "map / comprehension",
    "C++ remove_if": "filter / comprehension",
}

for k, value in mapping.items():
    print(f"{k:22} -> {value}")

print("\nAll Python algorithm examples completed.")
