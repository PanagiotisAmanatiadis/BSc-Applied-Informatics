package test2023;

import java.util.ArrayList;

public class Provider {

	
	private String name;
	
	private ArrayList<Subscriber> subscribers =new ArrayList<Subscriber>();
	
	public Provider(String name)
	{
		this.name=name;
	}
	
	
	public void addSubscriber(Subscriber r)
	{
		this.subscribers.add(r);
	}
	
	
	public double calculateTotalNetEnergy()
	{
		double sum=0;
		
		for(Subscriber tempSub:this.subscribers)
		{
			sum+=tempSub.calculateNetEnergy();
			
		}
		
		return sum;
		
	}


	public String getName() {
		return name;
	}


	public void setName(String name) {
		this.name = name;
	}


	public ArrayList<Subscriber> getSubscribers() {
		return subscribers;
	}


	public void setSubscribers(ArrayList<Subscriber> subscribers) {
		this.subscribers = subscribers;
	}
	
	
	
	
}
