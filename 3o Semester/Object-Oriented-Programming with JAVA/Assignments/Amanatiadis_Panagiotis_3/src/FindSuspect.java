
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;

import javax.swing.*;
public class FindSuspect extends JFrame{

	
	private JPanel panel;
	
	private JTextField text;
	
	private JButton button;
	
	private Registry registry;
	
	private ArrayList<Suspect>susp;
	public FindSuspect(Registry r)
	{
		registry=r;
		 susp=r.getSuspectList();
		
		
		panel=new JPanel();
		text = new JTextField("Please enter suspect's name");
		button=new JButton("Find");
		
		
		panel.add(text);
		panel.add(button);
	
		ButtonListener listener=new ButtonListener();
		button.addActionListener(listener);
		this.setContentPane(panel);
		
		
		
		this.setVisible(true);
		this.setTitle("Find Suspect");
		this.setSize(400, 150);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
	}
	
	class ButtonListener implements ActionListener{

	
		public void actionPerformed(ActionEvent e) {
			
			boolean flag=false;
			
			
			String nameFind = text.getText();
			Suspect s=new Suspect();
			
		
			
			if(e.getSource().equals(button))
			{
				//Anazhthsh tou Suspect me onoma pou dinei o xrhsths
			   for(Suspect x: susp)
			    {
				if(x.getName().equals(nameFind))
				{

				   s=x;
				   flag=true;
			    }
		        }
			 
			   if(flag==false)
			   {
				   //Dhmiourgia Frame
				   JFrame frame = new JFrame();
				   JOptionPane.showMessageDialog(frame,  "Suspect " +nameFind +" Not found");
				   
				
			   }
			   else
			   {
				     dispose();
				     new SuspectPage(s,susp,registry);
				     
				     
				     
			    }
		}
	
			
		}
		
}
	
	}

