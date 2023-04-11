'''
Write a program to check whether a pattern exists
in a text. If it does, delete the pattern and display
it.
'''
text=input('Enter some text: ')
pattern=input('Enter a pattern to search for: ')

if pattern in text:
    text=text.replace(pattern, '')
    print("The pattern '{}' was found and deleted from the text.".format(pattern))
    print("The new text is: {}".format(text))
else:
    print("The pattern '{}' was not found in the text.".format(pattern))