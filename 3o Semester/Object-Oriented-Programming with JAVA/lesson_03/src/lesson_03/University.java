package lesson_03;

import java.util.ArrayList;

public class University {

	private String name;
	
	
	private ArrayList<Student> studentList=new ArrayList<Student>();
	
	public University(String name) {
		this.name=name;
	}
	
	
	public ArrayList<Student> getStudentList()
	{
		return this.studentList;
	}
	
	public void addStudent(Student student)
	{
		//update studentList for current university.
		this.studentList.add(student);
		
		//update university field for current student.
		student.setUniversity(this);
		
	}
	
}
