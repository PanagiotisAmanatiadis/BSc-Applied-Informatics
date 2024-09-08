from tkinter import *
import tkinter as tk

root = Tk()
root1 = tk.Tk()


#root Gui
Lb1 = Listbox(root)
Lb1.insert(1,"PHP")
Lb1.insert(2,"Python")
Lb1.insert(3,"Java")
Lb1.insert(4,"SQL")
Lb1.pack(pady=15)


#root1 Gui

Lb2=tk.Listbox(root1)

Lb2.insert(1,"NoSQL")
Lb2.insert(2,"Android")
Lb2.pack(pady=15)


#Lb1.delete(index)
#Lb1.size()
#Lb1.get(index)

def delete():
    Lb1.delete(ANCHOR)
    Lb2.delete(ANCHOR)

def select():
    my_label1.config(text=Lb1.get(ANCHOR))
    my_label2.config(text=Lb2.get(ANCHOR))


#root
deleteButton = Button(root,text="Delete", command=delete)
deleteButton.pack(pady=10)

selectButton = Button(root,text="Select", command=select)
selectButton.pack(pady=10)


#root1
dButton = tk.Button(root1,text="Delete" ,command=delete)
dButton.pack(pady=10)

sButton = tk.Button(root1,text="Select",command=select)
sButton.pack(pady=15)


global my_label1
my_label1 = Label(root,text='')
my_label1.pack(pady=5)

global my_label2
my_label2 = tk.Label(root1,text='')
my_label2.pack(pady=5)




root.geometry("400x400")
root.mainloop()


root1.geometry("400x400")
root1.mainloop()