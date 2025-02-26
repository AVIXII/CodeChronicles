# Data Types in Java

## 1. **Primitive Data Types**
| Type        | Size             | Description                                     | Example          |
|-------------|------------------|-------------------------------------------------|------------------|
| `byte`      | 1 byte (8 bits)  | Stores whole numbers from -128 to 127.         | `byte b = 100;`  |
| `short`     | 2 bytes (16 bits)| Stores whole numbers from -32,768 to 32,767.   | `short s = 1000;`|
| `int`       | 4 bytes (32 bits)| Stores whole numbers from -2³¹ to 2³¹-1.       | `int x = 42;`    |
| `long`      | 8 bytes (64 bits)| Stores whole numbers from -2⁶³ to 2⁶³-1.       | `long l = 12345L;`|
| `float`     | 4 bytes          | Stores single-precision floating-point numbers.| `float f = 3.14f;`|
| `double`    | 8 bytes          | Stores double-precision floating-point numbers.| `double d = 3.14;`|
| `char`      | 2 bytes          | Stores a single 16-bit Unicode character.      | `char c = 'A';`  |
| `boolean`   | 1 bit (virtualized)| Stores `true` or `false`.                      | `boolean flag = true;`|

---

## 2. **Non-Primitive Data Types**
| Type           | Description                                      | Example                        |
|----------------|--------------------------------------------------|--------------------------------|
| `String`       | Represents a sequence of characters.             | `String s = "Hello";`         |
| `Array`        | A collection of elements of the same type.       | `int[] arr = {1, 2, 3};`      |
| `Class`        | Blueprint for creating objects with fields/methods.| `class MyClass { ... }`       |
| `Interface`    | Abstract type that specifies methods a class must implement. | `interface Runnable { ... }`|
| `List`         | Ordered collection of elements (e.g., `ArrayList`).| `List<Integer> list = new ArrayList<>();` |
| `Map`          | Key-value pair collection.                      | `Map<String, Integer> map = new HashMap<>();` |

---

## Notes:
- **Primitive data types** are the most basic building blocks.
- **Non-primitive data types** are objects or collections in Java's libraries.