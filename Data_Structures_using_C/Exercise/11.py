'''
Write a program to input an array of strings. Then,
reverse the string in the format shown below.
 "HAPPY BIRTHDAY TO YOU" should be displayed
as "YOU TO BIRTHDAY HAPPY"
'''

def reverse_array(array):
    
    string=' '.join(array)
    words=string.split()
    words.reverse()
    
    final_str=' '.join(words)
    return final_str

arr=['HAPPY', 'BIRTHDAY', 'TO', 'YOU']
reversed_str=reverse_array(arr)
print(reversed_str)