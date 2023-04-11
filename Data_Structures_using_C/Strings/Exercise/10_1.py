'''
Alternate method of solving question 10 without using rfind()
'''

def find_last_index(string, substring):
    last_index = -1
    index = 0
    while True:
        index = string.find(substring, index)
        if index == -1:
            return last_index
        last_index = index
        index += 1

string = 'Hello, World! Hello'
substring ='Hello'

last_index = find_last_index(string, substring)

if last_index == -1:
    print('Substring is not found')
else:
    print('Last occurence if substring is at index {}'.format(last_index))
