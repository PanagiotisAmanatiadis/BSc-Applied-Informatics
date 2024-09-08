package lesson07_September2021;

import java.util.ArrayList;

public class Fleet {

	private String cityName;
	
	private ArrayList<Taxi> taxies = new ArrayList<Taxi>();
	
	public Fleet(String cityName)
	{
		this.cityName=cityName;
	}
	
	public void storeTaxi(Taxi taxi) {
		this.taxies.add(taxi);
	}
}
