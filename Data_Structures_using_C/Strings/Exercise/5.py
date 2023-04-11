'''
Write a program
that replaces a given
character with another character in a string
'''

string=input('Enter a string: ')
char_to_replace=input('Enter the character to replace: ')
replacement_char=input('ENter the replacement char: ')
new_string=string.replace(char_to_replace, replacement_char)
print('The new string is: ', new_string)