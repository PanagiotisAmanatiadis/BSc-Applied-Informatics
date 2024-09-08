
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char userid[8];
}QueueElementType;
typedef struct QueueNode *QueuePointer;

typedef struct QueueNode
{
	QueueElementType Data;
    QueuePointer Next;
} QueueNode;

typedef struct
{
    QueuePointer Front;
    QueuePointer Rear;
} QueueType;

typedef enum {
    FALSE, TRUE
} boolean;


void CreateQ(QueueType *Queue);
boolean EmptyQ(QueueType Queue);
void AddQ(QueueType *Queue, QueueElementType Item);
void RemoveQ(QueueType *Queue, QueueElementType *Item);

void TraverseQ(QueueType Queue);

boolean search_for_userid(QueueElementType Item);
boolean search_in_Q(QueueType Queue,QueueElementType Item);

int main()
{


    QueueElementType Item;
    boolean foundInFile;
    boolean foundInQ;
    char choice = 'Y';

    QueueType Queue;


    CreateQ(&Queue);

    do{
        printf("USERNAME: ");
        scanf("%s",&Item.userid);
        fflush(stdin);

        foundInFile=search_for_userid(Item);

        if(!foundInFile) printf("Wrong user ID\n");
        else{

            foundInQ=search_in_Q(Queue,Item);
            if(foundInQ)
            {

                printf("You have logged in to the system from another terminal. New access is forbidden\n");
            }
            else
            {
                AddQ(&Queue,Item);
            }
        }

        printf("New entry? Y/N: ");
        scanf("%s",&choice);
        choice=toupper(choice);
    }while(choice!='N');

   TraverseQ(Queue);
   system("pause");
   return 0;
}

boolean search_for_userid(QueueElementType Item){

    char str[8];
    FILE *infile;

    if((infile=fopen("I11f4.dat","r"))==NULL)
        printf("Problem opening file...\n");
    else{
        while(!feof(infile))
        {
            fscanf(infile,"%s",&str);

            if(strcmp(str,Item.userid)==0)
            {
                fclose(infile);
                return TRUE;
            }
        }
    }
    fclose(infile);
    return FALSE;
}

boolean search_in_Q(QueueType Queue,QueueElementType Item){
    QueuePointer CurrPtr = Queue.Front;

    while(CurrPtr!=NULL&&CurrPtr->Next!=Queue.Rear){
        if(strcmp(CurrPtr->Data.userid,Item.userid)==0){
            return TRUE;
        }
        CurrPtr=CurrPtr->Next;
    }
    return FALSE;

}

void CreateQ(QueueType *Queue)
/* Λειτουργία: Δημιουργεί μια κενή συνδεδεμένη ουρά.
   Επιστρέφει: Μια κενή συνδεδεμένη ουρά
*/
{
	Queue->Front = NULL;
	Queue->Rear = NULL;
}

boolean EmptyQ(QueueType Queue)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Ελέγχει αν η συνδεδεμένη ουρά είναι κενή.
   Επιστρέφει: True αν η ουρά είναι κενή, false  διαφορετικά
*/
{
	return (Queue.Front==NULL);
}

void AddQ(QueueType *Queue, QueueElementType Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά Queue και ένα  στοιχείο Item.
   Λειτουργία: Προσθέτει το στοιχείο Item στο τέλος της συνδεδεμένης ουράς Queue.
   Επιστρέφει: Την τροποποιημένη ουρά
*/
{
	QueuePointer TempPtr;

    TempPtr= (QueuePointer)malloc(sizeof(struct QueueNode));
    TempPtr->Data = Item;
    TempPtr->Next = NULL;
    if (Queue->Front==NULL)
        Queue->Front=TempPtr;
    else
        Queue->Rear->Next = TempPtr;
    Queue->Rear=TempPtr;
}

void RemoveQ(QueueType *Queue, QueueElementType *Item)
/* Δέχεται:    Μια συνδεδεμένη ουρά.
   Λειτουργία: Αφαιρεί το στοιχείο Item από την  κορυφή της συνδεδεμένης ουράς,
                αν δεν είναι  κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη συνδεδεμένη ουρά.
   Έξοδος:     Μήνυμα κενής ουράς, αν η ουρά είναι  κενή
*/
{
    QueuePointer TempPtr;

    if (EmptyQ(*Queue)) {
   	    printf("EMPTY Queue\n");
    }
   else
   {
        TempPtr = Queue->Front;
        *Item=TempPtr->Data;
        Queue->Front = Queue->Front->Next;
        free(TempPtr);
        if (Queue->Front==NULL) Queue->Rear=NULL;
    }
}
void TraverseQ(QueueType Queue)
{
	QueuePointer CurrPtr;

   if (EmptyQ(Queue))
    {
   	    printf("EMPTY Queue\n");
    }
   else
   {
   	    CurrPtr = Queue.Front;
         while ( CurrPtr!=NULL )
        {
      	     printf("%s ", CurrPtr->Data.userid);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}


