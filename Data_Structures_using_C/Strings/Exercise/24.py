'''
. Write a program to read and display names of
employees in a department.
'''

n = int(input('Enter the number of elmployees: '))
names=[]
for i in range(n):
    name=input('Enter the name of employee {}: '.format(i+1))
    names.append(name)
print('The names of employees in the department are:')
for name in names:
    print(name)