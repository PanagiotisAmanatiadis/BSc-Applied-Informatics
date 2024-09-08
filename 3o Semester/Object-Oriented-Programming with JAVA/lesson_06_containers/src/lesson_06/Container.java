package lesson_06;

abstract public class Container {
	
	
	
	protected String code;
	protected String destination;
	
	public Container(String code,String destination)
	{
		this.code=code;
		this.destination=destination;
	}
	
	public void printInfo()
	{
		//System.out.println("Container:"+this.getClass());
		System.out.println("Code:"+this.code);
		System.out.println("Destination:"+this.destination);
	}
	
	abstract public double getCost();
    
}
