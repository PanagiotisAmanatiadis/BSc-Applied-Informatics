import java.math.BigDecimal;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;
import java.io.FileWriter;
import java.io.IOException;


public class Main {
	
	static String method;
	static BigDecimal goal_number;
	static ArrayList<String> moves;
	
	
	public static void main(String[] args) {
		
		readData();
		Tree root=new Tree(new BigDecimal("4"),null);
		solver(root);
		writeFile(moves);
		
	}
	
	
	
	public static void readData() {
		Scanner myObj = new Scanner(System.in);  // Create a Scanner object
		ArrayList<String> methods= new ArrayList<String>(Arrays.asList("BFS","ID")); 
		System.out.println("Give solution method(BFS or ID), goal number(int):");
		method=myObj.nextLine();
		goal_number=new BigDecimal(myObj.nextLine());
		
		if (!methods.contains(method.toUpperCase())) {
			System.out.println("Method incorrect");
			System.exit(1);
		}
		
	}
	
	
	
	
	public static void writeFile(ArrayList<String> moves) {
		try {
			
			if(moves.size()>0)
			{
				FileWriter myWriter=new FileWriter("example.txt");
				myWriter.write("Total sum of movements to find goal_number:"+String.valueOf(moves.size()-2)+", time: "+moves.get(moves.size()-1) +" milliseconds " );
			
			
				for(String m:moves)
				{
					if(!m.equals(moves.get(moves.size()-1)) || m.equals(""))
						myWriter.write(m +" \n");	
				}
			
				myWriter.close();
			}
		}
		catch(IOException e)
		{
			System.out.println("An error occurred.");
		}
		
		
	}


	
	public static void solver(Tree root) {
		if(method.equals("bfs"))
			moves=Algorithms.breadthFirstSearch(root);
		else
			moves=Algorithms.iterativeDeepening(root);
				
		
	}
	
	
	

}
