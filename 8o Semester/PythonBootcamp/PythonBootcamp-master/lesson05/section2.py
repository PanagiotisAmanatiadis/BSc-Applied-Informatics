"""
class Parent:

	def __init__(self,field1,field2):
		self.field1=field1
		self.field2=field2



class Child(parent):
	def __init__(self,field1,field2,field3,field4):
		Parent.__init__(self,field1,field2)
		or
		super().__init__(field1,field2)
		#add more fields
		self.field3=field3
		self.field4=field4

"""


class Person():
	def __init__(self,firstName,lastName):
		self.firstName=firstName
		self.lastName=lastName


	def printData(self):
		print('Person Data')
		print('firstName:',self.firstName)
		print('lastName:',self.lastName)




class Student(Person):
	
	def __init__(self,firstName,lastName,curent_year):
		#Person.__init__(self,firstName,lastName)
		super().__init__(firstName,lastName)
		self.curent_year=curent_year

	

	def printData(self):
		print('Student Data')
		print('firstName:',self.firstName)
		print('lastName:',self.lastName)
		print('curent_year:',self.curent_year)


person1=Person('Nikos','Papadopoulos')
student1=Student('Panagiotis','Amanatiadis',3)


person1.printData()
student1.printData()




