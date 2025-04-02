# Python Data Types

## 1. Standard Data Types

### 1.1 Numeric Types
- **int**: Represents integers.  
  Example: `10`, `-5`
- **float**: Represents floating-point numbers.  
  Example: `3.14`, `-0.01`
- **complex**: Represents complex numbers with real and imaginary parts.  
  Example: `1 + 2j`, `-3 - 4j`

---

### 1.2 Sequence Types
- **str**: Represents text (strings).  
  Example: `"hello"`, `'world'`
- **list**: Mutable, ordered collection.  
  Example: `[1, 2, 3]`, `["apple", "banana"]`
- **tuple**: Immutable, ordered collection.  
  Example: `(1, 2, 3)`, `("cat", "dog")`
- **range**: Represents a sequence of numbers, usually for iteration.  
  Example: `range(0, 10)`

---

### 1.3 Text Type
- **str**: Represents textual data.  
  Example: `"Python"`, `'Programming'`

---

### 1.4 Mapping Type
- **dict**: Represents key-value pairs.  
  Example: `{"name": "John", "age": 25}`

---

### 1.5 Set Types
- **set**: Mutable, unordered collection of unique items.  
  Example: `{1, 2, 3}`, `{"apple", "banana"}`
- **frozenset**: Immutable version of a set.  
  Example: `frozenset([1, 2, 3])`

---

### 1.6 Boolean Type
- **bool**: Represents Boolean values.  
  Example: `True`, `False`
- These are the only values which evaluate to falsy: False, None, 0, "", (), [], {}
- The following also evaluates to false in py
class myclass():
  def __len__(self):
    return 0

myobj = myclass()
print(bool(myobj))

---

### 1.7 None Type
- **bool**: Represents absence of a value.
  Example: `a = None`

---
