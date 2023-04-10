'''
Write a program to insert a new name in the string
array STUD[][], assuming that names are sorted
alphabetically
'''

# Define the initial array of names
STUD = [['Alice', 'Bob', 'Charlie'], ['A', 'B', 'C']]

# Read the new name to insert from the user
new_name = input("Enter a new name to insert: ")

# Find the index where the new name should be inserted
i = 0
while i < len(STUD[0]) and new_name > STUD[0][i]:
    i += 1

# Insert the new name into the array at the appropriate position
STUD[0].insert(i, new_name)
STUD[1].insert(i, new_name[0])

# Display the updated array
print("The updated array is:")
for i in range(len(STUD[0])):
    print(STUD[0][i] + " (" + STUD[1][i] + ")")
