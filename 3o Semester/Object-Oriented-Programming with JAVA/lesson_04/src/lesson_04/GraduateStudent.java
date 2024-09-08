package lesson_04;

public class GraduateStudent extends Student {
	
	private String supervisor;
	
	public GraduateStudent(String name, String am,String supervisor) {
		super(name, am);
		this.supervisor=supervisor;
	}
	
	//Epikalipsi:aksiopioisei yparxon kodika + prosthikes
	public void printInfo() {
		System.out.println("Supervisor: "+this.supervisor);
		//super.method()
		super.printInfo();
		
	}
	

	
    
}
