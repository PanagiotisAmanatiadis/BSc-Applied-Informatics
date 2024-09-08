package test2023;

public class Subscriber {

	
	protected String surname;
	protected double mesi_katanalosi;
	
	public Subscriber(String surname,double mesi_katanalosi)
	{
		this.surname=surname;
		this.mesi_katanalosi=mesi_katanalosi;
	}
	
	
	
	
	public double calculateNetEnergy()
	{
		return this.mesi_katanalosi;
	}
	
	
}
