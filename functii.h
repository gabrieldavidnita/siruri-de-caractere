#ifndef FUNCTII_H_INCLUDED
#define FUNCTII_H_INCLUDED
#include <cstring>
#include <iostream>
using namespace std;


void citire()
{
    char s[100] = "" ;
  //  cin>>s;
   cin.getline(s,100);

    cout<<s<<endl;


}

void functiiPrincipale()
{

    char x[100]="David are mere";


    cout<<"======= numar caractere====================="<<endl;
    cout<<strlen(x)<<endl; //numarul de cdaractere

    cout<<"===============copiere======================="<<endl;

    char ex[100];
    strcpy(ex,x);

    cout<<ex<<endl;// copy
    cout<<"=====================concatenare================="<<endl;
    char d[100]="ceva ";
    strcat(d, "mere");
    cout<<d<<endl;
    cout<<"=====================compararea================="<<endl;
    char a[100]="aiA" ;
    char b[100]="aiA";
    cout<<strcmp(a,b);
    cout<<"=====================prima aparitie a unui caracter================="<<endl;
    char s[100]="ceva va face";
    cout<<strchr(s, 'v')-s;
    cout<<"=====================prima aparietie a unui sir================="<<endl;
    char t[100]="va ajunge acasa";
    cout<<strstr(t,"aj");

    cout<<"======================== Separarea in cuvinte cu strtok=============="<<endl;
        char cuvinte[100] = "Ana are mere ce mai faci";
        char *p = strtok(cuvinte, " ");
        while (p != NULL) {
           cout << p << endl;
           p=strtok(NULL," ");
        }

}
#endif // FUNCTII_H_INCLUDED
