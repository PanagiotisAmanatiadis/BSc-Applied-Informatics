package lesson_03;

import java.util.ArrayList;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		//create some objects
		University u1=new University("pamak");
		University u2=new University("ap8");
		
		Student s1=new Student("dai15193");
		Student s2=new Student("dai15194");
		Student s3=new Student("dai15197");
		
		//Test
		u1.addStudent(s1);
		
		u2.addStudent(s2);
		u2.addStudent(s3);
		
		
		//u1 examples.
		//ArrayList<Student> list=u1.studentList;
		ArrayList<Student> list=u1.getStudentList();
		
		
		
		
		
		
		
		
	}

}
