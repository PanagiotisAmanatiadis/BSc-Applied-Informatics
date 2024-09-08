package lesson_01;

import java.util.ArrayList;

public class Owner {

	
	String firstName;
	String lastName;
	String phone;
	
	ArrayList<Animal> animals=new ArrayList<Animal>();
	
	public Owner(String firstName,String lastName,String phone)
	{
		this.firstName=firstName;
		this.lastName=lastName;
		this.phone=phone;
	}
	
	
	
}
