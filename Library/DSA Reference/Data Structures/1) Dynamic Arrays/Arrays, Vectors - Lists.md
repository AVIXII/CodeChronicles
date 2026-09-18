# Arrays — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Primary dynamic-array pair:** `std::vector` ↔ `list`

---

# 0. How to Use This Sheet

This sheet is intentionally split into two levels:

- **CORE / MUST KNOW** → memorize these for DSA.
- **EXTRAS / REFERENCE** → know that they exist; look them up when needed.

The runnable `.cpp` and `.py` files follow the same organization.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
C++ vector                    Python list
-----------                   -----------
dynamic array                 dynamic array
random access O(1)            random access O(1)
append O(1) amortized         append O(1) amortized
middle insert O(n)            middle insert O(n)
middle delete O(n)            middle delete O(n)
```

The reason middle insertion/deletion is linear is simple: existing elements generally have to be shifted.

---

## Core Complexity Table

| Operation | C++ `vector` | Python `list` | Why / Important Note |
|---|---:|---:|---|
| Access by index | **O(1)** | **O(1)** | Random access |
| Update by index | **O(1)** | **O(1)** | Direct assignment |
| Search by value | **O(n)** | **O(n)** | Linear scan |
| Append at end | **O(1) amortized** | **O(1) amortized** | Occasional growth/reallocation |
| Insert at beginning | **O(n)** | **O(n)** | Shift elements |
| Insert at middle | **O(n)** | **O(n)** | Shift elements |
| Delete last | **O(1)** | **O(1)** | No shifting |
| Delete beginning | **O(n)** | **O(n)** | Shift elements |
| Delete middle | **O(n)** | **O(n)** | Shift elements |
| Minimum | **O(n)** | **O(n)** | Unsorted array requires scan |
| Maximum | **O(n)** | **O(n)** | Unsorted array requires scan |
| Reverse | **O(n)** | **O(n)** | In-place for normal operations |
| Sort | **O(n log n)** | **O(n log n)** | Built-in sorting |
| Copy | **O(n)** | **O(n)** | Creates a new container |
| Slice / subrange copy | **O(k)** | **O(k)** | `k` = copied elements |
| Binary search | **O(log n)** | **O(log n)** with `bisect` | Sorted/partitioned data required |
| Lower bound | **O(log n)** for vector/random access | **O(log n)** | Sorted data |
| Upper bound | **O(log n)** for vector/random access | **O(log n)** | Sorted data |

### Memorize this first

```text
Access          O(1)
Search          O(n)
Append          O(1) amortized
Insert          O(n)
Delete          O(n)
Min / Max       O(n)
Reverse         O(n)
Sort            O(n log n)
Binary Search   O(log n)   [sorted]
```

---

# 2. CORE: C++ `vector`

## Creation

```cpp
vector<int> v;                 // empty
vector<int> v1(10);            // 10 zero/value-initialized ints
vector<int> v2(15, 2);         // {2,2,...,2}
vector<int> v3 = {1,2,3,4,5};
```

From a range:

```cpp
int arr[] = {1,2,3};

vector<int> v(arr, arr + 3);
```

Copy:

```cpp
vector<int> b = v;
```

---

## Size / Empty

```cpp
v.size()
v.empty()
```

**TC:** O(1)

---

## Access

```cpp
v[i]          // O(1)
v.at(i)       // O(1), bounds checked
v.front()     // O(1)
v.back()      // O(1)
```

Important:

```text
v[i]      -> unchecked
v.at(i)   -> bounds checked
```

C++ has no Python-style negative indexing.

---

## Update

```cpp
v[i] = x;
```

**TC:** O(1)

---

## Insert

```cpp
v.push_back(x);              // end
v.insert(v.begin(), x);      // beginning
v.insert(v.begin()+i, x);    // index
```

**Complexity**

```text
push_back        O(1) amortized
insert middle    O(n)
insert beginning O(n)
```

---

## Delete

```cpp
v.pop_back();                         // last
v.erase(v.begin());                   // first
v.erase(v.begin()+i);                // index
v.erase(v.begin()+l, v.begin()+r);   // range [l,r)
```

**Complexity**

```text
pop_back      O(1)
erase index   O(n) worst/typical
erase range   O(n) in general
```

---

## Search

```cpp
find(v.begin(), v.end(), x);
```

Check:

```cpp
auto it = find(v.begin(), v.end(), x);

if (it != v.end()) {
    // found
}
```

**TC:** O(n)

Count:

```cpp
count(v.begin(), v.end(), x);
```

**TC:** O(n)

---

## Traversal

Index:

```cpp
for (int i = 0; i < (int)v.size(); ++i)
    cout << v[i];
```

Range:

```cpp
for (int x : v)
    cout << x;
```

Iterator:

```cpp
for (auto it = v.begin(); it != v.end(); ++it)
    cout << *it;
```

All:

**TC:** O(n), **SC:** O(1)

---

## Min / Max / Sum

```cpp
*min_element(v.begin(), v.end());
*max_element(v.begin(), v.end());
accumulate(v.begin(), v.end(), 0);
```

Each:

**TC:** O(n), **SC:** O(1) auxiliary.

---

## Reverse

```cpp
reverse(v.begin(), v.end());
```

**TC:** O(n)  
**SC:** O(1)

---

## Sort

```cpp
sort(v.begin(), v.end());
```

```cpp
sort(v.rbegin(), v.rend());
```

Custom comparator:

```cpp
sort(v.begin(), v.end(), [](int a, int b) {
    return a > b;
});
```

**TC:** O(n log n)

---

## Clear

```cpp
v.clear();
```

Logical size becomes zero.

Important:

```text
size != capacity
```

`clear()` does not mean that capacity must become zero.

---

# 3. CORE: Python `list`

## Creation

```python
a = []
a = [1, 2, 3]
a = [0] * 10
a = list(range(10))
```

List comprehension:

```python
squares = [x*x for x in range(10)]
```

---

## Size / Empty

```python
len(a)
not a
```

Both:

**TC:** O(1)

---

## Access

```python
a[i]
a[-1]       # last
```

**TC:** O(1)

Python supports negative indexing.

---

## Update

```python
a[i] = x
```

**TC:** O(1)

---

## Insert

```python
a.append(x)          # end
a.insert(i, x)       # index
a.extend(b)          # append iterable
```

**Complexity**

```text
append       O(1) amortized
insert       O(n)
extend       O(k)
```

---

## Delete

```python
a.pop()              # last
a.pop(i)             # index
del a[i]             # index
del a[l:r]           # range
a.remove(x)          # first matching value
a.clear()            # all
```

**Complexity**

```text
pop()          O(1)
pop(i)         O(n) in general
del a[i]       O(n) in general
remove(x)      O(n)
clear()        O(n)
```

---

## Search

```python
x in a
```

**TC:** O(n)

First occurrence:

```python
a.index(x)
```

**TC:** O(n)

Count:

```python
a.count(x)
```

**TC:** O(n)

---

## Traversal

```python
for x in a:
    ...
```

With index:

```python
for i, x in enumerate(a):
    ...
```

Reverse:

```python
for x in reversed(a):
    ...
```

All:

**TC:** O(n), **SC:** O(1) auxiliary.

---

## Min / Max / Sum

```python
min(a)
max(a)
sum(a)
```

Each:

**TC:** O(n)

---

## Reverse

In place:

```python
a.reverse()
```

**TC:** O(n)  
**SC:** O(1) auxiliary.

New reversed list:

```python
b = a[::-1]
```

**TC:** O(n)  
**SC:** O(n)

---

## Sort

In place:

```python
a.sort()
```

Descending:

```python
a.sort(reverse=True)
```

New list:

```python
b = sorted(a)
```

Key:

```python
a.sort(key=lambda x: x[1])
```

**TC:** O(n log n)

---

# 4. CORE: C++ vs Python Syntax Map

| Concept | C++ | Python |
|---|---|---|
| Dynamic array | `vector<int>` | `list` |
| Access | `v[i]` | `a[i]` |
| Last | `v[n-1]` | `a[-1]` |
| Size | `v.size()` | `len(a)` |
| Empty | `v.empty()` | `not a` |
| Update | `v[i] = x` | `a[i] = x` |
| Append | `v.push_back(x)` | `a.append(x)` |
| Pop last | `v.pop_back()` | `a.pop()` |
| Insert | `v.insert(...)` | `a.insert(...)` |
| Delete index | `v.erase(...)` | `del a[i]` / `a.pop(i)` |
| Delete value | `erase(...)` / `find` | `a.remove(x)` |
| Search | `find(...)` | `x in a` |
| Count | `count(...)` | `a.count(x)` |
| Reverse | `reverse(...)` | `a.reverse()` |
| Sort | `sort(...)` | `a.sort()` |
| Min | `*min_element(...)` | `min(a)` |
| Max | `*max_element(...)` | `max(a)` |
| Sum | `accumulate(...)` | `sum(a)` |
| Copy | `vector<int> b = a` | `b = a.copy()` |
| Binary search | `binary_search(...)` | `bisect_left/right()` |

---

# 5. EXTRAS / REFERENCE

These are useful, but do **not** belong in your first memorization pass.

---

## C++: C-style arrays

```cpp
int arr[5] = {1,2,3,4,5};
```

Properties:

```text
fixed size
contiguous storage
O(1) indexing
no push_back
no erase
no resize
```

Size while still an actual array:

```cpp
sizeof(arr) / sizeof(arr[0])
```

Be careful: arrays decay to pointers when passed to functions in many contexts.

---

## C++: `std::array`

```cpp
array<int, 5> a = {1,2,3,4,5};
```

Useful methods:

```cpp
a.size();
a.empty();
a.front();
a.back();
a.fill(10);
```

It is fixed-size.

---

## C++: `capacity()`

```cpp
v.capacity()
```

**TC:** O(1)

`size()` = logical elements.

`capacity()` = allocated element capacity.

---

## C++: `reserve()`

```cpp
v.reserve(100);
```

Important:

```text
reserve() changes capacity
reserve() does NOT change size
```

It can prevent unnecessary reallocations.

---

## C++: `resize()`

```cpp
v.resize(10);
v.resize(20, 5);
v.resize(5);
```

Unlike `reserve()`, `resize()` changes the logical size.

---

## C++: `shrink_to_fit()`

```cpp
v.shrink_to_fit();
```

Requests reduction of capacity.

Important:

```text
It is a non-binding request.
Do not rely on it as a guaranteed exact-capacity operation.
```

---

## C++: lower / upper bound

Sorted vector:

```cpp
lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);
```

Meaning:

```text
lower_bound -> first element >= x
upper_bound -> first element > x
```

For random-access arrays/vectors:

**TC:** O(log n)

Equal range:

```cpp
equal_range(v.begin(), v.end(), x);
```

Returns:

```text
[lower_bound, upper_bound)
```

---

## Python: `bisect`

```python
from bisect import bisect_left, bisect_right
```

```python
bisect_left(a, x)
bisect_right(a, x)
```

Meaning:

```text
bisect_left  -> first position where x can be inserted
                while keeping sorted order, before equal values

bisect_right -> first position after equal values
```

**TC:** O(log n)

Important:

```text
bisect searches for a position.
It does not sort the list.
```

Insertion with Python's `insort()` still costs O(n) because the list must shift elements.

---

## Python: slicing

```python
a[l:r]
```

creates a new list.

**TC:** O(k)  
**SC:** O(k)

Useful:

```python
a[:]
a[::-1]
a[::2]
```

---

## Python: slice assignment

Insert:

```python
a[i:i] = [x, y]
```

Replace:

```python
a[l:r] = [x, y]
```

Delete:

```python
del a[l:r]
```

This can change list length.

---

## Python: aliasing

```python
a = [1,2,3]
b = a
```

`a` and `b` refer to the same list.

Copy:

```python
b = a.copy()
```

or:

```python
b = a[:]
```

---

## Python: shallow vs deep copy

```python
from copy import deepcopy

b = a.copy()
c = deepcopy(a)
```

`copy()` copies the outer list.

`deepcopy()` recursively copies nested objects.

---

# 6. Nested Arrays / Matrices

## C++

```cpp
vector<vector<int>> matrix(
    n,
    vector<int>(m, 0)
);
```

**TC:** O(nm)  
**SC:** O(nm)

---

## Python

Correct:

```python
matrix = [[0] * m for _ in range(n)]
```

Avoid:

```python
matrix = [[0] * m] * n
```

because every row references the same inner list.

This is one of the most important Python list traps for DSA.

---

# 7. Copy vs Move

## C++

Copy:

```cpp
vector<int> b = a;
```

**TC:** O(n)

Move:

```cpp
vector<int> b = move(a);
```

For normal `vector` usage with standard allocators, moving transfers ownership of the underlying storage rather than copying every element.

After moving, the source vector remains valid but its exact contents should not be relied on.

---

## Python

Assignment:

```python
b = a
```

creates another reference.

Shallow copy:

```python
b = a.copy()
```

creates a new list.

---

# 8. Iterator / Reference Invalidation

## C++ `vector`

Important DSA rules:

```text
Reallocation:
    invalidates all iterators/references/pointers.

erase():
    invalidates iterators/references at and after the erased position.

push_back():
    if reallocation occurs -> all invalidated.
    without reallocation -> existing element references remain valid;
                            end() may change.

reserve():
    may trigger reallocation.
```

This matters when using stored iterators or references.

Python does not expose an equivalent C++-style iterator invalidation model for everyday list use, but mutating a list while iterating over it can still produce incorrect logic.

---

# 9. Delete All Occurrences

## C++20

```cpp
erase(v, x);
```

**TC:** O(n)

Classic C++ pattern:

```cpp
v.erase(
    remove(v.begin(), v.end(), x),
    v.end()
);
```

**TC:** O(n)

---

## Python

```python
a = [x for x in a if x != target]
```

**TC:** O(n)  
**SC:** O(n) for the new list.

To mutate the existing list object:

```python
a[:] = [x for x in a if x != target]
```

---

# 10. Concatenation

## C++

A practical approach:

```cpp
vector<int> c;
c.reserve(a.size() + b.size());

c.insert(c.end(), a.begin(), a.end());
c.insert(c.end(), b.begin(), b.end());
```

**TC:** O(n+m)  
**SC:** O(n+m) for result.

## Python

```python
c = a + b
```

**TC:** O(n+m)  
**SC:** O(n+m)

---

# 11. Prefix Sum

## C++

```cpp
vector<int> prefix(n);

partial_sum(
    a.begin(),
    a.end(),
    prefix.begin()
);
```

**TC:** O(n)  
**SC:** O(n)

Manual form:

```cpp
prefix[0] = a[0];

for (int i = 1; i < n; ++i)
    prefix[i] = prefix[i-1] + a[i];
```

---

## Python

```python
prefix = [0] * len(a)

if a:
    prefix[0] = a[0]

for i in range(1, len(a)):
    prefix[i] = prefix[i-1] + a[i]
```

**TC:** O(n)  
**SC:** O(n)

---

# 12. Manual Algorithms Worth Knowing

## Linear Search

### C++

```cpp
int findIndex(const vector<int>& a, int x) {
    for (int i = 0; i < (int)a.size(); ++i)
        if (a[i] == x)
            return i;

    return -1;
}
```

### Python

```python
def find_index(a, x):
    for i, value in enumerate(a):
        if value == x:
            return i
    return -1
```

**TC:** O(n)  
**SC:** O(1)

---

## Binary Search

### C++

```cpp
int binarySearch(const vector<int>& a, int x) {
    int l = 0;
    int r = (int)a.size() - 1;

    while (l <= r) {
        int m = l + (r-l)/2;

        if (a[m] == x)
            return m;

        if (a[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }

    return -1;
}
```

### Python

```python
def binary_search(a, x):
    l, r = 0, len(a)-1

    while l <= r:
        m = l + (r-l)//2

        if a[m] == x:
            return m

        if a[m] < x:
            l = m + 1
        else:
            r = m - 1

    return -1
```

**TC:** O(log n)  
**SC:** O(1)

---

## Two-Pointer Reverse

### C++

```cpp
int l = 0;
int r = a.size() - 1;

while (l < r)
    swap(a[l++], a[r--]);
```

### Python

```python
l, r = 0, len(a)-1

while l < r:
    a[l], a[r] = a[r], a[l]
    l += 1
    r -= 1
```

**TC:** O(n)  
**SC:** O(1)

---

# 13. Common DSA Traps

## Core traps

**`push_back()` / `append()` is always O(1)**  
→ No. Treat it as **O(1) amortized**.

**Middle insertion is O(1)**  
→ No. Existing elements generally shift: **O(n)**.

**Middle deletion is O(1)**  
→ No. Remaining elements generally shift: **O(n)**.

**Binary search works on any array**  
→ No. The data must satisfy the required sorted/partitioned condition.

**Finding min/max is O(1)**  
→ No. On an unsorted array it is **O(n)**.

**Python `b = a` copies the list**  
→ No. It creates another reference to the same list.

**Python `a[::-1]` reverses in place**  
→ No. It creates a new list.

**`reserve(n)` creates n C++ vector elements**  
→ No. It changes capacity, not size.

**`resize(n)` only reserves memory**  
→ No. It changes logical size.

---

# 14. Core vs Extras: What to Memorize

## MUST MEMORIZE

### C++

```cpp
vector<int> v;

v[i]
v.size()
v.empty()

v.push_back(x)
v.pop_back()

v.insert(...)
v.erase(...)

find(...)
count(...)

*min_element(...)
*max_element(...)
accumulate(...)

reverse(...)
sort(...)

binary_search(...)
```

### Python

```python
a = []

a[i]
a[-1]
len(a)
not a

a.append(x)
a.pop()
a.insert(i, x)
del a[i]

x in a
a.index(x)
a.count(x)

min(a)
max(a)
sum(a)

a.reverse()
a.sort()

bisect_left(a, x)
bisect_right(a, x)
```

---

## REFERENCE ONLY

### C++

```text
std::array
C-style arrays
reserve()
capacity()
resize()
shrink_to_fit()
lower_bound()
upper_bound()
equal_range()
erase-remove idiom
data()
iterator invalidation
move()
partial_sum()
```

### Python

```text
slicing
slice assignment
copy()
deepcopy()
bisect module
extend()
list repetition
nested-list aliasing
```

---

# 15. One-Glance Syntax Reference

| Operation | C++ | Python |
|---|---|---|
| Create | `vector<int> v;` | `a = []` |
| Values | `vector<int> v{1,2,3};` | `a = [1,2,3]` |
| Access | `v[i]` | `a[i]` |
| Last | `v.back()` / `v[n-1]` | `a[-1]` |
| Update | `v[i] = x` | `a[i] = x` |
| Size | `v.size()` | `len(a)` |
| Empty | `v.empty()` | `not a` |
| Append | `v.push_back(x)` | `a.append(x)` |
| Pop last | `v.pop_back()` | `a.pop()` |
| Insert | `v.insert(...)` | `a.insert(i,x)` |
| Delete | `v.erase(...)` | `del a[i]` |
| Delete value | `erase(...)` | `a.remove(x)` |
| Search | `find(...)` | `x in a` |
| Count | `count(...)` | `a.count(x)` |
| Min | `*min_element(...)` | `min(a)` |
| Max | `*max_element(...)` | `max(a)` |
| Sum | `accumulate(...)` | `sum(a)` |
| Reverse | `reverse(...)` | `a.reverse()` |
| Sort | `sort(...)` | `a.sort()` |
| Binary search | `binary_search(...)` | `bisect_left/right()` |
| Lower bound | `lower_bound(...)` | `bisect_left()` |
| Upper bound | `upper_bound(...)` | `bisect_right()` |
| Copy | `vector<int> b=a;` | `b=a.copy()` |
| Clear | `v.clear()` | `a.clear()` |

---

# 16. Final Mental Model

```text
ARRAY / DYNAMIC ARRAY

Access                  O(1)
Update                  O(1)

Search                  O(n)

End insertion           O(1) amortized
Beginning insertion     O(n)
Middle insertion        O(n)

End deletion            O(1)
Beginning deletion      O(n)
Middle deletion         O(n)

Min / Max               O(n)
Reverse                 O(n)
Sort                    O(n log n)

Binary search           O(log n)
                        only with the required ordering assumption
```

The core idea is more important than memorizing every API:

```text
Contiguous dynamic array
        ↓
Random access            → O(1)
        ↓
Need to shift elements   → O(n)
        ↓
End insertion/deletion   → amortized O(1)
```

---

## Files

- `arrays_cpp.cpp` → runnable C++ reference
- `arrays_python.py` → runnable Python reference
- `arrays_cpp_python.md` → comparison + revision sheet
