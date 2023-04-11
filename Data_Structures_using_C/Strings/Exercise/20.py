'''
Write a program to insert "University" in the
given string "Oxford Press" so that the string
should read as "Oxford University Press"
'''

text='Oxford Press'
new_text=text[:6]+' University'+text[6:]
print(new_text)
