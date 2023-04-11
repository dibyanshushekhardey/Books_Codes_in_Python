'''
Write a program to enter a text that contains
multiple lines. Display the n lines of text starting
from the mth line.
'''
text=input('Enter a multi-line text:\n')
lines=text.splitlines()
m=int(input('Enter the starting line number: '))
n=int(input('enter the number of lines to display: '))
for line in lines[m-1:m-1+n]:
    print(line)