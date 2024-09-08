package lesson_06;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		
		Ship s=new Ship(450);
		
		
		Container bulk1=new Bulk("CYZ1011","Madrid",500);
		Container bulk2=new Bulk("CYZ1012","Barcelona",2000);
		
		Container ref1=new Refridgerator("CYZ1013","Rome",100);
		Container ref2=new Refridgerator("CYZ1014","Milano",200);
		
		
		s.addContainer(bulk1);
		s.addContainer(bulk2);
		s.addContainer(ref1);
		s.addContainer(ref2);
		
		System.out.println("Total cost: "+ s.getTotalCost());
		
		
		//pername os orisma to ship.
		
		new calculator(s);
		
	}

}
