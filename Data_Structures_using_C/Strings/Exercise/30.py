'''
Write a program to delete a name in the string
array STUD[][], assuming that names are sorted
alphabetically.
'''
# Define the initial array of names
STUD = [['Alice', 'Bob', 'Charlie'], ['A', 'B', 'C']]

# Read the name to delete from the user
name_to_delete = input("Enter the name to delete: ")

# Find the index of the name to delete
i = 0
while i < len(STUD[0]) and STUD[0][i] != name_to_delete:
    i += 1

# Delete the name from the array if it exists
if i < len(STUD[0]):
    del STUD[0][i]
    del STUD[1][i]
    print("The name", name_to_delete, "has been deleted from the array.")
else:
    print("The name", name_to_delete, "was not found in the array.")
    
# Display the updated array
print("The updated array is:")
for i in range(len(STUD[0])):
    print(STUD[0][i] + " (" + STUD[1][i] + ")")
