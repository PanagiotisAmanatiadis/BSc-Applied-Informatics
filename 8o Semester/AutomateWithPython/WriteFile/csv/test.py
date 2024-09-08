import csv

array=[1,2,3,4,5]

with open("output.csv","w") as csvfile:
	writer=csv.writer(csvfile,delimiter=",")
	writer.writerow(array)