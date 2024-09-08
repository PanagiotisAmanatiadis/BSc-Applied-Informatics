
import tkinter as tk

### https://www.geeksforgeeks.org/python-programming-language/
### https://www.youtube.com/watch?v=YXPyB4XeYLA

root = tk.Tk() #Create a Gui


label1 = tk.Label(root , text="Hello World!", font=('Arial',18) ) #Create a Label
label2 = tk.Label(root , text="Hello World!", font=('Arial',18) ) #Create a Label

label1.pack()  #Label Appearance
#padx=Additional padding left and right of the text. ,pady=Additional padding above and below the text.
label2.pack(pady=50) #Label Appearance  



textbox1 = tk.Text(root, height=2,font=('Arial',16))  #Create a TextBox
textbox2 = tk.Text(root, height=2,font=('Arial',16))  #Create a TextBox
textbox1.pack()
textbox2.pack(padx=40,pady=20)

myEntry=tk.Entry(root)  #Create an Entry form
myEntry.pack()



def button_event():
    
    label = tk.Label(root,text="Already Clicked")
    label.pack()

    ###Create new GUI
    root1 = tk.Tk()
    textbox = tk.Text(root1,height=2,font=('Arial',16))
    textbox.pack()
    root1.geometry("250x250")
    root1.mainloop()




button1 = tk.Button(root,text="Click Me!",font=('Arial',18) ,command=button_event) #Create a Button
button1.pack(padx=10,pady=10)
    


root.geometry("500x500")    #Set size
root.title("My First GUI")  #Set title
root.mainloop()             #Gui Appearance ,Every Gui needs that command







