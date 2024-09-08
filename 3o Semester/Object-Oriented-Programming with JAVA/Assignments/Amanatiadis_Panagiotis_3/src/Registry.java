

import java.util.ArrayList;

public class Registry {

	//ArrayList pou periexei olous tous Suspect
	private ArrayList<Suspect>Susp=new ArrayList<Suspect>();
	
	//ArrayList pou periexei oles tis Communication 
	private ArrayList<Communication>Comms=new ArrayList<Communication>();
	
	
	//ArrayList pou dhmiourgeitai gia thn epistrofh listas SMS
	protected ArrayList<SMS> listOfSMS=new ArrayList<SMS>();
	
	//Methodos pou epistrefei olous tous Suspects
	public ArrayList<Suspect> getSuspectList()
	{
		return Susp;
	}
	
	
	//ADDSUSPECT
	public void addSuspect(Suspect aSuspect)
	{
		Susp.add(aSuspect);
	}
	
	
	//ADDCOMUNICATION
	public void addCommunication(Communication aCommunication)
	{
		    Comms.add(aCommunication);
		    String number1=aCommunication.num1;
		    String number2=aCommunication.num2;
		    Suspect s1;
		    Suspect s2;
		    for(Suspect x: Susp)
		    {
		    	
		    	if(x.listNumber.contains(number1))
		    	{
		    		 s1=x;
		    		
		    		 for(Suspect c: Susp)
				    	{
				    		if(c.listNumber.contains(number2))
					    	{
					    		s2=c;
					    		s1.addCollaborators(s2);
						    	 s2.addCollaborators(s1);
					    	 
					    	}
				
				    	}
		    }
		  }
	}
		    	 
		    	
		    
		    
		    
	
	
	
	
	
	
	
	
	
	
	//GetSuspectWithMostPartners,euresh tou suspect me tous perissoterous sunergates
	public Suspect getSuspectWithMostPartners()
	{
		int max = 0 ;
		Suspect s=new Suspect();
		boolean flag=true;
		for(Suspect x: Susp)
		{
			if(flag)
			{
				flag=false;
				max=x.getSizelist();
				s=x;
				
				
			}
			if(x.getSizelist()>= max)
			{
				max=x.getSizelist();
				s=x;
				
			}
			
		}
		return s;
		
	}
	
	
	
	
	 
	//Euresh ths megaluterhs thlefwnikis klhshs metaksu 2 ari8mwn,GetLongestPhoneCallBetween
	public PhoneCall getLongestPhoneCallBetween(String number1,String number2)
	{
		PhoneCall MaxPhoneCall= new PhoneCall(" "," ",0,0,0,0);
	boolean flag=true;
		int max=0;
		
		for(Communication x: Comms)
		{
			
			if((x.num1.equals(number1)|| x.num1.equals(number2))&& (x.num2.equals(number2)|| x.num1.equals(number1)) && flag && x.getDuration()>0)
			{
				max=x.getDuration();
				MaxPhoneCall=(PhoneCall)x;
				flag=false;
			}
			if((x.num1.equals(number1)|| x.num1.equals(number2))&& (x.num2.equals(number2)|| x.num1.equals(number1)) && x.getDuration()>=max)
			{
				max=x.getDuration();
				MaxPhoneCall=(PhoneCall)x;
			}
	   }
		return MaxPhoneCall;
	
	
	}
	
	
	
	
	//Euresh lisas SMS pou na periexei mhnuma "Bomb" ,"Attack","Gun","Explosives"
	public ArrayList<SMS> getMessagesBetween(String number1,String number2)
	{
	    SMS s=new SMS(" "," ",0,0,0," ");
		for(Communication x: Comms)
		{
			if((x.num1.equals(number1) || x.num1.equals(number2)) &&(x.num2.equals(number2) || x.num2.contentEquals(number1)))
            { 
               if(x.getContentSMS()!=null)
               {
            	if(x.getContentSMS().contains("Bomb") || x.getContentSMS().contains("Attack") || x.getContentSMS().contains("Gun") || x.getContentSMS().contains("Explosives"))
            	{
            		s=(SMS)x;
            		listOfSMS.add(s);
            		
            	}
               }
            	
	        }

                   

		}
		return listOfSMS;
		
	}
	
	
	
	//Emfanish twn upoptwn pou katagontai apo mia sugkekrimenh xwra 
	public void printSuspectsFromCountry(String country)
	{
		for(Suspect s: Susp)
		{
			if(s.getCountry().equals(country))
			{
				System.out.println(s.getName() +" ("+s.getCodeName()+")");
			}
		}
	}
	
		
}
	
		
		
		
	
	
	

