package lesson07_September2021;

import java.util.ArrayList;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		
		Fleet fleet1=new Fleet("Rethimno");
		Fleet fleet2=new Fleet("Hrakleio");
		
		Taxi et1=new ElectricalTaxi("2003","giorgos",50);
		Taxi et2=new ElectricalTaxi("2008","trifon",80);

		Taxi gt1=new GasolineTaxi("2001","spiros",60,7.5);
		Taxi gt2=new GasolineTaxi("2004","nikos",55,6.5);
		
		fleet1.storeTaxi(et1);
		fleet1.storeTaxi(gt1);
		
		fleet2.storeTaxi(et2);
		fleet2.storeTaxi(gt2);
		
		ArrayList<Fleet> fleets=new ArrayList<Fleet>();
		fleets.add(fleet1);
		fleets.add(fleet2);
		
	}

}
