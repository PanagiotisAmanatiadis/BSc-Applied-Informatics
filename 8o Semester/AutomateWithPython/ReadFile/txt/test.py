
f=open('example.txt','r')
data=f.read()
f.close()
print(data)


f=open('example.txt','r')
lines=f.readlines()
for line in lines:
	print(line)

f.close()