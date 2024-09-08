"""

3.Sets

s=set() is an empty set

s={1,3,5,'2','panos'}


s.add(element)
s1.update(s2)   
s1.update(table)
s1.remove(element) -> error if the element is not in the set 
s1.discard(element) 
s1.clear()
del s1
s1.union(s2) -> returns a set with all elements which contains s1 and s2
s1.intersection(s2) -> returns a set with the common elements which there are s1,s2



loop is same with a loop of list.

for var in s1:
	code


4.Dictionaries: 
The keys must be unique.
d={key:value}
d=dict() or d={} is an empty dictionary

Change values:
d[key]=new_value or d.update({key:new_value})

Add new item:
d[new_key]=value or d.update({new_key:value})


Methods:
d.keys()
d.values()
d.items()
d.pop(key)
d.popitem() delete the most recent item(key:value)
d.clear()


Loop dictionaries:
for var in d    the var default is key but we can take value with d[var]
same with 
for var in d.keys()   

for var in d.values()
for var in d.items()  the var is a tuple (key,value)
for key,value in d.items()



#d=dict(name='Panagiotis',age=24,country='Greece')
d={'name':'Panagiotis','age':24,'country':'Greece'}
print(d)
#d={'name':'Panagiotis','age':24,'country':'Greece','name':'Petros'}
#print(d)
print(d['name'])
print(d.get('name'))
d['name']='Nikos'
print(d)
d.update({'name':'Petros'})
print(d)
d['phoneNumber']='6942442120'
print(d)
d.update({'city':'Karditsa'})
print(d)

print(d.keys())
print(d.values())
print(d.items())



"""


