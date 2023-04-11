'''
Write a program to concatenate first n
characters of a string with another string.
'''

string1=input('Enter the frist string: ')
string2=input('Enter the second string: ')

n = int(input('Enter the number of characters to concatenate: '))
result=string1[:n]+string2
print('The concatenated string is: ', result)
