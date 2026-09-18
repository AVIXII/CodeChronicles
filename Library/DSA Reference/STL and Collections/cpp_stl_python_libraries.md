# C++ STL & Python DSA Libraries
### Language Toolbox / Quick-Reference Index

> **Role of this sheet:** This is the **library/toolbox layer** of the DSA notes.
>
> The dedicated data-structure sheets remain the detailed operation references:
>
> - Arrays → `vector`, `array`, Python `list`
> - Strings → `string`, Python `str`
> - Sets → `set`, `unordered_set`, Python `set`
> - Maps → `map`, `unordered_map`, Python `dict`
> - Stacks → `stack`
> - Queues → `queue`, `deque`, `priority_queue`, Python `deque`, `heapq`
> - Bitset → `bitset`
> - Algorithms → generic STL algorithms and Python algorithmic equivalents
>
> This sheet answers a different question:
>
> **“What library/tool should I reach for?”**

---

# 1. Overall Organization

```text
DSA LANGUAGE TOOLKIT
│
├── C++ STL
│   ├── Containers
│   ├── Container Adapters
│   ├── Utilities
│   ├── Iterators
│   ├── Algorithms
│   └── STL Mechanics
│
└── Python DSA Libraries
    ├── Built-ins
    ├── collections
    ├── heapq
    ├── bisect
    ├── itertools
    ├── functools
    ├── math
    ├── string
    └── random
```

The supplied C++ material describes STL in terms of containers, algorithms, functions, and iterators, with `pair` and the containers as central examples. fileciteturn1file0L32-L52

The supplied Python material covers built-ins plus `collections`, `heapq`, `bisect`, `itertools`, `functools`, `math`, `random`, and `string`. fileciteturn1file1L18-L26 fileciteturn1file1L204-L208

---

# 2. C++ STL: What to Learn

## CORE

```text
Containers
├── array
├── vector
├── deque
├── list
├── set
├── multiset
├── map
├── multimap
├── unordered_set
├── unordered_multiset
├── unordered_map
└── unordered_multimap

Container adapters
├── stack
├── queue
└── priority_queue

Utilities
├── pair
├── tuple
├── tie
├── bitset
└── common type aliases

Iterators
├── begin / end
├── rbegin / rend
├── cbegin / cend
├── next / prev
├── advance
└── distance

STL mechanics
├── iterator invalidation
├── reference invalidation
├── size vs capacity
├── push vs emplace
├── comparator / lambda
├── erase-remove
└── output iterators
```

## EXTRAS

```text
forward_list
custom hash
custom comparators
insert_or_assign
try_emplace
extract / merge
hash-table reserve / buckets
optional
variant
function
C++20 ranges
```

---

# 3. C++ Containers: Reach-for Guide

| Need | C++ tool | Main idea |
|---|---|---|
| Fixed-size contiguous sequence | `array<T,N>` | fixed size |
| Default dynamic sequence | `vector<T>` | most common sequence container |
| Efficient both-end operations | `deque<T>` | front + back |
| Doubly-linked sequence | `list<T>` | iterator-based insertion/deletion |
| Singly-linked sequence | `forward_list<T>` | niche |
| Sorted unique values | `set<T>` | ordered tree |
| Sorted duplicate values | `multiset<T>` | ordered tree |
| Sorted key-value pairs | `map<K,V>` | unique keys |
| Sorted duplicate keys | `multimap<K,V>` | multiple values/key |
| Hash set | `unordered_set<T>` | average O(1) lookup |
| Hash multiset | `unordered_multiset<T>` | duplicates + hashing |
| Hash map | `unordered_map<K,V>` | average O(1) key lookup |
| Hash multimap | `unordered_multimap<K,V>` | duplicate keys + hashing |

---

# 4. C++ Container Adapters

| Need | Tool | Default behavior |
|---|---|---|
| LIFO | `stack<T>` | top access |
| FIFO | `queue<T>` | front removal / back insertion |
| Priority queue | `priority_queue<T>` | **max-heap** |
| Min-priority queue | `priority_queue<T, vector<T>, greater<T>>` | min-heap |

Your supplied STL material treats stack and queue as adapter-style interfaces rather than general-purpose containers. fileciteturn1file0L500-L614 fileciteturn1file0L672-L779

---

# 5. C++ Utilities

## Core

```cpp
pair<int, string> p = {1, "Alice"};

tuple<int, string, double> t = {
    1, "Alice", 9.5
};

auto [x, y] = p;
```

Useful:

```cpp
first
second

get<0>(t)
get<1>(t)
get<2>(t)

tie(a, b) = p;
```

### Common aliases

```cpp
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
```

---

# 6. C++ Iterator Toolbox

| Tool | Purpose |
|---|---|
| `begin()` | first element |
| `end()` | one-past-last |
| `rbegin()` | reverse beginning |
| `rend()` | reverse end |
| `cbegin()` | const beginning |
| `cend()` | const end |
| `next(it,k)` | return advanced iterator |
| `prev(it,k)` | return previous iterator |
| `advance(it,k)` | modify iterator |
| `distance(a,b)` | distance between iterators |

### Core mental model

```cpp
sort(v.begin(), v.end());
find(v.begin(), v.end(), x);
reverse(v.begin(), v.end());
```

The iterator range is:

```text
[first, last)
```

`end()` itself is not an element.

---

# 7. Iterator Categories: Why Complexity Sometimes Changes

```text
Input
Forward
Bidirectional
Random Access
Contiguous
```

The key CP distinction:

```text
vector / array
→ random-access / contiguous

list
→ bidirectional

forward_list
→ forward

set / map iterators
→ bidirectional
```

Therefore:

```text
distance(vector.begin(), it) → O(1)

distance(list.begin(), it) → O(n)
```

Likewise, generic `lower_bound()` on a random-access range behaves differently from using it with weaker iterator categories.

---

# 8. C++ STL Mechanics You Should Understand

## `size()` vs `capacity()`

```cpp
vector<int> v;

v.reserve(100);
```

means approximately:

```text
capacity >= 100
size == 0
```

while:

```cpp
v.resize(100);
```

means:

```text
size == 100
```

Your supplied material also explicitly distinguishes vector size and its dynamic behavior. fileciteturn1file0L118-L170 fileciteturn1file0L320-L414

---

## `push_*` vs `emplace_*`

```cpp
v.push_back(obj);
v.emplace_back(args...);
```

`emplace_back()` constructs from constructor arguments at the destination.

Useful to know, but do not memorize the myth:

```text
"emplace is always faster"
```

It is not a universal rule.

---

## Erase-remove

```cpp
v.erase(
    remove(v.begin(), v.end(), x),
    v.end()
);
```

Remember:

```text
remove() → rearranges range / logical removal
erase()  → actually shrinks vector
```

---

## Output iterators

```cpp
back_inserter(v)
front_inserter(lst)
inserter(container, pos)
```

These adapt insertion to algorithms such as:

```cpp
copy(...)
```

---

# 9. Python DSA Libraries: What to Learn

## CORE

```text
Built-ins
├── sorted
├── min / max
├── sum
├── len
├── any / all
├── enumerate
├── zip
├── reversed
└── range

collections
├── deque
├── Counter
└── defaultdict

heapq
├── heapify
├── heappush
├── heappop
├── heappushpop
├── heapreplace
├── nsmallest
├── nlargest
└── merge

bisect
├── bisect_left
├── bisect_right
└── insort

itertools
├── combinations
├── permutations
├── product
├── accumulate
├── chain
├── groupby
└── pairwise

functools
└── lru_cache

math
├── gcd
├── lcm
├── isqrt
├── factorial
└── prod
```

Your supplied Python material explicitly identifies these library families as the main DSA toolkit. fileciteturn1file1L204-L241 fileciteturn1file1L371-L420 fileciteturn1file1L425-L457

---

# 10. Python Built-ins: Reach-for Guide

| Need | Python |
|---|---|
| Sort new copy | `sorted(a)` |
| Sort in place | `a.sort()` |
| Minimum | `min(a)` |
| Maximum | `max(a)` |
| Sum | `sum(a)` |
| Product | `math.prod(a)` |
| Length | `len(a)` |
| Any true | `any(...)` |
| All true | `all(...)` |
| Index + value | `enumerate(a)` |
| Pair iterables | `zip(a,b)` |
| Reverse iterator | `reversed(a)` |
| Integer sequence | `range(...)` |

The source specifically documents these built-ins and their basic usage. fileciteturn1file1L18-L26 fileciteturn1file1L109-L125 fileciteturn1file1L128-L196

---

# 11. Python `collections`

## `deque`

```python
from collections import deque

d = deque()

d.append(x)
d.appendleft(x)

d.pop()
d.popleft()

d.extend(...)
d.extendleft(...)

d.rotate(k)
```

### Reach for it when

```text
queue
BFS
sliding window
both-end insertion/removal
```

---

## `Counter`

```python
from collections import Counter

freq = Counter(arr)

freq[x]
freq.most_common(k)

freq.update(...)
freq.subtract(...)

freq1 + freq2
freq1 - freq2
freq1 & freq2
freq1 | freq2
```

### Reach for it when

```text
frequency counting
anagrams
frequency comparison
top-k frequencies
```

The supplied notes explicitly position `Counter` around these frequency-oriented problems. fileciteturn1file1L243-L275

---

## `defaultdict`

```python
from collections import defaultdict

freq = defaultdict(int)
groups = defaultdict(list)
graph = defaultdict(list)
unique_groups = defaultdict(set)
```

### Reach for it when

```text
frequency map
grouping
adjacency lists
avoid repeated missing-key checks
```

The source explicitly lists grouping and graph construction as use cases. fileciteturn1file1L277-L311

---

# 12. Python `heapq`

```python
import heapq

heapq.heapify(a)

heapq.heappush(heap, x)
heapq.heappop(heap)

heapq.heappushpop(heap, x)
heapq.heapreplace(heap, x)

heapq.nsmallest(k, a)
heapq.nlargest(k, a)

heapq.merge(a, b, c)
```

Default:

```text
MIN-HEAP
```

Max-heap trick:

```python
heapq.heappush(heap, -x)
x = -heapq.heappop(heap)
```

### Reach for it when

```text
priority queue
Dijkstra
k smallest
k largest
merge sorted streams
```

Your supplied source uses exactly these patterns. fileciteturn1file1L371-L420

---

# 13. Python `bisect`

```python
from bisect import bisect_left, bisect_right

L = bisect_left(a, x)
R = bisect_right(a, x)
```

Mental translation:

```text
bisect_left  ↔ C++ lower_bound
bisect_right ↔ C++ upper_bound
```

Insertion:

```python
insort(a, x)
```

### Critical complexity distinction

```text
bisect search → O(log n)

list insertion after finding position → O(n)
```

So:

```text
insort(...)
```

is still O(n) overall on a Python list.

The source also explicitly requires the list to be sorted for `bisect`. fileciteturn1file1L425-L457

---

# 14. Python `itertools`

## Combinatorics

```python
permutations
combinations
combinations_with_replacement
product
```

## Running / structural iteration

```python
accumulate
chain
groupby
pairwise
islice
compress
zip_longest
cycle
repeat
```

### Reach-for map

```text
all permutations      → permutations
choose r elements     → combinations
Cartesian product     → product
prefix/running sum    → accumulate
concatenate iterables → chain
adjacent pairs        → pairwise
group consecutive keys→ groupby
take a slice of iter. → islice
```

The supplied Python notes already group these under `itertools`. fileciteturn1file1L461-L494

---

# 15. Python `functools`

## Core

```python
from functools import lru_cache

@lru_cache(maxsize=None)
def dp(...):
    ...
```

Use for:

```text
memoization
recursive DP
state caching
```

## Reference

```python
reduce(...)
partial(...)
```

Your source covers memoization, reduction, and partial application. fileciteturn1file1L498-L547

---

# 16. Python `math`: DSA Subset

## Memorize

```python
math.gcd(a, b)
math.lcm(a, b)
math.isqrt(n)
math.factorial(n)
math.prod(arr)
math.ceil(x)
math.floor(x)
```

## Useful reference

```python
math.sqrt(x)
math.log2(x)
math.log10(x)

math.isfinite(x)
math.isinf(x)
```

Do not attempt to memorize the entire `math` module. Humans already have enough ways to waste storage.

The supplied notes contain the broader math toolbox. fileciteturn1file1L551-L597

---

# 17. Python `string`

Useful constants:

```python
string.ascii_lowercase
string.ascii_uppercase
string.ascii_letters
string.digits
string.hexdigits
```

Primarily a convenience/reference module for character sets.

---

# 18. Python `random`

DSA-relevant:

```python
random.choice(...)
random.sample(...)
random.shuffle(...)
random.randint(...)
random.randrange(...)
```

Main use:

```text
testing
randomized experiments
test generation
```

Usually lower priority than `collections`, `heapq`, `bisect`, and `itertools`.

---

# 19. C++ ↔ Python Reach-For Map

| DSA Need | C++ | Python |
|---|---|---|
| Dynamic array | `vector` | `list` |
| Fixed array | `array` | tuple / list depending on semantics |
| Both-end queue | `deque` | `collections.deque` |
| Stack | `stack` | `list` / `deque` |
| Queue | `queue` | `deque` |
| Priority queue | `priority_queue` | `heapq` |
| Ordered set | `set` | No built-in tree set |
| Hash set | `unordered_set` | `set` |
| Ordered map | `map` | No built-in tree map |
| Hash map | `unordered_map` | `dict` |
| Frequency counter | `map` / `unordered_map` / `Counter` patterns | `Counter` |
| Default-valued map | `map` + checks / `operator[]` | `defaultdict` |
| Pair | `pair` | tuple |
| Tuple | `tuple` | tuple |
| Binary-search boundary | `lower_bound` / `upper_bound` | `bisect_left` / `bisect_right` |
| Generic sort | `sort` | `sorted` / `.sort()` |
| Prefix accumulation | `accumulate` | `itertools.accumulate` |
| Permutations | `next_permutation` | `itertools.permutations` |
| Combinations | custom / loops | `itertools.combinations` |
| Memoization | custom map/cache | `functools.lru_cache` |
| GCD | `gcd` | `math.gcd` |
| LCM | `lcm` | `math.lcm` |

---

# 20. What Belongs Where

This is the important organizational rule for your notes.

| Topic | Put detailed material in |
|---|---|
| `vector` operations | Arrays |
| `list` / Python list operations | Arrays |
| `set` operations | Sets |
| `map` / dict operations | Maps |
| stack operations | Stacks |
| queue / deque / priority queue operations | Queues |
| string methods | Strings |
| bitset operations | Bitset |
| `sort`, `find`, `lower_bound`, `transform` | Algorithms |
| iterator mechanics | **C++ STL** |
| `pair`, `tuple`, `tie` | **C++ STL** |
| `emplace`, `back_inserter`, iterator adapters | **C++ STL** |
| `Counter`, `defaultdict`, `deque` API | **Python DSA Libraries** |
| `heapq` API | **Python DSA Libraries** |
| `bisect` API | **Python DSA Libraries** |
| `itertools` API | **Python DSA Libraries** |
| `lru_cache` | **Python DSA Libraries** |

So the library files should **not duplicate the full data-structure sheets**.

---

# 21. Memorization Priority

## C++ STL

### Tier 1: Know cold

```text
vector
array
deque

set
map
unordered_set
unordered_map

stack
queue
priority_queue

pair
tuple

begin / end
rbegin / rend
next / prev
distance

lambda / comparator
```

### Tier 2: Know well

```text
multiset
multimap
list

cbegin / cend
advance

back_inserter
inserter

emplace / emplace_back
erase-remove

reserve / resize
iterator invalidation
```

### Tier 3: Reference

```text
forward_list
custom hash
extract / merge
hash policies
optional
variant
function
ranges
```

---

## Python

### Tier 1: Know cold

```text
sorted / sort
min / max / sum

enumerate
zip
any / all

deque
Counter
defaultdict

heapq
bisect

permutations
combinations
product
accumulate

lru_cache

math.gcd
math.lcm
math.isqrt
```

### Tier 2: Know well

```text
nsmallest / nlargest
heapq.merge

groupby
pairwise
chain
islice

insort

math.prod

string constants
```

### Tier 3: Reference

```text
OrderedDict
namedtuple
reduce
partial
cycle
repeat
compress
random
broader math functions
```

---

# 22. Common Library Traps

### C++

```text
Trap: vector.push_back() is always O(1).
Correction: O(1) amortized; an individual reallocation can be O(n).

Trap: reserve(n) creates n elements.
Correction: reserve changes capacity, not size.

Trap: remove() erases vector elements.
Correction: remove only rearranges the range; erase shrinks the container.

Trap: end() points to the last element.
Correction: end() is one-past-last.

Trap: unordered_map lookup is guaranteed O(1).
Correction: O(1) average; worst case can be O(n).

Trap: map[key] only reads.
Correction: missing key is inserted with a default value.

Trap: priority_queue is a min-heap by default.
Correction: the default is a max-heap.

Trap: list supports v[i].
Correction: std::list has no random-access indexing.

Trap: every iterator remains valid after insertion.
Correction: validity depends on the container and operation.
```

### Python

```text
Trap: bisect makes insertion O(log n).
Correction: search is O(log n), but list insertion is O(n).

Trap: heapq is a max-heap.
Correction: heapq provides a min-heap.

Trap: groupby groups all equal keys globally.
Correction: it groups consecutive equal keys.

Trap: zip pads shorter inputs.
Correction: zip stops at the shortest input.

Trap: Counter[x] raises KeyError when x is missing.
Correction: a missing Counter key returns 0.

Trap: defaultdict is just a normal dict.
Correction: missing-key access may create a default entry.

Trap: sorted() modifies the list.
Correction: sorted() returns a new list; list.sort() mutates.

Trap: is and == are interchangeable.
Correction: == compares values; is checks identity.

Trap: Python's list is a linked list.
Correction: list is a dynamic array-like sequence.
```

---

# 23. Final Mental Model

```text
WHEN SOLVING A DSA PROBLEM:

1. What DATA STRUCTURE do I need?
   ↓
   vector / set / map / stack / queue / ...

2. What ALGORITHM do I need?
   ↓
   sort / binary search / lower_bound / ...

3. What LANGUAGE TOOL saves me implementation effort?
   ↓
   C++ STL / Python library

4. What is the actual complexity?
   ↓
   guaranteed / average / amortized / worst

5. What language-specific trap applies?
   ↓
   iterator invalidation / aliasing / hashing / etc.
```

That separation is what keeps the notes manageable:

```text
DATA STRUCTURES
    = what the structure is

ALGORITHMS
    = what operation/process to perform

C++ STL / Python LIBRARIES
    = what library tool implements it conveniently
```

This is the organization I would keep going forward.
