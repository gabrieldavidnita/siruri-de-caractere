#ifndef FISA3_H_INCLUDED
#define FISA3_H_INCLUDED
#include <cstring>
#include <iostream>
void majusculeCuvinte(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(i==0||s[i-1]==' ')
        {
            if(s[i]>='a'&&s[i]<='z')
                s[i]=s[i]-'a'+'A';
        }
    }
}

void sol1()
{
    char s[1000]="ana are mere";
    majusculeCuvinte(s);
    cout<<s;
}



void stergeVocale(char s[])
{
    for(int i=0;s[i]!='\0';i++)
    {
        if(strchr("aeiouAEIOU",s[i])!=NULL)
        {
            for(int j=i;s[j]!='\0';j++)
                s[j]=s[j+1];
            i--;
        }
    }
}

void sol2()
{
    char s[1000]="informatica";
    stergeVocale(s);
    cout<<s;
}



void normalizeazaSpatii(char s[])
{
    int k=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' ')
        {
            s[k]=s[i];
            k++;
        }
        else
        {
            if(k>0&&s[k-1]!=' ')
            {
                s[k]=' ';
                k++;
            }
        }
    }

    if(k>0&&s[k-1]==' ')
        k--;

    s[k]='\0';
}

void sol3()
{
    char s[1000]="  Ana   are  mere  ";
    normalizeazaSpatii(s);
    cout<<"["<<s<<"]";
}


void dubleazaVocale(char s[])
{
    int n=strlen(s);
    for(int i=0;s[i]!='\0';i++)
    {
        if(strchr("aeiouAEIOU",s[i])!=NULL)
        {
            for(int j=n;j>=i+1;j--)
                s[j+1]=s[j];

            s[i+1]=s[i];
            n++;
            i++;
        }
    }
}

void sol4()
{
    char s[1000]="mere";
    dubleazaVocale(s);
    cout<<s;
}


// 5 , 6

void literaFrecventa(char s[])
{
    int f[26]={0};

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            f[s[i]-'a']++;
    }

    int poz=0;

    for(int i=1;i<26;i++)
        if(f[i]>f[poz])
            poz=i;

    if(f[poz]>0)
        cout<<char('a'+poz)<<" "<<f[poz];
    else
        cout<<"nu exista";
}

void sol7()
{
    char s[1000]="ana are mere";
    literaFrecventa(s);
}


void cezar(char s[],int k)
{
    k=(k%26+26)%26;

    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]>='a'&&s[i]<='z')
            s[i]='a'+(s[i]-'a'+k)%26;
    }
}

void sol8()
{
    char s[1000]="zebra";
    int k=2;
    cezar(s,k);
    cout<<s;
}

// 9, 10, 11, 12, 13?
#endif // FISA3_H_INCLUDED
