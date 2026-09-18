# Strings — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Main pair:** `std::string` ↔ `str`

---

# 0. How to Use This Sheet

This sheet deliberately separates information into:

- **CORE / MUST KNOW** → memorize these.
- **EXTRAS / REFERENCE** → know they exist; look them up when needed.

The corresponding `.cpp` and `.py` files follow the same structure.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
C++ string                  Python str
-----------                 ----------
mutable                     immutable
O(1) indexing               O(1) indexing
character update            cannot update in place
push_back/pop_back          no in-place character push/pop
middle insert/erase O(n)    "modification" creates a new string
```

The most important difference:

> **C++ strings are mutable. Python strings are immutable.**

---

## Core Complexity Summary

| Operation | C++ `string` | Python `str` | Important Note |
|---|---:|---:|---|
| Character access | **O(1)** | **O(1)** | Python supports negative indices |
| Character update | **O(1)** | N/A | Python strings immutable |
| Length | **O(1)** | **O(1)** | `size()/length()` vs `len()` |
| Empty check | **O(1)** | **O(1)** | |
| Search | O(n) typical / algorithm-dependent | O(n) typical | Don't assume O(log n) |
| Substring / slice | **O(k)** | **O(k)** | New string produced |
| Concatenation | O(n+m) | O(n+m) | Result is a new string |
| Compare | O(min(n,m)) | O(min(n,m)) | Lexicographical |
| Insert | O(n) | O(n) | Middle insertion |
| Erase | O(n) | O(n) | Python rebuilds a new string |
| Replace | O(n + output) | O(n + output) | New result |
| Reverse | O(n) | O(n) | Python result is new |
| Count | O(n) | O(n) typical | |
| Sort characters | O(n log n) | O(n log n) | Python uses `sorted()` |
| Min / Max char | O(n) | O(n) | |
| Push end | **O(1) amortized** | N/A | Python `str` immutable |
| Pop end | **O(1)** | N/A | Python `str` immutable |

### Memorize these first

```text
Access       O(1)
Length       O(1)
Search       O(n) typical
Slice        O(k)
Compare      O(min(n,m))
Insert       O(n)
Erase        O(n)
Reverse      O(n)
Count        O(n)
Sort         O(n log n)
```

---

# 2. CORE: C++ `string`

## Creation

```cpp
string s;
string a = "hello";
string b("hello world");
string c(5, 'a');
```

```text
c == "aaaaa"
```

Copy:

```cpp
string b2 = b;
```

---

## Input

Token:

```cpp
cin >> s;
```

Reads until whitespace.

Whole line:

```cpp
getline(cin, s);
```

Reads spaces too.

After `cin >> x`:

```cpp
cin.ignore(numeric_limits<streamsize>::max(), '\n');
getline(cin, s);
```

One character:

```cpp
char ch = cin.get();
```

---

## Length / Empty

```cpp
s.size();
s.length();
s.empty();
```

All:

**TC:** O(1)

---

## Character Access

```cpp
s[i];
s.at(i);
s.front();
s.back();
```

| Method | Behavior |
|---|---|
| `s[i]` | O(1), no bounds checking |
| `s.at(i)` | O(1), bounds checked |
| `s.front()` | First char |
| `s.back()` | Last char |

No Python-style negative indexing.

---

## Character Update

```cpp
s[i] = 'x';
```

**TC:** O(1)

---

## Concatenation / Append

```cpp
s += t;
s = s + t;
s.append(t);
s.push_back('x');
```

Repeated characters:

```cpp
s.append(3, '!');
```

**TC:** proportional to resulting/appended data, generally O(n+m) for concatenation.

---

## Clear

```cpp
s.clear();
```

or:

```cpp
s = "";
```

---

## Comparison

```cpp
a == b
a != b
a < b
a <= b
a > b
a >= b
```

Or:

```cpp
a.compare(b);
```

`compare()`:

```text
< 0  → a < b
  0  → a == b
> 0  → a > b
```

**TC:** O(min(n,m))

Comparison is lexicographical.

---

## Substring

```cpp
s.substr(pos, count);
s.substr(pos);
```

**TC:** O(k)  
**SC:** O(k)

---

## Search

```cpp
s.find("abc");
s.find('a');
s.find("abc", start);
s.rfind("abc");
```

Not found:

```cpp
string::npos
```

Example:

```cpp
size_t pos = s.find("world");

if (pos != string::npos) {
    // found
}
```

**TC:** depends on implementation/search pattern; don't treat it as automatically O(log n).

---

## Insert

```cpp
s.insert(index, "abc");
```

```cpp
s.insert(index, count, 'x');
```

**TC:** generally O(n + inserted length)

---

## Erase

```cpp
s.erase(index, count);
s.erase(index);
```

**TC:** O(n) in general because remaining characters may shift.

---

## Replace

```cpp
s.replace(index, count, "abc");
```

This is substring/range replacement.

---

## Push / Pop

```cpp
s.push_back('x');
s.pop_back();
```

```text
push_back  O(1) amortized
pop_back   O(1)
```

These are important because C++ strings are mutable.

---

## Traversal

```cpp
for (char c : s)
    cout << c;
```

With index:

```cpp
for (int i = 0; i < (int)s.size(); ++i)
    cout << s[i];
```

Iterator:

```cpp
for (auto it = s.begin(); it != s.end(); ++it)
    cout << *it;
```

All:

**TC:** O(n)

---

## Reverse

```cpp
reverse(s.begin(), s.end());
```

**TC:** O(n)  
**SC:** O(1)

---

## Sort Characters

```cpp
sort(s.begin(), s.end());
```

Descending:

```cpp
sort(s.rbegin(), s.rend());
```

**TC:** O(n log n)

---

## Search / Count Character

```cpp
count(s.begin(), s.end(), 'a');
```

**TC:** O(n)

---

# 3. CORE: Python `str`

## Creation

```python
s = "hello"
s = 'hello'
```

Multiline:

```python
s = """
hello
world
"""
```

---

## Input

```python
s = input()
```

Strip:

```python
s = input().strip()
```

Split:

```python
parts = input().split()
```

---

## Length / Empty

```python
len(s)
not s
```

Both:

**TC:** O(1)

---

## Character Access

```python
s[i]
s[-1]
```

Negative indexing is supported.

---

## Character Update

Not allowed:

```python
# s[0] = 'H'
```

Strings are immutable.

Instead:

```python
s = 'H' + s[1:]
```

This creates a new string.

---

## Concatenation

```python
s + t
s += t
```

Repetition:

```python
"abc" * 3
```

For many pieces:

```python
"".join(parts)
```

is the preferred pattern.

---

## Clear

```python
s = ""
```

Python strings cannot be cleared in place.

---

## Comparison

```python
a == b
a != b

a < b
a <= b
a > b
a >= b
```

Lexicographical.

**TC:** O(min(n,m))

Do not use:

```python
a is b
```

for value comparison.

`is` checks identity.

---

## Slicing

```python
s[l:r]
s[:r]
s[l:]
s[::-1]
s[::2]
```

Slices create new strings.

**TC:** O(k)  
**SC:** O(k)

---

## Search

```python
s.find("abc")
s.index("abc")
s.rfind("abc")
"abc" in s
```

Difference:

```text
find()  → -1 if absent
index() → ValueError if absent
in      → True / False
```

---

## Replace

```python
s.replace(old, new)
```

Limited:

```python
s.replace(old, new, count)
```

Returns a new string.

---

## Case

```python
s.upper()
s.lower()
s.capitalize()
s.title()
```

Each returns a new string.

---

## Traversal

```python
for ch in s:
    ...
```

With index:

```python
for i, ch in enumerate(s):
    ...
```

Reverse:

```python
for ch in reversed(s):
    ...
```

**TC:** O(n)

---

# 4. CORE C++ vs Python Syntax Map

| Concept | C++ | Python |
|---|---|---|
| String type | `string` | `str` |
| Create | `string s;` | `s = ""` |
| Literal | `string s="hello";` | `s="hello"` |
| Access | `s[i]` | `s[i]` |
| Last | `s[n-1]` / `s.back()` | `s[-1]` |
| Length | `s.size()` | `len(s)` |
| Empty | `s.empty()` | `not s` |
| Update char | `s[i]='x'` | Not allowed |
| Concatenate | `s += t` | `s += t` |
| Append char | `s.push_back(c)` | Immutable |
| Pop char | `s.pop_back()` | Immutable |
| Search | `s.find(x)` | `s.find(x)` |
| Index search | `find()` | `s.index(x)` |
| Last occurrence | `s.rfind(x)` | `s.rfind(x)` |
| Substring | `s.substr(i,k)` | `s[i:i+k]` |
| Erase | `s.erase(i,k)` | `s[:i] + s[i+k:]` |
| Replace | `s.replace(i,k,t)` | `s.replace(old,new)` |
| Reverse | `reverse(...)` | `s[::-1]` |
| Sort | `sort(...)` | `"".join(sorted(s))` |
| Count | `count(...)` | `s.count(...)` |
| Min | `*min_element(...)` | `min(s)` |
| Max | `*max_element(...)` | `max(s)` |
| Split | manual / streams | `s.split()` |
| Join | manual / algorithms | `sep.join(parts)` |
| Number → string | `to_string(x)` | `str(x)` |
| String → int | `stoi(s)` | `int(s)` |

---

# 5. EXTRAS / REFERENCE

These are useful but should **not** be part of your first memorization pass.

---

## C++: `std::transform` for Case Conversion

```cpp
transform(
    s.begin(),
    s.end(),
    s.begin(),
    [](unsigned char c) {
        return (char)toupper(c);
    }
);
```

Lowercase:

```cpp
transform(
    s.begin(),
    s.end(),
    s.begin(),
    [](unsigned char c) {
        return (char)tolower(c);
    }
);
```

**TC:** O(n)

---

## C++: Generic `std::replace`

```cpp
replace(
    s.begin(),
    s.end(),
    'a',
    'o'
);
```

Replaces individual characters/elements.

It is different from:

```cpp
s.replace(...)
```

which performs string/range replacement.

---

## C++: `min_element` / `max_element`

```cpp
char mn = *min_element(s.begin(), s.end());
char mx = *max_element(s.begin(), s.end());
```

**TC:** O(n)

---

## C++: Numeric Conversion

```cpp
stoi("123");
stoll("123456");
stod("12.34");

to_string(12345);
```

---

## C++: Character Classification

```cpp
isalpha(c);
isdigit(c);
islower(c);
isupper(c);
isalnum(c);
isspace(c);
```

---

## C++: Generic Algorithms

Useful with strings:

```cpp
find(...)
count(...)
replace(...)
sort(...)
reverse(...)
transform(...)
accumulate(...)
min_element(...)
max_element(...)
partial_sum(...)
```

---

## C++: `data()`

```cpp
const char* p = s.data();
```

Provides access to the string's underlying character storage.

---

## Python: `split()`

```python
s.split()
s.split(",")
```

Regex:

```python
import re
re.split(r"[;, ]+", s)
```

**Typical TC:** O(n)

---

## Python: `strip()`

```python
s.strip()
s.lstrip()
s.rstrip()
```

Can also remove specified characters:

```python
"---hello---".strip("-")
```

---

## Python: `join()`

```python
" ".join(words)
",".join(words)
```

**TC:** proportional to total input/output length.

This is one of the most useful Python string operations for DSA and general coding.

---

## Python: Character / String Classification

```python
s.isalpha()
s.isdigit()
s.isalnum()

s.islower()
s.isupper()
s.isspace()

s.isascii()
s.istitle()
s.isidentifier()
```

---

## Python: Formatting

```python
"Hello {}!".format(name)
```

Modern:

```python
f"Hello {name}!"
```

---

## Python: Sorting Characters

No in-place `.sort()` exists for strings.

```python
sorted_chars = sorted(s)
```

This returns a list.

To rebuild a string:

```python
sorted_s = "".join(sorted(s))
```

Descending:

```python
sorted_s = "".join(sorted(s, reverse=True))
```

**TC:** O(n log n)  
**SC:** O(n)

---

# 6. Copy / Aliasing / Identity

## C++

```cpp
string a = "hello";
string b = a;
```

`b` is an independent string object.

Reference:

```cpp
string& b = a;
```

---

## Python

```python
a = "hello"
b = a
```

Both names refer to the same immutable string object.

Value comparison:

```python
a == b
```

Identity:

```python
a is b
```

For normal string comparison, use `==`.

---

# 7. Manual DSA Algorithms

## Linear Search

### C++

```cpp
int findIndex(const string& s, char target) {
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == target)
            return i;
    }

    return -1;
}
```

### Python

```python
def find_index(s, target):
    for i, ch in enumerate(s):
        if ch == target:
            return i
    return -1
```

**TC:** O(n)  
**SC:** O(1)

---

## Palindrome

### C++

```cpp
bool isPalindrome(const string& s) {
    int l = 0;
    int r = (int)s.size() - 1;

    while (l < r) {
        if (s[l] != s[r])
            return false;

        ++l;
        --r;
    }

    return true;
}
```

### Python

```python
def is_palindrome(s):
    left, right = 0, len(s)-1

    while left < right:
        if s[left] != s[right]:
            return False

        left += 1
        right -= 1

    return True
```

**TC:** O(n)  
**SC:** O(1)

---

## Reverse

### C++

```cpp
int l = 0;
int r = (int)s.size() - 1;

while (l < r)
    swap(s[l++], s[r--]);
```

**TC:** O(n)  
**SC:** O(1)

### Python

Because `str` is immutable:

```python
chars = list(s)

left, right = 0, len(chars)-1

while left < right:
    chars[left], chars[right] = chars[right], chars[left]
    left += 1
    right -= 1

s = "".join(chars)
```

**TC:** O(n)  
**SC:** O(n)

---

## Naive Substring Search

### C++

```cpp
int naiveFind(const string& text,
              const string& pattern) {

    if (pattern.empty())
        return 0;

    if (pattern.size() > text.size())
        return -1;

    for (int i = 0;
         i + (int)pattern.size() <= (int)text.size();
         ++i) {

        int j = 0;

        while (j < (int)pattern.size() &&
               text[i+j] == pattern[j]) {
            ++j;
        }

        if (j == (int)pattern.size())
            return i;
    }

    return -1;
}
```

### Python

```python
def naive_find(text, pattern):
    if pattern == "":
        return 0

    if len(pattern) > len(text):
        return -1

    for i in range(len(text)-len(pattern)+1):
        j = 0

        while (
            j < len(pattern)
            and text[i+j] == pattern[j]
        ):
            j += 1

        if j == len(pattern):
            return i

    return -1
```

**Worst-case TC:** O(n·m)  
**SC:** O(1)

---

# 8. Important C++ String Distinctions

### `string::find()` vs `std::find()`

```cpp
s.find("abc");
```

Searches for a character or substring.

```cpp
find(s.begin(), s.end(), 'a');
```

Generic algorithm searching for an individual element.

---

### `string::replace()` vs `std::replace()`

```cpp
s.replace(...)
```

String/range replacement.

```cpp
std::replace(...)
```

Element-by-element replacement.

---

### `substr()` creates a new string

```cpp
string part = s.substr(l, r-l);
```

It is not a zero-copy view.

---

# 9. Important Python String Distinctions

### `find()` vs `index()`

```python
s.find(x)
```

→ `-1` if absent.

```python
s.index(x)
```

→ `ValueError` if absent.

### `in`

```python
x in s
```

→ boolean membership.

### `is` vs `==`

```python
a == b
```

→ value equality.

```python
a is b
```

→ object identity.

Never treat `is` as the normal string equality operator.

---

# 10. Common DSA Traps

## Core traps

**Python strings are mutable**  
→ False. `str` is immutable.

**C++ strings support negative indexing**  
→ False.

**`s[i]` is O(1) in both languages**  
→ Yes, for ordinary string indexing.

**Python `s[::-1]` reverses in place**  
→ No. It creates a new string.

**C++ `reverse()` creates a new string**  
→ No. It reverses in place.

**C++ `push_back()` is always O(1)**  
→ Treat it as **O(1) amortized**.

**String search is O(log n)**  
→ No. Ordinary substring search is not binary search.

**Python `find()` and `index()` behave the same when absent**  
→ No. `find()` returns `-1`; `index()` raises `ValueError`.

**`std::replace()` replaces substrings**  
→ No. It replaces elements/characters.

**Python strings have `.sort()`**  
→ No. Use `sorted(s)`.

---

# 11. What to Memorize

## MUST KNOW — C++

```cpp
string s;

s[i]
s.at(i)

s.size()
s.empty()

s.front()
s.back()

s += t
s.push_back(c)
s.pop_back()

s.substr(...)
s.find(...)
s.erase(...)
s.replace(...)

sort(...)
reverse(...)

s == t
s < t
```

Also know:

```text
string::npos
```

---

## MUST KNOW — Python

```python
s = ""

s[i]
s[-1]

len(s)
not s

s.find(...)
s.index(...)
x in s

s[start:end]
s[::-1]

s.replace(...)

s.upper()
s.lower()

s.split()
"".join(parts)

s == t
s < t
```

---

## REFERENCE ONLY

### C++

```text
transform()
rfind()
count()
min_element()
max_element()
accumulate()
partial_sum()
stoi()
stoll()
stod()
to_string()
character classification
data()
iterator details
```

### Python

```text
rfind()
strip()
lstrip()
rstrip()
capitalize()
title()
isalnum()
isascii()
isidentifier()
format()
f-strings
regex split
deep string-processing tricks
```

---

# 12. One-Glance Syntax Reference

| Operation | C++ | Python |
|---|---|---|
| Create | `string s;` | `s = ""` |
| Initialize | `string s="hello";` | `s="hello"` |
| Length | `s.size()` | `len(s)` |
| Empty | `s.empty()` | `not s` |
| Access | `s[i]` | `s[i]` |
| Last | `s.back()` | `s[-1]` |
| Update char | `s[i]='x'` | Not allowed |
| Concatenate | `s += t` | `s += t` |
| Append char | `s.push_back(c)` | Immutable |
| Pop char | `s.pop_back()` | Immutable |
| Find | `s.find(x)` | `s.find(x)` |
| Search index | iterator / `find()` | `s.index(x)` |
| Last find | `s.rfind(x)` | `s.rfind(x)` |
| Substring | `s.substr(i,k)` | `s[i:i+k]` |
| Erase | `s.erase(i,k)` | `s[:i]+s[i+k:]` |
| Replace | `s.replace(i,k,t)` | `s.replace(old,new)` |
| Reverse | `reverse(...)` | `s[::-1]` |
| Sort | `sort(...)` | `"".join(sorted(s))` |
| Count | `count(...)` | `s.count(x)` |
| Min | `*min_element(...)` | `min(s)` |
| Max | `*max_element(...)` | `max(s)` |
| Split | manual / stream | `s.split()` |
| Join | manual / algorithm | `sep.join(parts)` |
| Number → string | `to_string(x)` | `str(x)` |
| String → int | `stoi(s)` | `int(s)` |

---

# 13. Final Mental Model

```text
STRING

Access                 O(1)

Length                 O(1)

Search                 O(n) typical

Compare                O(min(n,m))

Substring / Slice      O(k)

Insert / Erase         O(n)

Replace                O(n + output)

Reverse                O(n)

Count                  O(n)

Sort                   O(n log n)
```

### The concept that explains most of the difference

```text
C++ string
    ↓
mutable
    ↓
character can be changed in place
    ↓
push_back / pop_back available

Python str
    ↓
immutable
    ↓
cannot change a character in place
    ↓
"modifications" create new strings
    ↓
join() is important for building many pieces
```

---

# 14. Files

- `strings_cpp.cpp` → runnable C++ reference
- `strings_python.py` → runnable Python reference
- `strings_cpp_python.md` → comparison + revision sheet
