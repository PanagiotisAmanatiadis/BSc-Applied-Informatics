
public class PhoneCall extends Communication {

	protected String num1;
	private String num2;
	private int year;
	private int month;
	private int day;
	private int duration;
	
	
	//CONSTRUCTOR
	public PhoneCall(String num1,String num2,int day,int month,int year,int duration)
	{
		
	    super(num1,num2,day,month,year);
		this.duration=duration;
	}
	
	
	//GETTERS AND SETTERS
	public String getContentSMS()
	{
		return " ";
	}
	
	public  String getNum1() {
		return num1;
	}
	public void setNum1(String num1) {
		this.num1 = num1;
	}
	public  String getNum2() {
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
	public int getDuration() {
		return duration;
	}
	public void setDuration(int duration) {
		this.duration = duration;
	}
	
	
	//Polumorfikh methodos printInfo gia emfanish twn periexomenwn mias thlefwnikhs klhsh
	public void printInfo()
	{
		System.out.println("This phone call has the following info");
		super.printInfo();
		System.out.println("Duration: " +duration);
	}
	
}


