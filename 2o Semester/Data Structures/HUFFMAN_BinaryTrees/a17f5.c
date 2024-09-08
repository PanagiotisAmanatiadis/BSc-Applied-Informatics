#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef  struct
{
    char data[20];
    char dummy;
}BinTreeElementType;
typedef struct BinTreeNode *BinTreePointer;
struct BinTreeNode {
    BinTreeElementType Data;
    BinTreePointer LChild, RChild;
} ;

typedef enum
{
    FALSE, TRUE
} boolean;


void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root);
void BuildDecodingTree(BinTreePointer *Root,   FILE  *CodeFile);
void Decode(BinTreePointer Root, FILE* MessageFile);
void PrintTree(FILE *t, BinTreePointer Root, int indent);






int main()
{

    FILE *t,*infile,*MessageFile;
    BinTreePointer Root;


     infile=fopen("codesRW.txt","r");
     if(infile==NULL)
        printf("Can't open codesRW.txt\n");
     else
     {
         BuildDecodingTree(&Root,infile);

         MessageFile=fopen("program.txt","r");

         if(MessageFile==NULL)
            printf("Can't open MESSAGES.TXT\n");
         else
            Decode(Root,MessageFile);

     }
     fclose(infile);
     fclose(MessageFile);

     printf("\n");
     system("pause");
     return 0;

}

void BuildDecodingTree(BinTreePointer *Root, FILE  *CodeFile)
/* ÄÅ×ÅÔÁÉ:    ÔÏ ÁÑ×ÅÉÏ CodeFile
   ËÅÉÔÏÕÑÃÈÁ: ÄÉÁÂÁÆÅÉ ÔÏÕÓ ×ÁÑÁÊÔÇÑÅÓ ÊÁÉ ÔÏÕÓ ÊÙÄÉÊÏÕÓ ÔÏÕÓ ÁÐÏ ÔÏ ÁÑ×ÅÉÏ
                CodeFile ÊÁÉ ÊÁÔÁÓÊÅÕÁÆÅÉ ÔÏ ÄÅÍÄÑÏ Huffman.
   ÅÐÉÓÔÑÅÖÅÉ: ÔÏ ÄÅÉÊÔÇ Root ÐÏÕ ÄÅÉ×ÍÅÉ ÓÔÇ ÑÉÆÁ ÔÏÕ ÄÅÍÄÑÏÕ Huffman.
*/
{
  char  ch[20],termch;
  char code[10];
  int nscan;




    (*Root) = (BinTreePointer)malloc(sizeof (struct BinTreeNode));

    (*Root)->Data.dummy='*';

    (*Root)->LChild=NULL;
    (*Root)->RChild=NULL;
            while (TRUE)
            {
                nscan = fscanf(CodeFile,"%20[^\n] %10[^\n]%c",ch, code,&termch);

                if (nscan == EOF) break;
                AddToTree(ch, code, strlen(code), &(*Root));
                if (nscan != 3 || termch != '\n')
                {
                    break;
                    printf("Improper file format\n");
                }

            }



}




void AddToTree(char ch[], char code[], int codelen, BinTreePointer *Root)
{
  int i;
  BinTreePointer TempPtr,p;
  i =0;
  p =*Root;
  while (i<codelen)

    if (code[i]=='0')
    {
        if (p->LChild==NULL)
        {
            TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));
            TempPtr->Data.dummy='*';
            TempPtr->LChild=NULL;
            TempPtr->RChild=NULL;
            p->LChild=TempPtr;
        }
        i=i+1;
        p=p->LChild;
    }
    else
      if (code[i]=='1')
      {
          if (p->RChild==NULL)
          {
              TempPtr = (BinTreePointer)malloc(sizeof (struct BinTreeNode));

               TempPtr->Data.dummy='*';

              TempPtr->LChild=NULL;
              TempPtr->RChild=NULL;
              p->RChild=TempPtr;
          }
          i=i+1;
          p=p->RChild;
      }
      strcpy(p->Data.data,ch);




}



void Decode(BinTreePointer Root, FILE* MessageFile)
/* ÄÝ÷åôáé: ¸íá äÝíôñï Huffman êáé ìéá áêïëïõèßá áðü bits ðïõ áíáðáñéóôÜ Ýíá ìÞíõìá,
            ôï ïðïßï Ý÷åé êùäéêïðïçèåß ìå ÷ñÞóç ôïõ äÝíôñïõ Huffman.
  Ëåéôïõñãßá:  Áðïêùäéêïðïéåß ôï ìÞíõìá.
  ÅðéóôñÝöåé: Ôï áðïêùäéêïðïéçìÝíï ìÞíõìá.*)
*/
{
  char bit;
  BinTreePointer p;


        while (TRUE)
        {
            p=Root;
            while (p->LChild!=NULL || p->RChild!=NULL)
            {
                bit=fgetc(MessageFile);
                if (bit != EOF)
                {
                    printf("%c",bit);
                    if (bit=='0')
                        p=p->LChild;
                    else
                    {
                        if (bit=='1')
                            p=p->RChild;
                        else
                        {
                            if (bit!='\n')
                                printf("MH APODEKTO bit: \n", bit);
                        }
                    }
                }
                else break;
            }
             if (bit != EOF)
                printf("---%s\n",p->Data.data);
             else break;
        }
}

void PrintTree(FILE *t, BinTreePointer Root, int indent)
{
  int i;
  if (Root!=NULL)
  {
      PrintTree(t, Root->RChild, indent+8);
      for (i=1;i<=indent;i++)
        fprintf(t," ");
      fprintf(t,"%c\n", Root->Data);
      PrintTree(t, Root->LChild, indent+8);
  }
}

