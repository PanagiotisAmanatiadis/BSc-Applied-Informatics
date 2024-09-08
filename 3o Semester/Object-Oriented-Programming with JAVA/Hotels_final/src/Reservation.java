
public class Reservation {

	
	protected int days;
	
	public Reservation(int days)
	{
		this.days=days;
	}
	
	
	public int getCost()
	{
		return this.days * 120;
	}
}
