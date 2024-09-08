package lesson07_September2021;

public class ElectricalTaxi extends Taxi {
    
	protected int count;
	
	public ElectricalTaxi(String number, String driverName,int count) {
		super(number, driverName);
		this.count=count;
	}

	@Override
	public double getAutonomy() {
		return 70 * this.count;
	}

}
