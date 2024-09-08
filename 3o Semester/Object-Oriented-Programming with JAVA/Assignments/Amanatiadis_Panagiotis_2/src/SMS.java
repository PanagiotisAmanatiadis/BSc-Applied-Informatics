
public class SMS extends Communication {

	private String num1;
	private String num2;
	private int year;
	private int month;
	private int day;
	private String contentSMS;
	
	
	//CONSTRUCTOR
	
	
	public SMS(String num1,String num2,int day,int month,int year,String contentSMS)
	{
		super(num1,num2,day,month,year);
		this.contentSMS=contentSMS;
		
	}
	
	
	
	
	//GETTERS AND SETTERS
	
	public String getNum1() {
		return num1;
	}






	public void setNum1(String num1) {
		this.num1 = num1;
	}






	public String getNum2() {
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






	public String getContentSMS() {
		return contentSMS;
	}






	public void setContentSMS(String contentSMS) {
		this.contentSMS = contentSMS;
	}


	public int getDuration()
	{
		return 0;
	}


  //Polumorfikh methodos printInfo pou emfanizei ta periexomena enos SMS
	public void printInfo()
	{
		System.out.println("This SMS has the following info");
		super.printInfo();
		
		System.out.println("Text: " +contentSMS);
	}
	
	
	
}
