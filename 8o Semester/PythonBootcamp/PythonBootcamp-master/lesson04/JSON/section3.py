import json

#open and read the JSON file
file=open('data.json','r')

data=json.load(file)

#print(data)

dictionary=data['emp_details']

for emp in dictionary:
	print(emp)


