package lesson_test;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
        
		
		City c=new City("Thessaloniki",2000000);
		
		Property p=new Property("MarysHouse",5);
		Property s=new SharedRoom("JohnsLodge",4,50);
		
		c.addProperty(p);
		c.addProperty(s);
		
		c.printProperties();
		
		
		
		
		
		
	}

}
