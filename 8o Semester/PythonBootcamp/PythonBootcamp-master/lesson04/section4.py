"""

the error handler prevent the fast end 

try:
    #statements in try block
except:
    #executed when error in try block
else:
    #executed if try block is error-free
finally:
    #executed irrespective of exception occured or not

"""



try:
	a=5
	b='0'
	print(a/b)
except:
	print('Some error occurred')

print("Out of try except blocks.")


try:
	a=5
	b=0
	print(a/b)
except TypeError:
	print('Unsupported operation')

except ZeroDivisionError:
    print ('Division by zero not allowed')


print ('Out of try except blocks')




try:
    print('try block')
    x=int(input('Enter a number: '))
    y=int(input('Enter another number: '))
    z=x/y
except ZeroDivisionError:
    print("except ZeroDivisionError block")
    print("Division by 0 not accepted")
else:
    print("else block")
    print("Division = ", z)
finally:
    print("finally block")
    x=0
    y=0
    print('x:',x,'y:',y)
print ("Out of try, except, else and finally blocks." )





