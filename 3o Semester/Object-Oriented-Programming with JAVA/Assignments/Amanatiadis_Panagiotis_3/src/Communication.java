
public abstract  class Communication {
 
	protected String num1;
	protected String num2;
	protected int year;
	protected int month;
	protected int day;
	
	//CONSTRUCTOR
	public Communication(String num1,String num2,int day,int month,int year)
    {
    	this.num1=num1;
  	  this.num2=num2;
  	  this.day=day;
  	  this.month=month;
  	  this.year=year;
	  
  }
	
	
	
	//GETTERS AND SETTERS
	
  public  String getNum1()
  {
  return num1;
  }
	
	public void setNum1(String num1) {
		this.num1 = num1;
	}
	public  String getNum2()
	{
		return num2;
	}
	
	
		
	
	public void setNum2(String num2) {
		this.num2 = num2;
	}
	public int getYear() {
		return year;
	}
	public void setYear(int year) {
		this.year = year;
	}
	public int getMonth() {
		return month;
	}
	public void setMonth(int month) {
		this.month = month;
	}
	public int getDay() {
		return day;
	}
	public void setDay(int day) {
		this.day = day;
	}
	
    
    
   //Polumorfikh methodos printInfo gia thn emfanish idiothtwn kathe epikoinwnias
  public void printInfo()
  {
    System.out.println("Between " +num1 +" --- "+num2);
	System.out.println("on "+year+"/"+month+"/"+day);
	
  }

  //Abstracts methods
  abstract public int  getDuration();
  abstract public String getContentSMS();
  

  
  
	
}
