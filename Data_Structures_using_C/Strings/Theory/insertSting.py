main_txt=input('Enter the main text: ')
insert_string=input('Enter the string to insert: ')
insert_index=int(input('Enter the index where the string should be inserted: '))
result=main_txt[:insert_index]+insert_string+main_txt[insert_index:]
print('The result is: ', result)