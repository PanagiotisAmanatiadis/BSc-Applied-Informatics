package lesson_05;

public class TechEmployee extends Employee {
    
	private double bonus;
	
	public TechEmployee(String firstName, String lastName, double salary,double bonus) {
		super(firstName, lastName, salary);
		this.bonus=bonus;
	}
	
	//Polymorphism: Idia methodo me goniki klasi me diaforetiki leitourgia.
	public void printSalary()
	{
		System.out.println(this.salary-this.salary*0.3 + this.bonus);
	}

	
	
}
