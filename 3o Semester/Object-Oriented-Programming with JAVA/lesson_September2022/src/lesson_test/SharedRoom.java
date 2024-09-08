package lesson_test;

public class SharedRoom extends Property {
    
	protected int tetragonika;
	public SharedRoom(String name, int people,int tetragonika) {
		super(name, people);
		this.tetragonika=tetragonika;
	}
	
	public double calculateTaxRate()
	{
		double foros=0;
		
		if(this.tetragonika>15)
			foros=0.11;
		else
			foros=0.09;
			
		if(this.people>4)
		   foros=foros+0.01;
			
		return foros;
	}
		
		
		
	
}
