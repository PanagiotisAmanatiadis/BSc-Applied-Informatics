package lesson_01;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Owner o1=new Owner("Georgios","Papadopoulos","6969696969");
		
		Animal a1=new Animal("jhony");
		Animal a2=new Animal("sona");
		
		o1.animals.add(a1);
		a1.owner=o1;
		o1.animals.add(a2);
		a2.owner=o1;
		
		
	}

}
