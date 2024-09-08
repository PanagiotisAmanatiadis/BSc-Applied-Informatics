
public class AllInclusive extends Reservation {

	
	protected int numberOfMeals;
	
	public AllInclusive(int days,int numberOfMeals) {
		super(days);
		this.numberOfMeals=numberOfMeals;
	}
	
	public int getCost()
	{
		
		return this.days * (120 + this.numberOfMeals * 30);
		
	}
	
	
	
	

}
