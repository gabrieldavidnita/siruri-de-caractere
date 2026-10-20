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


#endif // FISA2_H_INCLUDED
