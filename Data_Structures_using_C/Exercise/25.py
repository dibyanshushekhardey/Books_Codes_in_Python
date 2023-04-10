'''
Write a program to read a line until a newline is
entered.
'''

line=input('Enter a line: ')
while not line.endswith('\n'):
    line += input()
print('The line you entered is: '+line)