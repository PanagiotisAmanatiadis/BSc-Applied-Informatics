#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define HMax 10              /*     το μέγεθος του πίνακα HashTable
                                ενδεικτικά ίσο με 5 */
#define VMax 30             /*το μέγεθος της λίστας,
                                ενδεικτικά ίσο με 30 */
#define EndOfList -1        /* σημαία που σηματοδοτεί το τέλος της λίστας
                                και της κάθε υπολίστας συνωνύμων */

typedef struct{
    int code;
    char name[20];
}ListElementType;  /*τύπος δεδομένων για τα στοιχεία της λίστας
                               * ενδεικτικά τύπου int */

typedef struct {
	int RecKey;
	ListElementType Data;
	int Link;
} ListElm;

typedef struct  {
	int HashTable[HMax];   // πίνακας δεικτών προς τις υπολίστες συνωνύμων
    int Size;                // πλήθος εγγραφών της λίστας List
	int SubListPtr;          // Dδείκτης σε μια υπολίστα συνωνύμων
    int StackPtr;           // δείκτης προς την πρώτη ελεύθερη θέση της λίστας List
	ListElm List[VMax];
} HashListType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateHashList(HashListType *HList);
int HashKey(int Key);
boolean FullHashList(HashListType HList);
void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred);
void AddRec(HashListType *HList,ListElm InRec);
void DeleteRec(HashListType *HList,int DelKey);

void Print_HashList(HashListType HList);
void menu(int *choice);
void PrintPinakes(HashListType HList);

int main(){
   int choice;
   char ch;
   HashListType HList;
   ListElm AnItem;
   int AKey;
   int Loc, Pred;

   do
   {
   	menu(&choice);
      switch(choice)
      {
        case 1:
            CreateHashList(&HList);
            break;
      	case 2:	do
            {
   	            printf("Enter the key for insertion in the Hash: ");
                scanf("%d", &AnItem.RecKey);
                fflush(stdin);
                printf("Enter the name for insertion in the Hash: ");
                scanf("%20[^\n]", AnItem.Data.name);
                fflush(stdin);
                printf("Codes: 1-student, 2-postgraduate student, 3-teacher, 4-visitor\n");
                printf("Enter the code for insertion in the Hash: ");
                scanf("%d", &AnItem.Data.code);
                fflush(stdin);
                AnItem.Link=EndOfList;
                AddRec(&HList, AnItem);
                printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);

                } while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
            } while (toupper(ch)!='N');
            break;
         case 3: do{

                 printf("Enter a number for deleting in the Hash: ");

                 scanf("%d", &AKey);
                 fflush(stdin);
                 DeleteRec(&HList, AKey);
                 printf("\nContinue Y/N: ");
                 do{
                 scanf("%c",&ch);
                 }while (toupper(ch)!= 'N' && toupper(ch)!= 'Y');
         }while(toupper(ch)!='N');

         		 break;
         case 4:   do{
         printf("Enter a code for searching in the Hash: ");
         char *roles[20]={"student","postgraduate student","teacher","visitor"};

                    scanf("%d", &AKey);
                    SearchHashList( HList,AKey,&Loc,&Pred);
         			if ( Loc != -1)
                        printf("EGGRAFH [%d, %s, %s, %d]\n",HList.List[Loc].RecKey,HList.List[Loc].Data.name,roles[HList.List[Loc].Data.code-1],HList.List[Loc].Link);
                    else
                        printf("DEN YPARXEI EGGRAFH ME KLEIDI %d\n", AKey);
                 printf("\nContinue Y/N: ");
                do
                {
      	             scanf("%c", &ch);
      	             fflush(stdin);
                }while(toupper(ch)!= 'N' && toupper(ch)!= 'Y');
      }while(toupper(ch)!='N');
         			break;
        case 5: Print_HashList(HList);
         			break;
		}
   } while (choice!=6);

   printf("\n");

    system("pause");
	return 0;
}

void Print_HashList(HashListType HList)
{
   int i, SubIndex;

   char *roles[20]={"student","postgraduate student","teacher","visitor"};


          printf("OI YPO-LISTES TWN SYNWNYMWN EGGRAFWN:\n");
          for (i=0; i<HMax;i++)
          {
              SubIndex = HList.HashTable[i];
              if(SubIndex!=EndOfList){
                printf("Synonyms, collision at position: %d\n",HList.List[SubIndex].RecKey%HMax);
              }
              while ( SubIndex != EndOfList )
              {
                   printf("[%d, %s, %s]",HList.List[SubIndex].RecKey,HList.List[SubIndex].Data.name,roles[HList.List[SubIndex].Data.code-1]);
                   printf("\n");
                   SubIndex = HList.List[SubIndex].Link;
               } //* while *)
              //printf("TELOS % dHS YPO-LISTAS\n", i);
          }


}

void menu(int *choice)
{
    printf("                  MENOY                  \n");
    printf("-------------------------------------------------\n");
    printf("1. Create HashList\n");
    printf("2. Insert New User\n");
    printf("3. Delete a user\n");
    printf("4. Search for a user\n");
    printf("5. Print list of all users\n");
    printf("6. Quit\n");
    printf("\nCHOICE: ");
    do
    {
    	scanf("%d", choice);
    } while (*choice<1 && *choice>6);
}

void PrintPinakes(HashListType HList)
{
    int i;
	printf("Hash table\n");
	for (i=0; i<HMax;i++)
              printf("%d| ",i);
    printf("\n");
    for (i=0; i<HMax;i++)
         printf("%d| ",HList.HashTable[i]);
    printf("\n");


	printf("Hash List\n");
    for (i=0;i<=HList.Size-1;i++)
	   printf("%d) %d, %d\n",i,HList.List[i].RecKey,HList.List[i].Link);
	printf("\n");
}

int HashKey(int Key)
/* Δέχεται:    Την τιμή Key ενός κλειδιού.
   Λειτουργία: Βρίσκει την τιμή κατακερματισμού HValue για το κλειδί Key.
   Επιστρέφει: Την τιμή κατακερματισμού HValue
*/
{
	return Key%HMax;
}

void CreateHashList(HashListType *HList)
/* Λειτουργία: Δημιουργεί μια δομή HList.
   Επιστρέφει: Την δομή HList
*/
{
	int index;

	HList->Size=0;           //ΔΗΜΙΟΥΡΓΕΙ ΜΙΑ ΚΕΝΗ ΛΙΣΤΑ
	HList->StackPtr=0;       //ΔΕΙΚΤΗς ΣΤΗ ΚΟΡΥΦΗ ΤΗΣ ΣΤΟΙΒΑΣ ΤΩΝ ΕΛΕΥΘΕΡΩΝ ΘΕΣΕΩΝ

    /*ΑΡΧΙΚΟΠΟΙΕΙ ΤΟΝ ΠΙΝΑΚΑ HashTable ΤΗΣ ΔΟΜΗΣ HList ΩΣΤΕ ΚΑΘΕ ΣΤΟΙΧΕΙΟΥ ΤΟΥ
        ΝΑ ΕΧΕΙ ΤΗ ΤΙΜΗ EndOfList (-1)*/
    index=0;
	while (index<HMax)
	{
		HList->HashTable[index]=EndOfList;
		index=index+1;
    }

     //Δημιουργία της στοίβας των ελεύθερων θέσεων στη λίστα HList
    index=0;
	while(index < VMax-1)
	{
		HList->List[index].Link=index+1;
		strcpy(HList->List[index].Data.name,"");
		//HList->List[index].Data=0;
		index=index+1;
	}
	HList->List[index].Link=EndOfList;


}

boolean FullHashList(HashListType HList)
/* Δέχεται:    Μια δομή HList.
   Λειτουργία: Ελέγχει αν η λίστα List της δομής HList είναι γεμάτη.
   Επιστρέφει: TRUE αν η λίστα List είναι γεμάτη, FALSE διαφορετικά.
*/
{
	return(HList.Size==VMax);
}

void SearchSynonymList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στην υπολίστα συνωνύμων.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της προηγούμενης
                εγγραφής στην υπολίστα
*/
{
	int Next;
	Next=HList.SubListPtr;
	*Loc=-1;
	*Pred=-1;
	while(Next!=EndOfList)
	{
		if (HList.List[Next].RecKey==KeyArg)
		{
			*Loc=Next;
			Next=EndOfList;
		}
		else
		{
			*Pred=Next;
			Next=HList.List[Next].Link;
		}
	}
}
void SearchHashList(HashListType HList,int KeyArg,int *Loc,int *Pred)
/* Δέχεται:     Μια δομή HList και μια τιμή κλειδιού KeyArg.
    Λειτουργία: Αναζητά μια εγγραφή με κλειδί KeyArg στη δομή HList.
    Επιστρέφει: Τη θέση Loc της εγγραφής και τη θέση Pred της
                προηγούμενης εγγραφής της υπολίστας στην οποία ανήκει.
                Αν δεν υπάρχει εγγραφή με κλειδί KeyArg τότε Loc=Pred=-1
*/
{
	int HVal;
	HVal=HashKey(KeyArg);
    if (HList.HashTable[HVal]==EndOfList)
	{
		*Pred=-1;
		*Loc=-1;
	}
	else
	{
		HList.SubListPtr=HList.HashTable[HVal];
		SearchSynonymList(HList,KeyArg,Loc,Pred);
	}
}

void AddRec(HashListType *HList,ListElm InRec)
/* Δέχεται:    Μια δομή HList και μια εγγραφή InRec.
   Λειτουργία: Εισάγει την εγγραφή InRec στη λίστα List, αν δεν είναι γεμάτη,
                και ενημερώνει τη δομή HList.
   Επιστρέφει: Την τροποποιημένη δομή HList.
   Έξοδος:     Μήνυμα γεμάτης λίστας, αν η List είναι γεμάτη, διαφορετικά,
                αν υπάρχει ήδη εγγραφή με το ίδιο κλειδί,
                εμφάνιση αντίστοιχου μηνύματος
*/
{
	int Loc, Pred, New, HVal;

   // New=0;
	if(!(FullHashList(*HList)))
	{
		Loc=-1;
		Pred=-1;
		SearchHashList(*HList,InRec.RecKey,&Loc,&Pred);
		if(Loc==-1)
		{
			HList->Size=HList->Size +1;
			New=HList->StackPtr;
			HList->StackPtr=HList->List[New].Link;
			HList->List[New]=InRec;
			if (Pred==-1)
			{
			    HVal=HashKey(InRec.RecKey);
                HList->HashTable[HVal]=New;
				HList->List[New].Link=EndOfList;
			}
			else
			{
                HList->List[New].Link=HList->List[Pred].Link;
				HList->List[Pred].Link=New;
			}
		}

		else
		{
			printf("YPARXEI HDH EGGRAFH ME TO IDIO KLEIDI \n");
		}
	}
	else
	{
		printf("Full list...");
	}
}
void DeleteRec(HashListType *HList,int DelKey)
/* DEXETAI:    TH DOMH (HList) KAI To KLEIDI (DelKey) THS EGGRAFHS
               POY PROKEITAI NA DIAGRAFEI
   LEITOYRGIA: DIAGRAFEI, THN EGGRAFH ME KLEIDI (DelKey) APO TH
               LISTA (List), AN YPARXEI ENHMERWNEI THN DOMH HList
   EPISTREFEI: THN TROPOPOIHMENH DOMH (HList)
   EJODOS:     "DEN YPARXEI EGGRAFH ME KLEIDI" MHNYMA
*/
{
	int Loc, Pred, HVal;

	SearchHashList(*HList,DelKey,&Loc,&Pred);
	if(Loc!=-1)
	{
		if(Pred!=-1)
		{
			HList->List[Pred].Link=HList->List[Loc].Link;
		}
		else
		{
			HVal=HashKey(DelKey);
		    HList->HashTable[HVal]=HList->List[Loc].Link;
		}
		HList->List[Loc].Link=HList->StackPtr;
		HList->StackPtr=Loc;
		HList->Size=HList->Size -1;
	}
	else
	{
		printf("DEN YPARXEI  EGGRAFH ME KLEIDI %d \n",DelKey);
	}
}


