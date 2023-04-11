input_string=input('Enter a string: ')
string_length=len(input_string)
start_index=int(input('Enter the starting index of the substring: '))
substring_length=int(input('Enter the length of the substring: '))
substring=input_string[start_index:start_index+substring_length]
print('The extracted substring is: ', substring)