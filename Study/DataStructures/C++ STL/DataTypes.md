<h1> Data Types in C++ </h1>

For more reference read the book "Competitive Programmer's Handbook' by Antti Laaksonen.

C++ data types can be broadly classified into basic (primitive), derived, and user-defined types. Below is a detailed list:

<h2> 1. Basic (Primitive) Data Types </h2>

These are the fundamental data types built into the language.

| Type     | Size              | Example                  | Description                                                     |
|----------|-------------------|--------------------------|-----------------------------------------------------------------|
| int      | 4 bytes (32 bits) | `int x = 42;`           | Stores integers.                                               |
| float    | 4 bytes           | `float f = 3.14;`       | Stores single-precision floating-point numbers.                |
| double   | 8 bytes           | `double d = 3.14159;`   | Stores double-precision floating-point numbers.                |
| char     | 1 byte            | `char c = 'A';`         | Stores a single character.                                     |
| bool     | 1 byte            | `bool flag = true;`     | Stores `true` or `false`.                                      |
| void     | No memory allocated | `void function();`    | Represents absence of data, typically used for functions with no return value. |
---


* The size of int can vary based on the system architecture.

<h2> 2. Derived Data Types </h2>

These are derived from the primitive types.

| Type       | Description                                     | Example                                    |
|------------|-------------------------------------------------|--------------------------------------------|
| Array      | Collection of elements of the same type.        | `int arr[5] = {1, 2, 3, 4, 5};`           |
| Pointer    | Stores memory addresses.                       | `int *ptr = &x;`                          |
| Reference  | Stores references to variables.                | `int &ref = x;`                           |
| Function   | Group of statements performing a specific task. | `void func() { cout << "Hello!"; }`       |
---

<h2>3. User-Defined Data Types </h2>
These are types created by users for custom use cases.

| Type       | Description                                        | Example                                         |
|------------|----------------------------------------------------|-------------------------------------------------|
| Class      | Encapsulation of data and methods (object-oriented).| `class MyClass { public: int x; };`            |
| Struct     | User-defined grouping of related variables.       | `struct Point { int x, y; };`                   |
| Union      | Memory-efficient grouping of variables.           | `union Data { int x; char c; };`                |
| Enum       | A set of named integral constants.                | `enum Color { RED, GREEN, BLUE };`              |
| Typedef/using| Alternative name for a data type.                | `typedef int Marks; using Score = float;`      |

<h2> 4. Data Modifiers </h2>

Modifiers are used to change the properties of a basic data type. Examples include:

| Modifier   | Usage Example                     | Description                                      |
|------------|------------------------------------|--------------------------------------------------|
| signed     | `signed int x = -10;`             | Allows negative and positive values.             |
| unsigned   | `unsigned int x = 10;`            | Only allows non-negative values.                 |
| short      | `short int x = 100;`              | Reduces the size of integers.                    |
| long long      | `long long int x = 100000;`       | Increases the size of integers.                  |

<h2> 5. STL Data Types </h2>

| Type         | Description                                    |
|--------------|------------------------------------------------|
| `std::string`| Stores sequences of characters.                |
| `std::vector`| Dynamic array implementation.                  |
| `std::array` | Static array container introduced in C++11.    |
| `std::map`   | Stores key-value pairs.                        |
| `std::set`   | Stores unique elements.                        |