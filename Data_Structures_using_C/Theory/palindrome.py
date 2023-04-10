text=input('Enter the text: ')
reverse_text=text[::-1]
if text == reverse_text:
    print('The text is a palindrome')
else:
    print('The text is not a palindrome')