# Miscellaneous Toolbox — C++ vs Python
### DSA / Competitive Programming / “Why does this even work?” Cheat Sheet

> **Purpose:** A catch-all reference for small tricks, standard-library helpers, language quirks, conversions, shortcuts, and common traps that do not deserve their own data-structure chapter but absolutely show up in DSA code.
>
> The sheet keeps the supplied C++ examples and expands them with closely related high-value patterns.

---

# CORE / MUST KNOW

## 1. Quick Comparison

| Task | C++ | Python |
|---|---|---|
| Number → string | `to_string(x)` | `str(x)` |
| String → integer | `stoi(s)`, `stoll(s)` | `int(s)` |
| String → float | `stof`, `stod` | `float(s)` |
| Parse arbitrary formatted text | `stringstream` | `split()`, parsing, `io.StringIO` |
| Character → integer | `c - '0'`, `int(c)` equivalent via cast | `ord(c)` |
| Integer → character digit | `'0' + d` | `chr(ord('0') + d)` |
| Character code | `static_cast<int>(c)` | `ord(c)` |
| Pair | `pair<T1,T2>` | tuple `(a,b)` |
| Tuple | `tuple<...>` | `tuple` |
| Unpack | structured bindings | tuple/list unpacking |
| Swap | `swap(a,b)` | `a,b=b,a` |
| GCD | `gcd(a,b)` | `math.gcd(a,b)` |
| LCM | `lcm(a,b)` | `math.lcm(a,b)` |
| Prefix sum | `accumulate` / `partial_sum` | `itertools.accumulate` |
| Fill sequence | `iota` | `range`, comprehensions |
| Clamp | `clamp(x, lo, hi)` | `min(max(x, lo), hi)` |
| Count occurrences | `count` | `.count()` / `Counter` |
| Search | `find` | `in`, `.find()`, `bisect` |
| Binary search | `binary_search` | `bisect` |
| Reverse | `reverse` | `[::-1]`, `reversed()` |
| Permutations | `next_permutation` | `itertools.permutations` |
| Remove matching elements | erase-remove / `erase_if` | comprehension |
| Infinity | `numeric_limits<double>::infinity()` | `float("inf")` |
| Fast input | `ios::sync_with_stdio(false)` etc. | `sys.stdin.buffer` |
| Identity check | pointer/object identity concepts | `is` |

---

## 2. Your `string::replace()` Pattern

### C++

```cpp
string s = "rishabh";

s.replace(0, s.length(), "ahdskfa ");

cout << s;
```

General form:

```cpp
s.replace(pos, count, replacement);
```

Example:

```cpp
string s = "abcdef";

s.replace(2, 2, "XYZ");

// abXYZef
```

### Python

Python strings are immutable, so `replace()` returns a **new string**:

```python
s = "rishabh"
s = s.replace("rishabh", "ahdskfa ")
```

```text
C++: modifies std::string
Python: returns a new str
```

---

## 3. `to_string()` / `str()`

### C++

```cpp
string intStr = to_string(42);
string floatStr = to_string(3.141590);
string doubleStr = to_string(2.718280);
```

`std::to_string` is available since C++11 and has overloads for integral and floating-point types. citeturn377363search0

### Complexity

For integers:

```text
O(number of output digits)
≈ O(log |n|)
```

For floating-point values, the actual cost depends on the formatting/output length and conversion implementation. So the note `to_string() O(log(n))` is a useful integer mental model, not a universal complexity statement.

### Important floating-point quirk

Before C++26, floating-point `std::to_string()` behaves approximately like `printf("%f", value)`.

Therefore:

```cpp
to_string(3.14)
```

can produce:

```text
3.140000
```

rather than exactly the text you may expect from normal `cout`. C++26 changes the specification to use `std::format`-style conversion. citeturn377363search0

### Python

```python
str(42)
str(3.14)
```

For controlled formatting:

```python
f"{3.1415926:.2f}"
```

---

## 4. String → Number

### C++

```cpp
stoi("123");                 // int
stoll("1234567890123");      // long long
stoi("1010", nullptr, 2);    // base 2 → 10
```

Other useful functions:

```text
stol
stoll
stoul
stoull
stof
stod
stold
```

These are standard string conversion functions in `<string>`. citeturn775717search4turn377363search7

### Python

```python
int("123")
int("1010", 2)
float("3.14")
```

---

## 5. `stringstream`

C++'s little “turn this text into typed values without manually parsing every character” machine.

```cpp
string s = "10 20 30";

stringstream ss(s);

int a, b, c;
ss >> a >> b >> c;
```

Also useful for constructing strings:

```cpp
stringstream ss;

ss << "answer = " << 42
   << ", pi = " << 3.14;

string result = ss.str();
```

For many CP problems, `stringstream` is convenient but unnecessary when simple `cin`, `stoi`, or direct parsing works.

---

## 6. Character Arithmetic

### C++

```cpp
char c = 'A';

int code = c;
char next = c + 1;
```

Digit conversion:

```cpp
char digit = '7';

int value = digit - '0';
```

Reverse:

```cpp
int n = 5;

char c = '0' + n;
```

Alphabet trick:

```cpp
char c = 'a' + 2;   // c
```

These depend on the execution character set having the expected contiguous digit/letter representation. ASCII is overwhelmingly common in CP environments.

### Python

```python
ord('A')        # 65
chr(65)         # 'A'

ord('7') - ord('0')   # 7
chr(ord('0') + 5)     # '5'
```

---

## 7. `pair`, `tuple`, and Unpacking

### C++

```cpp
pair<int, string> p = {1, "one"};

cout << p.first;
cout << p.second;
```

Tuple:

```cpp
tuple<int, string, double> t = {7, "seven", 7.7};

get<0>(t);
get<1>(t);
get<2>(t);
```

Structured binding:

```cpp
auto [x, y] = p;
```

Structured bindings were introduced in C++17. citeturn775717search1

Reference form:

```cpp
auto& [x, y] = p;

x = 100;   // modifies p.first
```

### Python

```python
p = (1, "one")

x, y = p
```

---

## 8. `tie()` and `ignore`

### C++

```cpp
pair<int, int> p = {10, 20};

int x, y;
tie(x, y) = p;
```

Ignore a value:

```cpp
int y;
tie(ignore, y) = p;
```

`std::tie` creates a tuple of lvalue references and is commonly used to unpack pairs/tuples or selectively ignore returned values. citeturn775717search8

Modern code often uses structured bindings instead:

```cpp
auto [x, y] = p;
```

---

## 9. Swap

### C++

```cpp
swap(a, b);
```

### Python

```python
a, b = b, a
```

No temporary variable required in Python.

---

## 10. `std::exchange`

A surprisingly useful tiny operation:

```cpp
int x = 10;

int old = exchange(x, 100);

// old = 10
// x = 100
```

Mental model:

```text
return old value
replace with new value
```

---

## 11. `min`, `max`, and `clamp`

### C++

```cpp
min(a, b);
max(a, b);

min({5, 2, 9, 1});
max({5, 2, 9, 1});

clamp(x, low, high);
```

`clamp(x, low, high)` means:

```text
x < low  → low
low ≤ x ≤ high → x
x > high → high
```

### Python

```python
min(a, b)
max(a, b)

min([5, 2, 9, 1])
max([5, 2, 9, 1])

min(max(x, low), high)
```

---

## 12. `gcd()` / `lcm()`

### C++

```cpp
gcd(24, 18);   // 6
lcm(6, 8);     // 24
```

These are C++17 `<numeric>` utilities. citeturn775717search0turn775717search2

### Python

```python
import math

math.gcd(24, 18)
math.lcm(6, 8)
```

---

## 13. `iota()` and `accumulate()`

### C++

```cpp
vector<int> a(5);

iota(a.begin(), a.end(), 1);

// 1 2 3 4 5
```

`std::iota` fills a range with successive increments. citeturn377363search4

Sum:

```cpp
int sum = accumulate(a.begin(), a.end(), 0);
```

Product:

```cpp
long long product =
    accumulate(a.begin(), a.end(), 1LL,
               [](long long acc, int x) {
                   return acc * x;
               });
```

### CRITICAL TYPE TRAP

```cpp
vector<int> a = {...};

accumulate(a.begin(), a.end(), 0);
```

The accumulation starts as `int`.

For a `long long` result:

```cpp
accumulate(a.begin(), a.end(), 0LL);
```

This tiny suffix has saved many programmers from the beautiful experience of integer overflow.

---

## 14. Prefix Sums

### C++

```cpp
vector<int> a = {1, 2, 3, 4};

vector<int> pref(a.size());

partial_sum(a.begin(), a.end(), pref.begin());
```

Or modern explicit loop:

```cpp
for (int i = 1; i < n; i++)
    pref[i] = pref[i - 1] + a[i];
```

### Python

```python
from itertools import accumulate

pref = list(accumulate(a))
```

---

## 15. Lambdas

### C++

```cpp
auto square = [](int x) {
    return x * x;
};
```

Capture a value:

```cpp
int base = 10;

auto f = [base](int x) {
    return base + x;
};
```

Capture by reference:

```cpp
auto f = [&base]() {
    base++;
};
```

Most common CP use:

```cpp
sort(v.begin(), v.end(),
     [](const auto& a, const auto& b) {
         return a > b;
     });
```

---

## 16. Sorting with Custom Keys

### C++

```cpp
vector<pair<int,int>> v = {
    {2,5}, {1,9}, {2,3}, {1,4}
};

sort(v.begin(), v.end());
```

Default pair ordering is lexicographical:

```text
first ascending
then second ascending
```

Custom:

```cpp
sort(v.begin(), v.end(),
     [](auto& a, auto& b) {
         if (a.first != b.first)
             return a.first < b.first;

         return a.second > b.second;
     });
```

### Python

```python
sorted(v)
```

Custom:

```python
sorted(v, key=lambda p: (p[0], -p[1]))
```

---

## 17. `find`, `count`, `binary_search`, Bounds

### C++

```cpp
count(v.begin(), v.end(), x);

find(v.begin(), v.end(), x);

binary_search(v.begin(), v.end(), x);
```

For sorted ranges:

```cpp
lower_bound(v.begin(), v.end(), x);
upper_bound(v.begin(), v.end(), x);
```

Index:

```cpp
int pos =
    lower_bound(v.begin(), v.end(), x) - v.begin();
```

Interpretation:

```text
lower_bound(x) → first element >= x
upper_bound(x) → first element >  x
```

### Python

```python
x in arr
```

Sorted list:

```python
from bisect import bisect_left, bisect_right

bisect_left(arr, x)
bisect_right(arr, x)
```

---

## 18. Reverse / Rotate / Permutations

### C++

```cpp
reverse(v.begin(), v.end());
```

Rotate:

```cpp
rotate(v.begin(), v.begin() + k, v.end());
```

Next lexicographical permutation:

```cpp
sort(v.begin(), v.end());

do {
    // use permutation
} while (next_permutation(v.begin(), v.end()));
```

### Python

```python
arr[::-1]
```

or:

```python
list(reversed(arr))
```

Permutations:

```python
from itertools import permutations

for p in permutations(arr):
    ...
```

---

## 19. Erase-Remove Idiom

### C++

This does **not** mean `remove()` actually shrinks the vector.

```cpp
v.erase(
    remove(v.begin(), v.end(), x),
    v.end()
);
```

Meaning:

```text
remove() → shifts unwanted values toward the end
erase()  → actually shrinks the container
```

### C++20

```cpp
erase_if(v, [](int x) {
    return x % 2 == 0;
});
```

### Python

Usually:

```python
v = [x for x in v if x % 2 != 0]
```

---

## 20. `string::find()` and `npos`

### C++

```cpp
size_t pos = s.find("abc");

if (pos != string::npos) {
    ...
}
```

`npos` is an unsigned `size_t` sentinel value representing “not found”.

Do not casually write:

```cpp
if (s.find("abc") != -1)
```

It may work numerically in many cases, but `string::npos` is the correct idiom.

### Python

```python
pos = s.find("abc")

if pos != -1:
    ...
```

For Python, `-1` is the documented “not found” result for `.find()`.

---

# IMPORTANT GOTCHAS

## 21. Integer Division

### C++

```cpp
7 / 2    // 3
7.0 / 2  // 3.5
```

### Python

```python
7 / 2    # 3.5
7 // 2   # 3
```

Negative values differ:

```text
C++ integer division → truncates toward zero
Python //             → floor division
```

Example:

```cpp
-7 / 3   // -2
-7 % 3   // -1
```

```python
-7 // 3  # -3
-7 % 3   # 2
```

This is a genuinely useful “wait, why?” fact.

---

## 22. `1LL` to Avoid Intermediate Overflow

Bad:

```cpp
int a = 1000000;
int b = 1000000;

long long x = a * b;
```

The multiplication happens as `int` first.

Safer:

```cpp
long long x = 1LL * a * b;
```

Likewise:

```cpp
long long sum = 0;

sum += 1LL * a * b;
```

---

## 23. `memset()` Trap

### Safe zeroing

```cpp
int a[100];

memset(a, 0, sizeof(a));
```

### Dangerous misconception

```cpp
memset(a, 1, sizeof(a));
```

This fills every **byte** with `0x01`.

It does **not** set every `int` to numeric `1`.

Use:

```cpp
fill(a, a + 100, 1);
```

or:

```cpp
fill(begin(a), end(a), 1);
```

---

## 24. Fast I/O

### C++

Put this near the beginning of `main()`:

```cpp
ios::sync_with_stdio(false);
cin.tie(nullptr);
```

And normally:

```cpp
cout << '\n';
```

instead of:

```cpp
cout << endl;
```

`endl` also flushes the stream, which is often unnecessary.

### Python

Large input:

```python
import sys

data = sys.stdin.buffer.read().split()
```

Line-based:

```python
sys.stdin.readline
```

---

## 25. C++ Array vs Pointer

```cpp
int a[5];

int* p = a;
```

They are different types.

```cpp
sizeof(a)   // entire array size
sizeof(p)   // pointer size
```

But in many expressions, the array decays to a pointer to its first element:

```cpp
a[2]
*(a + 2)
p[2]
```

all access the same element.

---

## 26. `vector<bool>` Weirdness

`vector<bool>` is a specialized container representation rather than an ordinary `vector<T>` instantiation with normal `bool` references.

So code expecting:

```cpp
bool&
```

can behave differently.

For ordinary byte-like storage:

```cpp
vector<char>
```

is often simpler.

Use `vector<bool>` when its compact bit representation is actually useful.

---

## 27. `numeric_limits`

Useful constants:

```cpp
numeric_limits<int>::max();
numeric_limits<int>::min();

numeric_limits<long long>::max();

numeric_limits<double>::infinity();
numeric_limits<double>::quiet_NaN();
```

Python equivalents:

```python
float("inf")
float("-inf")
```

---

## 28. `INF` Sentinel

Classic CP pattern:

```cpp
const int INF = 1e9;
const long long LINF = 4e18;
```

But:

```cpp
LINF + LINF
```

can overflow `long long`.

A sentinel should leave enough headroom for operations performed on it.

Python:

```python
INF = float("inf")
```

or:

```python
INF = 10**18
```

---

# PYTHON-SPECIFIC CORE / REFERENCE

## 29. `divmod()`

```python
q, r = divmod(17, 5)

# q = 3
# r = 2
```

Equivalent conceptually to:

```python
q = 17 // 5
r = 17 % 5
```

---

## 30. `zip()` and `enumerate()`

```python
for a, b in zip(A, B):
    ...
```

```python
for i, x in enumerate(A):
    ...
```

Two of the most useful pieces of Python syntax for DSA loops.

---

## 31. `any()` and `all()`

```python
all(x > 0 for x in arr)
any(x == target for x in arr)
```

Think:

```text
all → AND
any → OR
```

The generator expression also avoids building an intermediate list.

---

## 32. `sorted(..., key=...)`

```python
sorted(words, key=len)
```

Multiple criteria:

```python
sorted(
    pairs,
    key=lambda p: (p[0], -p[1])
)
```

---

## 33. Python Slicing

```python
a[::-1]   # reverse
a[::2]    # every second element
a[l:r]    # [l, r)
a[:]      # shallow copy for a list
```

The stop index remains exclusive.

---

## 34. Python Aliasing

```python
a = [1, 2, 3]
b = a

b.append(4)

print(a)
# [1, 2, 3, 4]
```

Separate shallow copy:

```python
b = a.copy()
```

Nested structures may require `copy.deepcopy()`.

---

## 35. Nested-List Trap

Bad:

```python
matrix = [[0] * 4] * 3
```

All rows reference the same inner list.

Good:

```python
matrix = [[0] * 4 for _ in range(3)]
```

This is one of the classic Python DSA landmines.

---

## 36. `dict.get()` / `setdefault()`

```python
d.get("x")
```

does not raise `KeyError` when missing.

```python
d.setdefault("x", 0)
```

inserts the default if `"x"` does not already exist.

Common frequency idiom:

```python
d[x] = d.get(x, 0) + 1
```

Often replaced by:

```python
from collections import defaultdict

d = defaultdict(int)
d[x] += 1
```

---

## 37. `Counter`

```python
from collections import Counter

c = Counter([1, 2, 2, 3, 2])

c[2]                 # 3
c.most_common(2)
```

Useful for frequency problems.

---

## 38. `math.gcd()` / `math.lcm()`

```python
import math

math.gcd(a, b)
math.lcm(a, b)
```

---

## 39. `accumulate()`

```python
from itertools import accumulate

prefix = list(accumulate(arr))
```

For a running maximum:

```python
running_max = list(accumulate(arr, max))
```

---

## 40. `is` vs `==`

```python
a == b
```

means values compare equal.

```python
a is b
```

means they are the same object.

Use:

```python
x is None
```

for `None` checks.

Do not rely on implementation quirks such as small-integer interning to make `is` behave like `==`.

---

# EXTRAS / WEIRD-BUT-RELEVANT

## 41. C++ `bits/stdc++.h`

```cpp
#include <bits/stdc++.h>
```

Convenient in competitive programming, but it is **not a standard C++ header**.

For portable code, include the headers you actually need:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
```

Use `bits/stdc++.h` because your contest environment supports it, not because the C++ standard invented it.

---

## 42. `std::function` vs Lambda / Function Pointer

Function pointer:

```cpp
int (*f)(int, int) = add;
```

Lambda:

```cpp
auto f = [](int x) {
    return 2 * x;
};
```

Type-erased callable:

```cpp
function<int(int)> f =
    [](int x) { return 2 * x; };
```

For normal CP, plain lambdas are usually enough.

---

## 43. C++ `auto` Gotcha

```cpp
const int x = 10;
auto y = x;
```

`y` is an `int`, not `const int`.

For preserving references/qualifiers:

```cpp
const auto& y = x;
```

Also remember:

```cpp
auto x = {1, 2, 3};
```

deduces an `initializer_list<int>`, not a `vector<int>`.

---

## 44. Python `bool` Is an `int` Subclass

```python
True == 1
False == 0

isinstance(True, int)  # True
```

This is real language behavior, but usually not something you should exploit in normal DSA code unless the problem specifically makes it useful.

---

## 45. Python Arbitrary-Precision Integers

```python
x = 10**100
```

No fixed 32-bit or 64-bit overflow boundary for ordinary `int`.

The tradeoff is that very large arithmetic costs more time and memory.

---

## 46. Python `reduce()`

```python
from functools import reduce

reduce(lambda acc, x: acc + x, arr, 0)
```

For common operations, prefer the clearer specialized functions:

```python
sum(arr)
math.prod(arr)
```

`reduce()` is useful when the reduction operation is genuinely custom.

---

## 47. Mutable Default Argument Trap

Bad:

```python
def f(x, arr=[]):
    arr.append(x)
    return arr
```

The same default list is reused across calls.

Safer:

```python
def f(x, arr=None):
    if arr is None:
        arr = []

    arr.append(x)
    return arr
```

This is a language-semantics trap rather than a DSA technique, but worth knowing.

---

## 48. Chained Comparisons

Python:

```python
1 < x < 10
```

is valid and means:

```python
1 < x and x < 10
```

No equivalent compact syntax exists in C++.

---

## 49. Star Unpacking

Python:

```python
a = [1, 2]
b = [3, 4]

c = [*a, *b]
```

Dictionary merging:

```python
d = {**d1, **d2}
```

Function arguments:

```python
f(*args)
```

---

## 50. Matrix Transpose Trick

For a rectangular Python matrix:

```python
transpose = [list(col) for col in zip(*matrix)]
```

Example:

```python
[
    [1, 2, 3],
    [4, 5, 6]
]
```

becomes:

```python
[
    [1, 4],
    [2, 5],
    [3, 6]
]
```

---

# DSA MEMORIZATION TIER

## Memorize

```text
C++
string::replace
to_string
stoi / stoll
stringstream
char - '0'
'0' + digit
pair / tuple
structured bindings
tie / ignore
swap
min / max
gcd / lcm
iota
accumulate
lambda
sort with comparator
find / count
lower_bound / upper_bound
reverse
next_permutation
erase-remove
1LL
memset vs fill
fast I/O
numeric_limits
INF
```

```text
Python
str / int / float
ord / chr
f-strings
divmod
tuple unpacking
zip / enumerate
any / all
min / max / sum
sorted(key=...)
slicing
aliasing
dict.get
set operations
Counter
defaultdict
math.gcd / math.lcm
accumulate
is vs ==
float('inf')
sys.stdin.buffer
```

## Understand deeply

```text
C++:
integer promotion / overflow
array-to-pointer decay
erase-remove
reference vs value in structured bindings
accumulate's initial-value type
memset writes bytes
vector<bool>
npos
signed modulo / division
```

```text
Python:
mutability
aliasing
nested-list multiplication
floor division
truthiness
hashability
identity vs equality
mutable default arguments
arbitrary-precision integers
```

## Reference only

```text
C++:
std::function
std::exchange
stringstream
byte-level inspection
```

```text
Python:
walrus operator
reduce
star unpacking
matrix transpose trick
```

---

# ULTRA-SHORT “WEIRD THINGS” LIST

| Weird thing | Remember this |
|---|---|
| `to_string(3.14)` | Can produce `3.140000` in pre-C++26 behavior |
| `stoi("1010", nullptr, 2)` | Parses a base-2 integer |
| `char('0' + 5)` | `'5'` |
| `'7' - '0'` | `7` |
| `auto [a,b] = p` | Unpack pair/tuple |
| `auto& [a,b] = p` | Bind to original members |
| `tie(ignore,x)=p` | Ignore part of a pair |
| `1LL * a * b` | Promote before multiplication |
| `accumulate(v.begin(),v.end(),0LL)` | Long-long accumulation |
| `memset(a,1,...)` | Does **not** set ints to `1` |
| `vector<bool>` | Specialized proxy representation |
| `string::npos` | “Not found” sentinel |
| `-7 % 3` in C++ | `-1` |
| `-7 % 3` in Python | `2` |
| `-7 // 3` in Python | `-3` |
| `True == 1` | `True` |
| `a = b` for lists in Python | Aliases the same list |
| `[[0]*3]*3` | Same row referenced 3 times |
| `a is b` | Identity, not value equality |
| `x is None` | Correct `None` check |
| `1 < x < 10` | Valid chained comparison in Python |
| `bits/stdc++.h` | Convenient, non-standard C++ header |

---

## Sources / Verification Notes

The standard-library details were checked against current C++ references, including `std::to_string`, `stoi`/`stoll`, structured bindings, `std::tie`, numeric algorithms such as `gcd`, `lcm`, `iota`, and `accumulate`. citeturn377363search0turn775717search4turn775717search1turn775717search8turn775717search0turn377363search4

One important update for your original note: `std::to_string()` is not simply “O(log n)” in every case. That is a useful approximation for integer output because the number of digits grows logarithmically; floating-point formatting has different behavior and output-length considerations. citeturn377363search0
