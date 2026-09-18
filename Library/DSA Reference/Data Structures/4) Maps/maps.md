# Maps — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Main comparison:** `map` / `unordered_map` / `multimap` ↔ Python `dict` and its practical variants

---

# 0. How to Use This Sheet

This sheet separates:

- **CORE / MUST KNOW** → memorize these concepts, syntax and complexity.
- **EXTRAS / REFERENCE** → useful APIs and advanced details worth having in the master sheet.

The runnable `.cpp` and `.py` files follow the same organization.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
C++ map
    unique keys
    sorted by key
    tree-based ordered map
    O(log n)

C++ unordered_map
    unique keys
    no ordering guarantee
    hash table
    O(1) average / O(n) worst

C++ multimap
    duplicate keys allowed
    sorted by key
    O(log n) insertion/search
    operations over equal keys may include k matches

Python dict
    unique keys
    insertion order preserved
    hash table
    O(1) average / O(n) worst
```

`std::map` provides unique keys in sorted order with logarithmic search, insertion, and removal. `std::unordered_map` provides average constant-time lookup/insertion/removal with no ordering guarantee. `std::multimap` permits duplicate keys while maintaining key order.

Modern Python dictionaries preserve insertion order and require hashable keys; dictionary operations are hash-table based.

---

# 2. Core Complexity Summary

| Operation | C++ `map` | C++ `unordered_map` | C++ `multimap` | Python `dict` |
|---|---:|---:|---:|---:|
| Lookup by key | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n)** | **O(1) avg / O(n) worst** |
| Insert | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n)** | **O(1) avg / O(n) worst** |
| Update existing key | **O(log n)** via lookup | **O(1) avg / O(n) worst** | Duplicate-key model differs | **O(1) avg / O(n) worst** |
| Delete by key | **O(log n)** | **O(1) avg / O(n) worst** | **O(log n + k)** | **O(1) avg / O(n) worst** |
| Delete by iterator | **amortized O(1)** | Average constant-time | **amortized O(1)** | N/A |
| Size | O(1) | O(1) | O(1) | O(1) |
| Empty | O(1) | O(1) | O(1) | O(1) |
| Iteration | O(n) | O(n) | O(n) | O(n) |
| Smallest key | O(1) via `begin()` | No ordering | O(1) via `begin()` | By insertion order only |
| Largest key | O(1) via `rbegin()` | No ordering | O(1) via `rbegin()` | By insertion order only |
| Lower bound | **O(log n)** | Not available | **O(log n)** | No built-in equivalent |
| Upper bound | **O(log n)** | Not available | **O(log n)** | No built-in equivalent |
| Equal range | **O(log n)** | Not available | **O(log n)** to locate range | No direct equivalent |

For Python, average-case O(1) assumes normal hash-table operation; worst-case hash-table operations can degrade to O(n).

---

# 3. CORE: C++ `map`

## Creation

```cpp
map<string, int> mp;

map<int, string> m = {
    {10, "Alice"},
    {20, "Bob"},
    {30, "Charlie"}
};
```

Keys are unique and maintained in non-decreasing order.

---

## Insert / Update

### `operator[]`

```cpp
mp["R"] = 1;
mp["I"] = 2;
mp["H"] = 4;
```

Updating:

```cpp
mp["H"] = 7;
```

### Important

```cpp
mp["X"]
```

when `X` is absent **inserts** `X` with a default-constructed mapped value.

For:

```cpp
map<string, int>
```

that means:

```text
mp["X"] → 0
```

So `operator[]` is not a pure read operation.

---

## `insert()`

```cpp
mp.insert({"A", 10});
```

Does not overwrite an existing key.

Useful return form:

```cpp
auto [it, inserted] = mp.insert({"A", 10});
```

`inserted` tells whether insertion happened.

---

## `insert_or_assign()`

```cpp
mp.insert_or_assign("A", 100);
```

Insert if absent, otherwise assign.

C++17+.

---

## `try_emplace()`

```cpp
mp.try_emplace("A", 100);
```

Insert only if the key is absent, constructing the mapped value only when insertion occurs.

C++17+.

---

## Access

```cpp
mp["A"];
```

May insert if missing.

Bounds-checked/no-insertion access:

```cpp
mp.at("A");
```

Throws `std::out_of_range` if the key is absent.

---

## Size / Empty

```cpp
mp.size();
mp.empty();
```

Both:

**TC:** O(1)

---

## Membership / Find

```cpp
mp.find(key);
```

Check:

```cpp
if (mp.find(key) != mp.end()) {
    ...
}
```

C++20:

```cpp
mp.contains(key);
```

**TC:** O(log n)

---

## Erase

By key:

```cpp
mp.erase(key);
```

By iterator:

```cpp
auto it = mp.find(key);

if (it != mp.end())
    mp.erase(it);
```

By range:

```cpp
mp.erase(first, last);
```

---

## Important: Erasing While Iterating

Your original pattern is exactly the useful C++ idiom:

```cpp
auto it = mp.begin();

while (it != mp.end()) {
    if (it->first % 2 == 0)
        it = mp.erase(it);
    else
        ++it;
}
```

`erase(iterator)` returns the iterator immediately after the erased element, making this pattern safe.

---

## Traverse

```cpp
for (auto el : mp)
    cout << el.first << " " << el.second;
```

Structured binding:

```cpp
for (auto& [key, value] : mp)
    cout << key << " -> " << value;
```

`map` traversal is sorted by key.

---

## Clear

```cpp
mp.clear();
```

**TC:** O(n)

---

# 4. CORE: C++ `unordered_map`

## Creation

```cpp
unordered_map<string, int> mp;
```

---

## Main operations

```cpp
mp[key] = value;

mp.find(key);
mp.contains(key);

mp.erase(key);

mp.size();
mp.empty();
```

Complexity:

```text
Lookup     O(1) average / O(n) worst
Insert     O(1) average / O(n) worst
Erase      O(1) average / O(n) worst
```

The standard library gives average constant-time search/insertion/removal with linear worst-case bounds.

---

## Ordering

Do **not** rely on iteration order.

```cpp
for (auto& [key, value] : mp)
    ...
```

does not imply sorted or insertion order.

---

# 5. CORE: C++ `multimap`

A `multimap` is:

```text
sorted keys
+
duplicate keys allowed
```

Creation:

```cpp
multimap<int, string> mmap;
```

Insert:

```cpp
mmap.insert({1, "apple"});
mmap.insert({1, "cherry"});
mmap.insert({2, "banana"});
```

Both entries with key `1` exist.

---

## Find / Count

```cpp
mmap.find(key);
mmap.count(key);
```

`count(key)` returns the number of entries with that key.

For duplicate keys, complexity can include the number of matching entries:

```text
O(log n + k)
```

where `k` is the number of equal-key elements returned/countable.

---

## Erase

### Remove all matching keys

```cpp
mmap.erase(key);
```

Removes all entries with that key.

### Remove one matching entry

```cpp
auto it = mmap.find(key);

if (it != mmap.end())
    mmap.erase(it);
```

---

## Lower / Upper Bound

```cpp
auto first = mmap.lower_bound(key);
auto last = mmap.upper_bound(key);
```

All entries with key `key` lie in:

```text
[first, last)
```

---

# 6. CORE: Python `dict`

## Creation

```python
d = {
    1: "One",
    2: "Two",
    3: "Three"
}
```

Constructor:

```python
d = dict([
    (1, "One"),
    (2, "Two"),
    (3, "Three")
])
```

Comprehension:

```python
d = {
    i: f"Number {i}"
    for i in range(1, 4)
}
```

Empty:

```python
d = {}
```

---

## Insert / Update

```python
d[key] = value
```

New key:

```python
d[1] = "One"
```

Existing key:

```python
d[1] = "Uno"
```

updates the value.

Keys are unique.

---

## Access

Direct:

```python
value = d[key]
```

If absent:

```text
KeyError
```

Safe access:

```python
value = d.get(key, default)
```

Important:

> `get()` does **not** insert the missing key.

---

## Membership

```python
key in d
key not in d
```

Average:

**O(1)**

Worst:

**O(n)**

---

## Delete

```python
del d[key]
```

Raises `KeyError` if absent.

```python
value = d.pop(key)
```

Removes and returns the value.

Safe:

```python
value = d.pop(key, default)
```

---

## Size / Empty

```python
len(d)
not d
```

Both:

**TC:** O(1)

---

## Traversal

Keys:

```python
for key in d:
    ...
```

or:

```python
for key in d.keys():
    ...
```

Values:

```python
for value in d.values():
    ...
```

Pairs:

```python
for key, value in d.items():
    ...
```

---

## Insertion Order

Modern Python dictionaries preserve insertion order.

```python
d = {
    "apple": 3,
    "banana": 2,
    "cherry": 5
}
```

Iteration follows that insertion order.

This is an important difference from C++ `map`, which sorts by key, and C++ `unordered_map`, which gives no ordering guarantee. Python specifies dictionary insertion-order preservation.

---

## Clear

```python
d.clear()
```

**TC:** O(n)

---

# 7. CORE C++ vs Python Map Comparison

| Concept | C++ `map` | C++ `unordered_map` | C++ `multimap` | Python `dict` |
|---|---|---|---|---|
| Unique keys | Yes | Yes | **No** | Yes |
| Duplicate keys | No | No | **Yes** | No |
| Ordering | Sorted by key | No guarantee | Sorted by key | **Insertion order** |
| Data structure | Tree | Hash table | Tree | Hash table |
| Lookup | O(log n) | O(1) avg | O(log n) | O(1) avg |
| Insert | O(log n) | O(1) avg | O(log n) | O(1) avg |
| Delete | O(log n) | O(1) avg | O(log n + k) by key | O(1) avg |
| Lower bound | Yes | No | Yes | No built-in |
| Upper bound | Yes | No | Yes | No built-in |
| `operator[]` / equivalent | `mp[key]` inserts if missing | `mp[key]` inserts if missing | No `operator[]` | `d[key]` raises if missing |
| Safe access | `at()` | `at()` | N/A | `get()` |
| Smallest key | `begin()` | No ordering | `begin()` | First inserted key, not smallest |
| Largest key | `rbegin()` | No ordering | `rbegin()` | Last inserted key, not largest |

---

# 8. EXTRAS / REFERENCE — C++

## `lower_bound`

```cpp
auto it = mp.lower_bound(key);
```

First key:

```text
>= key
```

**TC:** O(log n)

---

## `upper_bound`

```cpp
auto it = mp.upper_bound(key);
```

First key:

```text
> key
```

**TC:** O(log n)

---

## `equal_range`

```cpp
auto [first, last] = mp.equal_range(key);
```

Conceptually:

```text
[lower_bound(key), upper_bound(key))
```

Especially useful with `multimap`.

---

## Smallest / Largest Key

For ordered maps:

```cpp
mp.begin()->first
mp.rbegin()->first
```

Both accessor operations are O(1).

Only use them when the map is non-empty.

---

## Custom Ordering

Descending:

```cpp
map<int, string, greater<int>> mp;
```

Custom comparator:

```cpp
struct Compare {
    bool operator()(const string& a,
                    const string& b) const {
        ...
    }
};

map<string, int, Compare> mp;
```

---

## `erase_if`

C++20:

```cpp
erase_if(mp, predicate);
```

Removes all elements satisfying the predicate.

---

## `unordered_map` Hash Policy

```cpp
mp.bucket_count();
mp.load_factor();

mp.reserve(n);
mp.rehash(n);
```

Useful for advanced hash-table control, but not first-pass DSA memory.

---

## `merge`

```cpp
a.merge(b);
```

Transfers nodes from `b` where the destination does not already contain an equivalent key for unique-key maps.

---

## `extract`

```cpp
auto node = mp.extract(key);
```

Extracts a node without destroying its stored key/value.

Advanced C++ library feature.

---

# 9. EXTRAS / REFERENCE — Python

## `dict.update`

```python
d.update(other)
```

Existing keys are overwritten.

---

## `setdefault`

```python
d.setdefault(key, default)
```

If missing:

```text
insert key → default
```

Then returns the value.

A common grouping pattern:

```python
groups.setdefault(key, []).append(value)
```

---

## `defaultdict`

```python
from collections import defaultdict
```

Integer counter:

```python
freq = defaultdict(int)

freq["a"] += 1
```

List grouping:

```python
groups = defaultdict(list)

groups["a"].append(1)
```

String builder:

```python
d = defaultdict(str)
```

Custom factory:

```python
def default_value():
    return "default"

d = defaultdict(default_value)
```

Important:

> Accessing a missing key in a `defaultdict` creates that key using the factory.

---

## `Counter`

```python
from collections import Counter

freq = Counter(["a", "b", "a"])

freq["a"]
freq.most_common()
```

Extremely useful for frequency-counting problems.

---

## `OrderedDict`

```python
from collections import OrderedDict

d = OrderedDict()
```

Normal Python `dict` already preserves insertion order, so `OrderedDict` is primarily useful for its additional order-manipulation APIs.

---

## `move_to_end`

```python
d.move_to_end(key)
d.move_to_end(key, last=False)
```

Moves the key to the end or beginning.

Missing key:

```text
KeyError
```

---

## `popitem`

For `OrderedDict`:

```python
d.popitem()
d.popitem(last=False)
```

The first removes the last item; the second removes the first item.

A normal `dict.popitem()` removes the last inserted item and does not expose `last=False`.

---

## Dictionary Views

```python
d.keys()
d.values()
d.items()
```

These return dynamic view objects.

Convert to actual lists:

```python
list(d.keys())
list(d.values())
list(d.items())
```

---

## Dictionary Merge

Python 3.9+:

```python
c = a | b
```

Right-hand values win on duplicate keys.

In-place:

```python
a |= b
```

---

## First / Last Key

Because normal Python dict preserves insertion order:

```python
first_key = next(iter(d))
last_key = next(reversed(d))
```

These mean:

```text
first inserted key
last inserted key
```

They do **not** mean numerically smallest/largest key.

---

## Safe Deletion While Iterating

Don't change dictionary size directly during iteration:

```python
# Bad
for key in d:
    del d[key]
```

Use:

```python
for key in list(d):
    if condition:
        del d[key]
```

Or construct a filtered dictionary.

---

# 10. Core DSA Pattern: Frequency Map

## C++

```cpp
unordered_map<int, int> freq;

for (int x : a)
    ++freq[x];
```

Average:

**TC:** O(n)  
**SC:** O(distinct values)

---

## Python

```python
freq = {}

for x in a:
    freq[x] = freq.get(x, 0) + 1
```

Or:

```python
from collections import Counter

freq = Counter(a)
```

Average:

**TC:** O(n)  
**SC:** O(distinct values)

---

# 11. Core DSA Pattern: Grouping

## C++

```cpp
unordered_map<string, vector<int>> groups;

groups["even"].push_back(2);
groups["even"].push_back(4);
```

## Python

```python
from collections import defaultdict

groups = defaultdict(list)

groups["even"].append(2)
groups["even"].append(4)
```

---

# 12. Important Semantic Differences

## C++ `map[key]` vs Python `d[key]`

C++:

```cpp
mp[key]
```

If missing:

```text
creates the key
with a default value
```

Python:

```python
d[key]
```

If missing:

```text
raises KeyError
```

This is one of the most important differences to remember.

---

## Safe access

C++:

```cpp
mp.at(key)
```

Python:

```python
d.get(key)
```

But their semantics differ:

- C++ `at()` throws if missing.
- Python `get()` returns `None` or the supplied default.

---

# 13. Common DSA Traps

### `map` and `unordered_map` are equivalent

→ No.

```text
map           sorted + O(log n)
unordered_map unordered + O(1) average
```

### Python `dict` is sorted by key

→ No. It preserves **insertion order**, not key-sorted order.

### `unordered_map` iteration is random

→ More precisely: there is **no ordering guarantee**. Don't rely on a particular order.

### `map[key]` only reads

→ No. If the key is missing, it inserts it.

### Python `d[key]` creates a missing key with a default

→ No. It raises `KeyError`.

### `d.get(key, 0)` inserts key if absent

→ No. `get()` simply returns the default.

### `multimap.erase(key)` removes one key-value pair

→ No. It removes **all entries with that equivalent key**.

### `multimap.find(key)` gives every matching pair

→ No. It gives an iterator to one matching entry. Use `lower_bound`/`upper_bound` or `equal_range` for the full range.

### Python `defaultdict` behaves exactly like `dict`

→ Not quite. Accessing a missing key creates it using the default factory.

### `OrderedDict` is needed just to preserve insertion order

→ Not in modern Python. Normal `dict` already guarantees insertion order. `OrderedDict` is useful for its extra reordering behavior.

---

# 14. What to Memorize

## MUST KNOW — C++

### `map`

```cpp
map<int,int> mp;

mp[key] = value;
mp.find(key);
mp.contains(key);
mp.at(key);

mp.erase(key);

mp.size();
mp.empty();

mp.lower_bound(key);
mp.upper_bound(key);
```

### `unordered_map`

```cpp
unordered_map<int,int> mp;

mp[key] = value;
mp.find(key);
mp.contains(key);

mp.erase(key);
```

### `multimap`

```cpp
multimap<int,string> mp;

mp.insert({key, value});
mp.find(key);
mp.count(key);

mp.erase(key);       // all matching keys

mp.lower_bound(key);
mp.upper_bound(key);
```

### Critical complexity

```text
map:
    lookup / insert / erase → O(log n)

unordered_map:
    average → O(1)
    worst   → O(n)

multimap:
    sorted + duplicate keys
```

---

## MUST KNOW — Python

```python
d = {}

d[key] = value
d[key]
d.get(key, default)

key in d

del d[key]
d.pop(key)

len(d)
not d

for key in d:
    ...

for value in d.values():
    ...

for key, value in d.items():
    ...

d.update(other)
```

And these DSA essentials:

```python
from collections import defaultdict, Counter
```

### Critical complexity

```text
dict lookup / insert / delete
    O(1) average
    O(n) worst
```

---

# 15. REFERENCE ONLY

## C++

```text
insert()
insert_or_assign()
try_emplace()
equal_range()
custom comparator
erase_if()
bucket_count()
load_factor()
reserve()
rehash()
merge()
extract()
```

## Python

```text
dict comprehension
setdefault()
defaultdict
Counter
OrderedDict
move_to_end()
popitem()
keys()/values()/items()
dictionary merge operator |
```

---

# 16. One-Glance Syntax Reference

| Operation | C++ `map` | C++ `unordered_map` | C++ `multimap` | Python `dict` |
|---|---|---|---|---|
| Create | `map<K,V> mp` | `unordered_map<K,V> mp` | `multimap<K,V> mp` | `d = {}` |
| Insert/update | `mp[k]=v` | `mp[k]=v` | `mp.insert({k,v})` | `d[k]=v` |
| Insert only | `mp.insert(...)` | `mp.insert(...)` | `mp.insert(...)` | N/A |
| Safe read | `mp.at(k)` | `mp.at(k)` | N/A | `d.get(k)` |
| Lookup | `mp.find(k)` | `mp.find(k)` | `mp.find(k)` | `k in d` |
| Contains | `mp.contains(k)` | `mp.contains(k)` | `mp.contains(k)` | `k in d` |
| Erase key | `mp.erase(k)` | `mp.erase(k)` | `mp.erase(k)` → all | `del d[k]` |
| Erase one | iterator | iterator | iterator | `pop(k)` |
| Size | `mp.size()` | `mp.size()` | `mp.size()` | `len(d)` |
| Empty | `mp.empty()` | `mp.empty()` | `mp.empty()` | `not d` |
| Clear | `mp.clear()` | `mp.clear()` | `mp.clear()` | `d.clear()` |
| Traverse | `for(auto& [k,v]:mp)` | same | same | `for k,v in d.items()` |
| Lower bound | `mp.lower_bound(k)` | No | `mp.lower_bound(k)` | No built-in |
| Upper bound | `mp.upper_bound(k)` | No | `mp.upper_bound(k)` | No built-in |
| Equal range | `mp.equal_range(k)` | No | `mp.equal_range(k)` | No direct equivalent |

---

# 17. Final Mental Model

```text
MAP

Need UNIQUE + SORTED KEYS?
        ↓
     C++ map
        O(log n)

Need UNIQUE + FAST AVERAGE LOOKUP?
        ↓
C++ unordered_map / Python dict
        O(1) average

Need DUPLICATE KEYS + SORTED KEYS?
        ↓
    C++ multimap
        O(log n)

Need FREQUENCY COUNTING?
        ↓
C++ unordered_map
Python dict / Counter

Need GROUPING?
        ↓
C++ unordered_map<K, vector<V>>
Python defaultdict(list)
```

### The most important distinction to memorize

```text
C++ map
    sorted by key

C++ unordered_map
    no ordering guarantee

C++ multimap
    sorted + duplicate keys

Python dict
    insertion order + unique keys
```

---

# 18. Source Notes

The C++ API/complexity distinctions here follow the standard-library documentation for `map`, `unordered_map`, and `multimap`, including ordered logarithmic operations, average constant-time hashing operations, duplicate-key behavior, and bounds.

Python dictionary behavior, insertion ordering, hashable keys, and the `defaultdict`/dictionary operation model follow the Python documentation and current CPython complexity references.

---

# 19. Files

- `maps_cpp.cpp` → runnable C++ reference
- `maps_python.py` → runnable Python reference
- `maps_cpp_python.md` → comparison + revision sheet
