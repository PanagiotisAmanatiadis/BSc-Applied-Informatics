package lesson_06;

public class Refridgerator extends Container {
    
	protected double kw;
	public Refridgerator(String code, String destination,double kw) {
		super(code, destination);
		this.kw=kw;
		
	}
	
	@Override
	public double getCost() {
		return 2000 * this.kw;
	}
	
	
	
	public void printInfo()
	{
		super.printInfo();
		System.out.println("kw:"+this.kw);
		
	}

}
