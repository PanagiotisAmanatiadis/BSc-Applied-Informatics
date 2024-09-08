import sys
from operator import itemgetter

def readFile(inputFile):
    try:
        table=[line.replace('\n','').split() for line in open(inputFile, 'r', encoding='utf-8')]
    except FileNotFoundError:
        print('File not found.\n')
        sys.exit(0)
    else:return table

def getStudentsInformation(inputs):
	students=list()
	for student in inputs:
		dictionary={'name':student[0],'skills':set(student[1:])}
		students.append(dictionary)	
	return students

def optimization(students,remaining_unique_skills):
	for student in students:
		#add the number of similar skills between student and remaining_unique_skills.
		student['numberOfSimilarSkills']=len(student['skills'].intersection(remaining_unique_skills))
	students.sort(key=itemgetter('numberOfSimilarSkills'),reverse=True)
	return students

def greedyAlgorithm(students,unique_skills):
	best_students,covered_unique_skills,remaining_unique_skills=set(),set(),unique_skills 
	
	while covered_unique_skills!=unique_skills:
		students=optimization(students,remaining_unique_skills)
		student=students.pop(0)
		best_students.add(student['name'])
		covered_unique_skills.update(student['skills'])
		remaining_unique_skills=remaining_unique_skills-covered_unique_skills
		
	return best_students

def main():
	inputs=readFile(sys.argv[1])
	unique_skills=set(inputs[0])
	students=getStudentsInformation(inputs[1:])
	#Search for the minimum number of students that have all the required.
	best_students=greedyAlgorithm(students,unique_skills)
	print("The company's personnel manager select this students:",best_students)
	


