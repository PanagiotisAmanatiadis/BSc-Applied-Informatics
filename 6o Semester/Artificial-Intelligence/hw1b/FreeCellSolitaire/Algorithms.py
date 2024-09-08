import time
timeLimit=300


def breadthFirstSearch(root):
    print('Breadth First search...')
    start=time.time()
    queue=[root]
    visitedList=list()
    visitedSet=set()
    movesToFinish=list()
    loops=0
    executionTime=time.time()-start

    while len(queue) > 0 and executionTime < timeLimit:

        currentNode=queue.pop(0)
        movesToFinish.append(currentNode.move)

        if currentNode==root:
            visitedList.append(currentNode)
            visitedSet.add(currentNode.valueToStr())

        if currentNode.checkIfWin():
            executionTime=time.time()-start
            return movesToFinish,executionTime,True

        allExpandMoves=currentNode.expandNode()

        for index,child in enumerate(currentNode.children):
            if not nodeAlreadyExists(visitedSet, child):
                queue.append(child)
                visitedList.append(child)
                visitedSet.add(child.valueToStr())
                child.move=allExpandMoves[index]

        loops+=1
        executionTime=time.time()-start

    print('The BFS algorithm failed to solve the problem within 5 minutes.')
    return movesToFinish,executionTime,False


def depthFirstSearch(root):
    print('Depth First search...')
    start=time.time()
    stack=[root]
    childrenToBeAdded=list()
    visitedList=list()
    visitedSet=set()
    movesToFinish=list()
    loops=0
    executionTime=time.time()-start

    while len(stack) > 0 and executionTime < timeLimit:
        
        currentNode=stack.pop(0)
        childrenToBeAdded.clear()
        movesToFinish.append(currentNode.move)

        if currentNode==root:
            visitedList.append(currentNode)
            visitedSet.add(currentNode.valueToStr())
        
        if currentNode.checkIfWin():
            executionTime=time.time()-start
            return movesToFinish,executionTime,True

        allExpandMoves=currentNode.expandNode()

        for index, child in enumerate(currentNode.children):
            if not nodeAlreadyExists(visitedSet, child):
                childrenToBeAdded.append(child)
                visitedList.append(child)
                visitedSet.add(child.valueToStr())
                child.move=allExpandMoves[index]

        childrenToBeAdded.reverse()
        for child in childrenToBeAdded:
            stack.insert(0,child)

        loops+=1
        executionTime=time.time()-start

    print('The DFS algorithm failed to solve the problem within 5 minutes.')
    return movesToFinish,executionTime,False


def bestFirstSearch(root):
    print('Best First search...')
    start=time.time()
    notVisitedList=[root]
    visitedList=list()
    visitedSet=set()
    movesToFinish=list()
    loops=0
    executionTime=time.time()-start

    while len(notVisitedList) > 0 and executionTime < timeLimit:

        currentNode=notVisitedList.pop(0)
        movesToFinish.append(currentNode.move)

        if currentNode==root:
            visitedList.append(currentNode)
            visitedSet.add(currentNode.valueToStr())
        
        if currentNode.checkIfWin():
            executionTime=time.time()-start
            return movesToFinish,executionTime,True

        allExpandMoves=currentNode.expandNode()

        for index,child in enumerate(currentNode.children):
            if not nodeAlreadyExists(visitedSet, child):
                notVisitedList.append(child)
                visitedList.append(child)
                visitedSet.add(child.valueToStr())
                child.move=allExpandMoves[index]

        notVisitedList.sort(key=lambda Node: Node.bestFirstScore)

        loops+=1
        executionTime =time.time()-start

    print('The algorithm best first search failed to solve the problem within 5 minutes.')
    return movesToFinish,executionTime,False


def ASearch(root):
    print('A* search...')
    start=time.time()
    notVisitedList=[root]
    visitedList=list()
    visitedSet=set()
    movesToFinish=list()
    loops=0
    executionTime=time.time()-start

    while len(notVisitedList) > 0 and executionTime < timeLimit:

        currentNode=notVisitedList.pop(0)
        movesToFinish.append(currentNode.move)

        if currentNode==root:
            visitedList.append(currentNode)
            visitedSet.add(currentNode.valueToStr())

        if currentNode.checkIfWin():
            executionTime=time.time()-start
            return movesToFinish,executionTime,True

        allExpandMoves=currentNode.expandNode()

        for index,child in enumerate(currentNode.children):
            if not nodeAlreadyExists(visitedSet, child):
                notVisitedList.append(child)
                visitedList.append(child)
                visitedSet.add(child.valueToStr())
                child.move=allExpandMoves[index]

        notVisitedList.sort(key=lambda Node: Node.AScore)
        
        loops+=1
        executionTime=time.time()-start

    print('The Α* algorithm failed to solve the problem within 5 minutes.')
    return movesToFinish,executionTime,False




def nodeAlreadyExists(visitedSet,child):
    return child.valueToStr() in visitedSet



