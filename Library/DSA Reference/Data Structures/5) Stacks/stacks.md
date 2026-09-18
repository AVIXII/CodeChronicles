# Stacks — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Main comparison:** `std::stack` ↔ Python `list`

---

# 0. How to Use This Sheet

This sheet is intentionally divided into:

- **CORE / MUST KNOW** → memorize these.
- **EXTRAS / REFERENCE** → useful implementation/library details to recognize and look up.

The accompanying `.cpp` and `.py` files follow the same organization.

---

# 1. CORE / MUST KNOW

## Core Mental Model

```text
STACK

LIFO
Last In, First Out

        TOP
         ↓
        [C]  ← first removed
        [B]
        [A]

Push → add at top
Pop  → remove from top
Peek → inspect top
```

The fundamental stack operations are:

```text
push
pop
top / peek
size
empty
```

---

# 2. Core Complexity Summary

| Operation | C++ `stack` | Python `list` stack | Notes |
|---|---:|---:|---|
| Push | **O(1) amortized** | **O(1) amortized** | Add at end/top |
| Pop | **O(1)** | **O(1)** | Remove top/end |
| Top / Peek | **O(1)** | **O(1)** | Inspect without removal |
| Size | **O(1)** | **O(1)** | |
| Empty | **O(1)** | **O(1)** | |
| Search | No direct operation | O(n) if manually scanned | Stack does not expose arbitrary access |
| Traverse | No direct iterator | O(n) | Usually done by copying/popping |
| Copy | O(n) | O(n) | Creates another stack/list |

### Memorize this

```text
push       O(1)
pop        O(1)
top/peek   O(1)
size       O(1)
empty      O(1)
```

---

# 3. CORE: C++ `std::stack`

## Creation

```cpp
stack<int> s;
```

---

## Push

```cpp
s.push(32);
```

**TC:** O(1) amortized for the normal stack implementations used underneath.

---

## Top

```cpp
s.top();
```

**TC:** O(1)

Important:

```cpp
if (!s.empty())
    cout << s.top();
```

Calling `top()` on an empty stack is invalid.

---

## Pop

```cpp
s.pop();
```

**TC:** O(1)

Important:

> `std::stack::pop()` does **not** return the removed value.

Correct:

```cpp
int x = s.top();
s.pop();
```

---

## Size

```cpp
s.size();
```

**TC:** O(1)

---

## Empty

```cpp
s.empty();
```

**TC:** O(1)

---

## Print / Traverse

`std::stack` does **not** provide `begin()` / `end()` or indexing.

To consume it:

```cpp
while (!s.empty()) {
    cout << s.top();
    s.pop();
}
```

**TC:** O(n)  
**SC:** O(1) auxiliary

But this **destroys the stack**.

To preserve it:

```cpp
stack<int> copy = s;

while (!copy.empty()) {
    cout << copy.top();
    copy.pop();
}
```

**TC:** O(n)  
**SC:** O(n)

---

# 4. CORE: Python Stack Using `list`

Python does not require a special stack class for normal DSA.

Use:

```python
stack = []
```

---

## Push

```python
stack.append(x)
```

**TC:** O(1) amortized

---

## Top / Peek

```python
stack[-1]
```

**TC:** O(1)

Safe pattern:

```python
if stack:
    top = stack[-1]
```

---

## Pop

```python
x = stack.pop()
```

**TC:** O(1)

Unlike C++:

> Python `list.pop()` returns the removed element.

---

## Size

```python
len(stack)
```

**TC:** O(1)

---

## Empty

```python
not stack
```

**TC:** O(1)

---

## Print / Consume

```python
while stack:
    print(stack[-1])
    stack.pop()
```

**TC:** O(n)  
**SC:** O(1) auxiliary

This destroys the stack.

To preserve it:

```python
copy_stack = stack.copy()
```

then pop from `copy_stack`.

---

# 5. CORE C++ vs Python

| Concept | C++ | Python |
|---|---|---|
| Stack | `stack<int> s` | `s = []` |
| Push | `s.push(x)` | `s.append(x)` |
| Pop | `s.pop()` | `s.pop()` |
| Peek / Top | `s.top()` | `s[-1]` |
| Size | `s.size()` | `len(s)` |
| Empty | `s.empty()` | `not s` |
| Popped value | Must call `top()` first | `pop()` returns it |
| Indexing | No | Technically possible if using list, but not part of stack abstraction |
| Iterators | No | List supports them |
| Destroy by traversal | Pop repeatedly | Pop repeatedly |

---

# 6. The Most Important C++ Difference

## `pop()` does not return the value

```cpp
int x = s.top();
s.pop();
```

versus Python:

```python
x = s.pop()
```

This is an easy syntax difference to accidentally carry from one language into the other.

---

# 7. EXTRAS / REFERENCE — C++

## `emplace`

Instead of:

```cpp
stack<pair<int,string>> s;

s.push({1, "one"});
```

you can write:

```cpp
s.emplace(1, "one");
```

Constructs the element in place.

---

## `swap`

```cpp
s1.swap(s2);
```

Useful when exchanging stacks.

---

## Custom Underlying Container

`std::stack` is a container adaptor.

```cpp
stack<int> a;                  // default underlying container
stack<int, deque<int>> b;
stack<int, vector<int>> c;
stack<int, list<int>> d;
```

For normal DSA:

```cpp
stack<int>
```

is enough.

The underlying container must provide the operations required by the adaptor.

---

## No Direct Iteration

Unlike `vector`:

```cpp
s.begin();      // not available
s.end();        // not available
s[i];           // not available
```

The stack intentionally exposes only its top.

This is the entire point of the abstraction:

> you don't get to rummage through the middle just because humans are incapable of leaving data structures alone.

---

# 8. EXTRAS / REFERENCE — Python

## `deque` as a Stack

```python
from collections import deque

stack = deque()

stack.append(x)
stack.pop()
stack[-1]
```

These are O(1).

This is useful when a problem may also require efficient operations at the other end.

---

## Why `list` is Usually the Default

For ordinary DSA stack problems:

```python
stack = []
```

is the simplest choice.

Use `deque` when the same problem also needs efficient operations from both ends.

---

## Custom Stack Class

```python
class Stack:
    def __init__(self):
        self.data = []

    def push(self, x):
        self.data.append(x)

    def pop(self):
        return self.data.pop()

    def top(self):
        return self.data[-1]

    def empty(self):
        return not self.data

    def size(self):
        return len(self.data)
```

This is useful for learning the abstraction, but you normally don't need to write it in DSA problems.

---

# 9. Manual Implementations

## Array-Based Stack

A stack can be implemented using a dynamic array:

```text
push  → append at end
pop   → remove end
top   → inspect end
```

### C++

```cpp
class Stack {
    vector<int> data;

public:
    void push(int x) {
        data.push_back(x);
    }

    void pop() {
        data.pop_back();
    }

    int top() {
        return data.back();
    }
};
```

### Python

```python
class Stack:
    def __init__(self):
        self.data = []

    def push(self, x):
        self.data.append(x)

    def pop(self):
        return self.data.pop()

    def top(self):
        return self.data[-1]
```

All core operations:

```text
push   O(1) amortized
pop    O(1)
top    O(1)
```

---

## Linked-List Stack

Representation:

```text
TOP
 ↓
[C] → [B] → [A] → null
```

Push:

```text
new node
   ↓
TOP → old TOP
```

Pop:

```text
TOP = TOP.next
```

Both:

```text
push → O(1)
pop  → O(1)
top  → O(1)
```

Extra storage:

```text
O(n)
```

---

# 10. Stack vs Queue

| Feature | Stack | Queue |
|---|---|---|
| Principle | LIFO | FIFO |
| Add | Top | Rear |
| Remove | Top | Front |
| Peek | Top | Front |
| Typical C++ | `stack` | `queue` |
| Python | `list` / `deque` | `deque` |

Memorize:

```text
Stack → LIFO
Queue → FIFO
```

---

# 11. Common DSA Applications

Stacks are commonly used for:

```text
Balanced parentheses
Expression evaluation
Infix → postfix/prefix
Undo / redo
Function-call / recursion simulation
Monotonic stack
Next greater element
Previous greater element
Next smaller element
Previous smaller element
Histogram problems
DFS variants
Backtracking
```

These are applications rather than stack API operations, so they belong in your DSA understanding rather than your API memorization list.

---

# 12. Common DSA Traps

### `pop()` gives the removed element in C++

→ No.

```cpp
int x = s.top();
s.pop();
```

### `pop()` gives the removed element in Python

→ Yes.

```python
x = stack.pop()
```

### `top()` is safe on an empty C++ stack

→ No. Check `empty()` first.

### `stack[-1]` is safe on an empty Python list

→ No. It raises `IndexError`.

### `std::stack` supports indexing

→ No.

### `std::stack` supports iterators

→ No.

### Python `pop(0)` is a good stack operation

→ It works on a list, but it is O(n). A stack should operate at the end.

### `list.insert(0, x)` is a good Python stack push

→ No. O(n). Use `append()`.

### Stack traversal preserves the stack

→ Not if you pop from the original. Copy first.

---

# 13. What to Memorize

## MUST KNOW — C++

```cpp
stack<int> s;

s.push(x);
s.pop();
s.top();

s.size();
s.empty();
```

And:

```cpp
while (!s.empty()) {
    int x = s.top();
    s.pop();
}
```

Remember:

```text
pop() → doesn't return value
top() → returns/refs top
```

---

## MUST KNOW — Python

```python
stack = []

stack.append(x)
stack.pop()
stack[-1]

len(stack)
not stack
```

Remember:

```text
append → push
pop    → pop + returns value
[-1]   → top
```

---

## REFERENCE ONLY

### C++

```text
emplace()
swap()
custom underlying container
vector/list/deque backing
manual linked-list stack
C++23 push_range()
```

### Python

```text
deque
custom Stack class
manual linked-list stack
two-queue implementations
```

---

# 14. One-Glance Syntax Reference

| Operation | C++ | Python |
|---|---|---|
| Create | `stack<int> s;` | `stack = []` |
| Push | `s.push(x)` | `stack.append(x)` |
| Pop | `s.pop()` | `stack.pop()` |
| Peek | `s.top()` | `stack[-1]` |
| Size | `s.size()` | `len(stack)` |
| Empty | `s.empty()` | `not stack` |
| Traverse | copy + pop | copy + pop |
| Swap | `s1.swap(s2)` | `s1, s2 = s2, s1` |
| In-place construct | `s.emplace(...)` | N/A |
| Deque stack | `stack<int, deque<int>>` | `deque()` |

---

# 15. Final Mental Model

```text
STACK

LIFO
│
├── push       O(1)
│
├── top/peek   O(1)
│
├── pop        O(1)
│
├── size       O(1)
│
└── empty      O(1)
```

### C++

```text
std::stack
    ↓
container adaptor
    ↓
top only
    ↓
push / pop / top / size / empty
```

### Python

```text
list
 ↓
append() → push
pop()    → pop
[-1]     → top
```

### The one thing to remember

```text
Stack = LIFO
Only interact with the TOP.
```

---

# 16. Files

- `stacks_cpp.cpp` → runnable C++ reference
- `stacks_python.py` → runnable Python reference
- `stacks_cpp_python.md` → comparison + revision sheet
