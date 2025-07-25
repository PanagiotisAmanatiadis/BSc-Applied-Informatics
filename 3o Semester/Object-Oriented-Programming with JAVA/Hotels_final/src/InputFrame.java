import java.awt.Color;
import java.awt.Component;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.ObjectInputStream;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.BorderFactory;
import javax.swing.BoxLayout;
import javax.swing.DefaultListModel;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JTextField;


public class InputFrame extends JFrame {
	
	private JPanel panel;
	private JPanel diamoniPanel;
	private JPanel allInclusivePanel;
	private JPanel buttonPanel;
	
	private JLabel diamoniLabel;
	private JLabel hotelLabel;
	private JLabel allInclusiveLabel;
	
	private JList listView;
	private DefaultListModel model;
	
	private JTextField daysField;
	private JTextField mealsField;
	
	private JButton storeButton;
	private JButton calculateCostButton;
	
	private JTextField costField;
    
	
	private ArrayList<Hotel> hotels=new ArrayList<Hotel>();
	
	
	public InputFrame() {
		
		
		File file = new File("hotels.ser");
		try {
			FileInputStream fileIn = new FileInputStream(file);
			ObjectInputStream in = new ObjectInputStream(fileIn);
			
			hotels = (ArrayList<Hotel>) in.readObject();
			
			in.close();
			fileIn.close();
			
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (ClassNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
		
		Collections.sort(hotels);
		
		
		
		panel = new JPanel();
		diamoniPanel = new JPanel();
		allInclusivePanel = new JPanel();
		buttonPanel = new JPanel();	
		
		listView = new JList();
		model = new DefaultListModel();
		for(Hotel tempHotel:hotels)
			model.addElement(tempHotel.getName());
	
		listView.setModel(model);
		
		
		
		
		
		diamoniLabel = new JLabel("Stoixeia Diamonis");
		hotelLabel = new JLabel("Hotel");
		allInclusiveLabel = new JLabel("AllInclusive");
		
		daysField = new JTextField("Hmeres Diamonis");
		mealsField = new JTextField("Plithos Geumatwn (1,2,3)");
		costField = new JTextField("Synoliko Kostos");
		
		storeButton = new JButton("Apothikeusi Kratisis");
		calculateCostButton = new JButton("Ypologismos Kostous");
		
		diamoniPanel.setLayout(new BoxLayout(diamoniPanel, BoxLayout.Y_AXIS));
		diamoniLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
		diamoniPanel.add(diamoniLabel);
		hotelLabel.setAlignmentX(Component.CENTER_ALIGNMENT);
		diamoniPanel.add(hotelLabel);
		diamoniPanel.add(listView);
		diamoniPanel.add(daysField);
		diamoniPanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		allInclusivePanel.setLayout(new GridLayout(2,0));
		allInclusivePanel.add(allInclusiveLabel);
		allInclusivePanel.add(mealsField);
		allInclusivePanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		buttonPanel.setLayout(new GridLayout(2,0));
		buttonPanel.add(storeButton);
		buttonPanel.add(calculateCostButton);
		buttonPanel.setBorder(BorderFactory.createLineBorder(Color.black));
		
		panel.add(diamoniPanel);
		panel.add(allInclusivePanel);
		panel.add(buttonPanel);
		panel.add(costField);
		
		ButtonListener listener = new ButtonListener();
		CalculateListener listener2 = new CalculateListener();
		storeButton.addActionListener(listener);
		calculateCostButton.addActionListener(listener2);
		
		
		this.setContentPane(panel);
		
		this.setVisible(true);
		this.setSize(200, 320);
		this.setLocation(200, 0);
		this.setTitle("Input");
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
	}
	
	class ButtonListener implements ActionListener {
		public void actionPerformed(ActionEvent e) {
			
			
			String selectedHotelName="";
			Hotel selectedHotel = null;
			
			Reservation r=null;
			
			
			if(e.getSource().equals(storeButton))
			{
				selectedHotelName = (String)listView.getSelectedValue();
				
				for(Hotel tempHotel:hotels)
				{
					if(selectedHotelName.equals(tempHotel.getName()))
						selectedHotel=tempHotel;
				}
				
				
				int days=Integer.parseInt(daysField.getText());
				int meals=Integer.parseInt(mealsField.getText());
				
				
				if(meals==0)
					r=new Reservation(days);
				else
					r=new AllInclusive(days,meals);
				
				
				
				
		    }
			
			
		
			
			
			
			
			
		}
	}
	
	
	class CalculateListener  implements ActionListener {

		@Override
		public void actionPerformed(ActionEvent e) {
			
			String selectedHotelName="";
			Hotel selectedHotel = null;
			
			Reservation r=null;
			int totalCost=0;
			
			if(e.getSource().equals(calculateCostButton))
			{
				
				selectedHotelName=(String)listView.getSelectedValue();
				
				for(Hotel tempHotel:hotels)
				{
					if(selectedHotelName.equals(tempHotel.getName()))
						selectedHotel=tempHotel;
				}
				
				
				int days=Integer.parseInt(daysField.getText());
				int meals=Integer.parseInt(mealsField.getText());
				
				
				if(meals==0)
					r=new Reservation(days);
				else
					r=new AllInclusive(days,meals);
				
				
				selectedHotel.AddReservation(r);
				
				totalCost=selectedHotel.getTotalCost();
				
				
				costField.setText(""+totalCost);
				
			}
			
		}
		
		
		
	}
	
	
	
	

}
