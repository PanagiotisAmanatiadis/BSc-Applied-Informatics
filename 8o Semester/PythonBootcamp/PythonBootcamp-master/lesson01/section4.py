
#string is unchangeable
#A sequence of characters into ' ' or " ".
name='panagiotis'


#length of string: we use the function len(s)
print(len(name))

print(name)
print(name[0]) #we take the first element of the string
print(name[len(name)-1])#we take the last element of the string

#slice: s[start:end]
print(name[:5]) #we take the first 5 characters of the string
print(name[5:]) #we take all characters starting of sixth character
print(name[-1]) #we take the last element of the string
print(name[-2:]) #we take the last two elements of the string


firstName='panagiotis'
lastName='amanatiadis'
print(firstName+lastName)
print(firstName*2)
#for char in s:


#If I want to change the string, I need to create a new variable with the result of the method.
#Methods for strings -> s.method()
#format()
age=23
txt='My name is Panagiotis,and I am {}'
print(txt.format(age))
#s.replace(old,new)
print(txt.replace('i','o'))
#s.count(str)
print(txt.count('a'))
#s.isalpha() -> returns True if s have only characters
print(txt.isalpha())
#s.isdigit() -> returns True if s have only numbers
print(txt.isdigit())
#s.lower() 
print(txt.lower())
#s.upper()
print(txt.upper())
#s.find(str)
print(txt.find('name'))
#s.split(char)
print(txt.split('a'))




