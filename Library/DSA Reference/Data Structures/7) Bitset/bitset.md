# Bitset — C++ & Python

> **Purpose:** DSA / competitive programming / bit manipulation revision  
> **C++:** C++20  
> **Python:** Python 3.x

---

# 0. How to Use This Sheet

Bitsets need a slightly different cross-language treatment:

```text
C++
    std::bitset<N>
    true fixed-size bit container

Python
    no direct built-in bitset type
    int is normally used as a bit mask
```

So the comparison is not pretending these are identical structures. The Python side uses `int` for normal DSA bit manipulation and a small fixed-width wrapper in Extras when behavior closer to `bitset<N>` is required.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
BITSET

bits:
    1 0 1 1 0 0 1 0

bit i:
    i = 0 → least-significant/rightmost bit
```

Common operations:

```text
set bit
clear bit
toggle bit
test bit

AND
OR
XOR
NOT

left shift
right shift

count set bits
```

---

# 2. Core Complexity Summary

For C++ `bitset<N>`, think in terms of `N`, the fixed number of bits.

| Operation | C++ `bitset<N>` | Python `int` bit mask | Notes |
|---|---:|---:|---|
| Access/test one bit | **O(1)** | roughly word-proportional | Python integer is arbitrary precision |
| Set one bit | **O(1)** | word-proportional | Python creates a new integer |
| Reset one bit | **O(1)** | word-proportional | |
| Flip one bit | **O(1)** | word-proportional | |
| Count 1s | O(N) conceptually | proportional to integer size | `count()` / `bit_count()` |
| Any | O(N) worst | O(1) practical truth test | For fixed integer value `x != 0` |
| All | O(N) worst | needs an explicit N-bit mask | `x == MASK` |
| None | O(N) worst | O(1) practical truth test | `x == 0` |
| AND | O(N) | proportional to integer size | |
| OR | O(N) | proportional to integer size | |
| XOR | O(N) | proportional to integer size | |
| NOT | O(N) | proportional to integer size | Python `~` is not fixed-width |
| Shift | O(N) | proportional to integer size/result | C++ result remains N bits |
| String conversion | O(N) | O(bit length) | |
| Size | O(1) | `bit_length()` gives significant width | Python has no fixed width |

> Python `int` complexity is naturally described in terms of the integer's word/bit size rather than treating it like a fixed N-bit container.

---

# 3. CORE: C++ `std::bitset<N>`

## Include

```cpp
#include <bitset>
```

---

## Initialization

```cpp
bitset<10> s1;
```

Creates:

```text
0000000000
```

From a binary string:

```cpp
bitset<10> s2("100100101");
```

The source string is shorter than 10 bits, so leading zero padding gives:

```text
0100100101
```

From an integer:

```cpp
bitset<10> s3(13);
```

gives:

```text
0000001101
```

`std::bitset<N>` represents exactly `N` bits. citeturn803370search0

---

## Print

```cpp
cout << s;
```

Example:

```cpp
bitset<8> s(10);
cout << s;
```

Output:

```text
00001010
```

---

## Size

```cpp
s.size();
```

Returns the fixed width `N`.

---

## Count Set Bits

```cpp
s.count();
```

Example:

```cpp
bitset<8> s("10110100");

cout << s.count();
```

Output:

```text
5
```

Think:

```text
count() = popcount
```

---

## Test One Bit

```cpp
s.test(i);
```

**TC:** O(1)

Important:

```cpp
s.test(i)
```

performs bounds checking and throws `std::out_of_range` if `i >= N`. citeturn803370search0turn803370search3

---

## Access with `[]`

```cpp
s[i];
```

Example:

```cpp
bool b = s[3];
```

**TC:** O(1)

C++ bit indexing uses:

```text
0 = least-significant/rightmost bit
```

---

## Set

One bit:

```cpp
s.set(i);
```

Set to specific value:

```cpp
s.set(i, false);
```

All bits:

```cpp
s.set();
```

---

## Reset

One bit:

```cpp
s.reset(i);
```

All:

```cpp
s.reset();
```

---

## Flip

One bit:

```cpp
s.flip(i);
```

All bits:

```cpp
s.flip();
```

---

# 4. CORE: Bitwise Operations

Given:

```cpp
bitset<8> a("10101010");
bitset<8> b("10010011");
```

AND:

```cpp
a & b
```

OR:

```cpp
a | b
```

XOR:

```cpp
a ^ b
```

NOT:

```cpp
~a
```

Compound forms:

```cpp
a &= b;
a |= b;
a ^= b;
```

These operate on corresponding bits.

---

# 5. CORE: Shifts

```cpp
s << k
s >> k
```

In-place:

```cpp
s <<= k;
s >>= k;
```

Bits shifted beyond the fixed width are discarded.

Example:

```text
10110000 << 2
→ 11000000
```

for an 8-bit bitset.

---

# 6. CORE: Convert to String

```cpp
string s = bits.to_string();
```

Possible custom characters:

```cpp
bits.to_string('O', 'I');
```

---

# 7. CORE: Convert to Integer

```cpp
bits.to_ulong();
bits.to_ullong();
```

Example:

```cpp
bitset<8> bits(42);

cout << bits.to_ulong();
cout << bits.to_ullong();
```

Conversion can throw `std::overflow_error` when the bitset value cannot be represented in the destination unsigned integer type. citeturn803370search1

---

# 8. CORE: Python Bitset Equivalent

Python has no direct built-in `bitset<N>` type.

For DSA, use an integer:

```python
x = 0b100100101
```

Display:

```python
bin(x)
```

Fixed-width display:

```python
f"{x:010b}"
```

---

## Test Bit

```python
(x >> i) & 1
```

---

## Set Bit

```python
x |= 1 << i
```

---

## Clear Bit

```python
x &= ~(1 << i)
```

---

## Toggle Bit

```python
x ^= 1 << i
```

These four expressions are among the most important Python bit-manipulation patterns to memorize.

---

# 9. CORE: Python Bitwise Operations

Given:

```python
a = 0b10101010
b = 0b10010011
```

AND:

```python
a & b
```

OR:

```python
a | b
```

XOR:

```python
a ^ b
```

NOT:

```python
~a
```

Left shift:

```python
a << k
```

Right shift:

```python
a >> k
```

Python integer bitwise operations are defined using a two's-complement model with an effectively unbounded number of sign bits. citeturn803370search4

---

# 10. IMPORTANT: Python `~` Is NOT Fixed-Width NOT

This matters a lot.

C++:

```cpp
bitset<8> a("00001111");

~a
```

stays within 8 bits:

```text
11110000
```

Python:

```python
a = 0b00001111

~a
```

does **not** mean 8-bit inversion.

For N-bit inversion:

```python
N = 8
MASK = (1 << N) - 1

result = (~a) & MASK
```

This gives:

```text
11110000
```

---

# 11. CORE: Count Set Bits

## C++

```cpp
s.count();
```

## Python

```python
x.bit_count();
```

Example:

```python
x = 0b10110100

print(x.bit_count())
```

Python's `int.bit_count()` returns the number of 1 bits in the binary representation of the absolute value. citeturn803370search4

---

# 12. CORE: Bit Length

## Python

```python
x.bit_length()
```

Example:

```python
x = 0b10110100

print(x.bit_length())
```

Returns the number of significant bits, excluding leading zeroes. citeturn803370search4

This is the closest useful built-in notion to:

```text
"How many bits are actually needed?"
```

It is **not** equivalent to a fixed C++ `bitset<N>.size()`.

---

# 13. C++ vs Python Core Syntax

| Operation | C++ `bitset<N>` | Python `int` mask |
|---|---|---|
| Create | `bitset<8> b;` | `b = 0` |
| From binary | `bitset<8>("1010")` | `int("1010", 2)` |
| Print | `cout << b` | `bin(b)` / `format()` |
| Fixed-width display | automatic | `f"{b:08b}"` |
| Size | `b.size()` | No fixed width; use `bit_length()` for significant width |
| Test bit | `b.test(i)` / `b[i]` | `(b >> i) & 1` |
| Set bit | `b.set(i)` | `b |= 1 << i` |
| Reset bit | `b.reset(i)` | `b &= ~(1 << i)` |
| Toggle bit | `b.flip(i)` | `b ^= 1 << i` |
| Set all | `b.set()` | `b = MASK` |
| Reset all | `b.reset()` | `b = 0` |
| Flip all | `b.flip()` | `b ^= MASK` |
| Count 1s | `b.count()` | `b.bit_count()` |
| Any | `b.any()` | `b != 0` |
| None | `b.none()` | `b == 0` |
| All | `b.all()` | `b == MASK` for N-bit value |
| AND | `a & b` | `a & b` |
| OR | `a \| b` | `a \| b` |
| XOR | `a ^ b` | `a ^ b` |
| NOT | `~a` | `~a`, but fixed width requires masking |
| Left shift | `a << k` | `a << k` |
| Right shift | `a >> k` | `a >> k` |
| To string | `b.to_string()` | `format(b, "b")` / `bin(b)[2:]` |
| To integer | `b.to_ullong()` | Already an integer |

---

# 14. EXTRAS / REFERENCE — C++

## Modify Through `operator[]`

```cpp
bitset<8> b;

b[0] = true;
b[3] = false;
```

---

## `all()`, `any()`, `none()`

```cpp
b.all();
b.any();
b.none();
```

Useful for checking entire bitsets.

---

## Stream Input

```cpp
bitset<8> b;
cin >> b;
```

---

## Equality

```cpp
a == b
a != b
```

Compares all bits.

---

## Custom String Representation

```cpp
b.to_string('0', '1');
```

The string constructor and `to_string()` support custom zero/one characters. citeturn803370search3

---

## Integer Popcount — C++20

For ordinary integers:

```cpp
#include <bit>

popcount(x);
```

Other C++20 utilities include:

```cpp
has_single_bit(x);

countl_zero(x);
countl_one(x);

countr_zero(x);
countr_one(x);
```

These are integer bit utilities rather than `bitset` methods. citeturn803370search7

---

## Dynamic Bitset

`std::bitset<N>` requires `N` at compile time.

If the number of bits must be known only at runtime, consider:

```text
vector<bool>
boost::dynamic_bitset<>
custom vector<uint64_t>
```

`boost::dynamic_bitset<>` is the common direct dynamic-bitset-style option.

---

## Hash Support

`std::hash<std::bitset<N>>` exists, allowing a `bitset` to participate in hash-based containers where appropriate. citeturn803370search2

---

# 15. EXTRAS / REFERENCE — Python Fixed-Width BitSet

A small wrapper can emulate fixed-width `bitset<N>` semantics:

```python
class BitSet:
    def __init__(self, n, value=0):
        self.n = n
        self.mask = (1 << n) - 1
        self.bits = value & self.mask

    def test(self, i):
        return bool((self.bits >> i) & 1)

    def set(self, i=None):
        if i is None:
            self.bits = self.mask
        else:
            self.bits |= 1 << i

    def reset(self, i=None):
        if i is None:
            self.bits = 0
        else:
            self.bits &= ~(1 << i)

    def flip(self, i=None):
        if i is None:
            self.bits ^= self.mask
        else:
            self.bits ^= 1 << i

    def count(self):
        return self.bits.bit_count()

    def to_string(self):
        return f"{self.bits:0{self.n}b}"
```

This is an **educational fixed-width abstraction**, not a standard Python built-in.

---

# 16. Important Bit-Manipulation Patterns

## Set bit

```python
x |= 1 << i
```

## Clear bit

```python
x &= ~(1 << i)
```

## Toggle bit

```python
x ^= 1 << i
```

## Test bit

```python
(x >> i) & 1
```

## Isolate lowest set bit

```python
x & -x
```

## Remove lowest set bit

```python
x & (x - 1)
```

## Power of two

```python
x > 0 and (x & (x - 1)) == 0
```

These are worth knowing for DSA even beyond the formal `bitset` structure.

---

# 17. Enumerate Set Bits

Python:

```python
def set_bit_positions(x):
    positions = []

    while x:
        lsb = x & -x
        pos = lsb.bit_length() - 1

        positions.append(pos)

        x &= x - 1

    return positions
```

For:

```text
10110100
```

the set-bit positions are:

```text
2, 4, 5, 7
```

**TC:** O(number of set bits) plus integer-word costs.

---

# 18. Common DSA Applications

Bitsets / bit masks are useful for:

```text
Subset representation
Set membership over a small universe
Visited masks
DP state compression
Subset DP
Bitmask enumeration
Feature flags
Permission masks
Parity/state toggles
Fast set intersection / union on bit representations
```

A common interpretation:

```text
bit i = 1
    → element/state i is present

bit i = 0
    → element/state i is absent
```

---

# 19. Common DSA Traps

### Python has `bitset`

→ Not as a direct built-in equivalent of `std::bitset<N>`. Use `int` as the normal built-in bit-mask representation.

### `std::bitset<10>` has 9 bits

→ No. It always has exactly 10 bits.

### `bitset<10>("100100101")` keeps only 9 bits

→ No. The shorter input is represented within the requested width, with leading zero padding. citeturn803370search3

### Python `~x` performs fixed-width inversion

→ No. Python integer bitwise operations use an unbounded sign-extension model. Mask explicitly for N-bit semantics. citeturn803370search4

### Python `bit_length()` is equivalent to C++ `bitset.size()`

→ No.

```text
bitset.size()   = fixed width N
bit_length()    = significant bits needed for integer
```

### Heap-like binary order exists inside a bitset

→ No. A bitset is simply a sequence of bits.

### `count()` means the number of zero bits

→ No. It counts set/1 bits.

### `bitset` and `vector<bool>` are identical

→ No. `bitset<N>` has compile-time fixed width; `vector<bool>` is dynamically sized.

---

# 20. What to Memorize

## MUST KNOW — C++

```cpp
bitset<N> b;

b[i];
b.test(i);

b.set(i);
b.reset(i);
b.flip(i);

b.count();
b.any();
b.all();
b.none();

a & b;
a | b;
a ^ b;
~a;

a << k;
a >> k;

b.to_string();
b.to_ullong();
```

And the concept:

```text
bitset<N> = exactly N bits
```

---

## MUST KNOW — Python

```python
x = 0

x |= 1 << i          # set
x &= ~(1 << i)       # clear
x ^= 1 << i          # toggle
(x >> i) & 1         # test

x & y
x | y
x ^ y
~x

x << k
x >> k

x.bit_count()
x.bit_length()

bin(x)
f"{x:08b}"
```

And:

```text
Python int = arbitrary-width bit mask
```

---

# 21. REFERENCE ONLY

## C++

```text
to_ulong()
to_ullong()
to_string(custom chars)
operator[]
stream input
hash<bitset>
vector<bool>
boost::dynamic_bitset
C++20 <bit> utilities
```

## Python

```text
fixed-width BitSet wrapper
set-bit enumeration
x & -x
x & (x-1)
power-of-two test
to_bytes()
from_bytes()
```

---

# 22. One-Glance Syntax Reference

| Operation | C++ `bitset<N>` | Python `int` |
|---|---|---|
| Create | `bitset<8> b;` | `b = 0` |
| Binary init | `bitset<8>("1010")` | `int("1010",2)` |
| Print | `cout << b` | `bin(b)` |
| Fixed width | automatic | `f"{b:08b}"` |
| Test | `b.test(i)` | `(b>>i)&1` |
| Access | `b[i]` | `(b>>i)&1` |
| Set | `b.set(i)` | `b \|= 1<<i` |
| Reset | `b.reset(i)` | `b &= ~(1<<i)` |
| Flip | `b.flip(i)` | `b ^= 1<<i` |
| Set all | `b.set()` | `b = MASK` |
| Reset all | `b.reset()` | `b = 0` |
| Flip all | `b.flip()` | `b ^= MASK` |
| Count 1s | `b.count()` | `b.bit_count()` |
| Any | `b.any()` | `b != 0` |
| All | `b.all()` | `b == MASK` |
| None | `b.none()` | `b == 0` |
| AND | `a & b` | `a & b` |
| OR | `a \| b` | `a \| b` |
| XOR | `a ^ b` | `a ^ b` |
| NOT | `~a` | `(~a) & MASK` for N bits |
| Left shift | `a << k` | `a << k` |
| Right shift | `a >> k` | `a >> k` |
| To string | `b.to_string()` | `f"{b:Nb}"` |
| To integer | `b.to_ullong()` | Already `int` |

---

# 23. Final Mental Model

```text
C++

std::bitset<N>
        ↓
exactly N bits
        ↓
set / reset / flip / test
        ↓
& / | / ^ / ~
        ↓
<< / >>
        ↓
count / any / all / none
```

```text
Python

int
 ↓
arbitrary-width bit mask
 ↓
set   |= 1<<i
clear &= ~(1<<i)
flip  ^= 1<<i
test  = (x>>i)&1
 ↓
& / | / ^ / ~
 ↓
<< / >>
 ↓
bit_count / bit_length
```

### The distinction to remember

```text
C++ bitset<N>
    fixed width

Python int
    arbitrary precision
    use MASK for fixed-width behavior
```

---

# 24. Files

- `bitset_cpp.cpp` → runnable C++ reference
- `bitset_python.py` → runnable Python reference
- `bitset_cpp_python.md` → comparison + revision sheet
