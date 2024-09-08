
"""
class name:
	
	code
	
	attribute='Hello World!' #class attribute

	constructor:
	def __init(self,fields)__:
		self.field1=field1   public instance attribute
		self._field2=field2  protected instance attribute
		self.__field3=field3 private instance attribute 
		...
	
	#getters
	def getField1(self):
		return self.field1
	
	def getField2(self):
		return self._field2
	
	def getField3(self):
		return self.__field3

	
	#setters
	def setField1(self,newField1):
		self.field1=newField1
	
	def setField2(self,newField2):
		self._field2=newField2
	
	def setField3(self,newField3):
		self.__field3=newField3




public:
object.attribute
object.method()

protected:
object._attribute
object._method()

private:
object._class.attribute
object._class.method()


"""
class Student:
	#pass
	school="5o dimotiko"

#This is an empty object
student1=Student()
print(student1)
print(student1.school)



class Employee:
	
	def __init__(self,firstName,lastName,age,email,salary):
		print('Welcome to the company!!!')
		self.firstName=firstName
		self.lastName=lastName
		self._age=age
		self.email=email
		self.__salary=salary

	
	def getAge(self):
		return self._age

	def setAge(self,newAge):
		self._age=newAge

	def getSalary(self):
		return self.__salary



employee1=Employee('Panagiotis','Amanatiadis',24,'amanatiadispan@gmail.com',800)
#public fields:
print('firstName:',employee1.firstName,'lastName:',employee1.lastName)

#protected fields:
print('age:',employee1._age,employee1.getAge())
employee1._age=30
print('age:',employee1._age,employee1.getAge())
employee1.setAge(45)
print('age:',employee1._age,employee1.getAge())

#private fields:
print('salary:',employee1._Employee__salary,employee1.getSalary())








