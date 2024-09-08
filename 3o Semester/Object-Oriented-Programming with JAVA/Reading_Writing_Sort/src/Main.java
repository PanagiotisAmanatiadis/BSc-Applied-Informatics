import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.io.ObjectOutputStream;
import java.util.ArrayList;
import java.util.Collections;



public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//Sou dinei etoimo auto to duadiko arxeio sth main
		Hotel h1 = new Hotel("Bellevue",1920);
		Hotel h2 = new Hotel("Hermes",1800);
		Hotel h3 = new Hotel("CityHotel",1760);
		Hotel h4 = new Hotel("Panorama",2010);
		
		ArrayList<Hotel> hotels = new ArrayList<Hotel>();
		hotels.add(h1);
		hotels.add(h2);
		hotels.add(h3);
		hotels.add(h4);
		
		try {
			FileOutputStream fileOut = new FileOutputStream("hotels.ser");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(hotels);
			out.close();
			fileOut.close();		
		}
		catch(IOException i) {
			i.printStackTrace();
		}
		
		
		//Prepei na to diabaseis sto constructor tou gui sou eno panw diloneis thn arrayList
		//auto to kaneis gia na mporeis na pareis ta hotels object
		ArrayList<Hotel> hotels1=new ArrayList<Hotel>();
		File file = new File("hotels.ser");
		try {
			FileInputStream fileIn = new FileInputStream(file);
			ObjectInputStream in = new ObjectInputStream(fileIn);
			
			hotels1 = (ArrayList<Hotel>) in.readObject();
			
			in.close();
			fileIn.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		
		//Sort ArrayList:
	
		//for(Hotel tempHotel:hotels1)
		//	System.out.println(tempHotel.getName());
		
		//System.out.println();
		//Collections.sort(hotels1);
		
		//for(Hotel tempHotel:hotels1)
		//	System.out.println(tempHotel.getName());
		
		
		for(Hotel tempHotel:hotels1)
					System.out.println(tempHotel.getName()+" "+tempHotel.getAge());
				
		System.out.println();
		Collections.sort(hotels1);
				
		for(Hotel tempHotel:hotels1)
			System.out.println(tempHotel.getName()+" "+tempHotel.getAge());
		
		
		
		
		//Γράψιμο σε αρχείο txt.
		try {
			FileWriter myWriter=new FileWriter("output.txt");
			
			myWriter.write("City: Thessaloniki"+"\n");
			myWriter.write("Onoma: Vasilis"+"\n");
			myWriter.write("Age: 23");
			
			myWriter.close();
			
			
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		
		
		
	}

}
