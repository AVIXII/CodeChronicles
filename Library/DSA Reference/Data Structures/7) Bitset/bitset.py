"""
    ============================================================
    BITSET CHEAT SHEET — Python 3.x
    ============================================================

    IMPORTANT LANGUAGE DIFFERENCE
    -----------------------------
    Python has no direct built-in equivalent of C++ std::bitset<N>.

    The normal built-in DSA approach is:
        int -> use as an arbitrary-width bit mask

    Core operations:
        &  |  ^  ~
        << >>
        bit_count()
        bit_length()
        bin()
        format()

    For fixed-width behavior, explicitly apply a mask:
        MASK = (1 << N) - 1

    EXTRAS / REFERENCE
    ------------------
    fixed-width BitSet wrapper, set/test/reset/toggle helpers,
    enumerate set bits, to_bytes/from_bytes, heap-free bit tricks,
    and dynamic bit-array notes.
"""


# ================================================================
# CORE — MUST KNOW
# ================================================================

# ------------------------------------------------
# 1. CREATE A BIT MASK
# ------------------------------------------------

x = 0b100100101

print("Integer:", x)
print("Binary:", bin(x))

# Fixed-width display:
print("10-bit:", f"{x:010b}")


# ------------------------------------------------
# 2. SET A BIT
# ------------------------------------------------

i = 3

x |= (1 << i)

# Set bit i to 1.
# Typical TC: O(number of machine words)


# ------------------------------------------------
# 3. TEST / GET A BIT
# ------------------------------------------------

bit = (x >> i) & 1

print("Bit:", bit)

# ------------------------------------------------
# 4. RESET / CLEAR A BIT
# ------------------------------------------------

x &= ~(1 << i)

# For a non-negative mask, this clears bit i.


# ------------------------------------------------
# 5. TOGGLE / FLIP A BIT
# ------------------------------------------------

x ^= (1 << i)


# ------------------------------------------------
# 6. BITWISE OPERATIONS
# ------------------------------------------------

a = 0b10101010
b = 0b10010011

and_ans = a & b
or_ans = a | b
xor_ans = a ^ b
not_ans = ~a

print("A & B:", bin(and_ans))
print("A | B:", bin(or_ans))
print("A ^ B:", bin(xor_ans))
print("~A:", bin(not_ans))


# ------------------------------------------------
# 7. FIXED-WIDTH NOT
# ------------------------------------------------

N = 8
MASK = (1 << N) - 1

fixed_not = (~a) & MASK

print("8-bit ~A:", f"{fixed_not:08b}")

"""
IMPORTANT:
Python integers conceptually use two's-complement behavior with
an unbounded number of sign bits for bitwise operations.

So:
    ~x

does NOT behave like a fixed-width N-bit NOT.

For N-bit behavior:
    (~x) & ((1 << N) - 1)
"""


# ------------------------------------------------
# 8. LEFT / RIGHT SHIFT
# ------------------------------------------------

x = 0b00101100

left = x << 2
right = x >> 2

print("Left:", bin(left))
print("Right:", bin(right))

# Left shift by k:
# x << k

# Right shift by k:
# x >> k


# ------------------------------------------------
# 9. COUNT SET BITS
# ------------------------------------------------

x = 0b10110100

count = x.bit_count()

print("Number of 1s:", count)

# Python 3.10+


# ------------------------------------------------
# 10. BIT LENGTH
# ------------------------------------------------

length = x.bit_length()

print("Bit length:", length)

# Number of bits needed to represent |x|,
# excluding leading zeroes.


# ------------------------------------------------
# 11. BINARY STRING
# ------------------------------------------------

binary = bin(x)

print(binary)                  # includes '0b'

binary_no_prefix = bin(x)[2:]

print(binary_no_prefix)

# Fixed-width:
print(f"{x:08b}")


# ------------------------------------------------
# 12. INTEGER FROM BINARY STRING
# ------------------------------------------------

binary_string = "100100101"

value = int(binary_string, 2)

print("Integer:", value)


# ================================================================
# EXTRAS — REFERENCE
# ================================================================

# ------------------------------------------------
# 13. FIXED-WIDTH BITSET WRAPPER
# ------------------------------------------------

class BitSet:
    """
    Small fixed-width bitset wrapper using Python int.

    Bits are indexed from:
        0 = least significant bit

    Width is fixed to N bits.
    """

    def __init__(self, n, value=0):
        if n < 0:
            raise ValueError("Number of bits must be non-negative")

        self.n = n
        self.mask = (1 << n) - 1
        self.bits = value & self.mask

    def size(self):
        return self.n

    def test(self, i):
        self._check_index(i)
        return bool((self.bits >> i) & 1)

    def set(self, i=None, value=True):
        if i is None:
            self.bits = self.mask
            return

        self._check_index(i)

        if value:
            self.bits |= (1 << i)
        else:
            self.bits &= ~(1 << i)

    def reset(self, i=None):
        if i is None:
            self.bits = 0
            return

        self._check_index(i)
        self.bits &= ~(1 << i)

    def flip(self, i=None):
        if i is None:
            self.bits ^= self.mask
            return

        self._check_index(i)
        self.bits ^= (1 << i)

    def count(self):
        return self.bits.bit_count()

    def any(self):
        return self.bits != 0

    def none(self):
        return self.bits == 0

    def all(self):
        return self.bits == self.mask

    def to_string(self):
        return f"{self.bits:0{self.n}b}"

    def _check_index(self, i):
        if not 0 <= i < self.n:
            raise IndexError("bit index out of range")


bs = BitSet(8, 0b10110010)

print("BitSet:", bs.to_string())
print("Size:", bs.size())
print("Count:", bs.count())
print("Test bit 1:", bs.test(1))

bs.set(2)
bs.reset(3)
bs.flip(4)

print("Modified:", bs.to_string())


# ------------------------------------------------
# 14. ALL / ANY / NONE HELPERS
# ------------------------------------------------

x = 0b10101010

print("Any set:", x != 0)

# For N-bit fixed-width:
N = 8
MASK = (1 << N) - 1

print("All set:", (x & MASK) == MASK)
print("None set:", (x & MASK) == 0)


# ------------------------------------------------
# 15. ENUMERATE SET BITS
# ------------------------------------------------

def set_bit_positions(x):
    """
    Return positions of set bits.
    Bit 0 = least significant bit.
    """
    positions = []

    while x:
        # Isolate lowest set bit
        lsb = x & -x

        # Index of that bit
        pos = lsb.bit_length() - 1

        positions.append(pos)

        # Remove lowest set bit
        x &= x - 1

    return positions


print(
    "Set bits:",
    set_bit_positions(0b10110100)
)


# ------------------------------------------------
# 16. CHECK POWER OF TWO
# ------------------------------------------------

def is_power_of_two(x):
    return x > 0 and (x & (x - 1)) == 0


print(is_power_of_two(16))      # True
print(is_power_of_two(18))      # False


# ------------------------------------------------
# 17. LOWEST SET BIT
# ------------------------------------------------

x = 0b10110000

lowest_set_bit = x & -x

print("Lowest set bit:", bin(lowest_set_bit))


# ------------------------------------------------
# 18. REMOVE LOWEST SET BIT
# ------------------------------------------------

x = 0b10110100

x_without_lowest = x & (x - 1)

print("After removal:", bin(x_without_lowest))


# ------------------------------------------------
# 19. BYTES CONVERSION
# ------------------------------------------------

x = 1024

data = x.to_bytes(
    2,
    byteorder="big"
)

restored = int.from_bytes(
    data,
    byteorder="big"
)

print("Bytes:", data)
print("Restored:", restored)


# ------------------------------------------------
# 20. MASKING TO N BITS
# ------------------------------------------------

N = 5
MASK = (1 << N) - 1

x = 0b11111111

x_n_bits = x & MASK

print("5-bit value:", f"{x_n_bits:05b}")


# ------------------------------------------------
# 21. CORE COMPLEXITY MEMORY
# ------------------------------------------------

"""
Python int as bit mask:

bit test / set / reset / toggle
    roughly O(number of machine words)

AND / OR / XOR / shifts
    roughly proportional to integer size

bit_count()
    proportional to integer size

bit_length()
    O(1) in practical CPython terms for machine-word metadata,
    but think of it as a bit-size query rather than a container
    traversal.

Important:
    Python int is arbitrary precision.
    It is NOT a fixed-width bitset.

For DSA, treat:
    int + bit operations
as the normal Python bitset/bitmask technique.
"""


# ------------------------------------------------
# 22. IMPORTANT PYTHON NOTES
# ------------------------------------------------

"""
1. Python has no direct built-in std::bitset<N> equivalent.
2. int is the normal built-in bit-mask representation.
3. int.bit_count() gives the number of set bits.
4. int.bit_length() gives the significant bit width.
5. bin(x) gives a binary string with '0b' prefix.
6. f"{x:08b}" gives fixed-width binary display.
7. Python bitwise operations behave as though integers have
   infinitely many sign-extension bits.
8. Therefore `~x` is not a fixed-width N-bit NOT.
9. For N-bit NOT/masking, use:
       (~x) & ((1 << N) - 1)
10. Bit 0 is the least significant bit.
"""
