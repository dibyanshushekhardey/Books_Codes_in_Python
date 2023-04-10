'''
Write a program to count the total number of
occurrences of a given character in the string
'''

string = input('Enter a string:')
char_to_count = input('Enter the character to count: ')
count = 0
for char in string.lower():
    if char == char_to_count:
        count += 1

print('The character {} occurs {} times in the stirng'.format(char_to_count, count))