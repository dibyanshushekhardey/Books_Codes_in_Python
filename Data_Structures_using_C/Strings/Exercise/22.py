'''
Write a program to copy the last n characters of a
character array in another character array. Also,
convert the lower case letters into upper case
letters while copying
'''
text=input('Enter a text: ')
n=int(input('Enter the number of characters to copy: '))
text_copy=text[-n:].upper()
print(text_copy)