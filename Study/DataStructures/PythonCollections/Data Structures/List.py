# Initialisation (can also use list comprehensions)
ls = [1, 2, 3, 4]

# Size
size = len(ls)

# Empty
is_empty = not ls  # Python treats empty lists as false!

# Access elements
a = ls[0]  # 1

# Pro Tip:- Use slices for insertion and deletion anywhere and everywhere
# Insertion
ls.append(2)  # [1, 2, 3, 4, 2]
ls.insert(3, 45)  # ls[3:3] = 45   [1, 2, 3, 45, 4, 2] 

# Deletion
# For deleting and adding another range of values ls[s:e] = [2, 3, 4, ...]
ls.pop()  # [1, 2, 3, 45, 4] or ls[-1] = []
ls.pop(2)  # [1, 2, 45, 4] or ls[2:3] = []
del ls[1:2]  # [1, 45, 4] or ls[1:2] = []
del ls[1]  # [1, 4]
# ls[index1:index2] = []

# Clear
ls = []  # or ls.clear()

# First
ls.insert(0, 45) 
first = ls[0]

# Last 
last = ls[-1]

# Printing a list
print(ls)

# Enhanced for loops
for el in ls:
    print(el)

# Enumerate objects in python
s = [i+10 for i in range(10)]
for i, e in enumerate(s):
    print(i, e)

# Find - Check whether an element is present in the list or not
el = 4
isPresent = el in ls  # Checks if the element is present in the list
idx = ls.index(4)  # Returns index if the element exists in the list else raises an error.
