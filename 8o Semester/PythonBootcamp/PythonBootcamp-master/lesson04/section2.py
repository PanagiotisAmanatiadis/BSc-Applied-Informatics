import os


file="C:\\Users\\user\\Desktop\\lesson04\\JSON\\data.json"

if os.path.isfile(file):
	print('path:',file)
else:
	print("that path doesn't exist")


