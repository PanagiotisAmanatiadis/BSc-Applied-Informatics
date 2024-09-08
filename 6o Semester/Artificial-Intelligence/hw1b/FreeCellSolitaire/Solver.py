import sys
from Validation import readFile,validation,writeFile
from treeClass import treeNode
from Algorithms import breadthFirstSearch,depthFirstSearch,bestFirstSearch,ASearch

def solver(method,tableau,outFile):
	#Initialize data.
	foundation=[['H0'],['S0'],['D0'],['C0']]
	freeCells=[None,None,None,None]
	root=treeNode(tableau,foundation,freeCells,None)
	win=False
	
	if method=='breadth':
		movesToFinish,executionTime,win=breadthFirstSearch(root)
	elif method=='depth':
		movesToFinish,executionTime,win=depthFirstSearch(root)
	elif method=='best':
		movesToFinish,executionTime,win=bestFirstSearch(root)
	else:
		movesToFinish,executionTime,win=ASearch(root)
	
	if win:
		writeFile(movesToFinish,executionTime,outFile)
    
def main():
	if validation(len(sys.argv),sys.argv[1]):
		method=sys.argv[1]
		tableau=readFile(sys.argv[2]) 
		outFile=sys.argv[3]
		#Start the round:
		solver(method,tableau,outFile)
		
		
	