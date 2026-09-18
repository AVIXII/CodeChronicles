"""
    ============================================================
    STRINGS CHEAT SHEET — Python 3.x
    ============================================================

    CORE / MUST KNOW
    ----------------
    Main DSA string type: str

    Access character       O(1)
    len()                  O(1)
    Search                 O(n) typical
    Concatenate            O(n + m)
    Slice                  O(k)
    Compare                O(min(n,m))
    upper/lower            O(n)
    replace                O(n + output)
    count                  O(n)
    reverse copy           O(n)

    IMPORTANT DIFFERENCE:
        Python strings are IMMUTABLE.
        String "modification" creates a new string.

    EXTRAS / REFERENCE
    ------------------
    split, join, strip, classification, formatting, sorting,
    aliasing/identity, manual algorithms, etc.
"""

import re


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. INITIALISATION
# ------------------------------------------------

name = "Rishabh"

a = "hello"
b = 'hello world'

# Multiline:
multi = """
hello
world
"""

# Raw string:
raw = r"C:\Users\name\file.txt"


# ------------------------------------------------
# 2. INPUT
# ------------------------------------------------

# input() returns a string.
#
# s = input()
# s = input().strip()
# parts = input().split()

sample = "10 20 30"
parts = sample.split()

numbers = list(map(int, parts))


# ------------------------------------------------
# 3. SIZE / EMPTY
# ------------------------------------------------

s = "hello"

n = len(s)                    # O(1)
is_empty = not s              # O(1)

print("Length:", n)
print("Empty:", is_empty)


# ------------------------------------------------
# 4. CHARACTER ACCESS
# ------------------------------------------------

first = s[0]                  # O(1)
last = s[-1]                  # O(1)
second_last = s[-2]           # O(1)

# Negative indexing is supported.


# ------------------------------------------------
# 5. IMMUTABILITY / CHARACTER UPDATE
# ------------------------------------------------

# s[0] = "H"                  # TypeError

# Correct:
s = "H" + s[1:]

# TC: O(n)


# ------------------------------------------------
# 6. CONCATENATION / REPETITION
# ------------------------------------------------

s1 = "abc"
s2 = "def"

combined = s1 + s2            # O(n + m)

s1 += s2                       # Creates a new string conceptually

repeated = "abc" * 3           # O(n*k)


# ------------------------------------------------
# 7. CLEAR
# ------------------------------------------------

s = "hello"
s = ""

# Strings are immutable.
# Rebinding does not mutate an existing string object.


# ------------------------------------------------
# 8. COMPARISON
# ------------------------------------------------

a = "Rishabh"
b = "Ramdhave"

print(a == b)
print(a != b)

print(a < b)
print(a <= b)
print(a > b)
print(a >= b)

# Lexicographical comparison:
# TC: O(min(n,m))

# IMPORTANT:
# a is b checks object identity, NOT string value equality.


# ------------------------------------------------
# 9. SUBSTRING / SLICING
# ------------------------------------------------

s = "rishabh shital ramdhave"

part = s[5:11]
rest = s[5:]
prefix = s[:7]
suffix = s[-7:]

every_second = s[::2]
reversed_s = s[::-1]

# Slice creates a new string.
# TC: O(k), SC: O(k)


# ------------------------------------------------
# 10. SEARCH
# ------------------------------------------------

text = "hello world"

pos = text.find("world")        # -1 if absent
char_pos = text.find("o")
last_pos = text.rfind("o")

# index() raises ValueError if absent:
try:
    idx = text.index("world")
except ValueError:
    idx = -1

# Membership:
present = "world" in text


# ------------------------------------------------
# 11. REPLACEMENT
# ------------------------------------------------

s = "apple apple banana"

result = s.replace("apple", "orange")

# Limit replacements:
limited = s.replace("apple", "orange", 1)

# Original string remains unchanged.


# ------------------------------------------------
# 12. CASE
# ------------------------------------------------

s = "hello WORLD"

upper = s.upper()
lower = s.lower()
capitalized = s.capitalize()
title = s.title()

# Each returns a new string.


# ------------------------------------------------
# 13. TRAVERSAL
# ------------------------------------------------

s = "hello"

for ch in s:
    print(ch)

for i in range(len(s)):
    print(i, s[i])

for i, ch in enumerate(s):
    print(i, ch)

for ch in reversed(s):
    print(ch)

# TC: O(n)


# ------------------------------------------------
# 14. COUNT
# ------------------------------------------------

count_world = "hello world world".count("world")
count_a = "banana".count("a")

# TC: O(n) typical


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 15. SPLIT / REGEX SPLIT
# ------------------------------------------------

text = "apple banana grape"

words = text.split()

csv = "apple,banana,grape"
items = csv.split(",")

# Regex split:
text = "apple;banana,grape orange"
result = re.split(r"[;, ]+", text)

# TC: O(n) typical
# SC: proportional to produced output


# ------------------------------------------------
# 16. STRIP
# ------------------------------------------------

s = "   hello world   "

clean = s.strip()
left = s.lstrip()
right = s.rstrip()

custom = "---hello---".strip("-")

# ------------------------------------------------
# 17. JOIN
# ------------------------------------------------

words = ["hello", "world"]

joined = " ".join(words)
csv = ",".join(words)

# TC: O(total input size + result size)
# SC: O(result size)

# IMPORTANT:
# join() is the preferred way to combine many strings.


# ------------------------------------------------
# 18. CHARACTER / STRING CLASSIFICATION
# ------------------------------------------------

s = "Hello"

is_alpha = s.isalpha()
is_digit = s.isdigit()
is_lower = s.islower()
is_upper = s.isupper()
is_alnum = s.isalnum()
is_space = s.isspace()

# Other useful methods:
is_ascii = s.isascii()
is_title = s.istitle()
is_identifier = s.isidentifier()


# ------------------------------------------------
# 19. FORMATTING
# ------------------------------------------------

name = "World"

formatted1 = "Hello {}!".format(name)

formatted2 = f"Hello {name}!"

# Modern Python usually prefers f-strings.


# ------------------------------------------------
# 20. SORTING CHARACTERS
# ------------------------------------------------

s = "dcba"

sorted_chars = sorted(s)              # ['a','b','c','d']
sorted_string = "".join(sorted(s))    # "abcd"

reverse_sorted = "".join(
    sorted(s, reverse=True)
)

# TC: O(n log n)
# SC: O(n)

# Strings have no in-place .sort() method.


# ------------------------------------------------
# 21. MIN / MAX
# ------------------------------------------------

s = "dcab"

mn = min(s)
mx = max(s)

# TC: O(n)


# ------------------------------------------------
# 22. CONVERSION
# ------------------------------------------------

integer_value = int("12345")
float_value = float("12.34")

string_value = str(12345)


# ------------------------------------------------
# 23. MANUAL CHARACTER SEARCH
# ------------------------------------------------

def find_index(s, target):
    for i, ch in enumerate(s):
        if ch == target:
            return i
    return -1


print("Manual char search:",
      find_index("abcdef", "d"))

# TC: O(n)
# SC: O(1)


# ------------------------------------------------
# 24. MANUAL PALINDROME
# ------------------------------------------------

def is_palindrome(s):
    left, right = 0, len(s) - 1

    while left < right:
        if s[left] != s[right]:
            return False

        left += 1
        right -= 1

    return True


print("Palindrome:",
      is_palindrome("madam"))

# TC: O(n)
# SC: O(1)


# ------------------------------------------------
# 25. MANUAL REVERSE
# ------------------------------------------------

def reverse_string(s):
    chars = list(s)

    left, right = 0, len(chars) - 1

    while left < right:
        chars[left], chars[right] = (
            chars[right], chars[left]
        )
        left += 1
        right -= 1

    return "".join(chars)


print("Manual reverse:",
      reverse_string("abcdef"))

# TC: O(n)
# SC: O(n), because Python str is immutable


# ------------------------------------------------
# 26. NAIVE SUBSTRING SEARCH
# ------------------------------------------------

def naive_find(text, pattern):
    if pattern == "":
        return 0

    if len(pattern) > len(text):
        return -1

    for i in range(
        len(text) - len(pattern) + 1
    ):
        j = 0

        while (
            j < len(pattern)
            and text[i + j] == pattern[j]
        ):
            j += 1

        if j == len(pattern):
            return i

    return -1


print(
    "Naive substring search:",
    naive_find("hello world", "world")
)

# Worst-case TC: O(n*m)
# SC: O(1)


# ------------------------------------------------
# 27. ALIASING / IDENTITY
# ------------------------------------------------

a = "hello"
b = a

# Strings are immutable, so mutating b cannot change a.

# Value comparison:
same_value = (a == b)

# Object identity:
same_object = (a is b)

# Do not use `is` for normal string-value comparison.


# ------------------------------------------------
# 28. COMMON DSA STRING BUILDING PATTERN
# ------------------------------------------------

parts = []

for i in range(5):
    parts.append(str(i))

result = "".join(parts)

# Better than repeated concatenation for building many pieces.


# ------------------------------------------------
# 29. COMMON PYTHON STRING METHODS
# ------------------------------------------------

"""
Length:
    len(s)

Access:
    s[i]
    s[-1]

Search:
    s.find(x)
    s.index(x)
    s.rfind(x)
    x in s

Case:
    s.upper()
    s.lower()
    s.capitalize()
    s.title()

Whitespace:
    s.strip()
    s.lstrip()
    s.rstrip()

Replacement:
    s.replace(old, new)
    s.replace(old, new, count)

Counting:
    s.count(x)

Split:
    s.split()
    s.split(sep)

Join:
    sep.join(iterable)

Checks:
    s.isalpha()
    s.isdigit()
    s.isalnum()
    s.islower()
    s.isupper()
    s.isspace()

Formatting:
    s.format(...)
    f"..."

Sorting:
    sorted(s)

Reverse:
    s[::-1]
"""


# ------------------------------------------------
# 30. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. str is immutable.
2. s[i] is O(1).
3. Negative indexing is supported.
4. Slicing creates a new string.
5. s.find(x) returns -1 if absent.
6. s.index(x) raises ValueError if absent.
7. x in s checks membership.
8. replace() handles substring replacement.
9. join() is preferred for joining many strings.
10. Strings have no .sort() method.
11. sorted(s) returns a list.
12. `is` is identity, `==` is value equality.
13. Avoid repeated large-string concatenation in a loop;
    collect pieces and use join().
"""
