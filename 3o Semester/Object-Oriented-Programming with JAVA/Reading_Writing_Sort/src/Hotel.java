import java.io.Serializable;

public class Hotel implements Serializable,Comparable<Hotel> {

	
	private String name;
	private int age;
	
	public Hotel(String name,int age) {
		this.name=name;
		this.age=age;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	
	public int getAge() {
		return age;
	}

	public void setAge(int age) {
		this.age = age;
	}

	
	public int compareTo(Hotel h) {
		
	
	
	/*	
	//Ταξινόμηση by String Field φθίνουσα.
	return h.name.compareTo(this.name);
	
	Ταξινόμηση by String Field αύξουσα
	return this.name.compareTo(h.name);
	
	*/	
    //Αν θέλουμε με αύξουσα μικρότερο προς μεγαλύτερο στο else if ->return -1 και στο else return 1.
	//Αλλιώς αν θέλουμε φθίνουσα στο else if ->return 1 και στο else return -1
	
		
	if(h.age==this.age)
		return 0;
	else if(h.age>this.age)
		return 1;
	else
		return -1;
	
	
	}
	
	
	
}
