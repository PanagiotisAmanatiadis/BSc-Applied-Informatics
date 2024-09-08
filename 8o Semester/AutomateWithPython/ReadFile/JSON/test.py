import json



# open and read the JSON file
with open('data.json','r') as jsonf:
	data=json.load(jsonf)


print(data)
#print the contents of the file
dictionary=data['emp_details']

for emp in dictionary:
	print(emp)



