

#read
file=open('data.txt','r')
data=file.read()
print(data)
file.close()

file=open('data.txt','r')
data=file.readlines()
for line in data:
	print(line)

file.close()

#write
file=open('output.txt','w')
file.write('Java\n')
file.write('Spring\n')
file.close()

