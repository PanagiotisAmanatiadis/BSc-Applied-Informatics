package test2023;

import java.util.ArrayList;

public class GreenSubscriber extends Subscriber{

	protected String location;
	
	protected ArrayList<SolarPanel> solarpanels=new ArrayList<SolarPanel>();
	
	public GreenSubscriber(String surname, double mesi_katanalosi,String location) {
		super(surname, mesi_katanalosi);
		this.location=location;
		
	}

	
	public void addSolarPanel(SolarPanel sp)
	{
		this.solarpanels.add(sp);
	}
	
	public double calculateNetEnergy()
	{
		double sum=0;
		for(SolarPanel tempSP:this.solarpanels)
			sum+=tempSP.getParagogi();
		
		return this.mesi_katanalosi-sum;
	}
	
	
}
