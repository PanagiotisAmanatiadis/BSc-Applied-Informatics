// Filename L_ListADT.h

#include <stdio.h>
#include <stdlib.h>


#define NumberOfNodes 10
#define NilValue -1

typedef int ListElementType;
typedef int ListPointer;

typedef struct {
    ListElementType Data;
    ListPointer  Next;
} NodeType;

typedef enum {
    FALSE, TRUE
} boolean;

void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr);
void CreateLList(ListPointer *List);
boolean EmptyLList(ListPointer List);
boolean FullLList(ListPointer FreePtr);
void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[]);
void ReleaseNode(NodeType Node[NumberOfNodes], ListPointer P, ListPointer *FreePtr);
void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item);
void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr);
void TraverseLinked(ListPointer List, NodeType Node[]);


void menu(int *choice);
void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[]);

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[], ListElementType Item, boolean *found, ListPointer *PredPtr);

int main()
{


    ListElementType Item;
    ListPointer List;
    NodeType Node[NumberOfNodes];
    ListPointer FreePtr,PredPtr;
    boolean found;


   int choice;
   char ch;

   InitializeStoragePool(Node, &FreePtr);
   printAll(List, FreePtr, Node);


   do
   {
   	menu(&choice);
      switch(choice)
      {
      	  case 1: CreateLList(&List);
          printf("Give  first number: ");
          scanf("%d",&Item);
          Node[0].Data=Item;
          Node[0].Next=-1;
          FreePtr=1;
          List=0;

          break;
          case 2:	do
                    {
   	                    printf("FreePtr=%d\n",FreePtr);
                        printf("DWSE ARI8MO GIA EISAGWGH STH LISTA: ");
                        scanf("%d", &Item);
                        Search(FreePtr,List,Node,Item,&found,&PredPtr);
                        Insert(&List, Node,&FreePtr, PredPtr, Item);
                        printf("List=%d\n",List);
                        printf("\nContinue Y/N: ");
                        do
                        {
      	                     scanf("%c", &ch);
                        } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
                    } while (toupper(ch)!='N');
                    printAll(List, FreePtr, Node);
                    break;
          case 3:	printf("FreePtr=%d\n",FreePtr);
                    TraverseLinked(List, Node);
         			break;
          case 4:   if (EmptyLList(List))
      	                 printf("Empty List\n");
      	            else
      	            {
                        printAll(List, FreePtr, Node);
                        printf("DWSE ARI8MO GIA DIAGRAFH APO TH LISTA: ");
                        scanf("%d", &Item);
                        Search(FreePtr,List,Node,Item,&found,&PredPtr);
                        if(found)
                        {
                            Delete(&List, Node, &FreePtr, PredPtr);

                        }
                        printAll(List, FreePtr, Node);
                    }
         			break;
          case 5:   if (EmptyLList(List))
      	                 printf("Empty List\n");
      	            else printf("Not an Empty List\n");
      	            break;
      	case 6:   if (FullLList(FreePtr))
      	                 printf("Full List\n");
      	            else printf("Not a Full List\n");
      	            break;
      	 case 7:	printAll(List, FreePtr, Node);     //EMFANISH STORAGE POOL
         			break;
         case 8:   printf("Dose arithmo gia anazhthsh sth lista: ");
                   scanf("%d",&Item);
                   Search(FreePtr,List,Node,Item,&found,&PredPtr);
                   if(found)
                   {
                       printf("to stoixeio exei prohgoumeno sth 8esi:%d\n", PredPtr);
                   }
                   else
                   {
                       printf("To stoixeio de bre8hke\n");
                   }
                   break;
	  }
   } while (choice!=9);
    system("pause");
	return 0;
}

void Search(ListPointer FreePtr, ListPointer List, NodeType Node[NumberOfNodes], ListElementType Item, boolean *found, ListPointer *PredPtr)
{
    ListPointer current;
    boolean stop;


    stop=FALSE;



    if(!EmptyLList(List))
    {

       current=List;
       *PredPtr=-1;
       while(current!=NilValue && !stop)
       {
           if(Node[current].Data>=Item)
           {
               stop=TRUE;
                *found=(Node[current].Data==Item);
               break;
           }
           else
           {
               *PredPtr=current;
               current=Node[current].Next;
                *found=(Node[current].Data==Item);
           }
       }
    }
    else
    {
        *found=FALSE;
    }


}



void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create List\n");
    printf("2. Insert an element to List\n");
    printf("3. Traverse List\n");
    printf("4. Delete an element from the List\n");
    printf("5. Check if List is empty\n");
    printf("6. Check if List is full\n");
    printf("7. Print storage pool\n");
    printf("8. Search an item\n");
    printf("9. Telos\n");
    printf("\nChoice 1-9 : ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>8);
}

void printAll(ListPointer List, ListPointer FreePtr, NodeType Node[])
{
    int i;
    printf("1o STOIXEIO LISTAS=%d, 1H FREE POSITION=%d\n", List, FreePtr);
    printf("H STORAGE POOL EXEI TA EJHS STOIXEIA\n");
    for (i=0;i<NumberOfNodes;i++)
        printf("(%d: %d,%d) ",i,Node[i].Data, Node[i].Next);
    printf("\n");
}


void InitializeStoragePool(NodeType Node[], ListPointer *FreePtr)
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr που δείχνει στον
                πρώτο διαθέσιμο κόμβο.
  Λειτουργία: Αρχικοποιεί τον πίνακα Node ως συνδεδεμένη λίστα συνδέοντας μεταξύ
                τους διαδοχικές εγγραφές του πίνακα,
                και αρχικοποιεί τον δείκτη FreePtr .
  Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον
                δείκτη FreePtr του πρώτου διαθέσιμου κόμβου
*/
{
   int i;

    for (i=0; i<NumberOfNodes-1;i++)
    {
        Node[i].Next=i+1;
        Node[i].Data=-1;
    }
    Node[NumberOfNodes-1].Next=NilValue;
    Node[NumberOfNodes-1].Data=NilValue;
    *FreePtr=0;
}

void CreateLList(ListPointer *List)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη λίστα.
   Επιστρέφει: Έναν (μηδενικό) δείκτη που δείχνει σε κενή λίστα
*/
{
  *List=NilValue;
}

boolean EmptyLList(ListPointer List)
/* Δέχεται:    Έναν δείκτη List που δείχνει σε μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι κενή.
   Επιστρέφει: True αν η συνδεδεμένη λίστα είναι κενή και false διαφορετικά
*/
{
  return (List==NilValue);
}

boolean FullLList(ListPointer FreePtr)
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη λίστα είναι γεμάτη.
   Επιστρέφει: True αν η συνδεδεμένηλίστα είναι γεμάτη, false διαφορετικά
*/
{
  return (FreePtr == NilValue);
}

void GetNode(ListPointer *P, ListPointer *FreePtr, NodeType Node[])
/* Δέχεται:   Τον πίνακα Node και τον δείκτη FreePtr.
  Λειτουργία: Αποκτά έναν "ελεύθερο" κόμβο που τον δείχνει ο δείκτης P.
  Επιστρέφει: Τον δείκτη P και τον τροποποιημένο  δείκτη FreePtr
                που δεικτοδοτεί στο πρώτο διαθέσιμο κόμβο
*/
{
  *P = *FreePtr;
  if (!FullLList(*FreePtr))
    *FreePtr =Node[*FreePtr].Next;
}

void ReleaseNode(NodeType Node[], ListPointer P, ListPointer *FreePtr)
/* Δέχεται:    Τον πίνακα Node, που αναπαριστά τη δεξαμενή των διαθέσιμων κόμβων,
                έναν δείκτη TempPtr και τον δείκτη FreePtr.
   Λειτουργία: Επιστρέφει στη δεξαμενή τον κόμβο στον οποίο δείχνει ο TempPtr.
   Επιστρέφει: Τον τροποποιημένο πίνακα Node και τον δείκτη FreePtr
*/
{
  Node[P].Next =*FreePtr;
  Node[P].Data = -1; /* Οχι αναγκαία εντολή, βοηθητική για να φαίνονται στην
                        εκτύπωση οι διαγραμμένοι κόμβοι */
  *FreePtr =P;
}

void Insert(ListPointer *List, NodeType Node[],ListPointer *FreePtr, ListPointer PredPtr, ListElementType Item)
/* Δέχεται:    Μια συνδεδεμένη λίστα, τον πίνακα Node, τον δείκτη PredPtr και
                ένα στοιχείο Item.
  Λειτουργία: Εισάγει στη συνδεδεμένη λίστα, αν δεν είναι γεμάτη, το στοιχείο
                Item μετά από τον κόμβο στον οποίο δείχνει ο δείκτης PredPtr.
  Επιστρέφει: Την τροποποιημένη συνδεδεμένη λίστα, τον τροποποιημένο πίνακα Node
                και τον δείκτη FreePtr.
  Εξοδος:     Μήνυμα γεμάτης λίστας, αν η συνδεδεμένη λίστα είναι γεμάτη
*/
{
  ListPointer TempPtr;
  GetNode(&TempPtr,FreePtr,Node);
  if (!FullLList(TempPtr)) {
    if (PredPtr==NilValue)
    {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =*List;
        *List =TempPtr;
    }
    else
      {
        Node[TempPtr].Data =Item;
        Node[TempPtr].Next =Node[PredPtr].Next;
        Node[PredPtr].Next =TempPtr;
      }
}
  else
    printf("Full List ...\n");
}

void Delete(ListPointer *List, NodeType Node[], ListPointer *FreePtr, ListPointer PredPtr)
/* Δέχεται:   Μια συνδεδεμένη λίστα και τον δείκτη PredPtr που δείχνει
                στον προηγούμενο κόμβο από αυτόν που θα διαγραφεί.
  Λειτουργία: Διαγράφει από τη συνδεδεμένη λίστα, αν δεν είναι κενή,
                τον προηγούμενο κόμβο από αυτόν στον οποίο δείχνει ο PredPtr.
  Επιστρέφει: Την τροποποιημένη λίστα και το δείκτη FreePtr.
  Έξοδος:     Μήνυμα κενής λίστας, αν η συνδεδεμένη λίστα είναι κενή
*/
{
  ListPointer TempPtr ;

  if (!EmptyLList(*List))
    if (PredPtr == NilValue)
    {
        TempPtr =*List;
        *List =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
    }
    else
      {
        TempPtr =Node[PredPtr].Next;
        Node[PredPtr].Next =Node[TempPtr].Next;
        ReleaseNode(Node,TempPtr,FreePtr);
      }
  else
    printf("Empty List ...\n");
}

void TraverseLinked(ListPointer List, NodeType Node[])
/* Δέχεται:    Μια συνδεδεμένη λίστα.
   Λειτουργία: Κάνει διάσχιση της συνδεδεμένης λίστας, αν δεν είναι κενή.
   Έξοδος:     Εξαρτάται από την επεξεργασία
*/
{
  ListPointer CurrPtr;

  if (!EmptyLList(List))
  {
      CurrPtr =List;
      while (CurrPtr != NilValue)
      {
          printf("(%d: %d,%d) ",CurrPtr,Node[CurrPtr].Data, Node[CurrPtr].Next);
          CurrPtr=Node[CurrPtr].Next;
       }
       printf("\n");
   }
  else printf("Empty List ...\n");
}









