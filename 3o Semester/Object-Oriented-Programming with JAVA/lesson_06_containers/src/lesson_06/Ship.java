package lesson_06;

import java.util.ArrayList;

public class Ship {
	
	private int numberOfContainers;
	
	ArrayList<Container> containers=new ArrayList<Container>();
	
	
	public Ship(int numberOfContainers) {
		
		this.numberOfContainers=numberOfContainers;
	}
	
	public void addContainer(Container container)
	{
		if(containers.size() <= this.numberOfContainers)
			this.containers.add(container);
	}
	
	public double getTotalCost()
	{
		double sum=0;
		
		for(Container tempContainer:this.containers)
			sum=sum+tempContainer.getCost();
		
		
		return sum;
	}
	
	
	public void printContainers()
	{
		for(Container tempContainer:this.containers) {
			tempContainer.printInfo();
			
		}
			
	}
	
	
	

}
