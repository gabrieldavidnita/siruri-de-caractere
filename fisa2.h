#ifndef FISA2_H_INCLUDED
#define FISA2_H_INCLUDED
#include <cstring>
#include <iostream>
using namespace std;



void celMaiLung(char a[], char b[])
{
    if(strlen(a)>strlen(b))
    {
        cout<<a;
    }else{
        cout<<b;
    }
}



void sol1(){
    char a[100]="Ana are mere", b[100]="Ana fura mere galbene";

    cout<<"Cel mai lung este"<<endl;
    celMaiLung(a,b);

}


void copieModificata(char s[])
{
    char copie[100];
    strcpy(copie,s);
    copie[0]='X';
    cout<<s<< " " << copie;

}


void sol2()
{
    char s[100]="Ana";
    copieModificata(s);
}



void lipsesteTrei(char a[], char b[], char c[], char rezultat[])
{
    strcpy(rezultat, a);
    strcat(rezultat, " ");
    strcat(rezultat, b);
    strcat(rezultat, " ");
    strcat(rezultat, c);

}

void sol3()
{
    char a[]="Ana",  b[]="are",  c[]="mere",  rezultat[]="Ana are mere";
    lipsesteTrei(a,b,c,rezultat);
    cout<<rezultat;
}


void verificaParola(char parola[])
{
    if(strcmp(parola, "mcs2026")==0 )
    {
        cout<<"Corect";
    }else
    {
        cout<<"Gresit";
    }
}

void sol4()
{
    char parola[101]="mcs2026";
    verificaParola(parola);

}

void primulAlfabetic(char cuvinte[][100], int n )
{
    char primul[100];
    strcpy(primul , cuvinte[0]);
    for(int i=1; i<n ; i++)
    {
        if(strcmp(cuvinte[i], primul)<0)
            strcpy(primul, cuvinte[i]);

    }
     cout<<primul;
}
void sol5()
{
     char cuvinte[100][100]={"pere","mere" ,"ana", "caise"};
     int n= 4;
     primulAlfabetic(cuvinte,n);
s
}

void cautaCaracter(char s[] , char c)
{
    bool gasit=false;
    int i=0;
    for(; s[i]!= '\0' &&gasit==false ; i++)
    {
        if(s[i]==c)
        {
           gasit=true;

        }
    }
    if(gasit){
        cout<<"Da "<<i<<endl;
    }else{
        cout<<"Nu "<<endl;

     }
}


void sol6()
{
    char s[100]="Ana are mere";
    char c='a';
    cautaCaracter(s,c);
}

void extensie(char fisier[]){



       int poz=-1;
      for(int i=strlen(fisier)-1;i>=0&&poz==-1;i--){

           if(fisier[i]=='.'){
              poz=i;
           }

      }
      for(int i=poz+1;i<strlen(fisier);i++){
          cout<<fisier[i];
      }

}


void sol7()
{
    char fisier[100]="tema.main.txt";
    extensie(fisier);
}


void aparitiiCaracter(char s[], char c)
{
    int nr=0;
    for(int i=0; s[i]!= '\0' ; i++)
    {
        if(s[i]==c)
            nr++;
    }
    cout<<nr;
}

void sol8()
{
    char s[100]="Ana are mere" ;
    char c='e';
    aparitiiCaracter(s,c);
}


void aparitiiSecventa(char s[],char t[])
{
    int nr=0;
    int n=strlen(s);
    int m=strlen(t);

    if(m==0)
    {
        cout<<0;
        return;
    }

    for(int i=0;i<=n-m;i++)
    {
        int j=0;
        for(;j<m&&s[i+j]==t[j];j++)
        {
        }
        if(j==m)
            nr++;
    }
    cout<<nr;
}

void sol9()
{
    char s[100]="Ana are mere";
    char t[100]="re";
    aparitiiSecventa(s,t);
}

void numarCuvinte(char s[])
{
    int nr=0;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' '&&s[i]!=','&&s[i]!='.')
        {
            if(i==0||s[i-1]==' '||s[i-1]==','||s[i-1]=='.')
                nr++;
        }
    }
    cout<<nr;
}

void sol10()
{
    char s[100]="Ana, are mere.";
    numarCuvinte(s);
}



//11 ?


void aparitiiCuvant(char s[],char cuvant[])
{
    int nr=0;
    char cuv[100];
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]!=' '&&s[i]!=','&&s[i]!='.')
        {
            int k=0;
            int j;
            for(j=i;s[j]!='\0'&&s[j]!=' '&&s[j]!=','&&s[j]!='.';j++)
            {
                cuv[k]=s[j];
                k++;
            }
            cuv[k]='\0';

            if(strcmp(cuv,cuvant)==0)
                nr++;

            i=j-1;
        }
    }
    cout<<nr;
}

void sol12()
{
    char s[100]="Ana are mere care are";
    char cuvant[100]="are";
    aparitiiCuvant(s,cuvant);
}
#endif // FISA2_H_INCLUDED
