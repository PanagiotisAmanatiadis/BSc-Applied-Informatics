import java.io.Serializable;
import java.util.ArrayList;


public class Hotel implements Serializable,Comparable<Hotel> {
	
	private String name;
	
	private ArrayList<Reservation> reservations=new ArrayList<Reservation>();

	public Hotel(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}
	
	
	public void AddReservation(Reservation r)
	{
		this.reservations.add(r);
	}

	@Override
	public int compareTo(Hotel h) {
		return this.name.compareTo(h.name);
	}
	
	
	public int getTotalCost()
	{
		int sum=0;
		for(Reservation tempReservation:this.reservations)
			sum+=tempReservation.getCost();
		
		return sum;
	}
	
	
}
