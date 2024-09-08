package lesson_04;

import java.util.ArrayList;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Course c1=new Course("Java",5);
		Course c2=new Course("PHP",5);
		
		Student s1=new Student("Georgios","dai17190");
		Student s2=new GraduateStudent("Spyros","dai18210","Ksinogalos");
		
		ArrayList<Student> students=new ArrayList<Student>();
		
		students.add(s1);
		students.add(s2);
		
		s1.addCourse(c1);
		s1.addCourse(c2);
		
		s2.addCourse(c1);
		
		
		
		for(Student tempStudent:students)
		{
			tempStudent.printInfo();
		}
		
		
		
		
		
		
		
		
		
	}

}
