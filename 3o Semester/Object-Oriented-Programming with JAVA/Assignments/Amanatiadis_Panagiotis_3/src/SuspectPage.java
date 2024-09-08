
import java.awt.Color;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import javax.swing.*;
import javax.swing.border.Border;


public class SuspectPage extends JFrame{
	
	
	

	
	private JPanel panel1;
	private JPanel panel2;
	private JPanel panel3;
	private JPanel panel4;
	private JPanel panel5;
	private JPanel panel6;
	private JPanel FinalPanel;
	
	
	private JScrollPane scrollPane1;
	private JScrollPane scrollPane2;
	private JScrollPane scrollPane3;
	private JScrollPane scrollPane4;
	private JScrollPane scrollPane5;
	

	private  JTextField NameText;
	private JTextField CodeNameText;
	private JTextField NumberText;
	
	
	
	private JLabel Partner=new JLabel("Partners");
	private JLabel SuggestedPartner=new JLabel("Suggested Partners ------>");
	
	private JButton findSMS;
	protected JButton ReturntoFind;
	
	
	
	private JTextArea listNumbers=new JTextArea(3,10);
	private JTextArea Comms=new JTextArea(10,20);
	private JTextArea listPartners=new JTextArea(10,20);
	private JTextArea listSuggestedPartners=new JTextArea(5,20);
	private JTextArea listForCountry=new JTextArea(5,30);
	
	
	//ArrayList pou exei olous tous Suspects
	private ArrayList<Suspect> RForSuspects;
	
	//Kentriko Arxeio ths main.
	private Registry registry;
	
	
	private Suspect suspect;
	
	//ArrayList me tous pithanous Proteinomenous upoptous.
	private ArrayList<Suspect> SuspectsSuggested;
	
	public SuspectPage(Suspect aSuspect,ArrayList<Suspect> Suspects,Registry r)
	{
		
		suspect=aSuspect;
		RForSuspects=Suspects;
		registry=r;
		
		
		panel1=new JPanel();
		panel2=new JPanel();
		panel3=new JPanel();
		panel4=new JPanel();
		panel5=new JPanel();
		panel6=new JPanel();
		
		
		
		FinalPanel=new JPanel();
		
		
	    NameText=new JTextField(10);
		NameText.setText(suspect.getName());
		CodeNameText=new JTextField(10);
		CodeNameText.setText(suspect.getCodeName());
		
		
		//NameText.setEditable(false);
		//CodeNameText.setEditable(false);
		
		ArrayList<String> PhoneNumbers=suspect.getNumberList();
		for(String x: PhoneNumbers)
		{
			listNumbers.append(x+"\n");
		}
		listNumbers.setEditable(false);
		
		NumberText=new JTextField(10);
		findSMS=new JButton("Find SMS");
		
		
		//Sarwnw ths lisa me tous sunergates tou Suspect kai tous pernaw sto JTextArea.
		for(Suspect x: suspect.getList())
		{
			listPartners.append(x.getName() +", " +x.getCodeName() +"\n");
		}
		listPartners.setEditable(false);
		
		
	    SuspectsSuggested=suspect.getSuggestedPartners();
	    
	    //Pernaw tous pithanous proteinomenous upoptous sto JTextArea.
		for(Suspect suspect: SuspectsSuggested)
		{
			listSuggestedPartners.append((String)suspect.getName()+"\n");
		}
		listSuggestedPartners.setEditable(false);
		
		

		String text=("Suspects coming from " +suspect.getCountry());
		listForCountry.append(text +"\n");
		listForCountry.setEditable(false);
		
		
		for(Suspect x: RForSuspects)
		{
			
			if(x.getCountry().equals(suspect.getCountry()))
			{
				listForCountry.append(x.getName() + "\n");
			}
		}
		
		
		ReturntoFind=new JButton("Return to Search Screen");
		
		
		
	    Comms.setEditable(false);
	    
		Border b=BorderFactory.createLineBorder(Color.GRAY);
		
		
		
		
		
		
		panel1.add(NameText);
		panel1.add(CodeNameText);
		panel1.add(listNumbers);
		
		scrollPane1= new JScrollPane();
		scrollPane1.setViewportView(panel1);
		scrollPane1.setVisible(true);
		
		
		
		
		
		
		
		
		Comms.setBorder(b);
		panel2.add(NumberText);
		panel2.add(Comms);
		panel2.add(findSMS);
		
		scrollPane2= new JScrollPane();
		scrollPane2.setVisible(true);
		scrollPane2.setViewportView(panel2);
		
		
	
		
		listPartners.setBorder(b);
		panel3.add(Partner);
		panel3.add(listPartners);
		
		scrollPane3= new JScrollPane();
		scrollPane3.setViewportView(panel3);
		scrollPane3.setVisible(true);
		
		
		listSuggestedPartners.setBorder(b);
		panel4.add(SuggestedPartner);
		panel4.add(listSuggestedPartners);
		
		scrollPane4= new JScrollPane();
		scrollPane4.setViewportView(panel4);
		scrollPane4.setVisible(true);
		
		
		listForCountry.setBorder(b);
		panel5.add(listForCountry);
		
		scrollPane5= new JScrollPane();
		scrollPane5.setViewportView(panel5);
		scrollPane5.setVisible(true);
		
		
		panel6.add(ReturntoFind);
		
		FinalPanel.add(scrollPane1);
		FinalPanel.add(scrollPane2);
		FinalPanel.add(scrollPane3);
		FinalPanel.add(scrollPane4);
		FinalPanel.add(scrollPane5);
		FinalPanel.add(panel6);
		
		
		
		
		
		
		this.setContentPane(FinalPanel);
		
		
		ButtonListener listener =new ButtonListener();
		findSMS.addActionListener(listener);
		ReturntoFind.addActionListener(listener);
		
		
		this.setVisible(true);
		this.setTitle("Suspect Page");
		this.setSize(500, 750);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
		
	}
	
	
 class ButtonListener implements ActionListener{

		
		public void actionPerformed(ActionEvent e) {

			 ArrayList<SMS> SMSlist=new ArrayList<SMS>();
			String Number=NumberText.getText();
			if(e.getSource().equals(findSMS))
			{
				 
				for(String x: suspect.getNumberList())
				{
					 SMSlist=registry.getMessagesBetween(x,Number);
					 
					 
					 for(SMS sms: SMSlist)
					 {
						
						 
						    Comms.append(sms.getContentSMS()+"\n");
						 
						 
						
					 }
					 

					
					  
				}
				 SMSlist.clear();
				
				 
			}
			if(e.getSource().equals(ReturntoFind))
			{
				
				  
			    SuspectsSuggested.clear();
				dispose();
				new FindSuspect(registry);
				
			}
			
			
			
		}
		
	}

}
 