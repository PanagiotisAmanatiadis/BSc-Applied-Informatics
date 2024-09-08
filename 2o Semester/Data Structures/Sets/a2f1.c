// * Filename: setadt.c

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


#define megisto_plithos 255         //������� ������ ��������� �������

typedef enum {
    FALSE, TRUE
} boolean;

typedef boolean typos_synolou[megisto_plithos];
typedef int stoixeio_synolou;

void Dimiourgia(typos_synolou synolo);
void Katholiko(typos_synolou synolo);
void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo);
void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo);
boolean KenoSynolo(typos_synolou synolo);
boolean IsaSynola(typos_synolou s1, typos_synolou s2);
boolean Yposynolo(typos_synolou s1, typos_synolou s2);
void EnosiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou enosi);
void TomiSynolou(typos_synolou s1, typos_synolou s2, typos_synolou tomi);
void DiaforaSynolou(typos_synolou s1, typos_synolou s2, typos_synolou diafora);


boolean isValidInteger(typos_synolou CharacterSet,typos_synolou DigitSet,int g[]);
boolean isValidIdentifier(typos_synolou LetterSet,typos_synolou DigitSet,int g[]);




int main()
{
    int i,j,g[100];
    char s[100],choise;
    typos_synolou CharacterSet, DigitSet, LetterSet;

    Dimiourgia(CharacterSet);
    Dimiourgia(DigitSet);
    Dimiourgia(LetterSet);


    Eisagogi(43,CharacterSet);
    Eisagogi(45,CharacterSet);

    for(i=48; i<=57; i++)
    {
        Eisagogi(i,DigitSet);
    }
     for(i=65; i<=90; i++)
    {
        Eisagogi(i,LetterSet);
    }
     for(i=97; i<=122; i++)
    {
        Eisagogi(i,LetterSet);
    }
    Eisagogi(95,LetterSet);
    do{
        printf("Give an integer: ");
        scanf("%s",s);

        j=0;
        for(i=0; s[i]!='\0'; i++)
        {
            g[j]=s[i];
            j++;
        }
        if(isValidInteger(CharacterSet,DigitSet,g))
        {
            printf("Valid integer\n");

        }
        else
        {
            printf("Not a valid integer\n");
        }
        do{
            printf("Continue with more integers: Y or N? :");
            fflush(stdin);
            scanf("%c",&choise);
        }while(toupper(choise)!='Y'&&toupper(choise)!='N');
    }while(toupper(choise) !='N' );
    do{
        printf("Give an identifier: ");
        scanf("%s",s);

        j=0;
        for(i=0; s[i]!='\0'; i++)
        {
            g[j]=s[i];
            j++;

        }
        if(isValidIdentifier(LetterSet,DigitSet,g))
        {
            printf("Valid identifier\n");

        }
        else
        {
            printf("Not a valid identifier\n");
        }
        do{
            printf("Continue with more identifiers: Y or N? :");
            fflush(stdin);
            scanf("%c",&choise);
        }while(choise!='Y'||choise!='y'||choise!='N'||choise!='n');
    }while(choise =='Y' && choise=='y');


}
boolean isValidInteger(typos_synolou CharacterSet,typos_synolou DigitSet,int g[100])
{
    int i;
    boolean flag=TRUE;

    if(!(Melos(g[0],CharacterSet) &&  Melos(g[0],DigitSet)))
    {
        flag=FALSE;
    }
    else
    {
        i=1;
        while(i<=100 && flag)
        {
            if(Melos(g[i],DigitSet))
            {
                flag =FALSE;
            }
           i++;
        }
    }
    return flag;
}
boolean isValidIdentifier(typos_synolou LetterSet,typos_synolou DigitSet,int g[])
{
    int i;
    boolean flag=TRUE;

    if (!Melos(g[0],LetterSet))
    {
        flag = FALSE;
    }
    else
    {
        i=1;
        while(i<=100 && flag)
        {
            if(Melos(g[i],LetterSet)||Melos(g[i],DigitSet)||g[i]==95)
            {
                flag = FALSE;
            }
            else
            {
                i++;
            }
        }
    }
    return flag;
}



void Dimiourgia(typos_synolou synolo)
/* ����������: ���������� ��� ������ ����� ��������, ������ �� ���� ������.
   ����������: �� ���� ������
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = FALSE;
}

void Katholiko(typos_synolou synolo)
/* �������:     ��� ������.
   ����������: ���������� ��� ������ �� ��� �� �������� �������,
                ���� ���� �������� ��� ����� �������� ��� ������������.
   ����������: �� �������� ������ ��� �������������
*/
{
    stoixeio_synolou i;

    for (i = 0; i < megisto_plithos; i++)
        synolo[i] = TRUE;
}

void Eisagogi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �������� ��� ������.
   ����������: �� ������������� ������
*/
{
    synolo[stoixeio] = TRUE;
}

void Diagrafi(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:     ��� ������ ��� ��� ��������.
   ����������:  ��������� �� �������� ��� �� ������.
   ����������:  �� ������������� ������
*/
{
    synolo[stoixeio] = FALSE;
}

boolean Melos(stoixeio_synolou stoixeio, typos_synolou synolo)
/* �������:    ��� ������ ��� ��� ��������.
   ����������: ������� �� �� �������� ����� ����� ��� �������.
   ����������: ���������� TRUE �� �� �������� ����� ����� ��� ��� FALSE �����������
*/
{
    return synolo[stoixeio];
}

boolean KenoSynolo(typos_synolou synolo)
/*
�������: ��� ������.
 ����������: ������� �� �� ������ ����� ����.
 ����������: ���������� TRUE �� �� ������ ����� ���� ��� FALSE �����������
*/
{
    stoixeio_synolou i;
    boolean keno;

    keno=TRUE;
    i = 0;

    while (i < megisto_plithos  && keno) {
        if (Melos(i, synolo))
            keno = FALSE;
        else
            i++;
    }
    return keno;
}

boolean IsaSynola(typos_synolou s1, typos_synolou s2)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ������� �� �� ��� ������ ����� ���.
   ����������: ���������� TRUE �� �� ��� ������ ����� �� ���� �������� ��� FALSE �����������
*/
{
    stoixeio_synolou i;
    boolean isa;

    isa = TRUE;
    i=0;
    while (i < megisto_plithos && isa)
        if (Melos(i,s1) != Melos(i,s2))
            isa = FALSE;
        else
            i++;
    return isa;
}

boolean Yposynolo(typos_synolou s1, typos_synolou s2)
/* �������:     ��� ������ s1 ��� s2.
   ����������: ������� �� �� ������ s1 ����� ��������� ��� s2.
   ����������: ���������� true �� �� ������ s1 ����� ��� ��������� ��� s2,
                ������ �� ���� �������� ��� s1 ����� ��� �������� ��� s2
*/
{
    stoixeio_synolou i;
    boolean yposyn;

    yposyn = TRUE;
    i=0;
    while (i < megisto_plithos && yposyn)
        if (Melos(i, s1) && !Melos(i, s2))
            yposyn = FALSE;
        else
            i++;
    return yposyn;
}
