# Data Types — C++ vs Python
### DSA / Competitive Programming / Interview Cheat Sheet

> **Purpose:** Fast revision of built-in types, composite types, user-defined types, memory/size behavior, mutability, conversions, and the syntax most useful in DSA.
>
> **Source note:** The terminology and examples below preserve the supplied notes, while a few details are tightened using current official language references. In particular, C++ sizes are implementation-dependent rather than universally fixed, and Python has arbitrary-precision integers. C++ data-type categories also differ slightly from the informal “basic / derived / user-defined” teaching classification.

---

# CORE / MUST KNOW

## 1. Big Picture

| Concept | C++ | Python |
|---|---|---|
| Typing model | **Statically typed** | **Dynamically typed** |
| Type known | At compile time | Associated with objects at runtime |
| Variable reassignment to different type | Not normally without changing declaration/type | Allowed |
| Primitive/fundamental numeric types | `short`, `int`, `long`, `long long`, `float`, `double`, `long double`, `char`, `bool` | `int`, `float`, `complex`, `bool` |
| Text | `char`, `std::string` | `str` |
| Array-like | C-style array, `std::array`, `std::vector` | `list` |
| Immutable sequence | No direct built-in tuple equivalent | `tuple` |
| Hash set | `std::unordered_set` | `set` |
| Ordered tree set | `std::set` | No built-in tree set |
| Hash map | `std::unordered_map` | `dict` |
| Ordered tree map | `std::map` | No built-in tree map |
| Null value | `nullptr` | `None` |
| Type aliases | `using`, `typedef` | Type aliases / annotations |
| User-defined record | `struct`, `class` | `class`, commonly `dataclass` |
| Enumeration | `enum`, `enum class` | `enum.Enum` (standard library) |
| Type inference | `auto` | Normal assignment already binds runtime objects |
| Runtime type check | `typeid`, type traits, concepts, etc. | `type()`, `isinstance()` |
| Exact-width integers | `int8_t`, `int16_t`, `int32_t`, `int64_t`, etc. when available | Not needed for ordinary integers |

---

## 2. Numeric Types

### C++

| Type | Typical modern size | Standard guarantee / notes | Example | DSA relevance |
|---|---:|---|---|---|
| `short` | 2 bytes | At least 16 bits | `short x = 10;` | Low |
| `int` | 4 bytes | At least 16 bits; commonly 32 bits | `int x = 42;` | **Very high** |
| `long` | 4 or 8 bytes | At least 32 bits; depends on data model | `long x = 42L;` | Medium |
| `long long` | 8 bytes | At least 64 bits | `long long x = 1e12;` | **Very high** |
| `unsigned int` | Usually 4 bytes | Non-negative modulo arithmetic | `unsigned x = 10;` | High |
| `float` | Usually 4 bytes | Single precision | `float x = 3.14f;` | Medium |
| `double` | Usually 8 bytes | Double precision | `double x = 3.14;` | **High** for math |
| `long double` | Implementation-dependent | Extended precision may be available | `long double x = 3.14L;` | Low |
| `char` | 1 byte | Exactly `sizeof(char) == 1`; byte width is implementation-defined | `char c = 'A';` | High |
| `bool` | Implementation-defined | Holds `true` / `false` | `bool ok = true;` | **Very high** |

**Important:** Do not memorize “`int = 4 bytes`” as a language guarantee. It is common on competitive-programming machines, but the C++ standard permits other sizes. The minimum widths and ordering are guaranteed by the language. citeturn407247search0

### Python

| Type | Meaning | Example | Key property |
|---|---|---|---|
| `int` | Integer | `42`, `-7` | **Arbitrary precision** |
| `float` | Floating-point | `3.14` | Usually C double precision |
| `complex` | Complex number | `1 + 2j` | `.real`, `.imag` |
| `bool` | Boolean | `True`, `False` | Subclass of `int` |

Python has three principal numeric types: `int`, `float`, and `complex`; Python integers have unlimited precision. citeturn532704search1

---

## 3. Integral / Integer Family in C++

```cpp
short a = 10;
int b = 20;
long c = 30L;
long long d = 40LL;

signed int x = -10;
unsigned int y = 10U;

int32_t p = 100;
int64_t q = 10000000000LL;
uint64_t r = 10000000000ULL;
```

### Must-remember relationships

```text
sizeof(char)
≤ sizeof(short)
≤ sizeof(int)
≤ sizeof(long)
≤ sizeof(long long)
```

C++ guarantees the size ordering above, while the exact byte counts are implementation-dependent. citeturn407247search0

### Exact-width integers

```cpp
#include <cstdint>

int8_t
int16_t
int32_t
int64_t

uint8_t
uint16_t
uint32_t
uint64_t
```

For DSA, `int` and `long long` are usually the important everyday choices; fixed-width types are useful when an exact width is part of the problem.

---

## 4. Ranges and Limits

### C++

```cpp
#include <limits>

cout << numeric_limits<int>::min();
cout << numeric_limits<int>::max();

cout << numeric_limits<long long>::max();
cout << numeric_limits<unsigned int>::max();
```

Common competitive-programming mental model:

| Type | Common 64-bit-platform expectation |
|---|---|
| `int` | about `-2.1e9 ... +2.1e9` |
| `unsigned int` | about `0 ... 4.3e9` |
| `long long` | about `-9.22e18 ... +9.22e18` |
| `unsigned long long` | about `0 ... 1.84e19` |

Use `numeric_limits<T>` when exactness matters.

### Python

```python
x = 10**100
```

Python `int` expands to whatever precision is required by the value, subject to available memory. There is no fixed 32-bit/64-bit ceiling for ordinary Python integers. citeturn532704search1

---

## 5. Floating-Point Types

### C++

```cpp
float f = 3.14f;
double d = 3.14;
long double ld = 3.14L;
```

### Python

```python
f = 3.14
```

Important practical distinction:

```text
C++: float / double / long double
Python: float
```

For ordinary Python code, `float` is generally implemented using C double precision. citeturn532704search1

### Floating-point warning

Do not assume decimal arithmetic is exact:

```cpp
double x = 0.1 + 0.2;
```

```python
x = 0.1 + 0.2
print(x == 0.3)   # False
```

For exact rational/decimal arithmetic in Python, see `Fraction` and `Decimal` in **Extras**.

---

## 6. Character / Text Types

### C++

```cpp
char c = 'A';
string s = "hello";
```

`char` is a distinct character type with a size of one byte. Its signedness is implementation-dependent. C++ also provides `char8_t`, `char16_t`, `char32_t`, and `wchar_t`. citeturn407247search0

Useful code:

```cpp
cout << static_cast<int>('A');  // character code
```

### Python

```python
c = "A"
s = "hello"
```

Python does not have a separate built-in single-character type. A one-character string is still a `str`.

---

## 7. Boolean Type

### C++

```cpp
bool flag = true;
bool ok = false;
```

```cpp
if (x) {
    // non-zero integer / non-null pointer converts to true
}
```

### Python

```python
flag = True
```

Python has exactly two Boolean values: `True` and `False`. `bool` is a subclass of `int`. citeturn532704search0

```python
True == 1      # True
False == 0     # True
isinstance(True, int)   # True
```

Do not rely on that relationship stylistically unless you actually need it.

---

## 8. Truthiness: C++ vs Python

### C++

In conditions, common conversions include:

```cpp
if (0)   // false
if (5)   // true

int* p = nullptr;
if (p)   // false
```

### Python

Most objects are truthy unless their truth-value behavior says otherwise.

Falsy built-ins include:

```text
False
None
0, 0.0, 0j
""
()
[]
{}
set()
range(0)
```

A custom class may define `__bool__()` or `__len__()` to control truthiness. citeturn532704search1

Example:

```python
class MyClass:
    def __len__(self):
        return 0

print(bool(MyClass()))   # False
```

---

## 9. `void` vs `None`

| Concept | C++ | Python |
|---|---|---|
| No return value | `void` | Function implicitly returns `None` |
| “No value” object | No ordinary `void` object | `None` |
| Null pointer/value marker | `nullptr` | `None` often plays the sentinel role |

C++:

```cpp
void f() {
    cout << "hello";
}
```

Python:

```python
def f():
    print("hello")

x = f()
print(x)   # None
```

---

## 10. `nullptr` vs `None`

### C++

```cpp
int* p = nullptr;

if (p == nullptr) {
    cout << "null";
}
```

`nullptr` is the null pointer literal and has type `std::nullptr_t`.

### Python

```python
x = None

if x is None:
    print("none")
```

Use `is None`, not `== None`, for the idiomatic identity check.

---

## 11. Arrays / List-like Types

| Use case | C++ | Python |
|---|---|---|
| Fixed-size built-in array | `int a[5];` | No direct equivalent |
| Fixed-size STL array | `array<int,5>` | `tuple` is closest in immutability, not semantics |
| Dynamic contiguous sequence | `vector<int>` | `list` |
| Nested sequence | `vector<vector<int>>` | `list[list[int]]` |

### C++

```cpp
int a[5] = {1, 2, 3, 4, 5};

array<int, 5> b = {1, 2, 3, 4, 5};

vector<int> c = {1, 2, 3, 4, 5};
```

### Python

```python
a = [1, 2, 3, 4, 5]
t = (1, 2, 3, 4, 5)
```

---

## 12. Pointer

### C++

```cpp
int x = 10;

int* p = &x;

cout << p;    // address
cout << *p;   // value
```

Core symbols:

| Syntax | Meaning |
|---|---|
| `&x` | address of `x` |
| `int* p` | pointer to `int` |
| `*p` | dereference pointer |
| `nullptr` | null pointer |

Python does not expose raw pointers as an ordinary DSA-level type. Python variables are references to objects.

---

## 13. Reference

### C++

```cpp
int x = 10;
int& ref = x;

ref = 20;
cout << x;    // 20
```

A reference provides another name for an existing object.

Key distinction:

```text
Pointer   → stores an address; can be null; can be reseated
Reference → alias to an object; normally must be initialized
```

### Python

Assignment binds another name to the same object:

```python
a = [1, 2]
b = a

b.append(3)

print(a)   # [1, 2, 3]
```

This is not a C++-style reference type, but it is crucial for understanding Python object behavior.

---

## 14. Struct / Class

### C++

```cpp
struct Point {
    int x;
    int y;
};

Point p{10, 20};
```

```cpp
class Box {
public:
    int value;
};
```

`class` and `struct` are almost the same language mechanism; the major default difference is access control. citeturn407247search4

### Python

```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

p = Point(10, 20)
```

---

## 15. Union

### C++

```cpp
union Data {
    int i;
    float f;
};

Data d;
d.i = 10;
```

A union's non-static members share overlapping storage; at most one member's stored value is active at a time. citeturn407247search5

Use unions carefully. They are much more relevant to systems/programming-language knowledge than everyday DSA.

Python has no direct built-in union storage type corresponding to C++ `union`.

---

## 16. Enum

### C++

```cpp
enum Color {
    RED,
    GREEN,
    BLUE
};

Color c = GREEN;
```

Modern scoped enum:

```cpp
enum class Direction {
    LEFT,
    RIGHT
};

Direction d = Direction::RIGHT;
```

Useful distinction:

```text
enum       → enumerators are less strongly scoped
enum class → scoped and strongly typed
```

### Python

Use `enum.Enum`:

```python
from enum import Enum

class Direction(Enum):
    LEFT = 1
    RIGHT = 2
```

---

## 17. Type Aliases

### C++

```cpp
using Marks = int;
typedef float Score;
```

Prefer modern `using` in new code:

```cpp
using ll = long long;
using pii = pair<int, int>;
```

### Python

```python
Age = int
```

With annotations:

```python
age: int = 20
```

Type annotations do not by themselves enforce runtime types.

---

## 18. Type Inference

### C++

```cpp
auto x = 42;       // int
auto y = 3.14;     // double
auto s = "hello";  // const char*
```

### Python

Normal assignment already binds names to runtime objects:

```python
x = 42
x = "hello"
```

The second assignment is legal because the name is not permanently declared as an `int`.

---

## 19. Type Checking

### C++

Compile-time-oriented tools:

```cpp
is_integral_v<int>
is_floating_point_v<double>
is_pointer_v<int*>
is_same_v<int, int>
```

Runtime type information:

```cpp
typeid(x).name()
```

The exact text returned by `typeid(...).name()` is implementation-dependent.

### Python

```python
type(x)
isinstance(x, int)
```

Prefer `isinstance()` for most type checks when inheritance/subclasses should count. citeturn532704search2

---

## 20. Conversions / Casting

### C++

```cpp
int x = 10;

double d = x;                    // implicit
int y = static_cast<int>(3.99);  // explicit
```

Common C++ casts:

```text
static_cast
const_cast
dynamic_cast
reinterpret_cast
```

For ordinary DSA code, `static_cast` is the one you should know first.

### Python

```python
int("123")
float("3.14")
str(123)
bool(1)
list((1, 2))
tuple([1, 2])
set([1, 1, 2])
```

Integer bases:

```python
int("1010", 2)
bin(10)
oct(10)
hex(10)
```

---

## 21. Mutability

| Type | C++ | Python |
|---|---|---|
| Integer | Value type | Immutable object |
| String | `std::string` mutable | `str` immutable |
| Fixed array | Elements mutable | No direct equivalent |
| `vector` | Mutable | `list` mutable |
| Tuple | No direct built-in equivalent | Immutable |
| `set` | `std::set` mutable | `set` mutable |
| `frozenset` | No direct built-in equivalent | Immutable/hashable |
| `dict` / map | `map`, `unordered_map` mutable | `dict` mutable |

Python's `set` is mutable and therefore unhashable; `frozenset` is immutable and hashable. citeturn532704search1

---

## 22. STL / Built-in DSA Types

| Purpose | C++ | Python |
|---|---|---|
| Dynamic array | `vector<T>` | `list` |
| Fixed array | `array<T,N>` | `tuple` only approximately similar |
| String | `string` | `str` |
| Stack | `stack<T>` | `list` / `deque` |
| Queue | `queue<T>` | `deque` |
| Priority queue | `priority_queue<T>` | `heapq` |
| Ordered set | `set<T>` | No built-in equivalent |
| Hash set | `unordered_set<T>` | `set` |
| Ordered map | `map<K,V>` | No built-in equivalent |
| Hash map | `unordered_map<K,V>` | `dict` |

---

# EXTRAS / REFERENCE

## 23. More C++ Character Types

```cpp
char8_t  c8  = u8'A';   // C++20
char16_t c16 = u'A';
char32_t c32 = U'A';
wchar_t  wc  = L'A';
```

These matter mainly for character encoding / text processing rather than ordinary DSA.

---

## 24. C++ `const` and `constexpr`

```cpp
const int x = 10;
constexpr int y = 20;
```

- `const` prevents modification through that declaration.
- `constexpr` indicates a value/function can participate in constant evaluation when requirements are satisfied.

---

## 25. C++ `volatile`

```cpp
volatile int x;
```

`volatile` is about special memory-access semantics and is **not** a general-purpose “thread-safe” or “do not optimize” switch. Rare in DSA.

---

## 26. C++ `decltype`

```cpp
int x = 10;
decltype(x) y = 20;
```

Useful in generic/template-heavy code.

---

## 27. Python Binary / Byte Types

```python
b = b"hello"               # bytes
ba = bytearray(b"hello")   # mutable
mv = memoryview(b)         # view
```

| Type | Mutable? | Typical use |
|---|---|---|
| `bytes` | No | Binary data |
| `bytearray` | Yes | Mutable binary data |
| `memoryview` | View | Avoid copying binary buffers |

These are standard built-in types, but generally lower priority for DSA. citeturn532704search5

---

## 28. Python `range`

```python
r = range(0, 10, 2)
```

Key properties:

```text
start
stop
step
```

It does not create a full list of all elements. A `range` object stores the parameters needed to represent the arithmetic progression and uses a small, fixed amount of memory independent of the number of represented values. citeturn532704search1

---

## 29. Python Other Numeric Types

```python
from fractions import Fraction
from decimal import Decimal

Fraction(1, 3)
Decimal("0.1")
```

| Type | Purpose |
|---|---|
| `Fraction` | Exact rational arithmetic |
| `Decimal` | Decimal floating-point with user-controlled precision |

Low priority for competitive programming unless a problem specifically needs them.

---

## 30. Python Special / Sentinel Values

```python
None
Ellipsis
NotImplemented
```

Most important:

```python
if x is None:
    ...
```

`None` is the standard absence/sentinel object.

---

## 31. Python Generator Type

```python
g = (x * x for x in range(10))
```

A generator is an iterator-producing object evaluated lazily.

This matters when understanding:

```text
list → stores values
generator → produces values on demand
```

---

## 32. Python Comprehension Types

```python
[x*x for x in range(5)]          # list
{x*x for x in range(5)}          # set
{x: x*x for x in range(5)}       # dict
(x*x for x in range(5))          # generator
```

Useful for compact construction, but not a separate primitive “data type category”.

---

## 33. C++ Array vs Pointer Trap

```cpp
int a[5] = {1, 2, 3, 4, 5};

int* p = a;
```

These are **not the same type**:

```text
a → array of 5 int
p → pointer to int
```

In many expressions, an array decays to a pointer to its first element, which is why:

```cpp
cout << a[2];
cout << *(a + 2);
```

both work.

But `sizeof(a)` and `sizeof(p)` are different.

---

## 34. C++ Reference vs Pointer Trap

```cpp
int x = 10;

int& ref = x;
int* ptr = &x;
```

| Property | Reference | Pointer |
|---|---|---|
| Must initialize? | Normally yes | No |
| Can be null? | No ordinary null reference | Yes |
| Can be reseated? | No | Yes |
| Access value | `ref` | `*ptr` |
| Address operator | `&x` | `&x` |

---

## 35. Python Assignment / Aliasing Trap

```python
a = [1, 2, 3]
b = a

b.append(4)

print(a)   # [1, 2, 3, 4]
```

Both names refer to the same list object.

To create a separate shallow list:

```python
b = a.copy()
```

For nested structures, use `copy.deepcopy()` when a deep independent copy is actually needed.

---

## 36. Python Hashability

Dictionary keys and set elements must be hashable.

Usually hashable:

```python
int
float
str
tuple      # if its elements are hashable
frozenset
```

Usually unhashable:

```python
list
dict
set
```

Example:

```python
d = {(1, 2): "ok"}      # valid
# d = {[1, 2]: "bad"}   # TypeError
```

---

## 37. Complexity Snapshot

Most plain type operations themselves are constant-time, but containers are different.

| Operation | C++ | Python |
|---|---:|---:|
| Read scalar variable | O(1) | O(1) conceptually |
| `sizeof(T)` | O(1) | N/A |
| Cast between basic numeric types | O(1) | O(1) typical |
| Array index | O(1) | List index O(1) |
| Vector/list append | O(1) amortized | O(1) amortized |
| String length | O(1) for `std::string::size()` | O(1) for `len(str)` |
| Hash-set membership | O(1) average | O(1) average |
| Hash-map lookup | O(1) average | O(1) average |
| Ordered map lookup | O(log n) | No built-in equivalent |

These are container-operation complexities, not “the complexity of the data type” itself.

---

## 38. DSA Memorization Tier

### Memorize

```text
C++:
int
long long
float / double
char
bool
string
array
vector
pointer
reference
struct / class
enum class
using
nullptr
auto
static_cast

Python:
int
float
complex
bool
str
list
tuple
range
dict
set
frozenset
None
bytes
type()
isinstance()
```

### Understand deeply

```text
C++:
int vs long long
signed vs unsigned
array vs pointer
pointer vs reference
const
numeric_limits
implicit vs explicit conversion
struct vs class
enum vs enum class

Python:
mutable vs immutable
list vs tuple
set vs frozenset
dict keys must be hashable
truthiness
None vs False
int arbitrary precision
aliasing / object references
type() vs isinstance()
```

### Reference only

```text
C++:
char8_t / char16_t / char32_t / wchar_t
long double
union
volatile
decltype
type_traits

Python:
Decimal
Fraction
memoryview
generator types
Ellipsis
NotImplemented
```

---

## 39. One-Page Mental Model

```text
C++
├── Fundamental
│   ├── integer: short / int / long / long long
│   ├── unsigned variants
│   ├── char
│   ├── bool
│   ├── floating: float / double / long double
│   └── void
│
├── Declarator-based / derived forms
│   ├── arrays
│   ├── pointers
│   ├── references
│   └── functions
│
├── User-defined
│   ├── struct
│   ├── class
│   ├── union
│   ├── enum
│   └── aliases
│
└── STL
    ├── string
    ├── vector
    ├── array
    ├── set
    └── map

Python
├── Numeric
│   ├── int
│   ├── float
│   └── complex
│
├── Sequence / Text
│   ├── str
│   ├── list
│   ├── tuple
│   └── range
│
├── Mapping
│   └── dict
│
├── Set
│   ├── set
│   └── frozenset
│
├── Boolean
│   └── bool
│
├── Null
│   └── None
│
└── Binary
    ├── bytes
    ├── bytearray
    └── memoryview
```

---

## 40. Ultra-Short Revision Table

| Topic | C++ | Python |
|---|---|---|
| Integer | `int`, `long long` | `int` |
| Decimal | `double` | `float` |
| Complex | library / `complex` support | `complex` |
| Character | `char` | `str` of length 1 |
| Boolean | `bool` | `bool` |
| No return | `void` | `None` |
| Null pointer | `nullptr` | `None` as common sentinel |
| Dynamic array | `vector<T>` | `list` |
| Immutable sequence | — | `tuple` |
| Hash set | `unordered_set` | `set` |
| Ordered set | `set` | — |
| Hash map | `unordered_map` | `dict` |
| Ordered map | `map` | — |
| Pointer | `T*` | No raw pointer type at normal DSA level |
| Reference / aliasing | `T&` | Name binding to object |
| Record | `struct` / `class` | `class` |
| Enum | `enum` / `enum class` | `Enum` |
| Type alias | `using` / `typedef` | alias / annotation |
| Type check | `typeid`, traits, etc. | `type`, `isinstance` |
| Type inference | `auto` | dynamic binding |
| Exact-width integer | `int64_t` etc. | ordinary `int` is arbitrary precision |

---

### Sources

Technical details updated against the current official references:

- C++ fundamental types, widths, modifiers, character types, and `sizeof` guarantees: citeturn407247search0turn407247search1
- C++ declarations, aliases, pointers, arrays, references, and declarators: citeturn407247search2turn407247search8
- C++ `class` / `struct` and `union` behavior: citeturn407247search4turn407247search5
- Python built-in types, numeric types, truth-value testing, sequences, sets, and mappings: citeturn532704search0turn532704search1
- Python built-in `type()` / `isinstance()`: citeturn532704search2
