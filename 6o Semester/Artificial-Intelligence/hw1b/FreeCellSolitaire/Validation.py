import sys

def readFile(inputFile):
    try:
        table=[line.replace('\n', '').split() for line in open(inputFile, 'r', encoding='utf-8')]
    except FileNotFoundError:
        print('File not found.\n')
        sys.exit(0)
    else:return table

def checkNumberOfArgs(numberOfArgs):
    if(numberOfArgs!=4):
    	print('You are dont give only three arguments.')
    	return False
    return True

def checkIfCorrectMethod(algorithm_method):
    if algorithm_method in ['breadth','depth','best','astar']:
        return True
    print('This method does not exist.')
    return False

def validation(numberOfArgs,algorithm_method):
    cond1=checkNumberOfArgs(numberOfArgs)
    cond2=checkIfCorrectMethod(algorithm_method)
    return cond1 and cond2

def writeFile(movesToFinish,executionTime,outFile):
    with open(outFile,'w') as f:
        executionTime=round((executionTime/60),2)
        f.write('Total sum of movements to win:'+str(len(movesToFinish))+', needed time to win:' +str(executionTime))
        for move in movesToFinish:
            f.write(move + '\n')


