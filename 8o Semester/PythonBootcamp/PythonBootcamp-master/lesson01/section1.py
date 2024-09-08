#1.Comments:

# this is a comment

"""
this is a comment

"""

#2.Printing to the Console in Python:
#We use the function print()
print("Hello World!\n")
print('Hello World!\n')
print("x","y")
print("x"+"y")
#print(5+'panos') -> TypeError


#3.The Python input function
#it always returns str type
input("What is your name? ") 
input("What is your age? ")


"""
4.
Basic DataTypes:
With below commands we create empty variables
x=int()   -> x is 0
x=str()   -> x is ''
x=float() -> x is 0.0
x=bool()  -> x is False
x=list()  -> x is [] 
x=set()   -> x is {}
x=None    -> x is None

Rules for Python variables:
A variable name must start with a letter or the underscore character 
A variable name cannot start with a number
A variable name can only contain alpha-numeric characters and underscores (A-z, 0-9, and _ )
Variable names are case-sensitive (age, Age and AGE are three different variables)
A variable name cannot be any of the Python keywords

Each word, except the first, starts with a capital letter: myFirstVariable
Each word is separated by an underscore character: my_first_variable

"""

n=5  #int
firstName=input("What is your firstname? ") # str
lastName = "Amanatiadis" # str
phoneNumber='6984214769' #str
x,z=20,5.3 #int,float
f1,f2='orange','cherry' #str,str
flag=True #bool
y=None    #NoneType

print(n)
print('firstName:',firstName)
print('lastName:',lastName)
print('phoneNumber:',phoneNumber)
print('x:',x,', z:',z)
print(f1,f2)
print(flag)
print(y)

#The function which return the type of variable is the type()
print(type(n))
print(type(firstName))
print(type(lastName))
print(type(phoneNumber))
print(type(z))
print(type(flag))
print(type(y))









