'''
Write a program that compares first n
characters of one string with first n characters of
another string.
'''

string1=input('Enter the frist string: ')
string2=input('Enter the second string: ')

n = int(input('Enter the number of characters to compare: '))

if string1[:n] == string2[:n]:
    print('The first {} characters of the two strings are the same.'.format(n))
else:
    print('The first {} characters of the two strings are different.'.format(n))