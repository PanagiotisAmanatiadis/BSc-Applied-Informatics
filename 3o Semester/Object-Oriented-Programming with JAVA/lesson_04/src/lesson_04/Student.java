package lesson_04;

import java.util.ArrayList;

public class Student {

	//private String name;
	protected String name;
	protected String am;
	
	protected ArrayList<Course> courses = new ArrayList<Course>();
	
	public Student(String name,String am)
	{
		this.name=name;
		this.am=am;
	}
	
	public void addCourse(Course course)
	{
		this.courses.add(course);
	}
	
	public void printInfo()
	{
		for(Course tempCourse:this.courses)
		{
			System.out.println("Course: "+tempCourse.getName()+", ecs: "+tempCourse.getEcs());
			
		}
	}
	
	
	
	
	
}
