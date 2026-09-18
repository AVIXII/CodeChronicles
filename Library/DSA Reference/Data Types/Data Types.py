# Data Types in Python 3 — DSA / Competitive Programming Reference
# Runnable reference file.

from collections import deque
from fractions import Fraction
from decimal import Decimal
from typing import Any


def section(title: str) -> None:
    print(f"\n===== {title} =====")


# ============================================================
# CORE / MUST KNOW
# ============================================================

section("1. Numeric Types")

i = 42
negative = -5
f = 3.14
c = 1 + 2j

print("int:", i)
print("negative int:", negative)
print("float:", f)
print("complex:", c)
print("complex real/imag:", c.real, c.imag)

# Python integers have arbitrary precision.
huge = 10**100
print("huge int has", len(str(huge)), "decimal digits")

section("2. Sequence / Text Types")

s = "hello"                     # str: immutable text
lst = [1, 2, 3]                 # list: mutable
tup = (1, 2, 3)                 # tuple: immutable
r = range(0, 5)                 # lazy arithmetic sequence

print("str:", s)
print("list:", lst)
print("tuple:", tup)
print("range:", r)
print("range as list:", list(r))

# Common indexing / slicing
print("s[0]:", s[0])
print("lst[-1]:", lst[-1])
print("tup[1:]:", tup[1:])

section("3. Mapping Type")

d = {"name": "John", "age": 25}

print("dict:", d)
print("d['name']:", d["name"])
print("d.get('missing'):", d.get("missing"))
print("'age' in d:", "age" in d)

section("4. Set Types")

st = {1, 2, 3}
fs = frozenset([1, 2, 3])

print("set:", st)
print("frozenset:", fs)
print("2 in set:", 2 in st)
print("union:", st | {3, 4, 5})
print("intersection:", st & {2, 3, 4})
print("difference:", st - {2, 3})
print("symmetric difference:", st ^ {3, 4})

section("5. Boolean / None")

flag = True
false_flag = False
nothing = None

print("bool:", flag)
print("bool type:", type(flag))
print("None:", nothing)
print("None type:", type(nothing))

# `bool(x)` applies Python truth-value testing.
values = [False, None, 0, 0.0, 0j, "", (), [], {}, set(), range(0)]
for value in values:
    print(repr(value), "->", bool(value))

# User-defined falsy objects can define __bool__ or __len__.
class MyClass:
    def __len__(self):
        return 0


myobj = MyClass()
print("custom __len__ == 0 ->", bool(myobj))

section("6. Type Inspection")

x = 10

print("type(x):", type(x))
print("isinstance(x, int):", isinstance(x, int))
print("isinstance(True, int):", isinstance(True, int))  # bool is a subclass of int
print("type(1) is int:", type(1) is int)

section("7. Mutability Snapshot")

mutable_list = [1, 2]
mutable_list.append(3)

immutable_tuple = (1, 2)
# immutable_tuple += (3,) creates a new tuple object

mutable_dict = {"a": 1}
mutable_dict["b"] = 2

print("mutable list:", mutable_list)
print("immutable tuple:", immutable_tuple)
print("mutable dict:", mutable_dict)

section("8. Conversions / Constructors")

print("int('123'):", int("123"))
print("float('3.14'):", float("3.14"))
print("str(123):", str(123))
print("bool(0):", bool(0))
print("list((1, 2)):", list((1, 2)))
print("tuple([1, 2]):", tuple([1, 2]))
print("set([1, 1, 2]):", set([1, 1, 2]))

# Bases for integers
print("int('1010', 2):", int("1010", 2))
print("bin(10):", bin(10))
print("oct(10):", oct(10))
print("hex(10):", hex(10))

section("9. Binary / Byte Types")

raw_bytes = b"hello"
mutable_bytes = bytearray(b"hello")
view = memoryview(raw_bytes)

print("bytes:", raw_bytes)
print("bytearray:", mutable_bytes)
print("memoryview[0]:", view[0])

section("10. Useful Built-in Type Operations")

print("len('hello'):", len("hello"))
print("len([1, 2, 3]):", len([1, 2, 3]))
print("hash(42):", hash(42))
print("callable(len):", callable(len))


# ============================================================
# EXTRAS / REFERENCE
# ============================================================

section("EXTRAS: Additional Standard Numeric Types")

fraction = Fraction(1, 3)
decimal = Decimal("0.1")

print("Fraction:", fraction)
print("Decimal:", decimal)

section("EXTRAS: Other Common Built-in / Standard Types")

q = deque([1, 2, 3])

print("deque:", q)
print("iterator type:", type(iter([1, 2, 3])))
print("generator type:", type(x for x in range(3)))

section("EXTRAS: Multiple Assignment / Packing / Unpacking")

a, b = 10, 20
pair = a, b
x1, x2 = pair

print("a, b:", a, b)
print("packed tuple:", pair)
print("unpacked:", x1, x2)

section("EXTRAS: Type Annotations")

age: int = 20
name: str = "Alice"
scores: list[int] = [90, 95]

print("annotations are not runtime enforcement:", age, name, scores)

section("EXTRAS: Special Singleton / Sentinel Values")

print("Ellipsis:", Ellipsis)
print("NotImplemented:", NotImplemented)

# Common identity check for None:
value = None
print("value is None:", value is None)

section("EXTRAS: Comprehension-created Types")

squares = [x * x for x in range(5)]
square_set = {x * x for x in range(5)}
square_dict = {x: x * x for x in range(5)}
square_gen = (x * x for x in range(5))

print("list comprehension:", squares)
print("set comprehension:", square_set)
print("dict comprehension:", square_dict)
print("generator expression:", list(square_gen))

section("EXTRAS: Type Relationships Worth Memorizing")

print("bool subclass of int:", issubclass(bool, int))
print("list mutable:", end=" ")
tmp = [1]
tmp.append(2)
print(tmp)

print("\nAll Python data-type examples completed.")
