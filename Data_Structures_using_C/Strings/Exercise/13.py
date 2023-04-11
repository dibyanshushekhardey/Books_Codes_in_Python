'''
Write a program to input a text of at least two
paragraphs. Interchange the first and second
paragraphs and then re-display the text on the
screen.
'''

def interchange_paragraphs(text):
    paragraphs=text.split('\n\n')
    if len(paragraphs) < 2:
        print('Error: Input text must contain at least two paragraphs.')
        return text
    temp=paragraphs[0]
    paragraphs[0]=paragraphs[1]
    paragraphs[1]=temp
    modified_text='\n\n'.join(paragraphs)
    return modified_text


text = "This is the first paragraph.\n\nThis is the second paragraph.\n\nThis is the third paragraph."
modified_text = interchange_paragraphs(text)
print(modified_text)