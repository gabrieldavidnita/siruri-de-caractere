#ifndef ALGORITMI_CIFRE_SIRURI_H_INCLUDED
#define ALGORITMI_CIFRE_SIRURI_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

int nrCifre(char s[])
{
    //  s = "4738"   ->   s[0] = '4'  s[1] = '7'  s[2] = '3'  s[3] = '8'  s[4] = '\0'
    return strlen(s);
}

int cifraLa(char s[], int i)
{
    //  s = "4738" , i = 1   ->   s[1] = '7'   ->   '7' - '0' = 7
    return s[i] - '0';
}

int sumaCifre(char s[])
{
    int suma = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        suma = suma + (s[i] - '0');
    }

    return suma;
}

long long produsCifre(char s[])
{
    //  s = "405"   ->   4 * 0 * 5 = 0
    long long produs = 1;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        produs = produs * (s[i] - '0');
    }

    return produs;
}

int cifraMaxima(char s[])
{
    int maxim = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int cifra = s[i] - '0';
        if (cifra > maxim)
        {
            maxim = cifra;
        }
    }

    return maxim;
}

int cifraMinima(char s[])
{
    int minim = 9;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        int cifra = s[i] - '0';
        if (cifra < minim)
        {
            minim = cifra;
        }
    }

    return minim;
}

int primaCifra(char s[])
{
    return s[0] - '0';
}

int ultimaCifra(char s[])
{
    //  s = "4738"   ->   strlen(s) = 4   ->   ultima cifra = s[3] - '0' = 8
    return s[strlen(s) - 1] - '0';
}

void oglindit(char s[], char rez[])
{
    //  s = "4738"   ->   rez[0] = s[3] , rez[1] = s[2] , rez[2] = s[1] , rez[3] = s[0]   ->   "8374"
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        rez[i] = s[n - 1 - i];
    }
    rez[n] = '\0';
}

bool estePalindrom(char s[])
{
    //  s = "1221"   ->   s[0] cu s[3] , s[1] cu s[2]   (fara sa construiesti oglinditul)
    int n = strlen(s);
    for (int i = 0; i < n / 2; i++)
    {
        if (s[i] != s[n - 1 - i])
        {
            return false;
        }
    }

    return true;
}

int contorAparitii(char s[], int c)
{
    int nr = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] - '0' == c)
        {
            nr++;
        }
    }

    return nr;
}

bool areCifra(char s[], int c)
{
    return contorAparitii(s, c) > 0;
}

void frecventaCifre(char s[], int f[])
{
    //  s = "1213"   ->   f[1] = 2 , f[2] = 1 , f[3] = 1 , restul 0
    for (int i = 0; i <= 9; i++)
    {
        f[i] = 0;
    }

    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        f[s[i] - '0']++;
    }
}

void stergeCifra(char s[], int i)
{
    //  s = "48723" , i = 2   ->   aux = "23"   ->   s = "48" + "23" = "4823"
    if (i < 0 || i >= (int)strlen(s))
    {
        return;
    }

    char aux[256];
    strcpy(aux, s + i + 1);
    strcpy(s + i, aux);
}

void taieZerouri(char s[])
{
    //  "0307" -> "307"      "000" -> "0"      "" -> "0"
    int k = 0;
    while (s[k] == '0' && s[k + 1] != '\0')
    {
        k++;
    }

    if (k > 0)
    {
        char aux[256];
        strcpy(aux, s + k);
        strcpy(s, aux);
    }

    if (s[0] == '\0')
    {
        strcpy(s, "0");
    }
}

void eliminaCifra(char s[], int c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] - '0' == c)
        {
            stergeCifra(s, i);
        }
        else
        {
            i++;
        }
    }

    taieZerouri(s);
}

void insereaza(char s[], int i, char c)
{
    //  s = "48723" , i = 2 , c = '9'   ->   aux = "723"   ->   "48" + '9' + "723" = "489723"
    char aux[256];
    strcpy(aux, s + i);
    s[i] = c;
    strcpy(s + i + 1, aux);
}

void dublareCifra(char s[], int c)
{
    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] - '0' == c)
        {
            insereaza(s, i, s[i]);
            i = i + 2;
        }
        else
        {
            i++;
        }
    }
}

int reducere(int n)
{
    //  n = 135   ->   1 + 3 + 5 = 9      n = 98   ->   17   ->   8
    while (n >= 10)
    {
        int suma = 0;
        while (n > 0)
        {
            suma = suma + n % 10;
            n = n / 10;
        }
        n = suma;
    }

    return n;
}

int cifraControl(char s[])
{
    return reducere(sumaCifre(s));
}

void cifrePare(char s[], char rez[])
{
    //  s = "10203"   ->   rez = "020"   ->   taieZerouri   ->   "20"      s = "1357"   ->   rez = ""   ->   "0"
    int k = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if ((s[i] - '0') % 2 == 0)
        {
            rez[k] = s[i];
            k++;
        }
    }
    rez[k] = '\0';
    taieZerouri(rez);
}

void afiseazaFrecventa(char s[])
{
    int f[10];
    frecventaCifre(s, f);
    cout << s << " :" << endl;
    for (int c = 0; c <= 9; c++)
    {
        if (f[c] > 0)
        {
            cout << "cifra " << c << " apare de " << f[c] << " ori" << endl;
        }
    }
}

void exemple()
{
    char mare[] = "123456789012345678901234567890";
    char teste[][40] = { "4738", "7", "0", "10203", "1000" };
    int nt = 5;

    cout << "--- nrCifre / cifraLa ---" << endl;
    for (int i = 0; i < nt; i++)
    {
        cout << "\"" << teste[i] << "\" are " << nrCifre(teste[i]) << " cifre , prima " << cifraLa(teste[i], 0) << endl;
    }
    cout << "\"" << mare << "\" are " << nrCifre(mare) << " cifre , cifra de pe indicele 24 este " << cifraLa(mare, 24) << endl;

    cout << endl << "--- sumaCifre / produsCifre ---" << endl;
    for (int i = 0; i < nt; i++)
    {
        cout << "\"" << teste[i] << "\" : suma " << sumaCifre(teste[i]) << " , produs " << produsCifre(teste[i]) << endl;
    }
    cout << "\"" << mare << "\" : suma " << sumaCifre(mare) << endl;

    cout << endl << "--- cifraMaxima / cifraMinima ---" << endl;
    for (int i = 0; i < nt; i++)
    {
        cout << "\"" << teste[i] << "\" : maxima " << cifraMaxima(teste[i]) << " , minima " << cifraMinima(teste[i]) << endl;
    }

    cout << endl << "--- primaCifra / ultimaCifra ---" << endl;
    for (int i = 0; i < nt; i++)
    {
        cout << "\"" << teste[i] << "\" : prima " << primaCifra(teste[i]) << " , ultima " << ultimaCifra(teste[i]) << endl;
    }
    cout << "\"" << mare << "\" : prima " << primaCifra(mare) << " , ultima " << ultimaCifra(mare) << endl;

    cout << endl << "--- oglindit / estePalindrom ---" << endl;
    char p6[][40] = { "4738", "120", "1221", "7", "12345678900987654321" };
    for (int i = 0; i < 5; i++)
    {
        char rez[256];
        oglindit(p6[i], rez);
        cout << "\"" << p6[i] << "\" : oglindit \"" << rez << "\"";
        if (estePalindrom(p6[i]))
        {
            cout << " , palindrom";
        }
        cout << endl;
    }

    cout << endl << "--- contorAparitii / areCifra ---" << endl;
    char a1[] = "12321";
    char a2[] = "10203";
    cout << "\"12321\", cifra 2 : " << contorAparitii(a1, 2) << " aparitii" << endl;
    cout << "\"12321\", cifra 9 : " << contorAparitii(a1, 9) << " aparitii" << endl;
    cout << "\"10203\", cifra 0 : " << contorAparitii(a2, 0) << " aparitii" << endl;
    cout << "\"" << mare << "\", cifra 5 : " << contorAparitii(mare, 5) << " aparitii" << endl;
    if (areCifra(mare, 0))
    {
        cout << "numarul de 30 de cifre are cifra 0" << endl;
    }

    cout << endl << "--- frecventaCifre ---" << endl;
    char f1[] = "1213";
    afiseazaFrecventa(f1);

    cout << endl << "--- stergeCifra / taieZerouri / eliminaCifra ---" << endl;
    char e1[256] = "48723";
    stergeCifra(e1, 2);
    cout << "48723 fara indicele 2 : " << e1 << endl;
    char e2[256] = "0307";
    taieZerouri(e2);
    cout << "\"0307\" -> \"" << e2 << "\"" << endl;
    char e3[256] = "000";
    taieZerouri(e3);
    cout << "\"000\" -> \"" << e3 << "\"" << endl;
    char e4[256] = "10203";
    eliminaCifra(e4, 0);
    cout << "10203 fara 0 : " << e4 << endl;
    char e5[256] = "777";
    eliminaCifra(e5, 7);
    cout << "777 fara 7 : " << e5 << endl;
    char e6[256] = "30000000000000000000000000001";
    eliminaCifra(e6, 3);
    cout << "3000...01 fara 3 : " << e6 << endl;

    cout << endl << "--- insereaza / dublareCifra ---" << endl;
    char i1[256] = "48723";
    insereaza(i1, 2, '9');
    cout << "48723 , indice 2 , cifra 9 : " << i1 << endl;
    char i2[256] = "48723";
    insereaza(i2, 0, '9');
    cout << "48723 , indice 0 , cifra 9 : " << i2 << endl;
    char i3[256] = "48723";
    insereaza(i3, 5, '9');
    cout << "48723 , indice 5 , cifra 9 : " << i3 << endl;
    char i4[256] = "1213";
    dublareCifra(i4, 1);
    cout << "1213 , dublez 1 : " << i4 << endl;
    char i5[256] = "1003";
    dublareCifra(i5, 0);
    cout << "1003 , dublez 0 : " << i5 << endl;

    cout << endl << "--- cifraControl ---" << endl;
    char p11[][40] = { "9875", "6", "99", "0", "123456789012345678901234567890" };
    for (int i = 0; i < 5; i++)
    {
        cout << "\"" << p11[i] << "\" : cifra de control " << cifraControl(p11[i]) << endl;
    }

    cout << endl << "--- cifrePare ---" << endl;
    char p12[][40] = { "4738", "7", "0", "10203", "1357" };
    for (int i = 0; i < 5; i++)
    {
        char rez[256];
        cifrePare(p12[i], rez);
        cout << "\"" << p12[i] << "\" : doar cifrele pare \"" << rez << "\"" << endl;
    }
}

#endif // ALGORITMI_CIFRE_SIRURI_H_INCLUDED
