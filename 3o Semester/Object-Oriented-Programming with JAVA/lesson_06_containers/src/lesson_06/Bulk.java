package lesson_06;

public class Bulk extends Container {
    
	protected double kila;
	
	public Bulk(String code, String destination,double kila) {
		super(code, destination);
		this.kila=kila;
		
	}

	@Override
	public double getCost() {
		return 10 * this.kila;
		
	}
   
	public void printInfo()
	{
		super.printInfo();
		System.out.println("kila:"+this.kila);
		
	}
	
	
}
