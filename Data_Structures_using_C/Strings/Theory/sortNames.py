num_students=int(input('Enter the number of students:'))
students=[]
for i in range(num_students):
    name=input('Enter the name of student {}:'.format(i+1))
    students.append(name)
students.sort()
print('The sorted list of the student names is: ', students)