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


}
// 01234567890123456789
//"Ana are mere galbene"                                           0 1 2 3 4 5           0 1 2 3 4 5
// s[i]!= '\0'   s[i]==' '    i     k   s[i]!='\0'&&s[i]!=' '      0 0 0 0 0 0     k  i  0 0 0 0 0 0   k>0   cout
//   da            nu         -     0           da                 A               1  1
//                                              da                   n             2  2
//                                              da                     a           3  3
//                                               f                                            \0       da    Ana
//  da             da          4
//                nu          -    0           da                 a                1  5
//                                             da                   r              2  6
//                                             da                     e            3  7       \0      da     are
//  da            da         8
//                nu         -     0           da                 m                1  9
//                                             da                   e              2  10
//                                             da                     r            3  11
//                                             da                       e          4  12      \0      da      mere
//
//  da            da         13
//                           -   0           da                 g                  1  14
//                                           da                   a                2  15
//                                           da                     l              3  16
//                                           da                       b            4  17
//                                           da                         e          5  18
//                                           da                           n        6  19
//                                           da                             e      7  20    \0        da      galbene
//
void spargereInCuvinte()
{
    char s[100]="Ana are mere galbene " , cuv[100];
    int i=0;
    while(s[i]!= '\0')
    {
        while(s[i]==' '){
            i++;
        }
        int k=0;
        while(s[i]!='\0'&&s[i]!=' '){
            cuv[k]=s[i];
            k++;
            i++;
        }
        cuv[k]='\0';
        if(k>0){
            cout<<cuv<<endl;
        }
    }
}
#endif // FUNCTII_H_INCLUDED
