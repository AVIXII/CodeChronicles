# Sets — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Main comparison:** `set` ↔ Python `set`  
> **C++ extras:** `unordered_set`, `multiset`

---

# 0. How to Use This Sheet

This sheet is split into:

- **CORE / MUST KNOW** → the concepts, syntax and complexities you should memorize.
- **EXTRAS / REFERENCE** → useful APIs and details you should recognize, but do not need to memorize initially.

The accompanying `.cpp` and `.py` files follow the same organization.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
C++ set
    unique
    sorted
    tree-based associative container
    search / insert / erase → O(log n)

C++ unordered_set
    unique
    no ordering guarantee
    hash-based
    search / insert / erase → O(1) average, O(n) worst

C++ multiset
    sorted
    duplicates allowed
    search / insert / erase → logarithmic for basic single-key operations

Python set
    unique
    unordered
    hash-based
    membership / add / remove → O(1) average, O(n) worst
```

`std::set` is an ordered associative container with unique keys and logarithmic search/insertion/removal. `std::unordered_set` has average constant-time search/insertion/removal and no sorted ordering guarantee. citeturn927540search3turn673723search5

Python `set` is an unordered collection of distinct hashable objects and supports membership and mathematical set operations, but not indexing or slicing. citeturn780618search1

---

# 2. Core Complexity Summary

| Operation | C++ `set` | C++ `unordered_set` | C++ `multiset` | Python `set` |
|---|---:|---:|---:|---:|
| Membership | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n)** | **O(1) avg / O(n) worst** |
| Insert | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n)** | **O(1) avg / O(n) worst** |
| Delete by key | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n + k)** | **O(1) avg / O(n) worst** |
| Delete by iterator | **amortized O(1)** | **O(1) avg** | **amortized O(1)** | N/A |
| Size | O(1) | O(1) | O(1) | O(1) |
| Empty | O(1) | O(1) | O(1) | O(1) |
| Iteration | O(n) | O(n) | O(n) | O(n) |
| Smallest | O(1) via `begin()` | No meaningful ordering | O(1) via `begin()` | No meaningful first element |
| Largest | O(1) via `rbegin()` | No meaningful ordering | O(1) via `rbegin()` | No meaningful last element |
| Clear | O(n) | O(n) | O(n) | O(n) |
| Lower bound | **O(log n)** | N/A | **O(log n)** | No built-in equivalent |
| Upper bound | **O(log n)** | N/A | **O(log n)** | No built-in equivalent |

For Python, these are CPython-oriented complexity expectations. Hash-based set operations are average-case constant time and can degrade to linear time in the worst case. citeturn780618search6turn780618search0

---

# 3. Core C++: `set`

## Creation

```cpp
set<int> s;

set<int> s1 = {1, 2, 3, 4, 5};
```

Duplicates during initialization are automatically removed.

```cpp
set<int> s2 = {1, 2, 2, 3};
```

Result:

```text
{1, 2, 3}
```

Construction from a range:

```cpp
vector<int> a = {5, 1, 3, 3, 2};

set<int> s(a.begin(), a.end());
```

---

## Insert

```cpp
s.insert(x);
```

**TC:** O(log n)

Duplicates are ignored.

```cpp
auto [it, inserted] = s.insert(x);
```

`inserted` tells you whether a new element was inserted.

---

## Size / Empty

```cpp
s.size();
s.empty();
```

Both:

**TC:** O(1)

---

## Membership

Classic:

```cpp
s.count(x) > 0
```

For `set`, `count(x)` is `0` or `1`.

C++20:

```cpp
s.contains(x)
```

This directly returns `bool`.

**TC:** O(log n) for `set`. citeturn673723search10

---

## Find

```cpp
auto it = s.find(x);

if (it != s.end()) {
    // found
}
```

**TC:** O(log n)

---

## Iteration

```cpp
for (int x : s)
    cout << x;
```

Elements appear in sorted order.

**TC:** O(n)

---

## Smallest / Largest

There are no `front()` / `back()` methods like `vector`.

Use:

```cpp
*s.begin()
```

for the smallest element.

Use:

```cpp
*s.rbegin()
```

for the largest.

Both accessor operations are O(1).

Only use them on a non-empty set.

---

## Erase by Key

```cpp
s.erase(x);
```

For `set`:

```text
return 0 → x not present
return 1 → x removed
```

**TC:** O(log n)

---

## Erase by Iterator

```cpp
auto it = s.find(x);

if (it != s.end())
    s.erase(it);
```

The iterator-based erase is amortized constant time. citeturn927540search1

---

## Erase Range

```cpp
s.erase(first, last);
```

Range is:

```text
[first, last)
```

Complexity:

```text
O(log n + distance(first,last))
```

for the general range erase guarantee. citeturn927540search1

---

## Clear

```cpp
s.clear();
```

**TC:** O(n)

---

# 4. Core C++: `unordered_set`

## Creation

```cpp
unordered_set<int> us;
```

---

## Insert

```cpp
us.insert(x);
```

```text
Average: O(1)
Worst:   O(n)
```

---

## Membership

```cpp
us.count(x)
```

or:

```cpp
us.contains(x);      // C++20
```

```text
Average: O(1)
Worst:   O(n)
```

---

## Find

```cpp
auto it = us.find(x);
```

```text
Average: O(1)
Worst:   O(n)
```

The standard library documents average constant-time lookup with linear worst case. citeturn673723search7

---

## Iteration

```cpp
for (int x : us)
    cout << x;
```

There is **no sorted-order guarantee**.

Do not build DSA logic around the iteration order.

---

## Delete

```cpp
us.erase(x);
```

```text
Average: O(1)
Worst:   O(n)
```

---

# 5. Core C++: `multiset`

`multiset` is basically:

```text
sorted + duplicates allowed
```

Creation:

```cpp
multiset<int> ms = {
    1, 2, 2, 2, 3
};
```

Unlike `set`, all equivalent values are retained. `std::multiset` keeps elements sorted and allows equivalent keys. citeturn927540search0

---

## Insert

```cpp
ms.insert(x);
```

**TC:** O(log n)

---

## Count

```cpp
ms.count(x);
```

Returns the number of occurrences.

For `multiset`, account for the number of matching elements:

```text
TC: O(log n + k)
```

where `k` = number of equal elements.

---

## Find

```cpp
auto it = ms.find(x);
```

Returns an iterator to one matching element.

---

## Erase One Occurrence

```cpp
auto it = ms.find(x);

if (it != ms.end())
    ms.erase(it);
```

This removes only that occurrence.

---

## Erase All Occurrences

```cpp
ms.erase(x);
```

This removes **all** elements equivalent to `x`.

---

## Lower / Upper Bound

```cpp
ms.lower_bound(x);
ms.upper_bound(x);
```

Both:

**TC:** O(log n)

---

# 6. Core C++: Ordered vs Unordered

| Feature | `set` | `unordered_set` |
|---|---|---|
| Unique elements | Yes | Yes |
| Sorted | Yes | No guarantee |
| Main structure | Balanced-tree style ordered structure | Hash table |
| Search | O(log n) | O(1) average |
| Insert | O(log n) | O(1) average |
| Delete | O(log n) | O(1) average |
| Lower bound | Yes | No |
| Upper bound | Yes | No |
| Smallest/largest by container order | Yes | No |
| Worst lookup | O(log n) | O(n) |

`std::set` is commonly implemented as a red-black tree; the standard requirement that matters for DSA is the logarithmic complexity, not relying on a specific implementation detail. citeturn927540search3

---

# 7. Core Python: `set`

## Creation

```python
s = {1, 2, 3, 4, 5}
```

From iterable:

```python
s = set([1, 2, 3, 4, 5])
```

Empty set:

```python
s = set()
```

Important:

```python
{}
```

creates an empty **dictionary**, not an empty set.

Python sets contain distinct hashable objects. citeturn780618search1

---

## Add

```python
s.add(x)
```

```text
Average: O(1)
Worst:   O(n)
```

---

## Membership

```python
x in s
x not in s
```

```text
Average: O(1)
Worst:   O(n)
```

---

## Remove

```python
s.remove(x)
```

Raises `KeyError` if `x` is absent.

---

## Discard

```python
s.discard(x)
```

Does nothing if `x` is absent.

Both removal operations have average O(1), worst-case O(n) behavior. citeturn780618search6

---

## Size / Empty

```python
len(s)
not s
```

Both:

**TC:** O(1)

---

## Iterate

```python
for x in s:
    print(x)
```

**TC:** O(n)

There is no guaranteed sorted order and no meaningful first/last element.

Python sets explicitly do not support indexing or slicing. citeturn780618search1

---

## Pop

```python
x = s.pop()
```

Important:

> `set.pop()` removes and returns an **arbitrary** element.

It does **not** mean "remove the first element" or "remove the last element."

An empty set raises `KeyError`. citeturn780618search1

---

## Clear

```python
s.clear()
```

**TC:** O(n)

---

# 8. Core Python Set Operations

Given:

```python
A = {1, 2, 3}
B = {3, 4, 5}
```

## Union

```python
A | B
```

or:

```python
A.union(B)
```

Result:

```text
{1,2,3,4,5}
```

**TC:** O(|A| + |B|)

---

## Intersection

```python
A & B
```

or:

```python
A.intersection(B)
```

Result:

```text
{3}
```

**Typical set/set TC:** O(min(|A|,|B|))

---

## Difference

```python
A - B
```

or:

```python
A.difference(B)
```

Result:

```text
{1,2}
```

Typical TC:

**O(|A|)**

---

## Symmetric Difference

```python
A ^ B
```

or:

```python
A.symmetric_difference(B)
```

Result:

```text
{1,2,4,5}
```

**TC:** O(|A| + |B|)

Current Python complexity references document these set-operation costs and note that hash-based operations have worst-case degradation. citeturn780618search6turn780618search0

---

# 9. CORE C++ vs Python

| Concept | C++ | Python |
|---|---|---|
| Unique sorted set | `set<T>` | No direct built-in equivalent |
| Unique unordered set | `unordered_set<T>` | `set` |
| Duplicates sorted | `multiset<T>` | No direct built-in equivalent |
| Insert | `s.insert(x)` | `s.add(x)` |
| Membership | `s.contains(x)` / `count` | `x in s` |
| Find | `s.find(x)` | `x in s` |
| Remove | `s.erase(x)` | `s.remove(x)` |
| Safe remove | Check `find()` first / use count | `s.discard(x)` |
| Size | `s.size()` | `len(s)` |
| Empty | `s.empty()` | `not s` |
| Clear | `s.clear()` | `s.clear()` |
| Iterate | `for(auto x:s)` | `for x in s` |
| Lower bound | `s.lower_bound(x)` | No built-in |
| Upper bound | `s.upper_bound(x)` | No built-in |
| Union | `set_union(...)` | `A \| B` |
| Intersection | `set_intersection(...)` | `A & B` |
| Difference | `set_difference(...)` | `A - B` |
| Symmetric difference | `set_symmetric_difference(...)` | `A ^ B` |
| Smallest | `*s.begin()` | No meaningful order |
| Largest | `*s.rbegin()` | No meaningful order |

---

# 10. EXTRAS / REFERENCE

These are useful, but should not be part of the first memorization pass.

---

## C++: `lower_bound`

```cpp
auto it = s.lower_bound(x);
```

First element:

```text
>= x
```

**TC:** O(log n)

---

## C++: `upper_bound`

```cpp
auto it = s.upper_bound(x);
```

First element:

```text
> x
```

**TC:** O(log n)

---

## C++: `equal_range`

```cpp
auto [first, last] = ms.equal_range(x);
```

Equivalent conceptually to:

```text
[lower_bound(x), upper_bound(x))
```

Particularly useful for `multiset`.

---

## C++: Set Algorithms

### Union

```cpp
set_union(...)
```

### Intersection

```cpp
set_intersection(...)
```

### Difference

```cpp
set_difference(...)
```

### Symmetric Difference

```cpp
set_symmetric_difference(...)
```

These algorithms operate on appropriately ordered input ranges. Since `std::set` is sorted, it is a natural input container.

For two input sizes `n` and `m`, the standard complexity is linear in the combined range sizes for these merge-style algorithms. citeturn673723search8

---

## C++: Subset Test

For ordered sets:

```cpp
includes(
    B.begin(), B.end(),
    A.begin(), A.end()
);
```

Checks:

```text
A ⊆ B
```

For sorted ranges:

**TC:** O(|A| + |B|)

---

## C++: Custom Ordering

Descending:

```cpp
set<int, greater<int>> s;
```

Custom comparator:

```cpp
struct Compare {
    bool operator()(int a, int b) const {
        return ...;
    }
};

set<int, Compare> s;
```

Important:

> `std::set` uniqueness is based on the comparator's equivalence relation, not necessarily `operator==`. citeturn927540search3

---

## C++: `erase_if`

C++20:

```cpp
erase_if(s, predicate);
```

Useful for deleting elements satisfying a condition.

---

## C++: `unordered_set` Hash Policy

```cpp
s.bucket_count();
s.load_factor();

s.reserve(n);
s.rehash(n);
```

These are primarily implementation/hash-policy tools.

For ordinary DSA, knowing:

```text
unordered_set → average O(1) lookup
```

is much more important than memorizing bucket APIs.

---

## C++: `merge`

```cpp
a.merge(b);
```

Transfers eligible nodes from `b` into `a`.

For `set`, nodes that would violate uniqueness remain in the source.

---

## C++: `extract`

```cpp
auto node = s.extract(x);
```

Extracts a node without destroying its stored value, allowing node-level manipulation before reinsertion.

Mostly an advanced library feature.

---

# 11. Python: Set Relations

## Subset

```python
A.issubset(B)
A <= B
```

Proper subset:

```python
A < B
```

---

## Superset

```python
A.issuperset(B)
A >= B
```

Proper superset:

```python
A > B
```

---

## Disjoint

```python
A.isdisjoint(B)
```

Returns `True` when the sets share no elements. citeturn780618search1

---

# 12. Python: Set Update Operations

These modify the left-hand set.

```python
A.update(B)
A &= B
A.intersection_update(B)

A -= B
A.difference_update(B)

A ^= B
A.symmetric_difference_update(B)
```

Use these when you want mutation rather than a new set.

Python's operator forms and method forms have slightly different operand restrictions: method forms can accept arbitrary iterables, while the operator forms require set-like operands. citeturn780618search1

---

# 13. Python: `frozenset`

Immutable set:

```python
fs = frozenset([1, 2, 3])
```

Cannot modify:

```python
# fs.add(4)       # AttributeError
```

It is hashable, so it can be used as:

```python
dict_key = {
    frozenset({1,2}): "value"
}
```

or as an element of another set:

```python
s = {
    frozenset({1,2}),
    frozenset({3,4})
}
```

Python documents `frozenset` as immutable and hashable, unlike mutable `set`. citeturn780618search1

---

# 14. Python: Hashable Elements

Valid:

```python
{
    1,
    "hello",
    (1, 2),
    frozenset({1,2})
}
```

Invalid:

```python
# {[1,2]}          # TypeError
# {{1,2}}          # TypeError
```

Why?

Set elements must be **hashable**.

---

# 15. Python: Set Comprehension

```python
squares = {x*x for x in range(10)}
```

With condition:

```python
even_squares = {
    x*x
    for x in range(10)
    if x % 2 == 0
}
```

---

# 16. Python: Removing Duplicates

```python
arr = [1,2,2,3,3,4]

unique = set(arr)
```

**Average TC:** O(n)  
**SC:** O(n)

If original order must be preserved:

```python
unique = list(dict.fromkeys(arr))
```

This is a Python-specific idiom, not a property of `set`.

---

# 17. Python: `Counter` as a Multiset-Like Tool

Python has no built-in `multiset` equivalent matching C++ `multiset`.

For frequency/multiset-style problems, `collections.Counter` is often useful:

```python
from collections import Counter

freq = Counter([1,2,2,2,3,3])

freq[2]          # 3
```

Updates:

```python
freq.update([2,4])
freq.subtract([2])
```

This is usually a **frequency map**, not a drop-in replacement for every operation of C++ `multiset`.

---

# 18. Common DSA Traps

## Core traps

**Python `{}` creates an empty set**  
→ No. `{}` creates an empty dictionary. Use `set()`.

**Sets preserve insertion order like lists**  
→ Do not rely on ordering. Python sets are unordered and do not support indexing/slicing. citeturn780618search1

**`set.pop()` removes the first element**  
→ No. It removes an arbitrary element.

**C++ `unordered_set` is always O(1)**  
→ No. Average O(1), worst O(n). citeturn673723search7

**C++ `set` allows duplicates**  
→ No. Use `multiset`.

**C++ `multiset.erase(x)` removes one occurrence**  
→ No. It removes all equivalent elements. To remove one occurrence, erase an iterator.

**Python `remove()` is safe when the value is absent**  
→ No. It raises `KeyError`. Use `discard()` for safe removal.

**You can index a set**  
→ No, not in Python or the C++ associative-container sense. A set has no positional indexing.

**`set.begin()` is the same idea as Python `set[0]`**  
→ No. C++ ordered sets expose iterators; Python sets do not expose positional indexing.

**C++ `set` has `front()` / `back()`**  
→ No. Use `begin()` / `rbegin()` for smallest/largest in an ordered set.

---

# 19. What to Memorize

## MUST KNOW — C++

### `set`

```cpp
set<int> s;

s.insert(x);

s.erase(x);

s.find(x);
s.contains(x);

s.size();
s.empty();

*s.begin();      // smallest
*s.rbegin();     // largest

s.lower_bound(x);
s.upper_bound(x);
```

### `unordered_set`

```cpp
unordered_set<int> us;

us.insert(x);
us.erase(x);

us.find(x);
us.contains(x);

us.size();
us.empty();
```

### `multiset`

```cpp
multiset<int> ms;

ms.insert(x);
ms.count(x);

ms.erase(x);          // ALL x

auto it = ms.find(x);
if (it != ms.end())
    ms.erase(it);     // ONE occurrence
```

---

## MUST KNOW — Python

```python
s = set()

s.add(x)

x in s

s.remove(x)
s.discard(x)

s.pop()
s.clear()

len(s)
not s

A | B
A & B
A - B
A ^ B

A <= B
A >= B

A.issubset(B)
A.issuperset(B)
A.isdisjoint(B)
```

Also:

```python
frozenset(...)
```

as the immutable set type.

---

# 20. REFERENCE ONLY

### C++

```text
equal_range()
includes()
set_union()
set_intersection()
set_difference()
set_symmetric_difference()
custom comparator
erase_if()
merge()
extract()
reserve()
rehash()
bucket_count()
load_factor()
```

### Python

```text
set comprehensions
update()
intersection_update()
difference_update()
symmetric_difference_update()
frozenset
dict.fromkeys()
Counter
method-vs-operator iterable behavior
```

---

# 21. One-Glance Syntax Reference

| Operation | C++ `set` | C++ `unordered_set` | C++ `multiset` | Python `set` |
|---|---|---|---|---|
| Create | `set<int> s` | `unordered_set<int> s` | `multiset<int> s` | `s=set()` |
| Insert | `s.insert(x)` | `s.insert(x)` | `s.insert(x)` | `s.add(x)` |
| Search | `s.find(x)` | `s.find(x)` | `s.find(x)` | `x in s` |
| Contains | `s.contains(x)` | `s.contains(x)` | `s.contains(x)` | `x in s` |
| Count | `s.count(x)` → 0/1 | `s.count(x)` → 0/1 | `s.count(x)` → k | No direct `.count()` |
| Delete by key | `s.erase(x)` | `s.erase(x)` | `s.erase(x)` → all x | `s.remove(x)` |
| Safe delete | check first | check first | check first | `s.discard(x)` |
| Delete one | iterator erase | iterator erase | iterator erase | N/A |
| Size | `s.size()` | `s.size()` | `s.size()` | `len(s)` |
| Empty | `s.empty()` | `s.empty()` | `s.empty()` | `not s` |
| Clear | `s.clear()` | `s.clear()` | `s.clear()` | `s.clear()` |
| Iterate | `for(x:s)` | `for(x:s)` | `for(x:s)` | `for x in s` |
| Smallest | `*s.begin()` | No ordering | `*s.begin()` | No meaningful one |
| Largest | `*s.rbegin()` | No ordering | `*s.rbegin()` | No meaningful one |
| Lower bound | `s.lower_bound(x)` | No | `ms.lower_bound(x)` | No built-in |
| Upper bound | `s.upper_bound(x)` | No | `ms.upper_bound(x)` | No built-in |
| Union | `set_union` | custom / algorithm | `set_union` | `A \| B` |
| Intersection | `set_intersection` | custom / algorithm | `set_intersection` | `A & B` |
| Difference | `set_difference` | custom / algorithm | `set_difference` | `A - B` |
| Symmetric diff | `set_symmetric_difference` | custom / algorithm | same | `A ^ B` |

---

# 22. Final Mental Model

```text
SET

Need UNIQUE + SORTED?
        ↓
    C++ set
        O(log n)

Need UNIQUE + FAST AVERAGE MEMBERSHIP?
        ↓
C++ unordered_set / Python set
        O(1) average
        O(n) worst

Need SORTED + DUPLICATES?
        ↓
    C++ multiset
        O(log n) basic operations

Need PYTHON IMMUTABLE SET?
        ↓
    frozenset
```

### Memorize this

```text
C++ set
    sorted + unique
    O(log n)

C++ unordered_set
    unordered + unique
    O(1) avg

C++ multiset
    sorted + duplicates
    O(log n)

Python set
    unordered + unique
    O(1) avg
    no indexing

Python frozenset
    immutable + hashable set
```

---

# 23. Source / Verification Notes

The C++ complexity and API details were checked against current cppreference documentation for `set`, `unordered_set`, `multiset`, `erase`, `contains`, and the standard set algorithms. citeturn927540search3turn673723search5turn927540search0turn927540search1turn673723search10turn673723search8

Python set behavior and complexity were checked against the current Python documentation and CPython time-complexity reference. citeturn780618search1turn780618search6turn780618search0

---

# 24. Files

- `sets_cpp.cpp` → runnable C++ reference
- `sets_python.py` → runnable Python reference
- `sets_cpp_python.md` → comparison + revision sheet
