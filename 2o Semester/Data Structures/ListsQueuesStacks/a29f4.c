#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>



typedef float StackElementType;
typedef struct StackNode *StackPointer;
typedef struct StackNode
{
	StackElementType Data;
    StackPointer Next;
} StackNode;

typedef enum {
    FALSE, TRUE
} boolean;

void CreateStack(StackPointer *Stack);
boolean EmptyStack(StackPointer Stack);
void Push(StackPointer *Stack, StackElementType Item);
void Pop(StackPointer *Stack, StackElementType *Item);


void TraverseStack(StackPointer Stack);

void ReadData(StackPointer *Stack,StackPointer *NewStack, StackElementType baros);

int main()
{
    StackPointer Stack,NewStack;
    StackElementType Sum,kostos,baros,aksia;


    boolean flag;


    CreateStack(&Stack);
    CreateStack(&NewStack);
    Push(&Stack,3);
    Push(&Stack,2);
    Push(&Stack,1);
    Push(&Stack,0.5);
    Push(&Stack,0.4);
    Sum=6.9;
    flag=FALSE;

    do
    {
         printf("Give the weight: ");
         scanf("%f",&baros);
         kostos=(baros*300);

         if(baros>0)
         {
             printf("Give the value: ");
             scanf("%f",&aksia);
            if(aksia>0)
            {
                if(Sum+baros<=10 &&  aksia >= kostos)
                 {

                    if(baros<=Stack->Data)
                    {
                      Push(&Stack,baros);
                      printf("--Platform--\n");
                      TraverseStack(NewStack);
                      printf("--Truck--\n");
                      TraverseStack(Stack);
                    }
                   else
                    {
                       ReadData(&Stack,&NewStack,baros);
                       Sum=Sum+baros;
                    }
                 }
                else
                {
                        printf("Not enough value\n");
                }

            }
            else
             {
                flag=TRUE;
             }
         }
         else
         {
             flag=TRUE;
         }
         fflush(stdin);
    }while(flag==FALSE);

    printf("--Truck--\n");
    TraverseStack(Stack);


    system("pause");
	return 0;


}




void ReadData(StackPointer *Stack,StackPointer *NewStack, StackElementType baros)
{


    StackPointer current,currPtr;
    boolean flag=FALSE;
    StackElementType tmp,temp;




     if(EmptyStack(*Stack))
     {
         printf("EMPTY Stack\n");
     }
     else
     {


          while(!EmptyStack(*Stack)&& flag==FALSE)
          {
              tmp = current->Data;
              Pop(Stack,&tmp);

              if(tmp<baros)
              {
                Push(NewStack,tmp);
              }
              else
              {
                  Push(Stack,tmp);
                  flag=TRUE;
              }
         }
          Push(Stack,baros);
          printf("--Platform--\n");
          TraverseStack(*NewStack);
          printf("--Truck--\n");
          TraverseStack(*Stack);


            while(!EmptyStack(*NewStack))
                {
                    temp=currPtr->Data;
                    Pop(NewStack,&temp);
                    Push(Stack,temp);


                }

    }
}












void CreateStack(StackPointer *Stack)
/* ����������: ���������� ��� ���� ����������� ������.
   ����������: ��� ���� ����������� ������, Stack
*/
{
	*Stack = NULL;
}

boolean EmptyStack(StackPointer Stack)
/* �������:     ��� ����������� ������, Stack.
   ����������:  ������� �� � Stack ����� ����.
   ����������:  TRUE �� � ������ ����� ����, FALSE �����������
*/
{
	return (Stack==NULL);
}

void Push(StackPointer *Stack, StackElementType Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ���
                ������ Stack ��� ��� �������� Item.
   ����������: ������� ���� ������ ��� ������������ �������, �� �������� Item.
   ����������: ��� ������������� ����������� ������
*/
{
	StackPointer TempPtr;

    TempPtr= (StackPointer)malloc(sizeof(struct StackNode));
    TempPtr->Data = Item;
    TempPtr->Next = *Stack;
    *Stack = TempPtr;
}

void Pop(StackPointer *Stack, StackElementType *Item)
/* �������:    ��� ����������� ������ ��� � ������ ��� �������������� ��� ��� ������ Stack.
   ����������: ������� ��� ��� ������ ��� ������������ �������,
                �� � ������ ��� ����� ����, �� �������� Item.
   ����������: ��� ������������� ����������� ������ ��� �� �������� Item.
   ������:     ������ ����� �������, �� � ����������� ������ ����� ����
*/
{
    StackPointer TempPtr;

    if (EmptyStack(*Stack)) {
   	    printf("EMPTY Stack\n");
    }
   else
   {
        TempPtr = *Stack;
        *Item=TempPtr->Data;
        *Stack = TempPtr->Next;
        free(TempPtr);
    }
}


void TraverseStack(StackPointer Stack)
{
	StackPointer CurrPtr;

   if (EmptyStack(Stack))
   {
   	    printf("EMPTY Stack\n");
    }
   else
   {
   	    CurrPtr = Stack;
         while ( CurrPtr!=NULL )
        {
      	     printf("%.1f\n", CurrPtr->Data);
             CurrPtr = CurrPtr->Next;
        }
   }
    printf("\n");
}




