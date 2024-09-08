

"""
1.Lists

list is a sequence that contains different types of elements. It is a changeable collection and allows duplicate members.

table=list() or table=[] is an empty list
table=[1,2.33,False,'panagiotis',None,True]

table[0]
table[:2] 
len(table)
table+[2,3]
table[-1] that command returns the most recent element 
table[0]=100


#Some basics methods:

table.append(element)
table.insert(i,element)
table.extend([2,3,True])
table.remove(element) #error if the element is not in the table
table.pop() #delete the most recent element
table.pop(i) #delete the element in the 'i' position of the table
table.index(element) # error if the element is not in the table
table.count(element)
table.sort() Sorts the list
table.reverse() Reverses the order of the list

loop lists:
1.
for var in table:
	code

2.
for i in range(0,len(table)):
	code

3.List Comprehension

new_table=[var for var in table]
new_table=[var for var in table if var>10]
new_table=[var if >10 else var-2 for var in table]



2.Tuples
A tuple is unchangeable, thus we can not add or remove any item after created it.
For this reason we often don't use a tuple.

table=tuple() or table=() is an empty tuple
table=(1,2,3,False,True,None,'panagiotis')

table[0]
table[-1]
table[:3]
table[0]=100  -> error

loop is same with a loop of list.



"""