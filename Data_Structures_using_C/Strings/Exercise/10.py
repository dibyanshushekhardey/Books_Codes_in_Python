'''
Write a program to find the last instance of
occurrence of a sub-string within a string.
'''

string='Hello World! Hello'
substring='Hello'

last_index=string.rfind(substring)
if last_index == -1:
    print('Substring not found')
else:
    print('Last occurence of substring is at index {}'.format(last_index))