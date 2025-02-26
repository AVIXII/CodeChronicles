from collections import OrderedDict

# Creating an OrderedDict
ordered_dict = OrderedDict()
ordered_dict['apple'] = 3
ordered_dict['banana'] = 2
ordered_dict['cherry'] = 5

print(ordered_dict)  # Output: OrderedDict([('apple', 3), ('banana', 2), ('cherry', 5)])

# Preserving order of elements
for key, value in ordered_dict.items():
    print(f"{key}: {value}")
# Output:
# apple: 3
# banana: 2
# cherry: 5

# move_to_end(key, last=True/False)  Error if key not in the dictionary. Always check before 
ordered_dict.move_to_end('banana')
print(ordered_dict)  # Output: OrderedDict([('apple', 3), ('cherry', 5), ('banana', 2)])

ordered_dict.move_to_end('apple', last=False)
print(ordered_dict)  # Output: OrderedDict([('apple', 3), ('cherry', 5), ('banana', 2)])

# popitem(last = True/False)
# Removing the last item
item = ordered_dict.popitem()
print(item)          # Output: ('banana', 2)
print(ordered_dict)  # Output: OrderedDict([('apple', 3), ('cherry', 5)])

# Removing the first item
item = ordered_dict.popitem(last=False)
print(item)          # Output: ('apple', 3)
print(ordered_dict)  # Output: OrderedDict([('cherry', 5)])