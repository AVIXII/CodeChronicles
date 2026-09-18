"""
    ============================================================
    STACKS CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------
    Primary DSA stack implementation: list

    Stack = LIFO
        Last In, First Out

    append / push       O(1) amortized
    pop last            O(1)
    top                 O(1) via a[-1]
    size                O(1)
    empty               O(1)

    Python also has collections.deque, which supports O(1)
    append/pop operations from either end and can be used as a
    stack.

    EXTRAS / REFERENCE
    ------------------
    deque, custom stack classes, linked-list stack, peek helpers,
    copying/printing, and implementation details.
"""

from collections import deque


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION
# ------------------------------------------------

stack = []


# ------------------------------------------------
# 2. PUSH
# ------------------------------------------------

stack.append(32)
stack.append(10)
stack.append(20)

# Stack:
# top -> 20
#        10
#        32

# TC: O(1) amortized


# ------------------------------------------------
# 3. TOP / PEEK
# ------------------------------------------------

if stack:
    top = stack[-1]                 # O(1)
    print("Top:", top)

# IMPORTANT:
# stack[-1] on an empty list raises IndexError.


# ------------------------------------------------
# 4. POP
# ------------------------------------------------

if stack:
    x = stack.pop()                 # O(1)
    print("Popped:", x)

# Unlike C++ stack.pop(), Python list.pop()
# returns the removed element.


# ------------------------------------------------
# 5. SIZE
# ------------------------------------------------

size = len(stack)                   # O(1)
print("Size:", size)


# ------------------------------------------------
# 6. EMPTY
# ------------------------------------------------

is_empty = not stack                # O(1)
print("Empty:", is_empty)


# ------------------------------------------------
# 7. COMMON STACK PATTERN
# ------------------------------------------------

while stack:
    print(stack[-1], end=" ")
    stack.pop()

print()

# TC: O(n)
# SC: O(1) auxiliary
#
# This destroys the stack.


# ------------------------------------------------
# 8. NON-DESTRUCTIVE PRINTING
# ------------------------------------------------

original = [1, 2, 3, 4]

copy_stack = original.copy()        # O(n)

while copy_stack:
    print(copy_stack[-1], end=" ")
    copy_stack.pop()

print()

print("Original preserved:", original)

# Copying costs O(n) time + O(n) space.


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 9. DEQUE AS STACK
# ------------------------------------------------

dq_stack = deque()

dq_stack.append(10)
dq_stack.append(20)

top = dq_stack[-1]                  # O(1)
x = dq_stack.pop()                  # O(1)

print("Deque stack popped:", x)

# deque is also useful when a problem needs both-end operations.


# ------------------------------------------------
# 10. CUSTOM STACK CLASS
# ------------------------------------------------

class Stack:
    def __init__(self):
        self._data = []

    def push(self, x):
        self._data.append(x)

    def pop(self):
        if not self._data:
            raise IndexError("pop from empty stack")
        return self._data.pop()

    def top(self):
        if not self._data:
            raise IndexError("top from empty stack")
        return self._data[-1]

    def empty(self):
        return not self._data

    def size(self):
        return len(self._data)


s = Stack()

s.push(10)
s.push(20)

print("Custom stack top:", s.top())

# Complexity:
# push  O(1) amortized
# pop   O(1)
# top   O(1)
# size  O(1)


# ------------------------------------------------
# 11. MANUAL LINKED-LIST STACK
# ------------------------------------------------

class Node:
    def __init__(self, value, next_node=None):
        self.value = value
        self.next = next_node


class LinkedStack:
    def __init__(self):
        self.head = None
        self._size = 0

    def push(self, x):
        self.head = Node(x, self.head)
        self._size += 1

    def pop(self):
        if self.head is None:
            raise IndexError("pop from empty stack")

        value = self.head.value
        self.head = self.head.next
        self._size -= 1
        return value

    def top(self):
        if self.head is None:
            raise IndexError("top from empty stack")
        return self.head.value

    def empty(self):
        return self.head is None

    def size(self):
        return self._size


linked = LinkedStack()

linked.push(100)
linked.push(200)

print("Linked stack top:", linked.top())

# push  O(1)
# pop   O(1)
# top   O(1)
# size  O(1)
# Extra storage: O(n)


# ------------------------------------------------
# 12. STACK FROM TWO QUEUES / OTHER IMPLEMENTATIONS
# ------------------------------------------------

"""
A stack can also be implemented using other data structures,
for example two queues.

This is generally an interview / implementation exercise,
not the normal DSA implementation to use in code.

For practical Python DSA:
    list is usually enough.
"""


# ------------------------------------------------
# 13. COMMON STACK IDIOMS
# ------------------------------------------------

s = []

# Push:
s.append(x) if False else None

# Top:
top = s[-1] if s else None

# Safe pop:
item = s.pop() if s else None

# Empty:
if not s:
    pass

# Non-empty:
if s:
    pass


# ================================================================
# 14. CORE COMPLEXITY MEMORY
# ================================================================

"""
Python list stack:

push / append     O(1) amortized
pop last          O(1)
top               O(1)
size              O(1)
empty             O(1)

Avoid:
    pop(0)
    insert(0, x)

Those operate at the beginning of a list and cost O(n).
Use deque when you need efficient operations at both ends.
"""


# ------------------------------------------------
# 15. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. Python does not have a dedicated built-in stack type.
2. list is the normal DSA stack implementation.
3. append() is push.
4. pop() is pop.
5. a[-1] is top/peek.
6. pop() returns the removed element.
7. pop() on an empty list raises IndexError.
8. a[-1] on an empty list raises IndexError.
9. pop(0) is O(n), so don't use it for a stack.
10. collections.deque is useful when both ends are needed.
"""
