"""
    ============================================================
    QUEUES CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------

    FIFO QUEUE:
        collections.deque

        append / popleft / appendleft / pop
        all O(1)

    DEQUE:
        collections.deque
        double-ended queue

    PRIORITY QUEUE:
        heapq + list
        Python's heapq is a MIN-HEAP by default.

        heappush       O(log n)
        heappop        O(log n)
        heap[0]        O(1)
        heapify        O(n)

    EXTRAS / REFERENCE
    ------------------
    heapq variants, max-heaps, nlargest/nsmallest, custom objects,
    queue.Queue / PriorityQueue, manual circular queue, etc.
"""

from collections import deque
import heapq
from queue import PriorityQueue


# ================================================================
# CORE — FIFO QUEUE
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION
# ------------------------------------------------

queue = deque()


# ------------------------------------------------
# 2. ENQUEUE
# ------------------------------------------------

queue.append(10)
queue.append(20)
queue.append(30)

# queue:
# front -> 10 20 30 <- back

# TC: O(1)


# ------------------------------------------------
# 3. FRONT
# ------------------------------------------------

if queue:
    front = queue[0]                    # O(1)
    print("Front:", front)


# ------------------------------------------------
# 4. BACK
# ------------------------------------------------

if queue:
    back = queue[-1]                    # O(1)
    print("Back:", back)


# ------------------------------------------------
# 5. DEQUEUE
# ------------------------------------------------

if queue:
    x = queue.popleft()                 # O(1)
    print("Dequeued:", x)


# ------------------------------------------------
# 6. SIZE / EMPTY
# ------------------------------------------------

size = len(queue)                       # O(1)
is_empty = not queue                    # O(1)

print("Size:", size)
print("Empty:", is_empty)


# ------------------------------------------------
# 7. PRINT / CONSUME QUEUE
# ------------------------------------------------

while queue:
    print(queue.popleft(), end=" ")

print()

# TC: O(n)
# SC: O(1) auxiliary
# This destroys the queue.


# ------------------------------------------------
# 8. NON-DESTRUCTIVE PRINTING
# ------------------------------------------------

original = deque([10, 20, 30])

copy_queue = original.copy()            # O(n)

while copy_queue:
    print(copy_queue.popleft(), end=" ")

print()

print("Original preserved:", original)


# ================================================================
# CORE — DEQUE
# ================================================================

# ------------------------------------------------
# 9. DEQUE INITIALISATION
# ------------------------------------------------

dq = deque()


# ------------------------------------------------
# 10. INSERT BOTH ENDS
# ------------------------------------------------

dq.appendleft(4)        # 4
dq.appendleft(3)        # 3 4
dq.append(6)            # 3 4 6
dq.append(2)            # 3 4 6 2

# End operations: O(1)


# ------------------------------------------------
# 11. FRONT / BACK
# ------------------------------------------------

if dq:
    print("Deque front:", dq[0])
    print("Deque back:", dq[-1])


# ------------------------------------------------
# 12. REMOVE BOTH ENDS
# ------------------------------------------------

if dq:
    dq.popleft()

if dq:
    dq.pop()


# ------------------------------------------------
# 13. DEQUE TRAVERSAL
# ------------------------------------------------

for x in dq:
    print(x, end=" ")

print()

# ------------------------------------------------
# 14. DEQUE INDEXING
# ------------------------------------------------

if dq:
    print("dq[0]:", dq[0])
    print("dq[-1]:", dq[-1])

# End indexing is O(1).
# Middle indexing is O(n).
# Use deque for end operations, not arbitrary middle access.


# ================================================================
# CORE — PRIORITY QUEUE / HEAP
# ================================================================

# ------------------------------------------------
# 15. MIN-HEAP INITIALISATION
# ------------------------------------------------

pq = []


# ------------------------------------------------
# 16. INSERT
# ------------------------------------------------

heapq.heappush(pq, 30)
heapq.heappush(pq, 10)
heapq.heappush(pq, 20)

# TC: O(log n)


# ------------------------------------------------
# 17. TOP / MIN
# ------------------------------------------------

if pq:
    print("Min:", pq[0])                 # O(1)


# ------------------------------------------------
# 18. POP MINIMUM
# ------------------------------------------------

if pq:
    print("Popped min:", heapq.heappop(pq))

# TC: O(log n)


# ------------------------------------------------
# 19. HEAPIFY
# ------------------------------------------------

arr = [30, 10, 20, 5, 50]

heapq.heapify(arr)

print("Heap:", arr)

# IMPORTANT:
# Heapified list is NOT necessarily globally sorted.
# Only the heap invariant is guaranteed.

print("Heap min:", arr[0])                 # O(1)
print("Pop min:", heapq.heappop(arr))      # O(log n)


# ------------------------------------------------
# 20. PRINT / CONSUME HEAP IN PRIORITY ORDER
# ------------------------------------------------

pq = [30, 10, 20, 5]
heapq.heapify(pq)

while pq:
    print(heapq.heappop(pq), end=" ")

print()

# Outputs elements in increasing order.
# TC: O(n log n)
# This destroys the heap.


# ================================================================
# EXTRAS — PRIORITY QUEUE / HEAP
# ================================================================

# ------------------------------------------------
# 21. MAX-HEAP USING NEGATIVE VALUES
# ------------------------------------------------

max_heap = []

heapq.heappush(max_heap, -30)
heapq.heappush(max_heap, -10)
heapq.heappush(max_heap, -20)

if max_heap:
    maximum = -max_heap[0]
    print("Max:", maximum)

    maximum = -heapq.heappop(max_heap)
    print("Popped max:", maximum)

# TC: O(log n) push/pop
#
# Common Python DSA trick:
# use negative values to turn the min-heap into an effective max-heap.


# ------------------------------------------------
# 22. HEAPQ N SMALLEST / LARGEST
# ------------------------------------------------

arr = [30, 10, 20, 5, 50]

print("2 smallest:", heapq.nsmallest(2, arr))
print("2 largest:", heapq.nlargest(2, arr))

# Useful when you need only k extremes rather than full sorting.
# Exact complexity depends on k and implementation.


# ------------------------------------------------
# 23. PUSH + POP COMBINATIONS
# ------------------------------------------------

heap = [10, 20, 30]
heapq.heapify(heap)

# pushpop:
result = heapq.heappushpop(heap, 15)

print("heappushpop result:", result)

heap = [10, 20, 30]
heapq.heapify(heap)

# replace:
result = heapq.heapreplace(heap, 15)

print("heapreplace result:", result)

"""
heappushpop(heap, x):
    push then pop smallest, efficiently combined

heapreplace(heap, x):
    pop smallest then push x, heap size stays same

These are advanced APIs.
"""


# ------------------------------------------------
# 24. TUPLE PRIORITY
# ------------------------------------------------

pq = []

heapq.heappush(pq, (2, "medium"))
heapq.heappush(pq, (1, "high"))
heapq.heappush(pq, (3, "low"))

print("Tuple priority:", heapq.heappop(pq))

# Tuples are compared lexicographically:
# first priority, then second field if needed.


# ------------------------------------------------
# 25. CUSTOM OBJECT PRIORITY
# ------------------------------------------------

class Task:
    def __init__(self, priority, name):
        self.priority = priority
        self.name = name


# A common pattern is to store:
# (priority, counter, object)
#
# The extra counter provides deterministic tie-breaking when
# objects themselves are not directly comparable.

tasks = []
counter = 0

task = Task(2, "write")
heapq.heappush(tasks, (task.priority, counter, task))
counter += 1

task = Task(1, "study")
heapq.heappush(tasks, (task.priority, counter, task))

priority, _, task = heapq.heappop(tasks)

print("Task:", priority, task.name)


# ------------------------------------------------
# 26. queue.PriorityQueue
# ------------------------------------------------

pq_threadsafe = PriorityQueue()

pq_threadsafe.put((2, "medium"))
pq_threadsafe.put((1, "high"))

print("PriorityQueue:", pq_threadsafe.get())

"""
queue.PriorityQueue is synchronized / thread-safe.

For normal DSA / competitive programming:
    prefer heapq.

Use PriorityQueue when thread-safety / blocking queue behavior
is actually required.
"""


# ------------------------------------------------
# 27. MANUAL CIRCULAR QUEUE
# ------------------------------------------------

class CircularQueue:
    def __init__(self, capacity):
        self.data = [None] * capacity
        self.front_index = 0
        self.size = 0

    def empty(self):
        return self.size == 0

    def full(self):
        return self.size == len(self.data)

    def push(self, x):
        if self.full():
            raise OverflowError("Queue is full")

        index = (
            self.front_index + self.size
        ) % len(self.data)

        self.data[index] = x
        self.size += 1

    def front(self):
        if self.empty():
            raise IndexError("Queue is empty")

        return self.data[self.front_index]

    def pop(self):
        if self.empty():
            raise IndexError("Queue is empty")

        x = self.data[self.front_index]

        self.front_index = (
            self.front_index + 1
        ) % len(self.data)

        self.size -= 1

        return x


cq = CircularQueue(5)

cq.push(10)
cq.push(20)
cq.push(30)

print("Circular queue front:", cq.front())
print("Circular queue pop:", cq.pop())

# push  O(1)
# pop   O(1)
# front O(1)
# size  O(1)


# ================================================================
# 28. CORE COMPLEXITY MEMORY
# ================================================================

"""
FIFO queue using deque:
    enqueue       O(1)
    dequeue       O(1)
    front         O(1)
    back          O(1)
    size          O(1)
    empty         O(1)

Deque:
    append        O(1)
    appendleft    O(1)
    pop            O(1)
    popleft        O(1)
    end indexing   O(1)
    middle indexing O(n)

Heap / priority queue:
    heappush      O(log n)
    heappop       O(log n)
    top           O(1)
    heapify       O(n)
"""


# ------------------------------------------------
# 29. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. Use collections.deque for a normal FIFO queue.
2. Do NOT use list.pop(0) for a queue; it is O(n).
3. deque supports O(1) operations at both ends.
4. heapq implements a min-heap by default.
5. heap[0] is the minimum element.
6. heapify() is O(n).
7. heappush/heappop are O(log n).
8. A heapified list is NOT necessarily sorted.
9. Use negative values for a max-heap when convenient.
10. PriorityQueue is thread-safe; heapq is generally preferred for
    DSA/competitive programming.
"""
