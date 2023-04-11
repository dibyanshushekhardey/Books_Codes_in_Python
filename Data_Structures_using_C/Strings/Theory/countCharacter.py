text=''
print('Enter the text(press Enter twice to end):')
while True:
    line=input()
    if line:
        text += line + '\n'
    else:
        break
num_characters=len(text)
num_words=len(text.split())
num_lines=text.count('\n')

print('Number of characters in the text:', num_characters)
print('Number if words in the text: ', num_words)
print('Number of lines in the text: ', num_lines)