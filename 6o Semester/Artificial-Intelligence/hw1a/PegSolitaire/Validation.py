import sys


def readFile(inputFile):
    try:
        state=[r.replace('\n', '').split() for r in open(inputFile, 'r', encoding='utf-8')]
    except FileNotFoundError:
        print('File not found.\n')
        sys.exit(0)
    else:return state


def checkNumberOfArgs(numberOfArgs):
    if(numberOfArgs!=4):
    	print('You are dont give only three arguments.')
    	return False
    return True


def checkIfCorrectMethod(algorithm_method):
    if algorithm_method in ['depth','best']:
        return True
    print('This method does not exist.')
    return False


def validation(numberOfArgs,algorithm_method):
    cond1=checkNumberOfArgs(numberOfArgs)
    cond2=checkIfCorrectMethod(algorithm_method)
    return cond1 and cond2


def writeFile(movesToWin,executionTime,outFile):
    with open(outFile,'w') as f:
        executionTime=round((executionTime/60),2)
        f.write(str(len(movesToWin)))
        for move in movesToWin:
            for pos in move.values():
                f.write(str(pos)+' ')
            f.write('\n')
