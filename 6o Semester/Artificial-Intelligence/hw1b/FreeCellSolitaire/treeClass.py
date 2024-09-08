import copy

class treeNode:
    def __init__(self,tableau,foundation,freeCells,parent):
        self.tableau=tableau
        self.freeCells=freeCells
        self.foundation=foundation
        self.parent=parent
        self.children=[]
        self.value=self.valueToStr()
        self.move=''
        self.bestFirstScore=self.calculateBestFirstSearchScore()
        self.AScore=self.calculateASearchScore()
     
    #If all stacks of the foundation have 13 cards you win the round.
    def checkIfWin(self):
        for pileF in self.foundation:
            if pileF[-1][1:] != '13': 
                return False
        print('Win the round.')
        return True
     
    #Check if the card from tableau can move to a free cell.
    def moveToAFreeCell(self, card, idSource):
        for index, cell in enumerate(self.freeCells):
            if cell==None: #If there is an empty cell.
                childFoundation,childFreeCells,childTableau=copy.deepcopy(self.foundation),copy.deepcopy(self.freeCells),copy.deepcopy(self.tableau)
                childFreeCells[index]=card   #Add the card to a free cell.
                childTableau[idSource].pop() #Remove the card from the top of the stack idSource of tableau.
                child=treeNode(childTableau,childFoundation,childFreeCells,self)
                self.children.append(child)
                return True,('freecell '+card)
        return False,''
    

    #Check if a card from the tableau or from the free cells can move to a stack of the foundation.
    def moveToAFoundation(self,card,idSource,typeSource):
        for index, pileF in enumerate(self.foundation):
            #cond1=If the stack contains only the element of initialization then check if card has the same symbol and the card value is 1.
            #cond2=If the symbol of the top element = symbol of tha card and the value of the top element = value of the card-1.
            if (pileF[-1][:1]==card[:1] and int(pileF[-1][1:])==0 and int(card[1:])==1) or (pileF[-1][:1]==card[:1] and int(pileF[-1][1:])==int(card[1:])-1):
                
                childFoundation,childFreeCells,childTableau=copy.deepcopy(self.foundation),copy.deepcopy(self.freeCells),copy.deepcopy(self.tableau)

                if typeSource=='Tableau':
                    if int(pileF[-1][1:])==0:
                        childFoundation[index].pop()  #Remove initialized item.
                        childFoundation[index].append(card)  #Add a card to the stack index of the foundation.
                        childTableau[idSource].pop()  #Remove the card from the stack idSource of the Tableau.
                    else:
                        childFoundation[index].append(card)  #Add a card to the stack index of the foundation.
                        childTableau[idSource].pop()  #Remove the card from the stack idSource of the Tableau.
                else:
                    if int(pileF[-1][1:])==0:
                        childFoundation[index].pop()  #Remove initialized item.
                        childFoundation[index].append(card)  #Add a card to the stack index of the foundation.
                        childFreeCells[idSource]=None  #Remove the card from the cell idsource and change the value to "None".
                    else:
                        childFoundation[index].append(card)  #Add a card to the stack index of the foundation.
                        childFreeCells[idSource]=None  #Remove the card from the cell idsource and change the value to "None".

                child=treeNode(childTableau,childFoundation,childFreeCells,self)
                self.children.append(child)

                return True,('source '+card)
        return False,''


    
    #Check if the card can move to a stack from another stack or from a free cell.
    def moveToAPile(self,card,idSource,typeSource):
        allmoves=list()

        #For every stack on tableau.
        for index, dataStack in enumerate(self.tableau):
            #cond1=if stack is empty.
            #cond2=if the value of the top element = value of card+1 and the symbol of the top element != symbol of card.
            if not dataStack or (dataStack[-1][:1]!=card[:1] and int(dataStack[-1][1:])==int(card[1:]) + 1): 

                childFoundation,childFreeCells,childTableau=copy.deepcopy(self.foundation), copy.deepcopy(self.freeCells), copy.deepcopy(self.tableau)

                if typeSource=='Tableau':
                    #If stack is not empty the card moves to the top of the stack.
                    if(childTableau[index]!=[]):
                        old_top_card=childTableau[index][-1]

                    childTableau[index].append(card)  #Add a card to the stack index of the tableau.
                    childTableau[idSource].pop()  #Remove the card from the stack idSource of the Tableau.

                else:
                    #If stack is not empty the card moves to the top of the stack.
                    if(childTableau[index]!=[]):
                        old_top_card=childTableau[index][-1]

                    childTableau[index].append(card)  #Add a card to the stack index of the tableau.
                    childFreeCells[idSource]=None  #Remove the card from the cell idsource and change the value to "None".
                
                child=treeNode(childTableau,childFoundation,childFreeCells,self)
                self.children.append(child)
                if not dataStack:
                    allmoves.append('newstack '+card)
                else:
                    allmoves.append('stack '+card+' '+old_top_card)

        if len(allmoves)>0: return True,allmoves

        return False,''

    #Function that finds next moves of the node.
    def expandNode(self):
        moves=list()
        dictionary={'result':[],'moves':[]}

        #For every stack on tableau.
        for index,dataStack in enumerate(self.tableau):
            #If stack is not empty.
            if dataStack: 
                #Take top element of the stack.
                takeCard=dataStack[-1]
                #Now first check if takeCard can move to a foundation.
                result,move=self.moveToAFoundation(takeCard,index,'Tableau')
                dictionary['result'].append(result)
                dictionary['moves'].append(move)
                #Second check if takeCard can move to a stack of the tableau.
                result,move=self.moveToAPile(takeCard,index,'Tableau')
                dictionary['result'].append(result)
                dictionary['moves'].append(move)
                #Last check if takeCard can move to a free cell.
                result,move=self.moveToAFreeCell(takeCard,index)
                dictionary['result'].append(result)
                dictionary['moves'].append(move)
        
        for index,cell in enumerate(self.freeCells):
            if cell!=None:
                takeCard = cell
                result,move= self.moveToAFoundation(takeCard, index,'freeCell')
                dictionary['result'].append(result)
                dictionary['moves'].append(move)  
                result,move=self.moveToAPile(takeCard, index,'freeCell')
                dictionary['result'].append(result)
                dictionary['moves'].append(move) 
        
        for move in dictionary['moves']:
            if move!='' and type(move)!=type([]):
                moves.append(move)
            if move!='' and type(move)==type([]):
                for m in move:
                    moves.append(m)

        return moves
                
    #Function that converts the current game situation to string.
    def valueToStr(self):
        #convert freeCells table to a string. 
        freeC=''.join(cell if cell else str('None') for cell in self.freeCells)
        
        #convert foundation stacks to a string.
        foundation=''
        for pileF in self.foundation:
            if (int(pileF[-1][1:])==0): #if stack is empty.
                thisFstack=''.join(str('None'))
            else:
                thisFstack=''.join(card for card in pileF)
            foundation+=thisFstack

        #convert tableau stacks to a string.
        tableau=''
        for pile in self.tableau:
            if pile:
                thisTStack=''.join(card for card in pile)
            else:
                thisTStack=''.join(str('None'))
            tableau+=thisTStack

        return freeC+foundation+tableau

    #Heuristic function:
    #f(n)=h(n)=totalCardsT+totalFC-totalCardsF-totalFoundationPiles-(totalCardsF / 4)
    #totalCardsF=Total cards of the foundation stacks.
    #totalCardsT=Total cards of the tableau stacks.
    #totalFC=Total cards of the freeCells table.
    #totalFoundationPiles=The number of foundation stacks that are not empty.
    def calculateBestFirstSearchScore(self):
        totalCardsF,totalCardsT,totalFoundationPiles=0,0,0
        for pileF in self.foundation:
            if pileF and int(pileF[-1][1:]) != 0:
                totalCardsF+=len(pileF)
                totalFoundationPiles+=1

        for pileT in self.tableau:
            totalCardsT+=len(pileT)

        totalFC=sum(1 for aCard in self.freeCells if aCard)

        return totalCardsT + totalFC - totalCardsF - totalFoundationPiles - (totalCardsF / 4)


    #f(n)=h(n)+g(n),g(n)=level depth of node.
    def calculateASearchScore(self):
        currentNode,depth=self,0
        while currentNode.parent:
            depth+=1
            currentNode=currentNode.parent

        self.depth=depth

        return self.bestFirstScore+depth



