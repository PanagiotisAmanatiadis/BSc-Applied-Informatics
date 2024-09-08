f=open("myfile.txt","w")
f.write("This is my file!")
for var in [1,2,3,4,5,6]:
	f.write(str(var)+'\n')

skills=['Python','Java']
f.writelines(skills)

f.close()