# #####  Write a Python program to create an array of 5 integers
#       and display the array items. Access individual elements
#       through indexes.


num_array = [1,2,3,4,5]
for i in num_array:
    print(i);

####
# append a new item to the end of the array
# ####

num_array.append(6)
print(num_array)

# Write a Python program to reverse the order of the items in the array. Go to the editor
# Sample Output


# [::-1] instructs Python to slice the list starting from the end (-1)
# and move towards the beginning, including all elements (:) and with a step of -1 (-1).

print(num_array[::-1])


