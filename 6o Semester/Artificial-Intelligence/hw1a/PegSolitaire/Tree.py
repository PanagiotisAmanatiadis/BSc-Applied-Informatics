import copy
from itertools import chain


class treeNode:
	def __init__(self,state,parent):
		self.state=state
		self.parent=parent
		self.children=list()
		self.move=dict()
		self.bestFirstScore=self.heuristic()
	
	
	def win(self):
		return list(chain.from_iterable(self.state)).count('1')==1
	
	
	def moveToAState(self,move,between):
		stateChild=copy.deepcopy(self.state)
		stateChild[move['x']][move['y']]='2'
		stateChild[between['x']][between['y']]='2' 
		stateChild[move["x'"]][move["y'"]]='1'
		child=treeNode(stateChild,self)
		child.move=move
		return child
	
		
	def expandNode(self):
		tableau=self.state.copy()
		for i in range(0,len(tableau)-1):
			for j in range(0,len(tableau[1])-2):
				
				#check if the peg can move right or left:
				if tableau[i][j]=='1' and tableau[i][j+1]=='1':
					if tableau[i][j-1]=='2' and j-1>=0:
						move={'x':i,'y':j+1,"x'":i,"y'":j-1}
						between={'x':i,'y':j}
						self.children.append(self.moveToAState(move,between))
						
					if tableau[i][j+2]=='2':
						move={'x':i,'y':j,"x'":i,"y'":j+2}
						between={'x':i,'y':j+1}
						self.children.append(self.moveToAState(move,between))
							
				#check if the peg can move to the top:
				if tableau[i][j]=='1' and tableau[i-1][j]=='1' and i-2>=0:
					if tableau[i-2][j]=='2':
						move={'x':i,'y':j,"x'":i-2,"y'":j}
						between={'x':i-1,'y':j}
						self.children.append(self.moveToAState(move,between))
						
				#check if the peg can move to the bottom:
				if tableau[i][j]=='1' and tableau[i+1][j]=='1' and i+2<=len(tableau)-1: 
					if tableau[i+2][j]=='2':
						move={'x':i,'y':j,"x'":i+2,"y'":j}
						between={'x':i+1,'y':j}
						self.children.append(self.moveToAState(move,between))	
	
	
	#f(n)=h(n)=The less the pegs on the board, the better the node.
	def heuristic(self):
		return list(chain.from_iterable(self.state)).count('1')
	
	
		
