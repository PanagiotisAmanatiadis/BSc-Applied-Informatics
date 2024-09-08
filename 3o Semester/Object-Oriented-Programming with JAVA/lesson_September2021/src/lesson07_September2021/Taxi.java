package lesson07_September2021;

abstract public class Taxi {
	
	
	protected String number;
	protected String driverName;
	
	public Taxi(String number,String driverName)
	{
		this.number=number;
		this.driverName=driverName;
	}
	
	abstract double getAutonomy();

}
