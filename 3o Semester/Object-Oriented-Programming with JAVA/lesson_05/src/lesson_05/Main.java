package lesson_05;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Company c=new Company("OTE");
		
		Employee e1=new Employee("Georgios","Papadopoulos",823.5);
		Employee e2=new TechEmployee("Spiros","Georgakopoulos",739.2,200.5);
		
		c.addEmployee(e1);
		c.addEmployee(e2);
		
		c.printEmployees();
	}

}
