import sys
from Validation import readFile,validation,writeFile
from Tree import treeNode
from Algorithms import depthFirstSearch,bestFirstSearch


def main():
	if validation(len(sys.argv),sys.argv[1]):
		method=sys.argv[1]
		state=readFile(sys.argv[2])
		outFile=sys.argv[3]
		#Start the round:
		solver(method,state[1:],outFile)


def solver(method,state,outFile):	
	root=treeNode(state,None)
	win=False
	
	if method=='depth':
		movesToWin,executionTime,win=depthFirstSearch(root)
	else:
		movesToWin,executionTime,win=bestFirstSearch(root)
	
	if win:
		writeFile(movesToWin,executionTime,outFile)
	else:
		print('Number of nodes reviewed:',len(movesToWin))	
	

