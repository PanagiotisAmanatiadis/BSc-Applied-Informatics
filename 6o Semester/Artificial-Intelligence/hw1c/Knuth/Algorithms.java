import java.util.ArrayList;
import java.util.Stack;

public class Algorithms {
	static long timeLimit1=60000;
	static long timeLimit2=30000;
	
	
	public static ArrayList<String> breadthFirstSearch(Tree root) {
		long start=System.currentTimeMillis();
		
		ArrayList<String> moves=new ArrayList<String>();
		ArrayList<Tree> queue=new ArrayList<Tree>();
		queue.add(root);
		long executionTime=System.currentTimeMillis()-start;
		
		while(queue.size()>0 && executionTime<=timeLimit1) {
			
			Tree currentNode=queue.remove(0);
			moves.add(currentNode.move);
			
			if (currentNode.win()){
				executionTime=System.currentTimeMillis()-start;
				String time=String.valueOf(executionTime);
				moves.add(time);
				return moves;
			}
			
			currentNode.expandNode();
			for(Tree child: currentNode.children) {
				queue.add(child);
			}
			executionTime=System.currentTimeMillis()-start;
			
			
		}
		System.out.println("The BFS algorithm failed to solve the problem within 60 seconds.");
		System.out.println("Number of movements:"+String.valueOf(moves.size()-1));
		return new ArrayList<String>();
		
	}
	
	
	
	
	public static ArrayList<String> iterativeDeepening(Tree root){
		long start=System.currentTimeMillis();
		ArrayList<String> moves=new ArrayList<String>();
		int depth_limit=1;
		long executionTime=System.currentTimeMillis()-start;
		boolean win=true;
		
		while(win && executionTime<=timeLimit2)
		{
			
			moves=depthFirstSearch(root,depth_limit,executionTime,start);
			if(moves.size()>0)
			{
				
				win=false;
				return moves;
			}
			
			depth_limit++;
			executionTime=System.currentTimeMillis()-start;
			
		}
		
		System.out.println("The ID algorithm failed to solve the problem within 30 seconds.");
		return new ArrayList<String>();
	}
	
	
	
	public static ArrayList<String> depthFirstSearch(Tree root,int depth_limit,long executionTime,long start){
		ArrayList<String> moves=new ArrayList<String>();
		Stack<Tree> stack=new Stack<Tree>();
		stack.push(root);
		
		
		while(stack.size()>0 && executionTime<=timeLimit2)
		{
			Tree currentNode=stack.pop();
			moves.add(currentNode.move);
			
			
			if (currentNode.win()){
				executionTime=System.currentTimeMillis()-start;
				String time=String.valueOf(executionTime);
				moves.add(time);
				return moves;
			}
			
			if(currentNode.depth<=depth_limit && currentNode.depth!=depth_limit) 
			{
				currentNode.expandNode();
				
				for(Tree child: currentNode.children) {
					stack.push(child);
					}	
			}
			
			executionTime=System.currentTimeMillis()-start;
			
		}
		
		return new ArrayList<String>();
	}
	
	
		
	


}
