import java.math.BigDecimal;
import java.math.BigInteger;
import java.math.MathContext;
import java.math.RoundingMode;
import java.util.ArrayList;

public class Tree {
	static BigDecimal goal_number=Main.goal_number;
	
	BigDecimal state;
	Tree parent;
	ArrayList<Tree> children=new ArrayList<Tree>();
	String move="";
	int depth;
	
	public Tree(BigDecimal state,Tree parent) {
		this.state=state;
		this.parent=parent;
		this.depth=this.calculateDepth();
	}
	
	public boolean isInteger() {
		BigDecimal bd1=this.state;
		BigDecimal bd2=new BigDecimal(this.state.setScale(0, RoundingMode.FLOOR).unscaledValue());
        BigDecimal bd3=bd1.subtract(bd2).abs(new MathContext(9));
        //if return true , the number is not integer.
        return bd3.compareTo(new BigDecimal("0.00000001")) ==1;
            
	}
		
	public boolean overLimit() {
		BigDecimal bd1=this.state;
		BigDecimal bd2=new BigDecimal("9999");
		return bd1.compareTo(bd2) <0 ;
	}
	
	
	public boolean win() {
		return this.state.compareTo(goal_number)==0;
		
	}
	
	public Tree moveFactorial() {
			Tree child=new Tree(new BigDecimal(factorialHavingLargeResult(this.state.intValue())),this);
			child.move="factorial";
			return child;	
		
	}
	
	public Tree moveRoot() {
		Tree child=new Tree(this.state.sqrt(new MathContext(3)),this);
		child.move="root";
		return child;
	}
	
	
	public Tree moveFloor() {
		Tree child=new Tree(new BigDecimal(this.state.setScale(0, RoundingMode.FLOOR).unscaledValue()),this);
		child.move="floor";
		return child;
	}
	
	
	public void expandNode() {
		
		if (!this.isInteger() && this.overLimit())
			this.children.add(this.moveFactorial());
		if(this.isInteger())
			this.children.add(this.moveFloor());
		
		this.children.add(this.moveRoot());	
			
	}
	
	
	public static BigInteger factorialHavingLargeResult(int n) {
	    BigInteger result = BigInteger.ONE;
	    for (int i = 2; i <= n; i++)
	        result = result.multiply(BigInteger.valueOf(i));
	    return result;
	}
	
	
	public int calculateDepth() {
		int depth=0;
		Tree currentNode=this;
		while(currentNode.parent!=null)
		{
			depth++;
			currentNode=currentNode.parent;
			
		}
		return depth;
		
	}
	
	
		

}
