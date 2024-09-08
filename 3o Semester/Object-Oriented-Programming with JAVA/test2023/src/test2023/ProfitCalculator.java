package test2023;

import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.ArrayList;
import java.util.HashMap;

import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;

public class ProfitCalculator extends JFrame {
	
	private JPanel panel = new JPanel();
	private JList<String> providersList = new JList<>();
	private DefaultListModel<String> providerModel = new DefaultListModel<>();
	
	private JButton profitButton = new JButton("Calculate Provider Profit");
	
	private JTextField profitTextField = new JTextField("calculated profit");
	
	
	private HashMap<String,String> results;
	private ArrayList<Provider> providers;
	
	public ProfitCalculator(HashMap<String,String> r,ArrayList<Provider> p) {
		
		results=r;
		providers=p;
		
		
		for(String key:results.keySet())
			providerModel.addElement(key);
		
		providersList.setModel(providerModel);
			
		panel.add(providersList);
		panel.add(profitButton);
		panel.add(profitTextField);
		
		ButtonListener listener =new ButtonListener();
		profitButton.addActionListener(listener);
		
		this.setContentPane(panel);
		
		this.setVisible(true);
		this.setSize(400, 400);
		this.setTitle("Profit Calculator");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	
	
	
	class ButtonListener implements ActionListener{

		
		public void actionPerformed(ActionEvent e) {
			
			
				
			
			
			if(e.getSource().equals(profitButton))
			{
				Provider p=null;
				String selectedProvider=(String)providersList.getSelectedValue();
				
				for(Provider tempP:providers)
				{
					if(selectedProvider.equals(tempP.getName()))
						p=tempP;
				}
				
				profitTextField.setText(""+p.calculateTotalNetEnergy() * (Double.parseDouble(results.get(selectedProvider))));
				
			}
				
		}
		
	}
	
}
