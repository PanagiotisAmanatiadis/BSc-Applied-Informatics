package lesson_06;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;



public class calculator extends JFrame{
	
	
	private Ship ship;
	
	private JPanel panel;
	
	private JButton button1;
	private JButton button2;
	
	private JTextField text;
	
	
	
	public calculator(Ship s)
	{
		
		ship=s;
		
		panel=new JPanel();
		button1=new JButton("Calculate Charge");
		text=new JTextField();
		text.setText("Total charge for all containers");
		//text.setEditable(false);
		//text.getText(): String -> "55" 
		
		button2=new JButton("Print Containers");
		
		panel.add(button1);//adding button in JPanel
		panel.add(text);
		panel.add(button2);
		
		
		
		
		
		//click event
		ButtonListener listener =new ButtonListener();
		//call method 
		//button.method
		button1.addActionListener(listener);
		button2.addActionListener(listener);
		
		
		
		
		
		//default
		this.setContentPane(panel);
		this.setVisible(true);
		this.setTitle("Charge Calculator");
		this.setSize(400, 180);
		this.setResizable(false);
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		
		
		
	}
	
	
	class ButtonListener implements ActionListener{

		@Override
		public void actionPerformed(ActionEvent e) {
			// TODO Auto-generated method stub
			
			//double or int to string -> ""+number
			if(e.getSource().equals(button1))
				text.setText(""+ship.getTotalCost());
				
			if(e.getSource().equals(button2))
			{
				//more code.
				ship.printContainers();
			}			
			
		}
		
		}
	
	

}
