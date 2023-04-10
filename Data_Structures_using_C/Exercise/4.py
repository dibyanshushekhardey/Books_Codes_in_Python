'''
Write a program that removes leading and
trailing spaces from a string
'''

string_with_spaces=input('Enter a string with leading and trailing spaces: ')
trimmed_string=string_with_spaces.strip()
print('The trimmed string is :{}'.format(trimmed_string))