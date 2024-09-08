package lesson_05;

import java.util.ArrayList;

public class Company {
	
	private String name;
	
	private ArrayList<Employee> employees =new ArrayList<Employee>();
	
	public Company(String name) {
		this.name=name;
	}
	
	public void addEmployee(Employee employee)
	{
		this.employees.add(employee);
	}
	
	public void printEmployees()
	{
		for(Employee tempEmployee:this.employees)
		{
			tempEmployee.printInfo();
			tempEmployee.printSalary();
		}
	}

}
