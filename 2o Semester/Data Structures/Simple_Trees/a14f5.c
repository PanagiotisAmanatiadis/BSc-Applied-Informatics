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
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean EmptyBST(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{   return (Root==NULL);
}

void BSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���
                ��� ��� ������ ��� ������ �����.
   ����������: � Found ���� ���� TRUE, � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue ��� � Parent ������� ���� ������
                ����� ��� ������, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE.
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
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
  ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer
   n,                   //������� ���� ����� ��� �������� ��� ���� KeyValue *)
   Parent,              // ������� ��� n � ��� nNext
   nNext,               // ����������������� �������� ��� n
   SubTree;             // ������� ���� ��������� ��� n
   boolean Found;       // TRUE AN TO �������� KeyValue EINAI ������� ��� ��� *)

     BSTSearch2(*Root, KeyValue, &Found , &n, &Parent);
     if (!Found)
        printf("TO STOIXEIO %s DEN EINAI STO DDA\n", KeyValue.name);
     else {
          if (n->LChild != NULL && n->RChild != NULL)
          {  // ������ ���� �������� �� ��� ������
                 //���� ��� ���������������� ������� ��� ��� ������ ���
                 nNext = n->RChild;
                 Parent = n;
                 while (nNext->LChild !=NULL)  //* DIASXISH PROS TA ARISTERA *)
                 {
                      Parent = nNext;
                      nNext = nNext->LChild;
                 }
                /* ��������� ��� ������������ ��� nNext ���� n ���
                ������ ��� n ���� �� ������� ���� ������� */
                n->Data = nNext->Data;
                n = nNext;
          } //����������� �� ��� ��������� ��� � ������ ���� �� ���� 1 �����
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
*/
{
    if (Root!=NULL) {
        InorderTraversal(Root->LChild);
        printf("%s, %s, %d",Root->Data.name, Root->Data.number, Root->Data.pass);
        printf("\n");
        InorderTraversal(Root->RChild);
    }
}


