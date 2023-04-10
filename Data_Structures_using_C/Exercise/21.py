'''
. Write a program to read a text, delete all the semicolons it has, and finally replace all '.' with a ','.
'''

text=input('Enter a text: ')
text=text.replace(';', '')
text=text.replace('.', ',')
print(text)