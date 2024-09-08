#include <stdio.h>
#include <stdlib.h>

#define StackLimit 6

typedef  char  StackElementType;
typedef struct  {
    int Top;
    StackElementType Element[StackLimit];
} StackType;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackType *Stack);
boolean EmptyStack(StackType Stack);
boolean FullStack(StackType Stack);
void Push(StackType *Stack, StackElementType Item);
void Pop(StackType *Stack, StackElementType *Item);


void TraverseStack(StackType Stack);


int main()
{
    StackType Stack1,Stack2,Stack3;
    char Item;
    CreateStack(&Stack1);
    CreateStack(&Stack2);
    CreateStack(&Stack3);
    printf("Stack1\n");
    Push(&Stack1,'P');
    Push(&Stack1,'A');
    Push(&Stack1,'S');
    Push(&Stack1,'C');
    Push(&Stack1,'A');
    Push(&Stack1,'L');
    TraverseStack(Stack1);
    while(!EmptyStack(Stack1))
    {

        Pop(&Stack1,&Item);
        Push(&Stack2,Item);

    }

    printf("\n");
    printf("Stack2\n");

    TraverseStack(Stack2);


while(!EmptyStack(Stack2))
    {

        Pop(&Stack2,&Item);
        Push(&Stack3,Item);
    }
    printf("\n");
    printf("Stack3\n");

    TraverseStack(Stack3);

    while(!EmptyStack(Stack3))
    {
        Push(&Stack1,Stack3.Element[Stack3.Top]);
        Pop(&Stack3,&Item);
    }


    printf("\n");
    printf("Stack1\n");
    TraverseStack(Stack1);






    printf("\n");
    system("pause");
    return 0;
}

void CreateStack(StackType *Stack)
/* Λειτουργία: Δημιουργεί μια κενή στοίβα.
   Επιστρέφει: Κενή Στοίβα.*
*/
{
    Stack -> Top = -1;
   // (*Stack).Top = -1;
}

boolean EmptyStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι κενή.
   Επιστρέφει: True αν η Stack είναι κενή, False διαφορετικά
*/
{
    return (Stack.Top == -1);
}

boolean FullStack(StackType Stack)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Ελέγχει αν η στοίβα Stack είναι γεμάτη.
   Επιστρέφει: True αν η Stack είναι γεμάτη, False διαφορετικά
*/
{
    return (Stack.Top == (StackLimit - 1));
}

void Push(StackType *Stack, StackElementType Item)
/* Δέχεται: Μια στοίβα Stack και ένα στοιχείο Item.
   Λειτουργία: Εισάγει το στοιχείο Item στην στοίβα Stack αν η Stack δεν είναι γεμάτη.
   Επιστρέφει: Την τροποποιημένη Stack.
   Έξοδος: Μήνυμα γεμάτης στοίβας, αν η στοίβα Stack είναι γεμάτη
*/
{
    if (!FullStack(*Stack)) {
        Stack -> Top++;
        Stack -> Element[Stack -> Top] = Item;
    } else
        printf("Full Stack...");
}

void Pop(StackType *Stack, StackElementType *Item)
/* Δέχεται: Μια στοίβα Stack.
   Λειτουργία: Διαγράφει το στοιχείο Item από την κορυφή της Στοίβας αν η Στοίβα δεν είναι κενή.
   Επιστρέφει: Το στοιχείο Item και την τροποποιημένη Stack.
   Έξοδος:  Μήνυμα κενής στοίβας αν η Stack είναι κενή
*/
{
    if (!EmptyStack(*Stack)) {
        *Item = Stack -> Element[Stack -> Top];
        Stack -> Top--;
    } else
        printf("Empty Stack...");
}




void TraverseStack(StackType Stack)
{
    int i;
    printf("\nplithos sto stack %d\n",Stack.Top+1);
    for (i=0 ;i<Stack.Top+1 ;i++) {
        printf("%c, ",Stack.Element[i]);
    }
    printf("\n");
}

