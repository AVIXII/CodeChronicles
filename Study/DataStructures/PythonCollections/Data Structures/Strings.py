from re import regex as re
# Strings in python are immutable.
 
# Initialisation - ' ', " " for single line strings. """ """ for multiline strings.
name = "Rishabh"  # Literal

# Input - input(), strip(), split()
# Split returns a list by default
s = input().strip().split()  # All inputs in python are strings. They need to be typecasted into another data types if required

# Split - re.split(regex, string)
text = "apple;banana,grape orange"
result = re.split(r'[;, ]+', text)

# Size of the string
l = len(s)  # 5

# Access elements of a string
c = s[0]

# Appending Strings - It is the same as concatenating as str are immutable
s = "sakdfjah"
s += "sdkh"

# Clearing a string
s = []

# Comparing two strings. The operators <, ==, > are overloaded in python compare functions to provide lexicographic
# comparisons of the strings.
a = "Rishabh"
b = "ramdhave"
print(a == b)
# a is b can be used but there are cases when python does not optimize by pointing to the same location

# Check empty
is_empty = not s

# Substrings - Slicing
str = s[:]

# Find - find() -> returns index (-1 if not found). index() -> returns index (ValueError if not found).
str in s  # Check using in
s.find(str)  # Find index using .find() or .index()

# Insert and Erase -> string slices
# new_string = original[:index] + substring + original[index:]
# new_string = original[:start] + original[end:]


strold = "rishi"
strnew = "sam"
limit = 3

#  All the methods in strings return new strings and do not modify the original strings (Strings in python are immutable)
s.upper()  # Converts all characters in the string to uppercase.
s.lower()  # Converts all characters in the string to lowercase.
s.capitalize() # Capitalizes the first character of the string and converts all other characters to lowercase.
s.title()  # Converts the first character of each word to uppercase and the rest to lowercase.
s.strip()  # lstrip, rstrip; Removes leading and trailing whitespace (spaces, tabs, and newlines) from the string.
s.replace(strold, strnew, limit)  # Replace all the old occurences of a string with new occurences if limit not mentioned, then all the occurences.
s.count("world")  # Counts the number of occurences of a given word in the 
s.isalpha()  # Checks if the string consists only of alphabetic characters.
s.isdigit() # Checks if the string consists only of digits.
s.islower()  # Checks if all characters in the string are lowercase.
s.isupper()  # Checks if all characters in the string are uppercase.
" ".join(list)  # Concatenates the elements of an iterable with the string as the separator.
"Hello {}. I come from another world.".format("World")  #  

# Repetition
s = 'sdf'*3
