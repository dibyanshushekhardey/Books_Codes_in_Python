'''
Write a program to accept a text. Count and
display the number of times the word ‘the’ appears
in the text.
'''

text=  input('Enter somee text:')
words=text.split()
count = 0
for word in words:
    if word == 'the':
        count += 1

print("The word 'the' apperas {} times in the text".format(count))