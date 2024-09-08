package lesson_test;

public class Property {
	
	protected String name;
	protected int people;
	
	protected City city;
	
	public Property(String name,int people)
	{
		this.name=name;
		this.people=people;
	}
    
	
	public double calculateTaxRate()
	{
		double foros=0;
		if(this.city.getPopulation() < 100000)
			foros=0.1;
		else
			foros=0.12;
		
		if(this.people>4)
			foros=foros+0.01;
		
		return foros;
	}
	
}
