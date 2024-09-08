package lesson07_September2021;

public class GasolineTaxi extends Taxi {
    
	protected int liter;
	protected double average;
	
	public GasolineTaxi(String number, String driverName,int liter,double average) {
		super( number, driverName);
		this.liter=liter;
		this.average=average;
	
	}

	@Override
	public double getAutonomy() {
		return 90 * (this.liter/this.average);
	}

}
