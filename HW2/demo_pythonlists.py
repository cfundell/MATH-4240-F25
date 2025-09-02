# 
# HW2 - Python lists practice 
#

# append()
print("Demonstration of .append()")
list_nums = [0,1,2,3]
print("Before append:", list_nums)
list_nums.append(4)
print("After append:", list_nums)

# clear()
print("\nDemonstration of .clear()")
list_nums = [0,1,2,3]
print("Before clear:", list_nums)
list_nums.clear()
print("After clear:", list_nums)

# copy()
print("\nDemonstration of .copy()")
list_nums = [0,1,2,3]
print("Original list: list_nums = ", list_nums)
list_copy = list_nums.copy()
print("Copied list: list_copy = ", list_copy)

# count()
print("\nDemonstration of .count()")
list_names = ["Jim", "Jerry", "Gerry", "Jim", "Jane"]
print("List of names:", list_names)
num_jims = list_names.count("Jim")
print("Number of times 'Jim' appears in the list:", num_jims)

# extend()
print("\nDemonstration of .extend()")
list1 = ["a", "b", "c"]
list2 = ["d", "e", "f"]
print("List 1:", list1)
print("List 2:", list2)
list1.extend(list2)
print("After extending List 1 with List 2: list1 = ", list1)

# index()
print("\nDemonstration of .index()")
list_games = ["chess", "uno", "hold em", "checkers"]
print("List of games:", list_games)
index_poker = list_games.index("hold em")
print("Index of 'hold em' in the list:", index_poker)

# insert()
print("\nDemonstration of .insert()")
list_of_fibs = [1, 1, 2, 3, 5, 13]
print("Before insert:", list_of_fibs)
list_of_fibs.insert(5, 8)
print("After insert:", list_of_fibs)

# pop()
print("\nDemonstration of .pop()")
list_months = ["Jan", "Feb", "Mar", "Apr", "August", "May"]
print("Before pop:", list_months)
popped_month = list_months.pop(4)
print("After pop:", list_months)
print("Popped month:", popped_month)

# remove()
print("\nDemonstration of .remove()")
list_months = ["Jan", "Feb", "Mar", "Apr", "August", "May"]
print("Before remove:", list_months)
list_months.remove("August")
print("After remove:", list_months)

# reverse()
print("\nDemonstration of .reverse()")
list_months = ["May", "April", "March", "February", "January"]
print("Before reverse:", list_months)
list_months.reverse()
print("After reverse:", list_months)

# sort()   
print("\nDemonstration of .sort()")
list_nums = [8, 2, 45, 9, 3, 1]
print("Before sort:", list_nums)
list_nums.sort()
print("After sort:", list_nums)

