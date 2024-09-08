
"""
1.Functions:

def name(parameters):
	code
	return result

def name(*arg): arg is a tuple
	code
	return result

def name(**arg): arg is a dictionary
	code
	return result

2.Lamba:

lamda argument:expression

x=lambda a:a+10
y=lambda a,b:a*b


"""


#examples:

def myFunction():
	print('Hello world!')

def printFirstName(firstName):
	print(firstName)

def getMaxMin(array):
	return max(array),min(array)

def myF():
	pass

def printTuple(*arg):
	for var in arg:
		print(var)

def printDict(**arg):
	for key in arg:
		print(arg[key])


def myfunc(a):
	return lambda a:a*3


myFunction()
printFirstName('Nikos')
max,min=getMaxMin([-1,2,0,55])
print('The max is:',max,'The min is:',min)
printTuple(1,2,3,4,5,False)
printDict(fname='Panagiotis',lname='Amanatiadis')

x=lambda number: number*10
y=lambda table: [var+2 for var in table]

array=[1,2,3]

print(x(5))
print(y(array))