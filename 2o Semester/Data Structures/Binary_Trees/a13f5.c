#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>



typedef struct{
              char surname[20];
              char name[20];
              int pass;
}BinTreeElementType;

typedef struct BinTreeNode *BinTreePointer;
 struct BinTreeNode
 {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateBST(BinTreePointer *Root);
boolean BSTEmpty(BinTreePointer Root);
void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item);
void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue, boolean *Found, BinTreePointer *LocPtr);
void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue);
void RecBSTInorder(BinTreePointer Root);
void RecBSTPreorder(BinTreePointer Root);
void RecBSTPostorder(BinTreePointer Root);

void menu(int *choice);

void BuildBST(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3);

int main()
{

  BinTreePointer Root1,Root2,Root3,LocPtr;
  int choice;
  BinTreeElementType Item;
  boolean Found;

  do
   {
   	menu(&choice);
      switch(choice)
      {
      	case 1:
            {
   	            BuildBST(&Root1,&Root2,&Root3);
                break;

        case 2:	fflush(stdin);
                printf("Dwse epwnumo: ");
                scanf("%20[^\n]",Item.surname);
                fflush(stdin);
                printf("Dwse onoma: ");
                scanf("%20[^\n]",Item.name);
                fflush(stdin);
                printf("Dwse kwdiko upallhlou: ");
                scanf("%d",&Item.pass);
                if(Item.pass==1)
                {
                    RecBSTInsert(&Root1,Item);
                }
                else if(Item.pass==2)
                {
                    RecBSTInsert(&Root2,Item);
                }
                else
                {
                    RecBSTInsert(&Root3,Item);
                }
                break;
        case 3:
                fflush(stdin);
                printf("Dwse epwnumo: ");
                scanf("%20[^\n]",Item.surname);
                fflush(stdin);
                printf("Dwse kwdiko upallhlou: ");
                scanf("%d",&Item.pass);
                if(Item.pass==1)
                {
                    if (BSTEmpty(Root1))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        RecBSTSearch(Root1,Item,&Found,&LocPtr);
                        if(Found)
                        {
                            printf("%s %s %d\n",LocPtr->Data.surname, LocPtr->Data.name, LocPtr->Data.pass);
                        }
                        else
                            printf("Den uparxei autos o upallhlos\n");

                    }
                }

                else if(Item.pass==2)
                {
                    if (BSTEmpty(Root2))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        RecBSTSearch(Root2,Item,&Found,&LocPtr);
                        if(Found)
                        {
                           printf("%s %s %d\n",LocPtr->Data.surname, LocPtr->Data.name, LocPtr->Data.pass);
                        }
                        else
                            printf("Den uparxei autos o upallhlos\n");
                    }



                }
                else
                {
                    if (BSTEmpty(Root3))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        RecBSTSearch(Root3,Item,&Found,&LocPtr);
                        if(Found)
                        {
                            printf("(%s, %s, %d)\n",LocPtr->Data.surname, LocPtr->Data.name, LocPtr->Data.pass);
                        }
                        else
                            printf("Den uparxei autos o upallhlos\n");
                    }
                }

         			break;
        case 4:
                  if (BSTEmpty(Root1))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        printf("Ypallhloi Grafeiou:\n");
                        RecBSTInorder(Root1);
                    }
                    printf("\n");
                    if (BSTEmpty(Root2))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        printf("Ergates:\n");
                        RecBSTInorder(Root2);
                    }
                    printf("\n");
                    if (BSTEmpty(Root3))
                      {
                        printf("\nEmpty tree\n");
                      }
                    else
                    {
                        printf("Antiproswpoi:\n");
                        RecBSTInorder(Root3);
                    }
         			break;
		    }

      }
   }while (choice!=5);

    printf("\n");
    system("pause");
    return 0;

}




void BuildBST(BinTreePointer *Root1,BinTreePointer *Root2,BinTreePointer *Root3)
{
    BinTreeElementType Item;
    FILE *infile;
    int nscan;
    char termch;


    infile=fopen("I13F5.txt","r");

    CreateBST(Root1);
    CreateBST(Root2);
    CreateBST(Root3);

    while(TRUE)
     {

        nscan=fscanf(infile,"%20s %20s %d%c", Item.surname, Item.name, &Item.pass,&termch);


        if(nscan==EOF)break;
        if(nscan!=4 || termch!='\n')
        {
            break;
            printf("Improper file format\n");
        }
        if(Item.pass==1)
        {
            RecBSTInsert(Root1,Item);
        }
        else if(Item.pass==2)
        {
            RecBSTInsert(Root2,Item);
        }
        else
            RecBSTInsert(Root3,Item);


     }
    fclose(infile);
}













void menu(int *choice)
{
    printf("\n                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create BSTs from file\n");
    printf("2. Insert new employee\n");
    printf("3. Search for an employee \n");
    printf("4. Traverse Inorder\n");
    printf("5. Quit\n");
    printf("\nEpilogh: ");
    do
    {
    	scanf("%d", choice);
    	fflush(stdin);
    } while (*choice<1 && *choice>5);
}




















void CreateBST(BinTreePointer *Root)
/* Λειτουργία: Δημιουργεί ένα κενό ΔΔΑ.
   Επιστρέφει:  Τον μηδενικό δείκτη(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* Δέχεται:   Ενα ΔΔα με το Root να δείχνει στη ρίζα του.
  Λειτουργία: Ελέγχει αν το ΔΔΑ είναι κενό.
  Επιστρέφει: TRUE αν το ΔΔΑ είναι κενό και FALSE διαφορετικά
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* Δέχεται:     Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και ένα στοιχείο Item.
   Λειτουργία:  Εισάγει το στοιχείο Item στο ΔΔΑ.
   Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του
*/
{
    if (BSTEmpty(*Root)) {
        (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
        strcpy((*Root)->Data.surname,Item.surname);
        strcpy((*Root)->Data.name,Item.name);
        (*Root) ->Data.pass = Item.pass;
        (*Root) ->LChild = NULL;
        (*Root) ->RChild = NULL;
    }
    else
        if (strcmp(Item.surname ,(*Root)->Data.surname)<0)
            RecBSTInsert(&(*Root) ->LChild,Item);
        else if (strcmp(Item.surname ,(*Root)->Data.surname)>0)
            RecBSTInsert(&(*Root) ->RChild,Item);
        else
            printf("To %s EINAI HDH STO DDA\n", Item.surname);
}

void RecBSTSearch(BinTreePointer Root, BinTreeElementType KeyValue,
                    boolean *Found, BinTreePointer *LocPtr)
/* Δέχεται:    Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Αναζητά στο ΔΔΑ έναν κόμβο με τιμή KeyValue στο πεδίο κλειδί του.
   Επιστρέφει: Η Found έχει τιμή TRUE και ο δείκτης LocPtr δείχνει στον κόμβο που
                περιέχει την τιμή KeyValue, αν η αναζήτηση είναι επιτυχής.
                Διαφορετικά η Found έχει τιμή FALSE
*/
{
    boolean stop;

    if (BSTEmpty(Root))
        *Found=FALSE;
    else
        if (strcmp(KeyValue.surname,Root->Data.surname)<0)
            RecBSTSearch(Root->LChild, KeyValue, &(*Found), &(*LocPtr));
        else
            if (strcmp(KeyValue.surname,Root->Data.surname)>0)
                RecBSTSearch(Root->RChild, KeyValue, &(*Found), &(*LocPtr));
            else
                {
                    *Found = TRUE;
                    *LocPtr=Root;
                }
}

void RecBSTDelete(BinTreePointer *Root, BinTreeElementType KeyValue)
/* Δέχεται:  Ένα ΔΔΑ με το δείκτη Root να δείχνει στη ρίζα του και μια τιμή KeyValue.
   Λειτουργία: Προσπαθεί να βρει έναν κόμβο στο ΔΔΑ που να περιέχει την τιμή
                KeyValue στο πεδίο κλειδί του τμήματος δεδομένων του και,
                αν τον βρει, τον διαγράφει από το ΔΔΑ.
  Επιστρέφει: Το τροποποιημένο ΔΔΑ με τον δείκτη Root να δείχνει στη ρίζα του.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ΑΔΕΙΟ ΔΕΝΔΡΟ ΤΟ KeyValue ΔΕ ΘΑ ΒΡΕΘΕΙ *)
        printf("to %s DeN BRE8HKe STO DDA\n", KeyValue);
     else
         //* αναζήτησε αναδρομικά τον κόμβο που περιέχει την τιμή KeyValue και διάγραψέ τον
          if (strcmp(KeyValue.surname ,(*Root)->Data.surname)<0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* ΑΡΙΣΤΕΡΟ ΥΠΟΔΕΝΔΡΟ *
          else
            if (strcmp(KeyValue.surname ,(*Root)->Data.surname)>0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ΔΕΞΙ  ΥΠΟΔΕΝΔΡΟ *
            else                                       //* TO KeyValue ΒΡΕΘΗΚΕ ΔΙΑΓΡΑΦΗ ΤΟΥ ΚΟΜΒΟΥ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ΔΕΝ ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ΕΧΕΙ ΑΡΙΣΤΕΡΟ ΠΑΙΔΙ, ΑΛΛΑ ΟΧΙ ΔΕΞΙ *)
                        free(TempPtr);
                   }
                   else                               //* ΕΧΕΙ 2 ΠΑΙΔΙΑ *)
                   {
                        //* ΕΥΡΕΣΗ ΤΟΥ INORDER ΑΠΟΓΟΝΟΥ ΤΟΥ *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ΜΕΤΑΚΙΝΗΣΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΤΗς ΡΙΖΑΣ ΤΟΥ ΥΠΟΔΕΝΔΡΟΥ
                        ΠΟΥ ΕΞΕΤΑΖΕΤΑΙ ΚΑΙ ΔΙΑΓΡΑΦΗ ΤΟΥ ΑΠΟΓΟΝΟΥ ΚΟΜΒΟΥ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί ενδοδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL)
        {

        RecBSTInorder(Root->LChild);
        printf("(%s, %s, %d),", Root->Data.surname, Root->Data.name,Root->Data.pass);

        RecBSTInorder(Root->RChild);
    }

}

void RecBSTPreorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί προδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("/%d ",Root->Data,"/");
        printf("L");
        RecBSTPreorder(Root->LChild);
        printf("R");
        RecBSTPreorder(Root->RChild);
    }
    printf("U");
}

void RecBSTPostorder(BinTreePointer Root)
/* Δέχεται:    Ένα δυαδικό δέντρο με το δείκτη Root να δείχνει στην ρίζα του.
   Λειτουργία: Εκτελεί μεταδιατεταγμένη διάσχιση του δυαδικού δέντρου και
                επεξεργάζεται κάθε κόμβο ακριβώς μια φορά.
   Εμφανίζει: Το περιεχόμενο του κόμβου, και εξαρτάται από το είδος της επεξεργασίας
*/
{
    if (Root!=NULL) {
        printf("L");
        RecBSTPostorder(Root->LChild);
        printf("R");
        RecBSTPostorder(Root->RChild);
        printf("/%d ",Root->Data,"/");
    }
    printf("U");
}





