# Algorithms — C++ vs Python
### DSA / Competitive Programming / Interview Cheat Sheet

> **Purpose:** A systematic catalog of reusable algorithms for arrays, strings, sorted ranges, sets, permutations, heaps, numeric sequences, and iterator/range manipulation.
>
> **Important:** In C++, these algorithms are mostly generic `<algorithm>` / `<numeric>` functions operating on iterator ranges. Python spreads the equivalent functionality across built-ins, list methods, `bisect`, `itertools`, `heapq`, `math`, and a few standard idioms.
>
> The source notes supplied for this topic are preserved as the starting point, with outdated/ambiguous points cleaned up.

---

# CORE / MUST KNOW

## 1. Master Mapping

| Category | C++ | Python | Typical TC |
|---|---|---|---|
| Iterate | `for_each` | `for` / comprehension | O(n) |
| Search | `find`, `find_if` | `in`, `index`, `find` | O(n) |
| Count | `count`, `count_if` | `.count()`, `Counter` | O(n) |
| Predicate | `all_of`, `any_of`, `none_of` | `all`, `any`, `not any` | O(n) |
| Sort | `sort`, `stable_sort` | `sorted`, `.sort()` | O(n log n) |
| Reverse | `reverse` | `reverse()`, `reversed`, `[::-1]` | O(n) |
| Rotate | `rotate` | slicing | O(n) |
| Fill | `fill` | repetition / slice assignment | O(n) |
| Replace | `replace`, `replace_if` | comprehension / `str.replace` | O(n) |
| Remove | `remove_if` + `erase` | comprehension / `filter` | O(n) |
| Unique | `unique` + `erase` | custom consecutive pass | O(n) |
| Binary search | `binary_search` | `bisect` + equality check | O(log n) on list |
| Lower bound | `lower_bound` | `bisect_left` | O(log n) |
| Upper bound | `upper_bound` | `bisect_right` | O(log n) |
| Permutations | `next_permutation` | `itertools.permutations` | O(n) / permutation output |
| Merge | `merge` | `heapq.merge` | O(n+m) stream |
| Min/Max | `min_element` / `max_element` | `min` / `max` | O(n) |
| Accumulate | `accumulate` / `partial_sum` | `itertools.accumulate` | O(n) |
| GCD / LCM | `gcd` / `lcm` | `math.gcd` / `math.lcm` | ~O(log n) |
| Heap | `make_heap` etc. | `heapq` | O(log n) updates |
| K-th selection | `nth_element` | no direct built-in | C++ avg O(n) |

---

## 2. Generic Algorithm Model in C++

Most classic algorithms look like:

```cpp
algorithm(first, last, ...);
```

Example:

```cpp
sort(v.begin(), v.end());
find(v.begin(), v.end(), x);
count(v.begin(), v.end(), x);
reverse(v.begin(), v.end());
```

The range is conventionally:

```text
[first, last)
```

meaning `first` is included and `last` is excluded.

---

# SEARCHING

## 3. `find()`

```cpp
auto it = find(v.begin(), v.end(), x);

if (it != v.end()) {
    int index = it - v.begin();
}
```

Returns an iterator to the first matching element, or `end()`.

| Property | Value |
|---|---|
| TC | O(n) worst |
| SC | O(1) |
| Returns | iterator |

For `vector`, convert iterator to index using:

```cpp
it - v.begin()
```

or generically:

```cpp
distance(v.begin(), it)
```

---

## 4. `find_if()` / `find_if_not()`

```cpp
auto it = find_if(
    v.begin(), v.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

```cpp
auto it = find_if_not(
    v.begin(), v.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

| Property | Value |
|---|---|
| TC | O(n) worst |
| SC | O(1) |

### Python

```python
next((x for x in arr if condition(x)), default)
```

Usually a normal loop is clearer.

---

## 5. `count()` / `count_if()`

```cpp
count(v.begin(), v.end(), x);

count_if(
    v.begin(), v.end(),
    [](int x) { return x % 2 == 0; }
);
```

| Property | Value |
|---|---|
| TC | O(n) |
| SC | O(1) |

### Python

```python
arr.count(x)
sum(x % 2 == 0 for x in arr)
```

For repeated frequency queries:

```python
from collections import Counter
freq = Counter(arr)
```

---

# PREDICATES

## 6. `all_of()` / `any_of()` / `none_of()`

```cpp
all_of(v.begin(), v.end(), pred);
any_of(v.begin(), v.end(), pred);
none_of(v.begin(), v.end(), pred);
```

Python equivalents:

```python
all(pred(x) for x in arr)
any(pred(x) for x in arr)
not any(pred(x) for x in arr)
```

All can short-circuit.

| Algorithm | Worst TC | SC |
|---|---:|---:|
| `all_of` | O(n) | O(1) |
| `any_of` | O(n) | O(1) |
| `none_of` | O(n) | O(1) |

---

# SORTING

## 7. `sort()`

```cpp
sort(v.begin(), v.end());

sort(v.begin(), v.end(), greater<int>());
```

Custom comparator:

```cpp
sort(v.begin(), v.end(),
     [](const auto& a, const auto& b) {
         return a > b;
     });
```

| Property | Value |
|---|---|
| TC | O(n log n) |
| Stable? | **No** |
| In-place? | Yes |

C++'s `std::sort` does not guarantee preservation of the relative order of equivalent elements. citeturn725974search2

### Python

```python
sorted(arr)              # new list
arr.sort()               # in-place

sorted(arr, reverse=True)

sorted(arr, key=lambda x: ...)
```

Python sorting is stable.

---

## 8. `stable_sort()`

```cpp
stable_sort(v.begin(), v.end(), comp);
```

Equivalent elements retain relative order.

Typical:

```text
TC: O(n log n)
SC: O(n) when auxiliary memory is available
```

Use it when stability matters.

---

# REORDERING

## 9. `reverse()`

```cpp
reverse(v.begin(), v.end());
```

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python:

```python
arr.reverse()       # in-place
reversed(arr)       # iterator
arr[::-1]           # new list
```

---

## 10. `rotate()`

```cpp
rotate(v.begin(), v.begin() + k, v.end());
```

Example:

```text
[1 2 3 4 5], k=2
→ [3 4 5 1 2]
```

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python:

```python
rotated = arr[k:] + arr[:k]
```

---

## 11. `fill()` / `fill_n()`

```cpp
fill(v.begin(), v.end(), 0);

fill_n(v.begin(), 5, 7);
```

| TC | SC |
|---:|---:|
| O(n) over written range | O(1) |

Python:

```python
arr = [0] * n
```

or:

```python
arr[l:r] = [7] * (r - l)
```

---

# MODIFYING

## 12. `replace()` / `replace_if()`

```cpp
replace(v.begin(), v.end(), oldValue, newValue);

replace_if(
    v.begin(), v.end(),
    [](int x) { return x < 0; },
    0
);
```

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python:

```python
arr = [new if x == old else x for x in arr]
```

For strings:

```python
s = s.replace(old, new)
```

---

## 13. `remove()` / `remove_if()`

### The critical C++ pattern

```cpp
v.erase(
    remove(v.begin(), v.end(), x),
    v.end()
);
```

For predicates:

```cpp
v.erase(
    remove_if(v.begin(), v.end(),
              [](int x) { return x % 2 == 0; }),
    v.end()
);
```

`remove()` does **not** change the container's size. It rearranges the range and returns the new logical end.

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python:

```python
arr = [x for x in arr if x != value]
```

---

## 14. `unique()`

```cpp
v.erase(
    unique(v.begin(), v.end()),
    v.end()
);
```

### Important

`unique()` removes **consecutive** duplicates only.

```text
1 1 2 2 3 1
↓
1 2 3 1
```

The final `1` remains because it was not adjacent to the first `1`.

If all duplicates should be grouped:

```cpp
sort(v.begin(), v.end());

v.erase(
    unique(v.begin(), v.end()),
    v.end()
);
```

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python has no direct equivalent:

```python
[x for i, x in enumerate(arr)
 if i == 0 or x != arr[i - 1]]
```

---

# BINARY SEARCH

## 15. `binary_search()`

```cpp
bool exists =
    binary_search(v.begin(), v.end(), x);
```

Returns only `true/false`.

Requires the range to satisfy the required ordering/partition condition.

For a normally sorted vector:

| TC | SC |
|---:|---:|
| O(log n) comparisons | O(1) |

---

## 16. `lower_bound()`

```cpp
auto it =
    lower_bound(v.begin(), v.end(), x);
```

Returns the first element:

```text
>= x
```

Index:

```cpp
int pos = lower_bound(
    v.begin(), v.end(), x
) - v.begin();
```

Python:

```python
from bisect import bisect_left

pos = bisect_left(arr, x)
```

| Typical vector TC | SC |
|---:|---:|
| O(log n) | O(1) |

**Important:** for `std::map` / `std::set`, prefer the container's member `lower_bound()`. Generic `std::lower_bound()` on their non-random-access iterators can require linear iterator movement. citeturn725974search3

---

## 17. `upper_bound()`

Returns the first element:

```text
> x
```

```cpp
int pos =
    upper_bound(v.begin(), v.end(), x)
    - v.begin();
```

Python:

```python
bisect_right(arr, x)
```

---

## 18. `equal_range()`

Equivalent to finding both boundaries:

```cpp
auto [L, R] =
    equal_range(v.begin(), v.end(), x);

int frequency = R - L;
```

Python:

```python
L = bisect_left(arr, x)
R = bisect_right(arr, x)
frequency = R - L
```

| TC on vector/list | O(log n) |
|---|---:|
| Extra SC | O(1) |

---

# MIN / MAX

## 19. `min()` / `max()`

```cpp
min(a, b);
max(a, b);

min({1, 5, 2, 9});
max({1, 5, 2, 9});
```

Python:

```python
min(a, b)
max(a, b)
min(arr)
max(arr)
```

---

## 20. `min_element()` / `max_element()`

```cpp
auto mn = min_element(v.begin(), v.end());
auto mx = max_element(v.begin(), v.end());
```

For the actual value:

```cpp
*mn
*mx
```

| TC | SC |
|---:|---:|
| O(n) | O(1) |

Python:

```python
min(arr)
max(arr)
```

---

## 21. `minmax()` / `minmax_element()`

```cpp
auto [mn, mx] =
    minmax(a, b);

auto [mnIt, mxIt] =
    minmax_element(v.begin(), v.end());
```

The range form finds both with fewer comparisons than two completely independent scans.

TC:

```text
O(n)
```

---

# PERMUTATIONS

## 22. `next_permutation()`

```cpp
sort(v.begin(), v.end());

do {
    // process v
} while (next_permutation(v.begin(), v.end()));
```

Returns:

```text
true  → next lexicographical permutation exists
false → wrapped past the last permutation
```

Each call:

```text
TC O(n)
SC O(1)
```

### Critical point

The current arrangement is **not automatically processed** by `next_permutation()`.

That is why the common enumeration pattern uses:

```cpp
do {
    ...
} while (next_permutation(...));
```

If you want all permutations exactly once in lexicographical order, start from sorted order.

---

## 23. `prev_permutation()`

```cpp
do {
    ...
} while (prev_permutation(
    v.begin(), v.end()
));
```

Works in reverse lexicographical order.

---

## 24. `is_permutation()`

```cpp
bool same =
    is_permutation(
        a.begin(), a.end(),
        b.begin(), b.end()
    );
```

Checks whether two ranges contain equivalent elements with equivalent multiplicities.

Generic complexity can be quadratic depending on the iterator/value behavior, so do not blindly label it O(n).

For hashable Python values:

```python
Counter(a) == Counter(b)
```

or:

```python
sorted(a) == sorted(b)
```

with O(n log n) sorting.

---

# MERGING

## 25. `merge()`

```cpp
merge(
    a.begin(), a.end(),
    b.begin(), b.end(),
    out.begin()
);
```

**Both input ranges must already be sorted.**

It writes into a separate destination range.

```text
TC: O(n + m)
SC: O(1) algorithm workspace
     + destination storage
```

### Python

```python
from heapq import merge

result = list(merge(a, b))
```

`heapq.merge()` lazily merges already-sorted inputs. citeturn360523search2

---

## 26. `inplace_merge()`

```cpp
inplace_merge(
    v.begin(),
    middle,
    v.end()
);
```

Merges two consecutive sorted subranges:

```text
[first, middle)
[middle, last)
```

while keeping the result inside the original range.

---

# SET ALGORITHMS

## 27. Set Algorithm Family

These operate on **sorted ranges**, not arbitrary `std::set` containers specifically.

```cpp
set_union
set_intersection
set_difference
set_symmetric_difference
includes
```

Example:

```cpp
set_intersection(
    a.begin(), a.end(),
    b.begin(), b.end(),
    back_inserter(result)
);
```

Typical TC:

```text
O(n + m)
```

### Python

For actual mathematical sets:

```python
a | b
a & b
a - b
a ^ b
a.issubset(b)
```

**Important distinction:** C++ set algorithms operate on sorted sequences and retain duplicate multiplicities according to their sequence rules. Python `set` removes duplicates by definition.

---

# PARTITIONING

## 28. `partition()`

```cpp
auto mid = partition(
    v.begin(), v.end(),
    [](int x) {
        return x % 2 == 0;
    }
);
```

Afterwards:

```text
[first, mid) → predicate true
[mid, last)  → predicate false
```

Relative order is **not preserved**.

| TC | Typical SC |
|---:|---:|
| O(n) | O(1) |

---

## 29. `stable_partition()`

Same grouping idea, but relative order inside the groups is preserved.

```cpp
stable_partition(
    v.begin(), v.end(),
    pred
);
```

Usually requires extra memory for efficient linear-time behavior; without enough memory, it can use a slower fallback.

---

# PARTIAL / SELECTIVE SORTING

## 30. `nth_element()`

One of the most useful less-obvious algorithms.

```cpp
nth_element(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

Afterwards:

```text
v[k] = element that would be at index k
       if the entire array were sorted
```

But:

```text
The whole array is NOT sorted.
```

Elements before `k` are not necessarily sorted.

### Typical complexity

```text
Average: O(n)
Worst-case: O(n log n) complexity guarantee
```

This is a direct tool for kth-smallest / kth-largest style problems.

---

## 31. `partial_sort()`

```cpp
partial_sort(
    v.begin(),
    v.begin() + k,
    v.end()
);
```

Afterwards, the first `k` elements are sorted and contain the smallest `k` elements.

Typical complexity:

```text
O(n log k)
```

Useful when you need the smallest `k` elements in sorted order.

---

# HEAPS

## 32. Heap Algorithms

```cpp
make_heap(v.begin(), v.end());

push_heap(v.begin(), v.end());

pop_heap(v.begin(), v.end());

sort_heap(v.begin(), v.end());
```

Default heap:

```text
max-heap
```

Typical complexities:

| Operation | TC |
|---|---:|
| `make_heap` | O(n) |
| `push_heap` | O(log n) |
| `pop_heap` | O(log n) |
| `sort_heap` | O(n log n) |

For normal CP use, `priority_queue` is often more convenient.

### Python

```python
import heapq

heapq.heapify(a)          # O(n)
heapq.heappush(heap, x)   # O(log n)
heapq.heappop(heap)       # O(log n)
```

Python's `heapq` is a **min-heap**.

---

# ITERATOR UTILITIES

## 33. `distance()`

```cpp
auto it = find(v.begin(), v.end(), x);

auto index =
    distance(v.begin(), it);
```

Prefer:

```cpp
auto index = ...
```

rather than forcing the result into `int`, because the return type is the iterator's `difference_type`.

Complexity:

```text
random-access iterator → O(1)
other iterator types   → may be O(n)
```

---

## 34. `next()` / `prev()` / `advance()`

```cpp
auto it2 = next(it, 3);
auto it3 = prev(v.end(), 2);

advance(it, 5);
```

`next()` / `prev()` return a new iterator.

`advance()` modifies the iterator itself.

Complexity depends on iterator category.

---

# TRANSFORMATION / COPY

## 35. `transform()`

Unary:

```cpp
transform(
    v.begin(), v.end(),
    v.begin(),
    [](int x) {
        return x * x;
    }
);
```

Binary:

```cpp
transform(
    a.begin(), a.end(),
    b.begin(),
    out.begin(),
    plus<int>()
);
```

Typical TC:

```text
O(n)
```

Python:

```python
[x * x for x in arr]

[x + y for x, y in zip(a, b)]
```

---

## 36. `copy()` / `copy_if()`

```cpp
copy(
    a.begin(), a.end(),
    out.begin()
);
```

```cpp
copy_if(
    a.begin(), a.end(),
    back_inserter(out),
    pred
);
```

Typical TC:

```text
O(n)
```

Python:

```python
b = a.copy()

filtered = [x for x in a if pred(x)]
```

---

# NUMERIC ALGORITHMS

## 37. `iota()`

```cpp
vector<int> v(5);

iota(v.begin(), v.end(), 1);

// 1 2 3 4 5
```

TC:

```text
O(n)
```

Python:

```python
list(range(1, 6))
```

---

## 38. `accumulate()`

```cpp
int sum =
    accumulate(
        v.begin(), v.end(), 0
    );
```

Product:

```cpp
long long product =
    accumulate(
        v.begin(), v.end(), 1LL,
        multiplies<long long>()
    );
```

### Critical type trap

```cpp
accumulate(v.begin(), v.end(), 0);
```

uses an `int` accumulator.

For `long long`:

```cpp
accumulate(v.begin(), v.end(), 0LL);
```

Typical TC:

```text
O(n)
```

Python:

```python
from itertools import accumulate

prefix = list(accumulate(arr))
```

`itertools.accumulate()` also supports a custom binary operation. citeturn360523search1

---

# EXTRAS / REFERENCE

## 39. Search Algorithms You Don't Need Daily

> `search_n(first, last, count, value)` returns an iterator to the first run of `count`
> consecutive matching values. It does not return a boolean.


| C++ | Meaning | Typical TC |
|---|---|---:|
| `search` | Find a subsequence | O(nm) worst |
| `search_n` | Find n consecutive equal/predicate values | O(n) to O(nm), depending on conditions |
| `find_end` | Last occurrence of a subsequence | O(nm) worst |
| `find_first_of` | First element matching any from another range | O(nm) worst |
| `adjacent_find` | Find consecutive equivalent elements | O(n) |

---

## 40. `equal()` / `mismatch()`

```cpp
equal(a.begin(), a.end(), b.begin());
```

Checks corresponding elements.

```cpp
auto [it1, it2] =
    mismatch(
        a.begin(), a.end(),
        b.begin(), b.end()
    );
```

Typical TC:

```text
O(n)
```

Both can stop early.

---

## 41. More Copy Algorithms

```cpp
copy_n(...)
copy_backward(...)
```

`copy_backward` is useful when the source and destination overlap in the appropriate direction.

---

## 42. `generate()` / `generate_n()`

```cpp
int x = 1;

generate(v.begin(), v.end(), [&x] {
    return x++;
});
```

Typical:

```text
O(n)
```

---

## 43. `shift_left()` / `shift_right()`

C++20:

```cpp
shift_left(v.begin(), v.end(), k);
shift_right(v.begin(), v.end(), k);
```

Useful for shifting elements without writing manual loops.

---

## 44. `shuffle()` / `sample()`

Use:

```cpp
shuffle(
    v.begin(), v.end(),
    rng
);
```

Do **not** use:

```cpp
random_shuffle(...)
```

`random_shuffle` was removed from modern C++. `shuffle` is the current standard algorithm. citeturn725974search0

Random sample:

```cpp
sample(
    v.begin(), v.end(),
    back_inserter(out),
    k,
    rng
);
```

---

## 45. Lexicographical Comparison

```cpp
lexicographical_compare(
    a.begin(), a.end(),
    b.begin(), b.end()
);
```

Conceptually similar to dictionary ordering:

```text
"apple" < "apply"
```

Python:

```python
"apple" < "apply"
(1, 5) < (2, 1)
```

---

# PYTHON-SPECIFIC ALGORITHM TOOLBOX

## 46. `bisect`

```python
from bisect import bisect_left, bisect_right

L = bisect_left(arr, x)
R = bisect_right(arr, x)
```

Equivalent mental model:

```text
bisect_left  = lower_bound
bisect_right = upper_bound
```

Both search for insertion positions in a sorted sequence. The search is O(log n), but inserting into a Python list is O(n) because elements must be shifted. citeturn360523search0

---

## 47. `insort`

```python
from bisect import insort_left

insort_left(arr, x)
```

Maintains sorted order.

Important:

```text
search: O(log n)
actual list insertion: O(n)
overall: O(n)
```

---

## 48. `itertools.permutations`

```python
from itertools import permutations

for p in permutations(arr):
    ...
```

For all permutations of n unique elements:

```text
n!
```

outputs.

Python's iterator is lazy, but storing all permutations is enormous.

---

## 49. `combinations`

```python
from itertools import combinations

for c in combinations(arr, r):
    ...
```

Number of outputs:

```text
C(n, r)
```

Also:

```python
combinations_with_replacement(arr, r)
```

---

## 50. `product`

Cartesian product:

```python
from itertools import product

for x in product(A, B):
    ...
```

Equivalent conceptually to nested loops.

---

## 51. `accumulate`

```python
from itertools import accumulate

prefix = list(accumulate(arr))
```

Custom operation:

```python
list(accumulate(arr, max))
```

Running product:

```python
list(accumulate(arr, operator.mul))
```

`accumulate` returns an iterator and supports a custom binary function. citeturn360523search1

---

## 52. `heapq`

Core:

```python
heapq.heapify(heap)
heapq.heappush(heap, x)
heapq.heappop(heap)
```

Also:

```python
heapq.nsmallest(k, arr)
heapq.nlargest(k, arr)
heapq.merge(a, b, c)
```

`heapq.merge()` expects already-sorted inputs and lazily yields merged values. `nsmallest()` / `nlargest()` are particularly useful when `k` is small. citeturn360523search5

---

## 53. `chain`

```python
from itertools import chain

list(chain(a, b, c))
```

Conceptually:

```text
a followed by b followed by c
```

without requiring one giant intermediate list.

---

## 54. `compress`

```python
from itertools import compress

list(compress(data, selectors))
```

Keeps values whose selector is truthy.

---

## 55. `pairwise`

```python
from itertools import pairwise

list(pairwise([1, 2, 4, 7]))
```

Produces:

```text
(1,2)
(2,4)
(4,7)
```

Useful for adjacent differences, comparisons, etc.

---

## 56. `groupby`

```python
from itertools import groupby

for key, group in groupby(data, key=key_fn):
    ...
```

### Trap

`groupby()` groups **consecutive** equal keys.

If you need all equal keys together:

```python
data.sort(key=key_fn)
```

first.

---

# C++ ↔ PYTHON “ALGORITHM TRANSLATOR”

| C++ | Python |
|---|---|
| `find(begin,end,x)` | `x in arr`, `arr.index(x)` |
| `find_if` | `next((x for x in arr if pred(x)), default)` |
| `count` | `arr.count(x)` |
| `count_if` | `sum(pred(x) for x in arr)` |
| `all_of` | `all(pred(x) for x in arr)` |
| `any_of` | `any(pred(x) for x in arr)` |
| `none_of` | `not any(pred(x) for x in arr)` |
| `sort` | `sorted`, `.sort()` |
| `stable_sort` | `sorted`, `.sort()` |
| `reverse` | `.reverse()`, `[::-1]` |
| `rotate` | slicing concatenation |
| `fill` | `[value] * n` |
| `replace` | comprehension / `str.replace()` |
| `remove_if` | comprehension / `filter()` |
| `unique` | custom consecutive pass |
| `binary_search` | `bisect_left` + equality |
| `lower_bound` | `bisect_left` |
| `upper_bound` | `bisect_right` |
| `equal_range` | `bisect_left`, `bisect_right` |
| `next_permutation` | `itertools.permutations` **not equivalent iteration semantics** |
| `merge` | `heapq.merge` |
| `min_element` | `min` |
| `max_element` | `max` |
| `partition` | comprehension into groups |
| `nth_element` | no direct built-in |
| `transform` | `map` / comprehension |
| `copy_if` | comprehension |
| `iota` | `range` |
| `accumulate` | `itertools.accumulate` |
| `make_heap` | `heapq.heapify` |
| `push_heap` | `heapq.heappush` |
| `pop_heap` | `heapq.heappop` |
| set union | `a \| b` |
| set intersection | `a & b` |
| set difference | `a - b` |
| set symmetric difference | `a ^ b` |

---

# COMPLEXITY CHEAT SHEET

| Algorithm | C++ typical/worst | Python counterpart |
|---|---:|---|
| `find` | O(n) | `in`: O(n) list |
| `count` | O(n) | `.count()`: O(n) |
| `all_of` / `any_of` | O(n) | `all` / `any`: O(n) |
| `sort` | O(n log n) | O(n log n) |
| `reverse` | O(n) | O(n) |
| `rotate` | O(n) | O(n) |
| `unique` | O(n) | O(n) custom |
| `binary_search` | O(log n) on vector | O(log n) search via `bisect` |
| `lower_bound` | O(log n) on random access | O(log n) |
| `upper_bound` | O(log n) on random access | O(log n) |
| `merge` | O(n+m) | `heapq.merge`: O((n+m) log k) style heap merge behavior |
| `nth_element` | average O(n) | no direct built-in |
| `make_heap` | O(n) | `heapq.heapify`: O(n) |
| heap push/pop | O(log n) | O(log n) |
| `gcd` | O(log min(a,b)) | O(log min(a,b)) |
| `accumulate` | O(n) | O(n) |
| permutation step | O(n) | iterator generation depends on output size |

> Complexity for generic C++ algorithms can depend on iterator category. In particular, an algorithm may perform O(log n) comparisons but still make O(n) iterator increments when given only forward iterators. `lower_bound` is a classic example. citeturn725974search3

---

# DSA MEMORIZATION TIER

## Memorize first

```text
find
count
all_of / any_of / none_of

sort
stable_sort

reverse
rotate

fill
replace

remove + erase
unique + erase

binary_search
lower_bound
upper_bound
equal_range

min_element
max_element

next_permutation

merge
set_union
set_intersection
set_difference

partition

nth_element

make_heap / push_heap / pop_heap

distance
iota
accumulate

transform
```

### Python

```text
in
find / index
count

any / all

sorted / sort

reversed
slicing

bisect_left
bisect_right

heapq.heapify
heappush
heappop

itertools.accumulate
permutations
combinations
product
pairwise
chain

min / max / sum
math.gcd / math.lcm
```

---

# ULTRA-SHORT REVISION

```text
SEARCH
find → exact element
find_if → predicate
count → frequency
all/any/none → predicates

SORT
sort → not stable
stable_sort → stable
nth_element → kth element, NOT full sort
partial_sort → first k sorted

ORDER
reverse
rotate
next_permutation

BINARY SEARCH
lower_bound → first >= x
upper_bound → first > x
equal_range → [lower_bound, upper_bound)
binary_search → bool only

REMOVE
remove → logical removal only
erase → actual container shrink
unique → consecutive duplicates only

PARTITION
partition → groups, order not preserved
stable_partition → groups + order preserved

HEAP
make_heap → O(n)
push_heap / pop_heap → O(log n)

NUMERIC
iota
accumulate
gcd / lcm

PYTHON
bisect_left  = lower_bound
bisect_right = upper_bound
heapq        = heap algorithms
accumulate   = prefix/running operation
```

---

## Important corrections to the original sample

Your original notes had a few things that should not be carried forward unchanged:

1. `random_shuffle()` is obsolete. It was removed in C++17. Use `shuffle()` with a random-number generator. citeturn725974search0

2. `unique()` removes **consecutive** duplicates and returns a new logical end. For vectors, use:

```cpp
v.erase(unique(v.begin(), v.end()), v.end());
```

3. `distance()` returns the iterator's `difference_type`, not literally `int`. Use:

```cpp
auto index = distance(v.begin(), it);
```

4. `merge()` requires **both input ranges to be sorted** and writes into a destination range. citeturn725974search1

5. `lower_bound()` is best thought of as operating on a suitably partitioned range. Its comparison count is logarithmic, but iterator movement can be linear for non-random-access iterators. For `set`/`map`, use the container member function instead. citeturn725974search3turn725974search5

6. Python does not have a one-to-one copy of C++ `<algorithm>`. Its equivalent toolbox is distributed across built-ins, `bisect`, `itertools`, and `heapq`. citeturn360523search0turn360523search1turn360523search5

---

## Verification sources

C++ algorithm coverage and current status were checked against cppreference's `<algorithm>`, ranges algorithms, sorting, binary-search, and container references. citeturn725974search0turn725974search1turn725974search4turn725974search3

Python `bisect`, `itertools`, and `heapq` behavior was checked against the Python standard-library documentation. citeturn360523search0turn360523search4turn360523search5
