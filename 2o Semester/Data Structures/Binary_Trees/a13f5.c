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
/* ����������: ���������� ��� ���� ���.
   ����������:  ��� �������� ������(NULL) Root
*/
{
    *Root = NULL;
}

boolean BSTEmpty(BinTreePointer Root)
/* �������:   ��� ��� �� �� Root �� ������� ��� ���� ���.
  ����������: ������� �� �� ��� ����� ����.
  ����������: TRUE �� �� ��� ����� ���� ��� FALSE �����������
*/
{
    return (Root==NULL);
}

void RecBSTInsert(BinTreePointer *Root, BinTreeElementType Item)
/* �������:     ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� �������� Item.
   ����������:  ������� �� �������� Item ��� ���.
   ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���
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
/* �������:    ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ������� ��� ��� ���� ����� �� ���� KeyValue ��� ����� ������ ���.
   ����������: � Found ���� ���� TRUE ��� � ������� LocPtr ������� ���� ����� ���
                �������� ��� ���� KeyValue, �� � ��������� ����� ��������.
                ����������� � Found ���� ���� FALSE
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
/* �������:  ��� ��� �� �� ������ Root �� ������� ��� ���� ��� ��� ��� ���� KeyValue.
   ����������: ��������� �� ���� ���� ����� ��� ��� ��� �� �������� ��� ����
                KeyValue ��� ����� ������ ��� �������� ��������� ��� ���,
                �� ��� ����, ��� ��������� ��� �� ���.
  ����������: �� ������������� ��� �� ��� ������ Root �� ������� ��� ���� ���.
*/
{

   BinTreePointer TempPtr;          //* true AN TO STOIXEIO KeyValue EINAI STOIXEIO TOY DDA *)

    if (BSTEmpty(*Root))          //* ����� ������ �� KeyValue �� �� ������ *)
        printf("to %s DeN BRE8HKe STO DDA\n", KeyValue);
     else
         //* ��������� ���������� ��� ����� ��� �������� ��� ���� KeyValue ��� �������� ���
          if (strcmp(KeyValue.surname ,(*Root)->Data.surname)<0)
             RecBSTDelete(&((*Root)->LChild), KeyValue);       //* �������� ��������� *
          else
            if (strcmp(KeyValue.surname ,(*Root)->Data.surname)>0)
                  RecBSTDelete(&((*Root)->RChild), KeyValue);   //* ����  ��������� *
            else                                       //* TO KeyValue ������� �������� ��� ������ *)
                if ((*Root)->LChild ==NULL)
                 {
                      TempPtr = *Root;
                      *Root = (*Root)->RChild;      //* ��� ���� �������� ����� *)
                      free(TempPtr);
                 }
                else if ((*Root)->RChild == NULL)
                   {
                        TempPtr = *Root;
                        *Root = (*Root)->LChild;      //* ���� �������� �����, ���� ��� ���� *)
                        free(TempPtr);
                   }
                   else                               //* ���� 2 ������ *)
                   {
                        //* ������ ��� INORDER �������� ��� *)
                        TempPtr = (*Root)->RChild;
                        while (TempPtr->LChild != NULL)
                              TempPtr = TempPtr->LChild;
                        /* ���������� ��� �������� ��� ����� ��� ����������
                        ��� ���������� ��� �������� ��� �������� ������ */
                        (*Root)->Data = TempPtr->Data;
                        RecBSTDelete(&((*Root)->RChild), (*Root)->Data);
                   }
}

void RecBSTInorder(BinTreePointer Root)
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ��������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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
/* �������:    ��� ������� ������ �� �� ������ Root �� ������� ���� ���� ���.
   ����������: ������� ���������������� �������� ��� �������� ������� ���
                ������������� ���� ����� ������� ��� ����.
   ���������: �� ����������� ��� ������, ��� ��������� ��� �� ����� ��� ������������
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





