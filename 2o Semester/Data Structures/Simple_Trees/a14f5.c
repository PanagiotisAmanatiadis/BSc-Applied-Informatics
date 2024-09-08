#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct{
              char name[20];
              char number[10];
              int pass;
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
};

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean EmptyBST(BinTreePointer Root);
void BSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void BSTSearch2(BinTreePointer Root, BinTreeElementType Item, boolean *Found,
BinTreePointer *LocPtr, BinTreePointer *Parent);
void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void InorderTraversal(BinTreePointer Root);



void menu(int *choice);




void BuildBST(BinTreePointer *Root);

void BSTSearchBySubject(BinTreePointer Root,int code);





int main()
{
  BinTreePointer Root,LocPtr;
  BinTreeElementType Item;
  int code,choice;
  boolean Found;





   CreateBST(&Root);
   do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1: BuildBST(&Root);
                break;

         case 2:	fflush(stdin);
                    printf("Give teacher name: ");
                    scanf("%20[^\n]",Item.name);
                    fflush(stdin);
                    printf("Give teacher phone number: ");
                    scanf("%10[^\n]",Item.number);
                    printf("Give teacher code: ");
                    fflush(stdin);
                    scanf("%d",&Item.pass);
                    BSTInsert(&Root,Item);
         			break;
         case 3:    if (EmptyBST(Root))
                        printf("Empty Tree\n");
                    else
                    {
                        fflush(stdin);
                        printf("Enter a name for deleting in the Tree: ");
                        scanf("%20[^\n]", Item.name);
                        BSTDelete(&Root, Item);
                    }
         			break;

        case 4:     if (EmptyBST(Root))
                        printf("Empty Tree\n");
                    else
                    {

                        printf("Enter a name for searching in the Tree: ");
                        fflush(stdin);
                        scanf("%20[^\n]",Item.name);

                        BSTSearch(Root, Item, &Found, &LocPtr);
         			    if (Found==FALSE)
                        {
                            printf("\n");
         			        printf("Item %s not in Tree \n",Item.name);
                        }
         			    else
         			    {
         			        printf("%s, %s, %d\n",LocPtr->Data.name, LocPtr->Data.number, LocPtr->Data.pass);

         			    }
                    }
         			break;


        case 5:   printf("Give teacher code: ");
                  fflush(stdin);
                  scanf("%d",&code);

                  BSTSearchBySubject(Root,code);
               break;

        case 6:  if(EmptyBST(Root))
                    printf("Empty Tree\n");
                else
                  InorderTraversal(Root);
        break;
		}
   } while(choice!=7);
   system("pause");
   return 0;
}






void BuildBST(BinTreePointer *Root)
{
    BinTreeElementType Item;
    char termch;
    int nscan;

    FILE *infile;


    infile=fopen("I14F5.TXT","r");

    while(TRUE)
     {

        nscan=fscanf(infile,"%20[^,], %10[^,], %d%c", Item.name, Item.number, &Item.pass,&termch);


        if(nscan==EOF)break;
        if(nscan!=4 || termch!='\n')
        {
            printf("Improper file format\n");
             break;
        }
         BSTInsert(Root,Item);
     }
    fclose(infile);
}


void BSTSearchBySubject(BinTreePointer Root,int code)
{
    if(!EmptyBST(Root))
    {
       BSTSearchBySubject(Root->LChild,code);
       if(Root->Data.pass == code)
       {
         printf("%s, %s, %d\n",Root->Data.name, Root->Data.number, Root->Data.pass);
       }
      BSTSearchBySubject(Root->RChild,code);
    }
}
















void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1.Create BST\n");
    printf("2.Insert new teacher\n");
    printf("3.Delete a teacher\n");
    printf("4.Search for a teacher\n");
    printf("5.Search by subject\n");
    printf("6.Print teachers\n");
    printf("7.Quit\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>7);
}














void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    BinTreePointer LocPtr, Parent;
    boolean Found;

    LocPtr = *Root;
    Parent = NULL;
    Found = FALSE;
    while (!Found && LocPtr != NULL) {
        Parent = LocPtr;

         if (strcmp(Item.name,LocPtr->Data.name)<0)
            LocPtr = LocPtr ->LChild;

        else if (strcmp(Item.name,LocPtr->Data.name)>0)
            LocPtr = LocPtr ->RChild;
        else
            Found = TRUE;
    }
    if (Found)
        printf("To %s ONOMA EINAI HDH STO DDA\n", Item.name);
    else {

        LocPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy(LocPtr ->Data.name,Item.name);
        strcpy(LocPtr ->Data.number,Item.number);
        LocPtr ->Data.pass=Item.pass;

        LocPtr ->LChild = NULL;
        LocPtr ->RChild = NULL;
        if (Parent == NULL)
            {
                *Root = LocPtr;
            }
        else if (strcmp(Item.name ,Parent->Data.name)<0)
            Parent ->LChild = LocPtr;
        else
            Parent ->RChild = LocPtr;
    }
}

void BSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
                BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{

    (*LocPtr) = Root;
    (*Found) = FALSE;
    while (!(*Found) && (*LocPtr) != NULL)
    {
        if (strcmp(KeyValue.name ,(*LocPtr)->Data.name)<0)
            (*LocPtr) = (*LocPtr)->LChild;
        else
            if (strcmp(KeyValue.name ,(*LocPtr)->Data.name)>0)
                (*LocPtr) = (*LocPtr)->RChild;
            else (*Found) = TRUE;
    }
}

void BSTSearch2(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found,
    BinTreePointer *LocPtr, BinTreePointer *Parent)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του
                και τον πατέρα του κόμβου αυτού.
   Επιστρέφει: Η Found έχει τιμή TRUE, ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue και ο Parent δείχνει στον πατέρα
                αυτού του κόμβου, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE.
*/
{
    *LocPtr = Root;
    *Parent=NULL;
    *Found = FALSE;
    while (!(*Found) && *LocPtr != NULL)
    {
        if (strcmp(KeyValue.name ,(*LocPtr)->Data.name)<0)
        {
            *Parent=*LocPtr;
            *LocPtr = (*LocPtr)->LChild;
        }
        else
            if (strcmp(KeyValue.name ,(*LocPtr)->Data.name)>0)
            {
                *Parent=*LocPtr;
                *LocPtr = (*LocPtr)->RChild;
            }
            else *Found = TRUE;
    }

}

void BSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
  Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer
   n,                   //δείχνει στον κόμβο που περιέχει την τιμή KeyValue *)
   Parent,              // πατέρας του n ή του nNext
   nNext,               // ενδοδιατεταγμένος επόμενος του n
   SubTree;             // δείκτης προς υποδέντρο του n
   boolean Found;       // TRUE AN TO ΣΤΟΙΧΕΙΟ KeyValue EINAI ΣΤΟΙΧΕΟ ΤΟΥ ΔΔΑ *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue.name);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // κόμβος προς διαγραφή με δύο παιδιά
                 //Βρες τον ενδοδιατεταγμένο επόμενο και τον πατέρα του
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* Αντιγραφή των περιεχομένων του nNext στον n και
                αλλαγή του n ώστε να δείχνει στον επόμενο */
                n->Data = nNext->Data;
                n = nNext;
          } //Συνεχίζουμε με την περίπτωση που ο κόμβος έχει το πολύ 1 παιδί
          SubTree = n->LChild;
          if (SubTree == NULL)
             SubTree = n->RChild;
          if (Parent == NULL)                 //* 8A DIAGRAFEI H RIZA *)
             *Root = SubTree;
          else if (Parent->LChild == n)
                  Parent->LChild = SubTree;
               else
                   Parent->RChild = SubTree;
          free(n);
     }
}

void InorderTraversal(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s, %s, %d",Root->Data.name, Root->Data.number, Root->Data.pass);
        printf("\n");
        InorderTraversal(Root->RChild);
    }
}


