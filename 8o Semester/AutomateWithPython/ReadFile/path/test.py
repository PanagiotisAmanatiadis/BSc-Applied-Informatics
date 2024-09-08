import os.path

file="C:\\Users\\user\\Desktop\\AutomatePython\\ReadFile\\txt\\example.txt"

if os.path.isfile(file):
	with open(file,'r') as f:
		contents=f.read()
		print(contents)
else:
	print('File does not exist.')

