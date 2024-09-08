package lesson_05;

public class Employee {

	protected String firstName;
	protected String lastName;
	protected double salary;
	
	public Employee(String firstName,String lastName,double salary)
	{
		this.firstName=firstName;
		this.lastName=lastName;
		this.salary=salary;
	}
	
	public void printInfo()
	{
		System.out.println("firstName: "+this.firstName+", lastName: "+this.lastName);
	}
	public void printSalary() {
		System.out.println(this.salary-this.salary*0.2);
	}
	
	
	
}
