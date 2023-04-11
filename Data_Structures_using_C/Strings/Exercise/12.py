'''
Write a program to append a given string in the
following format.
 "GOOD MORNING MORNING GOOD"
'''

def reverse_array(array):
    
    string=' '.join(array)
    words=string.split()
    words.reverse()
    
    final_str=' '.join(words)
    return string+' '+final_str

arr=['GOOD', 'MORNING']
reversed_str=reverse_array(arr)
print(reversed_str)