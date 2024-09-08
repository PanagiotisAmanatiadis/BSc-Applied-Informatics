package lesson08_test;

import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class City {
	
	private String name;
	private int population;
	
	private ArrayList<Property> properties= new ArrayList<Property>();
	
	public City(String name,int population)
	{
		this.name=name;
		this.population=population;
	}
	
	public void addProperty(Property property)
	{
		this.properties.add(property);
		property.city=this;
	}

	public void printProperties()
	{
		try {
			FileWriter myWriter=new FileWriter("output.txt");
		
			//System.out.println("City: "+this.name);
		    myWriter.write("City: "+this.name+"\n");
			
			for(Property tempProperty:this.properties)
			{
				if(tempProperty instanceof SharedRoom)
					//System.out.println("SharedRoom: "+tempProperty.name+" Tax Rate: "+tempProperty.calculateTaxRate());
				    myWriter.write("SharedRoom: "+tempProperty.name+" Tax Rate: "+tempProperty.calculateTaxRate()+"\n");
				else
					//System.out.println("Property: "+tempProperty.name+" Tax Rate: "+tempProperty.calculateTaxRate());
					myWriter.write("Property: "+tempProperty.name+" Tax Rate: "+tempProperty.calculateTaxRate()+"\n");
				
			}
		    
			myWriter.close();
			
		}catch(IOException e)
		{
			System.out.println(e);
		}
	}
	
	
	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public int getPopulation() {
		return population;
	}

	public void setPopulation(int population) {
		this.population = population;
	}

	public ArrayList<Property> getProperties() {
		return properties;
	}

	public void setProperties(ArrayList<Property> properties) {
		this.properties = properties;
	}

	
	
}
