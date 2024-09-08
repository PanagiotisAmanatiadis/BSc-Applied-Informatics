import java.util.ArrayList;

public class Driver {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Owner o1=new Owner("Georgios","Papadopoulos","6969696969");
		
		Animal a1=new Animal("jhony");
		Animal a2=new Animal("sona");
		
		//Test
		//object.method()
		//System.out.println(o1.getFirstName());
		o1.setFirstName("Nikos");
		//System.out.println(o1.getFirstName());
		
		System.out.println(o1.getAnimals());
		
		//add some objects
		o1.addAnimal(a1);
		o1.addAnimal(a2);
		
		System.out.println(o1.getAnimals());
		
		ArrayList<Animal> list=o1.getAnimals();
		
		//for(Animal tempAnimal:list)
		//
		for(Animal tempAnimal:o1.getAnimals())
		{
			System.out.println(tempAnimal.getName());
		}
		
		System.out.println("printInfo()");
		
		o1.printInfo();
		
		
	}

}
