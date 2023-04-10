input_text=input('Enter the text: ')
substring=input('Enter the substring to delete: ')
start_index=input_text.find(substring)
if start_index == -1:
    print('Error: The substring was  ot found in the text: ')
    exit()
end_index=start_index+len(substring)
result=input_text[:start_index]+input_text[end_index:]
print('The result is', result)