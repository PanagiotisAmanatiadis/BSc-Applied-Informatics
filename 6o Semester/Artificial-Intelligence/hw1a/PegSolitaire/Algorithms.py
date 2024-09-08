import time
timeLimit=60


def depthFirstSearch(root):
    print('Depth First search...')
    start=time.time()
    stack=[root]
    childrenToBeAdded=list()
    movesToWin=list()
    executionTime=time.time()-start
    while len(stack)>0 and executionTime<timeLimit:
        currentNode=stack.pop(0)
        childrenToBeAdded.clear()
        movesToWin.append(currentNode.move)
		
        if currentNode.win():
            executionTime=time.time()-start
            return movesToWin,executionTime,True
        
        currentNode.expandNode()
        
        childrenToBeAdded=[child for child in currentNode.children]
        childrenToBeAdded.reverse()
        
        for child in  childrenToBeAdded:
            stack.insert(0,child)
        
        executionTime=time.time()-start
             
    print('The DFS algorithm failed to solve the problem within 1 minutes.')
    return movesToWin,executionTime,False


def bestFirstSearch(root):
    print('Best First search...')
    start=time.time()
    notVisitedList=[root]
    movesToWin=list()
    executionTime=time.time()-start
    while len(notVisitedList)>0 and executionTime<timeLimit:
        currentNode=notVisitedList.pop(0)
        movesToWin.append(currentNode.move)
  
        if currentNode.win():
            executionTime=time.time()-start
            return movesToWin,executionTime,True

        currentNode.expandNode()
        
        notVisitedList=notVisitedList+[child for child in currentNode.children]
        
        notVisitedList.sort(key=lambda Node:Node.bestFirstScore)
        
        executionTime =time.time()-start

    print('The algorithm best first search failed to solve the problem within 1 minutes.')
    return movesToWin,executionTime,False
    

