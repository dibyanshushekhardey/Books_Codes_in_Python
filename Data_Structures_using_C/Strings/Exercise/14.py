'''
Write a program to input a text of at least two
paragraphs. Construct an array PAR such that
PAR[I] contains the location of the ith paragraph
in text.
'''

def construct_paragraph_array(text):
    paragraphs=text.split('\n\n')
    if len(paragraphs) < 2:
        print('Error: Input text must contain at least two paragraphs.')
        return []
    par = [0]*len(paragraphs)
    location= 0
    for i in range(len(paragraphs)):
        par[i]=location
        location += len(paragraphs[i])+2
    return par

text = "This is the first paragraph.\n\nThis is the second paragraph.\n\nThis is the third paragraph."
par = construct_paragraph_array(text)
print(par)
