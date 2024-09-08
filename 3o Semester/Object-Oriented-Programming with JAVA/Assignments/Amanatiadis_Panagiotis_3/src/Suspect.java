
import java.util.ArrayList;

public class Suspect {
  
	private String Name;
	private String CodeName;
	private String country;
	private String city;
	//Array List pou apothikeuei tous thlefwnikous arithmous kathe Suspect
	protected ArrayList<String>listNumber=new ArrayList<String>();
	//ArrayList pou apothikeuei tous pithanous sunergates gia kathe Suspect
	private ArrayList<Suspect> Suspects=new ArrayList<Suspect>();
	
	//ArrayList pou apothikeuei tous proteinomenous pithanous sunergates gia kathe Suspect
	private ArrayList<Suspect> SuggestedPartners=new ArrayList<Suspect>();
	
	
	private Registry R1;
	
	//ArrayList pou apothikeuei tous pithanous koinous sunergates meta Suspect
	private ArrayList<Suspect> S=new ArrayList<Suspect>();
	
	
	
	//CONSTRUCTORs
	public Suspect()
	{}
	
	public Suspect(String Name,String CodeName,String country,String city)
	{
		this.Name=Name;
		this.CodeName=CodeName;
		this.country=country;
		this.city=city;
	}
	
	
	//GETTERS AND SETTERS
	public String getName() {
		return Name;
	}


	public void setName(String name) {
		Name = name;
	}


	public String getCodeName() {
		return CodeName;
	}


	public void setCodeName(String codeName) {
		CodeName = codeName;
	}


	public String getCountry() {
		return country;
	}


	public void setCountry(String country) {
		this.country = country;
	}


	public String getCity() {
		return city;
	}


	public void setCity(String city) {
		this.city = city;
	}
	
	//Getter pou epistrefei to megethos ths listas me tous sunergates kathe Suspect
	public int getSizelist()
	{
		return Suspects.size();
		
	}
	
	//Getter pou epistrefei ArrayList me tous sunergates tou kathe Suspect
	public ArrayList<Suspect> getList()
    {
	return Suspects;
    }
	//Return listNumber
	public ArrayList<String> getNumberList()
	{
		return listNumber;
	}
	
	
    
	//Pros8iki enos arithmou sthn lista thlefwnikwn arithmwn kathe Suspect
	public void addNumber(String number)
	{
	   if(listNumber.contains(number))
	   {
		   System.out.println("this subject is already on the list");
		   
		}
	   else
		{
		  listNumber.add(number);
		
		}
	} 
	
	
	
	//Pros8iki pithanou sunergath sth lista pithanwn sunrgatwn kathe Suspect
	public void addCollaborators(Suspect aSuspect)
	{
		
         if(!Suspects.contains(aSuspect))
         {
        	 
        	 Suspects.add(aSuspect);
         }
         
			 
	}
	
	
	
	
	
	//Epistrofh boolean timh gia to an duo Suspect einai sundedemenoi metaksu tous
	public boolean isConnectedTo(Suspect aSuspect)
	{
		if(Suspects.contains(aSuspect))
		    return true;
		return false;
	}
		
	
	
	
	//Euresh listas me tous koinous sunergates metaksu duo SUSPECT
	public ArrayList<Suspect> getCommonPartners(Suspect aSuspect)
	{
		ArrayList<Suspect>list2=aSuspect.getList();
		for(Suspect x: Suspects)
		{
			
			for(Suspect s: list2)
			{
				if(x.equals(s))
				{
					S.add(x);
				}
			}
			
			
		}
	         return S;
	       	
	}
	
	
	
		
		
		
		
		
		//Emfanish me * meta to codename kathe sunergath an katagetai apo thn idia Xwra
	public void printAll()
	{
		for(Suspect x: Suspects)
		{
			
			
			if((this).getCountry().equals(x.getCountry()))
			{
			 System.out.println("Name: "+x.getName());
			 System.out.println("CodeName: "+x.getCodeName()+"*");
			}
			else
			{System.out.println("Name: "+x.getName());
			 System.out.println("CodeName: "+x.getCodeName());
			}
			
		}
	}
	
	
	public ArrayList<Suspect> getSuggestedPartners()
	{
		
		for(Suspect x: Suspects)
		{
			for(Suspect s: x.getList())
			{
				if(!Suspects.contains(s) && !(this==s))
				{
					SuggestedPartners.add(s);
					
				}
		   
			  
		   
			}
		  
		}
		return SuggestedPartners;
		
	}
	
	
	
	
	
	
}
