

"""
Arithmetic Operators:
=	x = 5	x = 5	
+=	x += 3	x = x + 3	
-=	x -= 3	x = x - 3	
*=	x *= 3	x = x * 3	
/=	x /= 3	x = x / 3	
%=	x %= 3	x = x % 3	
//=	x //= 3	x = x // 3	
**=	x **= 3	x = x ** 3

Comparison Operators:
==	Equal	x == y	
!=	Not equal	x != y	
>	Greater than	x > y	
<	Less than	x < y	
>=	Greater than or equal to	x >= y	
<=	Less than or equal to	x <= y

Logical Operators:
and Returns True if both statements are true	x < 5 and  x < 10	
or	Returns True if one of the statements is true	x < 5 or x < 4	
not	Reverse the result, returns False if the result is true	not(x < 5 and x < 10)

Identity Operators:
x is y
x is not y

Membership Operators:
x in y
x not in y

"""

x=1
print('x:',x)
x+=5
print('x:',x)
x-=2
print('x:',x)
x*=3
print('x:',x)
x/=3
print('x:',x)
print('x:',x%3)
print('x:',x//3)
print('x:',x**2)

x,z=2,5
print('x='+str(x),',z='+str(z))
print('x==z:',x==z)
print('x!=z:',x!=z)
print('x>z:',x>z)
print('x>=:',x>=z)
print('x<z:',x<z)
print('x<=z:',x<=z)


print('x>1 and z<=3:',x>1 and z<=3)
print('x>1 or z <=3:',x>1 or z<=3)
print('not x<10:',not x<10)

print('x is z:',x is z)
print('x is not z:',x is not z)

txt="The best things in life are free!"
print('free in txt:','free' in txt)
print('free not in txt:','free' not in txt)





