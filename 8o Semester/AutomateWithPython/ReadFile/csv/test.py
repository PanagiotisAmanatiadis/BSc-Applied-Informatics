#import the csv module
import csv

#open the csv file
with open('data.csv') as csvfile:
	#create a reader object
	reader=csv.reader(csvfile, delimiter=',')

	#loop through the rows in the csv file
	for row in reader:
		#print out the contents of each row
		print(row)

