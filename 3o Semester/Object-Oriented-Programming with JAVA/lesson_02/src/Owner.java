

import java.util.ArrayList;

public class Owner {

	
	private String firstName;
	private String lastName;
	private String phone;
	
	private ArrayList<Animal> animals=new ArrayList<Animal>();
	
	public Owner(String firstName,String lastName,String phone)
	{
		this.firstName=firstName;
		this.lastName=lastName;
		this.phone=phone;
	}
	
	public String getFirstName() {
		return this.firstName;
	}
	
	public void setFirstName(String value) 
	{
		this.firstName=value;
	}
	
	
	public ArrayList<Animal> getAnimals(){
		
		return this.animals;
		
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getPhone() {
		return phone;
	}

	public void setPhone(String phone) {
		this.phone = phone;
	}
	
	
	public void addAnimal(Animal animal) {
		//o1.animals.add(a1);
		//this=object.field 
		this.animals.add(animal);
		
		//a1.owner=o1;
		animal.setOwner(this);
	}
	
	
	public void printInfo() {
		
		for(Animal tempAnimal:this.animals)
		{
			System.out.println(tempAnimal.getName());
		}
	}
	
	
	
}
