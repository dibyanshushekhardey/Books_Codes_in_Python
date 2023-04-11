'''
Write a program to count the total number of
occurrences of a word in the text.
'''


text=  input('Enter somee text:')
word=input('Enter a word: ')
words=text.split()
count = 0
for w in words:
    if w == word:
        count += 1

print("The word 'the' apperas {} times in the text".format(count))