# Python DSA Libraries — Standard Library Toolbox
#
# PURPOSE
# -------
# This is the LANGUAGE TOOLBOX layer, not a replacement for the individual
# data-structure sheets.
#
# Detailed structures:
#   list / array-like     -> Arrays sheet
#   str                   -> Strings sheet
#   set                   -> Sets sheet
#   dict                  -> Maps sheet
#   deque / heap           -> Queues sheet
#   bit operations        -> Bitset sheet
#   generic algorithms    -> Algorithms sheet
#
# Here we focus on:
#   1) which standard-library tool to reach for
#   2) Python's DSA-oriented modules
#   3) important semantics and traps
#
# Python 3.x

from collections import Counter, defaultdict, deque, OrderedDict, namedtuple
from bisect import bisect_left, bisect_right, bisect, insort_left, insort_right, insort
from functools import lru_cache, reduce
from itertools import (
    accumulate,
    chain,
    combinations,
    combinations_with_replacement,
    compress,
    cycle,
    groupby,
    islice,
    pairwise,
    permutations,
    product,
    repeat,
    zip_longest,
)
import heapq
import math
import operator
import random
import string


def section(title: str) -> None:
    print(f"\n===== {title} =====")


# ============================================================
# CORE / MUST KNOW
# ============================================================

# ------------------------------------------------------------
# 1. Built-in algorithmic helpers
# ------------------------------------------------------------
section("1. Built-in DSA Helpers")

arr = [5, 1, 4, 2, 3]

print(sorted(arr))                  # new list
arr.sort()                          # in-place
print(arr)

print(min(arr))
print(max(arr))
print(sum(arr))
print(len(arr))

print(any(x > 4 for x in arr))
print(all(x > 0 for x in arr))

for i, x in enumerate(arr):
    print(i, x)

for x, y in zip(arr, [10, 20, 30, 40, 50]):
    print(x, y)

print(list(reversed(arr)))
print(list(range(5)))

# ------------------------------------------------------------
# 2. list methods worth knowing
# ------------------------------------------------------------
section("2. List Toolbox")

a = [1, 2, 3]

a.append(4)
a.extend([5, 6])
a.insert(1, 99)

print(a)

print(a.pop())
print(a.pop(1))

a.remove(2)             # removes first matching value
print(a)

print(a.count(3))
print(a.index(3))

a.reverse()
print(a)

# copy
b = a.copy()
print(b)

# Sort
b.sort(reverse=True)
print(b)

# Data-structure sheets contain the detailed list operation table.

# ------------------------------------------------------------
# 3. deque
# ------------------------------------------------------------
section("3. collections.deque")

d = deque([1, 2, 3])

d.append(4)
d.appendleft(0)

print(d.pop())
print(d.popleft())

d.extend([5, 6])
d.extendleft([-1, 0])

print(d)

d.rotate(2)
print(d)

print(d[0])
print(len(d))

# Core use:
# queue, BFS, sliding window, double-ended operations.
#
# End insertion/removal: O(1) typical/documented.
# Random indexing is not the main use case.

# ------------------------------------------------------------
# 4. Counter
# ------------------------------------------------------------
section("4. Counter")

c = Counter([1, 2, 2, 3, 3, 3])

print(c[2])
print(c[99])                  # 0
print(c.most_common(2))
print(list(c.elements()))

c.update([3, 4])
c.subtract([2])

c2 = Counter([3, 4, 4])

print(c + c2)
print(c - c2)
print(c & c2)
print(c | c2)

# Core use:
# frequency counting, anagrams, top frequencies.

# ------------------------------------------------------------
# 5. defaultdict
# ------------------------------------------------------------
section("5. defaultdict")

freq = defaultdict(int)
freq["a"] += 1
freq["a"] += 1

groups = defaultdict(list)
groups["even"].append(2)
groups["even"].append(4)

neighbors = defaultdict(set)
neighbors[1].add(2)

print(freq)
print(groups)
print(neighbors)

# Very common:
# defaultdict(int)  -> frequency
# defaultdict(list) -> grouping / adjacency list
# defaultdict(set)  -> unique grouping

# ------------------------------------------------------------
# 6. heapq
# ------------------------------------------------------------
section("6. heapq")

heap = [5, 1, 4, 2, 3]
heapq.heapify(heap)

print(heap)
heapq.heappush(heap, 0)
print(heap)

print(heapq.heappop(heap))
print(heap)

print(heap[0])  # smallest without popping

print(heapq.heappushpop(heap, -1))
print(heapq.heapreplace(heap, 7))

print(heapq.nsmallest(3, [8, 1, 5, 2, 9]))
print(heapq.nlargest(3, [8, 1, 5, 2, 9]))

# Min-heap is native.
# Max-heap trick:
max_heap = []
heapq.heappush(max_heap, -10)
heapq.heappush(max_heap, -5)

print(-heapq.heappop(max_heap))

# merge sorted iterables lazily
print(list(heapq.merge([1, 3, 5], [2, 4, 6])))

# ------------------------------------------------------------
# 7. bisect
# ------------------------------------------------------------
section("7. bisect")

sorted_arr = [1, 3, 3, 3, 5, 7]

print(bisect_left(sorted_arr, 3))
print(bisect_right(sorted_arr, 3))
print(bisect(sorted_arr, 3))

print(bisect_left(sorted_arr, 4))

x = [1, 3, 5]
insort_left(x, 2)
insort_right(x, 3)
insort(x, 4)

print(x)

# bisect_left  = C++ lower_bound
# bisect_right = C++ upper_bound
#
# Search: O(log n)
# Actual insertion into Python list: O(n)

# ------------------------------------------------------------
# 8. itertools: combinatorics
# ------------------------------------------------------------
section("8. itertools Combinatorics")

print(list(combinations([1, 2, 3], 2)))
print(list(combinations_with_replacement([1, 2, 3], 2)))
print(list(permutations([1, 2, 3], 2)))
print(list(product([1, 2], ["a", "b"])))

# Number of generated outputs can itself be enormous.
# The iterator is lazy until materialized.

# ------------------------------------------------------------
# 9. itertools: accumulation / iteration
# ------------------------------------------------------------
section("9. itertools Iteration")

print(list(accumulate([1, 2, 3, 4])))
print(list(accumulate([1, 2, 3, 4], operator.mul)))
print(list(accumulate([1, 4, 2, 7], max)))

print(list(chain([1, 2], [3, 4], [5])))
print(list(compress(["A", "B", "C", "D"], [1, 0, 1, 0])))
print(list(islice(range(10), 2, 8, 2)))
print(list(pairwise([1, 2, 4, 7])))

# ------------------------------------------------------------
# 10. groupby
# ------------------------------------------------------------
section("10. itertools.groupby")

data = [
    ("A", 1),
    ("A", 2),
    ("B", 3),
    ("B", 4),
]

for key, group in groupby(data, key=lambda x: x[0]):
    print(key, list(group))

# IMPORTANT:
# groupby groups consecutive equal keys.
# Sort by key first if global grouping is required.

# ------------------------------------------------------------
# 11. functools.lru_cache
# ------------------------------------------------------------
section("11. functools.lru_cache")

@lru_cache(maxsize=None)
def fib(n: int) -> int:
    if n < 2:
        return n
    return fib(n - 1) + fib(n - 2)

print(fib(10))
print(fib.cache_info())

# DSA use:
# memoization in recursion / DP.

# ------------------------------------------------------------
# 12. gcd / lcm / product
# ------------------------------------------------------------
section("12. math toolbox")

print(math.gcd(48, 18))
print(math.lcm(12, 8))
print(math.isqrt(100))
print(math.sqrt(16))
print(math.factorial(5))
print(math.prod([2, 3, 4]))

print(math.ceil(4.3))
print(math.floor(4.7))
print(math.log2(8))
print(math.log10(100))

print(math.isfinite(10))
print(math.isinf(float("inf")))

# ------------------------------------------------------------
# 13. Infinity
# ------------------------------------------------------------
section("13. Infinity")

INF = float("inf")
NEG_INF = float("-inf")

print(INF, NEG_INF)
print(INF > 10**1000)

# ------------------------------------------------------------
# 14. strings module
# ------------------------------------------------------------
section("14. string constants")

print(string.ascii_lowercase)
print(string.ascii_uppercase)
print(string.ascii_letters)
print(string.digits)
print(string.hexdigits)

# Useful for character-class construction.

# ------------------------------------------------------------
# 15. random toolbox
# ------------------------------------------------------------
section("15. random")

sample_data = [1, 2, 3, 4, 5]

print(random.choice(sample_data))
print(random.sample(sample_data, 3))

random.shuffle(sample_data)
print(sample_data)

# Useful mainly for testing / randomized experiments.

# ------------------------------------------------------------
# 16. identity / copying helpers
# ------------------------------------------------------------
section("16. Identity / copying")

a = [1, 2]
b = a
c = a.copy()

print(a == b, a is b)
print(a == c, a is c)

# == -> value equality
# is -> identity

# ============================================================
# EXTRAS / REFERENCE
# ============================================================

# ------------------------------------------------------------
# 17. OrderedDict
# ------------------------------------------------------------
section("EXTRAS: OrderedDict")

od = OrderedDict([
    ("a", 1),
    ("b", 2),
    ("c", 3),
])

od.move_to_end("a")
od.move_to_end("c", last=False)

print(od.popitem())
print(od.popitem(last=False))

# Modern dict preserves insertion order.
# OrderedDict is still useful for its specialized reordering/pop APIs.

# ------------------------------------------------------------
# 18. namedtuple
# ------------------------------------------------------------
section("EXTRAS: namedtuple")

Point = namedtuple("Point", ["x", "y"])

p = Point(1, 2)

print(p.x, p.y)
print(p[0], p[1])

# Immutable tuple-like record.

# ------------------------------------------------------------
# 19. zip_longest
# ------------------------------------------------------------
section("EXTRAS: zip_longest")

print(list(zip_longest([1, 2], [10, 20, 30], fillvalue=0)))

# Normal zip stops at the shortest input.

# ------------------------------------------------------------
# 20. cycle / repeat
# ------------------------------------------------------------
section("EXTRAS: cycle / repeat")

print(list(islice(cycle([1, 2, 3]), 7)))
print(list(repeat(5, 3)))

# ------------------------------------------------------------
# 21. reduce
# ------------------------------------------------------------
section("EXTRAS: reduce")

print(reduce(operator.add, [1, 2, 3, 4], 0))
print(reduce(operator.mul, [1, 2, 3, 4], 1))

# Prefer sum()/math.prod() for simple standard operations.

# ------------------------------------------------------------
# 22. partial
# ------------------------------------------------------------
section("EXTRAS: partial")

from functools import partial

def multiply(a: int, b: int) -> int:
    return a * b

double = partial(multiply, 2)
triple = partial(multiply, 3)

print(double(5))
print(triple(4))

# Low priority for ordinary DSA.

# ------------------------------------------------------------
# 23. sorted keys / advanced sorting
# ------------------------------------------------------------
section("EXTRAS: sorting patterns")

words = ["apple", "pie", "banana"]

print(sorted(words, key=len))

pairs = [(2, 5), (1, 9), (2, 3), (1, 4)]

print(sorted(
    pairs,
    key=lambda p: (p[0], -p[1])
))

# Python sort is stable.

# ------------------------------------------------------------
# 24. set operations
# ------------------------------------------------------------
section("EXTRAS: set toolbox")

s1 = {1, 2, 3}
s2 = {3, 4, 5}

print(s1 | s2)
print(s1 & s2)
print(s1 - s2)
print(s1 ^ s2)

print(s1.issubset({1, 2, 3, 4}))
print(s1.isdisjoint({7, 8}))

# Detailed operations -> Sets sheet.

# ------------------------------------------------------------
# 25. dictionary toolbox
# ------------------------------------------------------------
section("EXTRAS: dict toolbox")

d = {"a": 1}

print(d.get("missing"))
d.setdefault("b", 0)
d.update({"c": 3})

print(d.pop("a"))
print(d)

# Merge (Python 3.9+):
left = {"a": 1, "b": 2}
right = {"b": 20, "c": 30}

print(left | right)

# Detailed dict operations -> Maps sheet.

# ------------------------------------------------------------
# 26. matrix / transpose idiom
# ------------------------------------------------------------
section("EXTRAS: transpose")

matrix = [
    [1, 2, 3],
    [4, 5, 6],
]

transpose = [list(col) for col in zip(*matrix)]
print(transpose)

# ------------------------------------------------------------
# 27. heap of tuples
# ------------------------------------------------------------
section("EXTRAS: heap tuples")

heap = []

heapq.heappush(heap, (2, "task-B"))
heapq.heappush(heap, (1, "task-A"))
heapq.heappush(heap, (3, "task-C"))

print(heapq.heappop(heap))

# Tuples compare lexicographically, so the first field is the primary key.

# ------------------------------------------------------------
# 28. lru_cache trap
# ------------------------------------------------------------
section("EXTRAS: lru_cache rules")

# Arguments supplied to a cached function must be hashable.
# Lists cannot be used directly as cache keys.
#
# Good:
@lru_cache(maxsize=None)
def ways(n: int, k: int) -> int:
    if n == 0:
        return 1
    if n < 0:
        return 0
    return ways(n - 1, k) + ways(n - 2, k) if n >= 2 else ways(n - 1, k)

print(ways(6, 0))

# ============================================================
# QUICK DECISION GUIDE
# ============================================================

section("Quick Decision Guide")

guide = [
    ("Need a dynamic array", "list"),
    ("Need both-end O(1) queue/deque operations", "collections.deque"),
    ("Need frequency counts", "collections.Counter"),
    ("Need automatic dictionary defaults", "collections.defaultdict"),
    ("Need a min-heap / priority queue", "heapq"),
    ("Need kth/smallest-largest subset", "heapq.nsmallest / nlargest"),
    ("Need binary-search boundaries", "bisect"),
    ("Need combinations/permutations", "itertools"),
    ("Need prefix/running aggregation", "itertools.accumulate"),
    ("Need memoization", "functools.lru_cache"),
    ("Need gcd/lcm/integer math", "math"),
]

for need, tool in guide:
    print(f"{need:38} -> {tool}")

print("\nPython DSA library toolbox completed.")
