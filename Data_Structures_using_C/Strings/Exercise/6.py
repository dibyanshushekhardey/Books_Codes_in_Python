'''
Write a program to count the number of digits,
upper case characters, lower case characters, and
special characters in a given string.
'''

string=input('Enter a string: ')

num_digits=0
num_uppercase=0
num_lowercase=0
num_special=0

for char in string:
    if char.isdigit():
        num_digits += 1
    elif char.isupper():
        num_uppercase += 1
    elif char.islower():
        num_lowercase += 1
    else:
        num_special += 1

print('Digits: ', num_digits)
print('Uppercase characters: ', num_uppercase)
print('Lowercase characters: ', num_lowercase)
print('Special characters: ', num_special)
