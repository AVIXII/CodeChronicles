# Queues — C++ & Python

> **Purpose:** DSA / competitive programming / interview revision  
> **C++:** C++20  
> **Python:** Python 3.x  
> **Scope:** FIFO queue, deque, priority queue / heap

---

# 0. How to Use This Sheet

Queues are a family of related structures, not one single structure:

```text
FIFO Queue
    First In, First Out

Deque
    Double-ended queue

Priority Queue / Heap
    Highest-priority element comes out first
```

This sheet is split into:

- **CORE / MUST KNOW** → memorize these.
- **EXTRAS / REFERENCE** → useful APIs and implementation details.

The `.cpp` and `.py` files follow the same organization.

---

# 1. CORE / MUST KNOW

## Mental Model

### FIFO Queue

```text
FRONT → [A] [B] [C] ← BACK

push/enqueue  → BACK
pop/dequeue   → FRONT
```

### Deque

```text
FRONT ⇄ [A] [B] [C] ⇄ BACK

insert/remove at BOTH ends
```

### Priority Queue

```text
                 TOP
                  ↓
        highest-priority item
                  ↓
          remaining items

pop() always removes the current highest-priority item
```

---

# 2. Core Complexity Summary

| Operation | C++ `queue` | Python `deque` | C++ `deque` | Priority Queue / Heap |
|---|---:|---:|---:|---:|
| Push/enqueue back | O(1) | O(1) | O(1) | O(log n) |
| Pop/dequeue front | O(1) | O(1) | O(1) | O(log n) |
| Push front | N/A | O(1) | O(1) | N/A |
| Pop back | N/A | O(1) | O(1) | N/A |
| Front | O(1) | O(1) | O(1) | N/A |
| Back | O(1) | O(1) | O(1) | N/A |
| Top priority | N/A | N/A | N/A | **O(1)** |
| Size | O(1) | O(1) | O(1) | O(1) |
| Empty | O(1) | O(1) | O(1) | O(1) |
| Random access | No API | O(1) at ends, O(n) middle | O(1) | Heap-array access is not a sorted-order operation |
| Heapify | N/A | N/A | N/A | **O(n)** |

C++ `std::queue` is a FIFO container adaptor, normally backed by `std::deque`; its interface exposes front/back, push/pop, size and empty. citeturn696562search1

C++ `std::deque` supports O(1) insertion/removal at either end and O(1) random access. citeturn696562search0

Python's `collections.deque` is the appropriate standard-library structure for efficient operations at both ends. Python list `pop(0)`/`insert(0, ...)` are O(n), so they should not be used as queue operations. citeturn696562search4

---

# 3. CORE: C++ `queue`

## Creation

```cpp
queue<int> q;
```

---

## Enqueue / Push

```cpp
q.push(x);
```

Adds to the back.

**TC:** O(1)

---

## Front

```cpp
q.front();
```

Returns the oldest element.

**TC:** O(1)

---

## Back

```cpp
q.back();
```

Returns the newest element.

**TC:** O(1)

---

## Dequeue / Pop

```cpp
q.pop();
```

Removes the front element.

**TC:** O(1)

Important:

```cpp
queue.pop()
```

does **not** return the removed element.

Use:

```cpp
int x = q.front();
q.pop();
```

---

## Size / Empty

```cpp
q.size();
q.empty();
```

Both:

**TC:** O(1)

---

## Print / Consume

```cpp
while (!q.empty()) {
    cout << q.front() << ' ';
    q.pop();
}
```

**TC:** O(n)  
**SC:** O(1) auxiliary

This destroys the queue.

To preserve it:

```cpp
queue<int> copy = q;
```

then pop from `copy`.

---

# 4. CORE: Python `deque` as Queue

## Creation

```python
from collections import deque

q = deque()
```

---

## Enqueue

```python
q.append(x)
```

**TC:** O(1)

---

## Front

```python
q[0]
```

For normal endpoint access:

**TC:** O(1)

---

## Back

```python
q[-1]
```

**TC:** O(1)

---

## Dequeue

```python
x = q.popleft()
```

**TC:** O(1)

Unlike C++:

> Python `popleft()` returns the removed element.

---

## Size / Empty

```python
len(q)
not q
```

**TC:** O(1)

---

## Consume queue

```python
while q:
    print(q.popleft())
```

**TC:** O(n)

---

# 5. CORE: Deque

## C++

```cpp
deque<int> dq;
```

Insert:

```cpp
dq.push_front(x);
dq.push_back(x);
```

Remove:

```cpp
dq.pop_front();
dq.pop_back();
```

Access:

```cpp
dq.front();
dq.back();
dq[i];
dq.at(i);
```

Traversal:

```cpp
for (int x : dq)
    cout << x;
```

### Core complexity

```text
push_front    O(1)
push_back     O(1)

pop_front     O(1)
pop_back      O(1)

front         O(1)
back          O(1)
random access O(1)
```

`std::deque` is not contiguous like `vector`, but provides constant-time random access and constant-time end insertion/removal. citeturn696562search0

---

## Python

```python
from collections import deque

dq = deque()
```

Insert:

```python
dq.appendleft(x)
dq.append(x)
```

Remove:

```python
dq.popleft()
dq.pop()
```

Access:

```python
dq[0]
dq[-1]
```

Traversal:

```python
for x in dq:
    ...
```

### Important

```text
append       O(1)
appendleft   O(1)

pop          O(1)
popleft      O(1)

end access   O(1)
middle access O(n)
```

For Python, `deque` is optimized for end operations, not arbitrary middle indexing. citeturn696562search4turn696562search5

---

# 6. CORE: C++ Priority Queue

## Max Priority Queue

```cpp
priority_queue<int> pq;
```

Default behavior:

```text
largest element = top()
```

---

## Push

```cpp
pq.push(x);
```

**TC:** O(log n)

---

## Top

```cpp
pq.top();
```

**TC:** O(1)

---

## Pop

```cpp
pq.pop();
```

Removes the top-priority element.

**TC:** O(log n)

`std::priority_queue` provides constant-time access to the largest element by default, with logarithmic insertion and extraction. citeturn696562search3

---

## Size / Empty

```cpp
pq.size();
pq.empty();
```

**TC:** O(1)

---

## Min Priority Queue

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

Now:

```text
smallest element = top()
```

---

## Custom Comparator

```cpp
struct createMin {
    bool operator()(const int& a,
                    const int& b) const {
        return a > b;
    }
};
```

Then:

```cpp
priority_queue<
    int,
    vector<int>,
    createMin
> pq;
```

The comparator defines the priority relationship. citeturn696562search3

---

# 7. CORE: Python Priority Queue / Heap

Python's normal DSA priority queue is:

```python
import heapq

pq = []
```

`heapq` provides a **min-heap by default**. The smallest item is always at `pq[0]`. citeturn696562search2

---

## Push

```python
heapq.heappush(pq, x)
```

**TC:** O(log n)

---

## Top / Minimum

```python
pq[0]
```

**TC:** O(1)

---

## Pop

```python
x = heapq.heappop(pq)
```

Returns and removes the smallest element.

**TC:** O(log n)

If the heap is empty:

```text
IndexError
```

---

## Heapify

```python
arr = [30, 10, 20, 5, 50]

heapq.heapify(arr)
```

Transforms the list **in place** into a min-heap.

**TC:** O(n)

Important:

> A heapified list is **not a sorted list**.

Only the heap invariant is guaranteed. citeturn696562search2

---

# 8. C++ vs Python Priority Queue

| Concept | C++ | Python |
|---|---|---|
| Default | Max-heap | Min-heap |
| Create | `priority_queue<int> pq` | `pq=[]` |
| Module | `<queue>` | `heapq` |
| Push | `pq.push(x)` | `heappush(pq,x)` |
| Top | `pq.top()` | `pq[0]` |
| Pop | `pq.pop()` | `heappop(pq)` |
| Size | `pq.size()` | `len(pq)` |
| Empty | `pq.empty()` | `not pq` |
| Min-heap | `greater<int>` comparator | Default |
| Max-heap | Default | Negative values or max-heap APIs |
| Heapify existing data | Constructor / heap adaptor methods | `heapq.heapify()` |
| Iteration | No direct iteration API | Heap is a list |

---

# 9. EXTRAS / REFERENCE: C++ Priority Queue

## Pair Priority Queue

```cpp
priority_queue<pair<int,int>> pq;
```

Pairs are compared lexicographically.

For max-heap:

```text
larger first element wins
if equal, larger second element wins
```

---

## Custom Object

```cpp
struct Node {
    int data;
};

struct cmp {
    bool operator()(const Node* a,
                    const Node* b) const {
        return a->data < b->data;
    }
};

priority_queue<
    Node*,
    vector<Node*>,
    cmp
> pq;
```

Useful for problems involving nodes/pointers.

---

## Underlying Container

Default:

```cpp
priority_queue<int>
```

uses `vector` underneath.

You can also use:

```cpp
priority_queue<int, deque<int>>
```

The standard requires the underlying container to provide random-access iterators and the required back/front/pop-back operations. citeturn696562search3

---

# 10. EXTRAS / REFERENCE: Python Heap

## Max-Heap via Negative Values

```python
max_heap = []

heapq.heappush(max_heap, -30)
heapq.heappush(max_heap, -10)
heapq.heappush(max_heap, -20)

maximum = -heapq.heappop(max_heap)
```

Common DSA trick.

---

## `nsmallest`

```python
heapq.nsmallest(k, arr)
```

Returns the `k` smallest elements.

---

## `nlargest`

```python
heapq.nlargest(k, arr)
```

Returns the `k` largest elements.

These are useful when you need only a limited number of extremes rather than fully sorting the entire collection.

---

## `heappushpop`

```python
heapq.heappushpop(heap, x)
```

Push then pop the smallest, efficiently combined.

---

## `heapreplace`

```python
heapq.heapreplace(heap, x)
```

Pop smallest and push `x`, keeping heap size unchanged.

These are advanced heap operations.

---

## Tuple Priority

```python
pq = []

heapq.heappush(pq, (2, "medium"))
heapq.heappush(pq, (1, "high"))

priority, value = heapq.heappop(pq)
```

Tuple comparison provides a natural priority mechanism.

For non-comparable task objects, use:

```python
(priority, counter, object)
```

to provide deterministic tie-breaking.

---

# 11. `queue.PriorityQueue` vs `heapq`

Python also provides:

```python
from queue import PriorityQueue
```

Example:

```python
pq = PriorityQueue()

pq.put((2, "medium"))
pq.put((1, "high"))

pq.get()
```

But:

```text
heapq
    → usual DSA / competitive-programming choice

PriorityQueue
    → synchronized / thread-safe queue
```

For normal DSA, use `heapq`.

---

# 12. Manual Circular Queue

A fixed-capacity circular queue uses:

```text
array
front index
size
```

Conceptually:

```text
[0][1][2][3][4]
 ↑
front

next index:
(i + 1) % capacity
```

Core operations:

```text
enqueue → O(1)
dequeue → O(1)
front   → O(1)
```

### C++

```cpp
class CircularQueue {
    vector<int> data;
    int frontIndex = 0;
    int size = 0;

public:
    explicit CircularQueue(int capacity)
        : data(capacity) {}

    void push(int x) {
        int index =
            (frontIndex + size) % data.size();

        data[index] = x;
        ++size;
    }

    int pop() {
        int x = data[frontIndex];

        frontIndex =
            (frontIndex + 1) % data.size();

        --size;
        return x;
    }
};
```

### Python

```python
class CircularQueue:
    def __init__(self, capacity):
        self.data = [None] * capacity
        self.front_index = 0
        self.size = 0
```

This implementation is useful to understand how a queue works internally.

---

# 13. Stack vs Queue vs Deque vs Priority Queue

| Structure | Rule | Add | Remove | Peek |
|---|---|---|---|---|
| Stack | LIFO | Top | Top | Top |
| Queue | FIFO | Back | Front | Front |
| Deque | Both ends | Both | Both | Front/Back |
| Priority Queue | Highest priority | Heap | Highest priority | Highest priority |

### Memorize

```text
Stack          → LIFO
Queue          → FIFO
Deque          → BOTH ends
Priority Queue → PRIORITY
```

---

# 14. Common DSA Applications

## Queue

```text
BFS
Level-order traversal
Scheduling
Producer-consumer patterns
Sliding-window support
```

## Deque

```text
Sliding-window maximum
Monotonic deque
0-1 BFS
Palindromic / two-ended processing
```

## Priority Queue / Heap

```text
Top-k problems
Kth largest / smallest
Dijkstra
Prim
Scheduling by priority
Merge k sorted structures
Median / two-heap patterns
```

---

# 15. Common DSA Traps

### Python list as queue with `pop(0)`

Wrong for efficient queues.

```python
queue.pop(0)
```

is O(n).

Use:

```python
from collections import deque
queue.popleft()
```

Python's CPython complexity reference explicitly recommends `deque` when adding/removing at both ends is required. citeturn696562search4

---

### C++ `queue.pop()` returns the removed item

No.

```cpp
int x = q.front();
q.pop();
```

---

### Python `deque.popleft()` returns the removed item

Yes.

```python
x = q.popleft();
```

---

### C++ priority queue is a min-heap by default

No.

```cpp
priority_queue<int>
```

is a **max-heap** by default.

---

### Python `heapq` is a max-heap by default

No.

It is a **min-heap** by default. citeturn696562search2

---

### Heapified list is sorted

No.

```python
heapq.heapify(a)
```

only establishes the heap invariant.

---

### Priority queue supports arbitrary search

Not as a normal efficient operation.

A priority queue is designed around:

```text
top
push
pop
```

not arbitrary lookup.

---

### Queue supports indexing in C++

`std::queue` does not expose indexing.

---

### `deque` is the same as `vector`

No.

Both provide O(1) indexing, but `deque` provides efficient insertion/removal at both ends and does not store all elements contiguously like `vector`. citeturn696562search0

---

# 16. What to Memorize

## MUST KNOW — C++

### Queue

```cpp
queue<int> q;

q.push(x);
q.pop();

q.front();
q.back();

q.size();
q.empty();
```

### Deque

```cpp
deque<int> dq;

dq.push_front(x);
dq.push_back(x);

dq.pop_front();
dq.pop_back();

dq.front();
dq.back();

dq[i];
```

### Priority Queue

```cpp
priority_queue<int> pq;

pq.push(x);
pq.pop();
pq.top();

pq.size();
pq.empty();
```

Min-heap:

```cpp
priority_queue<
    int,
    vector<int>,
    greater<int>
> pq;
```

---

## MUST KNOW — Python

### Queue / Deque

```python
from collections import deque

q = deque()

q.append(x)
q.popleft()

q[0]
q[-1]

len(q)
not q
```

### Deque

```python
dq.append(x)
dq.appendleft(x)

dq.pop()
dq.popleft()
```

### Priority Queue / Heap

```python
import heapq

pq = []

heapq.heappush(pq, x)
heapq.heappop(pq)

pq[0]
len(pq)
not pq

heapq.heapify(a)
```

Max-heap trick:

```python
heapq.heappush(pq, -x)
x = -heapq.heappop(pq)
```

---

# 17. REFERENCE ONLY

## C++

```text
queue::emplace()
queue::swap()
queue::push_range()          [C++23]

deque iterators
deque custom allocator
deque range APIs

priority_queue::emplace()
priority_queue::swap()
priority_queue::push_range() [C++23]
custom comparators
custom objects / pointers
custom underlying container

manual circular queue
```

## Python

```text
deque.copy()
deque.rotate()
deque.extend()
deque.extendleft()

heapq.nsmallest()
heapq.nlargest()
heapq.heappushpop()
heapq.heapreplace()

tuple priorities
custom priority objects
queue.PriorityQueue
manual circular queue
```

---

# 18. One-Glance Syntax Reference

| Operation | C++ `queue` | C++ `deque` | C++ `priority_queue` | Python `deque` | Python `heapq` |
|---|---|---|---|---|---|
| Create | `queue<int> q` | `deque<int> d` | `priority_queue<int> p` | `d=deque()` | `h=[]` |
| Add back | `q.push(x)` | `d.push_back(x)` | `p.push(x)` | `d.append(x)` | `heappush(h,x)` |
| Add front | N/A | `d.push_front(x)` | N/A | `d.appendleft(x)` | N/A |
| Remove front | `q.pop()` | `d.pop_front()` | N/A | `d.popleft()` | N/A |
| Remove back | N/A | `d.pop_back()` | N/A | `d.pop()` | N/A |
| Front | `q.front()` | `d.front()` | N/A | `d[0]` | N/A |
| Back | `q.back()` | `d.back()` | N/A | `d[-1]` | N/A |
| Top priority | N/A | N/A | `p.top()` | N/A | `h[0]` |
| Pop priority | N/A | N/A | `p.pop()` | N/A | `heappop(h)` |
| Size | `q.size()` | `d.size()` | `p.size()` | `len(d)` | `len(h)` |
| Empty | `q.empty()` | `d.empty()` | `p.empty()` | `not d` | `not h` |
| Heapify | N/A | N/A | adaptor | N/A | `heapify(h)` |

---

# 19. Final Mental Model

```text
QUEUE
    FIFO
    add → back
    remove → front

DEQUE
    add/remove → BOTH ends

PRIORITY QUEUE
    add → heap
    remove → highest priority

PYTHON:
    deque → FIFO / double-ended operations
    heapq → priority queue / min-heap

C++:
    queue → FIFO
    deque → double-ended
    priority_queue → max-heap by default
```

### Complexity to memorize

```text
QUEUE
    push       O(1)
    pop        O(1)
    front      O(1)
    back       O(1)

DEQUE
    both ends  O(1)
    access     O(1) in C++ deque
               O(1) at Python deque ends
               O(n) in middle for Python deque

PRIORITY QUEUE
    top        O(1)
    push       O(log n)
    pop        O(log n)
    heapify    O(n)
```

---

# 20. Files

- `queues_cpp.cpp` → runnable C++ reference
- `queues_python.py` → runnable Python reference
- `queues_cpp_python.md` → comparison + revision sheet
