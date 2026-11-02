#ifndef FISA6_H_INCLUDED
#define FISA6_H_INCLUDED
#include <cstring>
#include <iostream>
bool eVocala(char c)
{
    char v[]="aeiouAEIOU";
    for(int i=0;v[i]!='\0';i++)
        if(v[i]==c)
            return true;
    return false;
}

bool eSeparator(char c)
{
    char v[]=" ,.;:!?";
    for(int i=0;v[i]!='\0';i++)
        if(v[i]==c)
            return true;
    return false;
}


void alTreileaCuvant(char s[])
{
    char cuv[201];
    int i=0,nr=0;

    while(s[i]!='\0')
    {
        while(eSeparator(s[i]))
            i++;

        int k=0;
        while(s[i]!='\0'&&!eSeparator(s[i]))
            cuv[k++]=s[i++];

        cuv[k]='\0';

        if(k>0)
        {
            nr++;
            if(nr==3)
            {
                strcpy(s,cuv);
                return;
            }
        }
    }

    strcpy(s,"nu exista");
}

void sol1()
{
    char s[201]="unu, doi;; trei!! patru";
    alTreileaCuvant(s);
    cout<<s;
}

void celeMaiMulteVocale(char s[])
{
    char cuv[201],maxim[201]="";
    int i=0,nrmax=-1;

    while(s[i]!='\0')
    {
        while(eSeparator(s[i]))
            i++;

        int k=0;
        while(s[i]!='\0'&&!eSeparator(s[i]))
            cuv[k++]=s[i++];

        cuv[k]='\0';

        if(k>0)
        {
            int nr=0;

            for(int j=0;cuv[j]!='\0';j++)
                if(eVocala(cuv[j]))
                    nr++;

            if(nr>nrmax)
            {
                nrmax=nr;
                strcpy(maxim,cuv);
            }
        }
    }

    if(nrmax==-1)
        strcpy(s,"nu exista");
    else
        strcpy(s,maxim);
}

void sol2()
{
    char s[201]="ana, mere si portocale.";
    celeMaiMulteVocale(s);
    cout<<s;
}

void incepCuPrimul(char s[])
{
    char cuv[201],primul[201]="",rezultat[201]="";
    int i=0;

    while(s[i]!='\0')
    {
        while(eSeparator(s[i]))
            i++;

        int k=0;
        while(s[i]!='\0'&&!eSeparator(s[i]))
            cuv[k++]=s[i++];

        cuv[k]='\0';

        if(k>0)
        {
            if(primul[0]=='\0')
                strcpy(primul,cuv);
            else
            {
                int n=strlen(primul);
                bool incepe=true;

                if(strlen(cuv)<n)
                    incepe=false;
                else
                {
                    for(int j=0;j<n;j++)
                        if(cuv[j]!=primul[j])
                            incepe=false;
                }

                if(incepe)
                {
                    if(rezultat[0]!='\0')
                        strcat(rezultat," ");

                    strcat(rezultat,cuv);
                }
            }
        }
    }

    if(rezultat[0]=='\0')
        strcpy(s,"nu exista");
    else
        strcpy(s,rezultat);
}

void sol3()
{
    char s[201]="cas, casa; casca: masa! casuta cas";
    incepCuPrimul(s);
    cout<<s;
}

//5?


bool palindrom(char s[])
{
    int n=strlen(s);

    for(int i=0;i<n/2;i++)
        if(s[i]!=s[n-1-i])
            return false;

    return true;
}

void doarPalindroame(char s[])
{
    char cuv[201],rezultat[201]="";
    int i=0;

    while(s[i]!='\0')
    {
        while(eSeparator(s[i]))
            i++;

        int k=0;
        while(s[i]!='\0'&&!eSeparator(s[i]))
            cuv[k++]=s[i++];

        cuv[k]='\0';

        if(k>0&&palindrom(cuv))
        {
            if(rezultat[0]!='\0')
                strcat(rezultat," ");

            strcat(rezultat,cuv);
        }
    }

    if(rezultat[0]=='\0')
        strcpy(s,"nu exista");
    else
        strcpy(s,rezultat);
}

void sol6()
{
    char s[201]="ana are ou, ele si rar!";
    doarPalindroame(s);
    cout<<s;
}

void eliminaVocale(char s[])
{
    int prima=-1,ultima=-1;

    for(int i=0;s[i]!='\0';i++)
    {
        if(eVocala(s[i]))
        {
            if(prima==-1)
                prima=i;

            ultima=i;
        }
    }

    char rezultat[21];
    int k=0;

    for(int i=0;s[i]!='\0';i++)
    {
        if(i!=prima&&i!=ultima)
            rezultat[k++]=s[i];
    }

    rezultat[k]='\0';
    strcpy(s,rezultat);
}

void sol7()
{
    char s[21]="bacalaureat";
    eliminaVocale(s);
    cout<<s;
}

// 8 , 9?
#endif // FISA6_H_INCLUDED
