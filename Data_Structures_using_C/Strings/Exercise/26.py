'''
Write a program to read a short story. Rewrite
the story by printing the line number before the
starting of each line.
'''

story=input('Enter a short story:\n')
lines=story.splitlines()
for i, line in enumerate(lines, 1):
    print(f'{i}. {line}')