#ifndef ALGORITMI_SIRURI_H_INCLUDED
#define ALGORITMI_SIRURI_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

int lungime(char s[])
{
    //  s = "Ana"   ->   s[0] = 'A'  s[1] = 'n'  s[2] = 'a'  s[3] = '\0'
    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }

    return i;
}

int pozitiePrimulSpatiu(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == ' ')
        {
            return i;
        }
    }

    return -1;
}

bool esteMica(char c)
{
    return c >= 'a' && c <= 'z';
}

bool esteMare(char c)
{
    return c >= 'A' && c <= 'Z';
}

bool esteLitera(char c)
{
    return esteMica(c) || esteMare(c);
}

bool esteCifra(char c)
{
    return c >= '0' && c <= '9';
}

char inMajuscula(char c)
{
    //  'a' = 97 , 'A' = 65   ->   'g' - 'a' + 'A' = 'G'
    if (esteMica(c))
    {
        return c - 'a' + 'A';
    }

    return c;
}

char inMinuscula(char c)
{
    if (esteMare(c))
    {
        return c - 'A' + 'a';
    }

    return c;
}

bool esteVocala(char c)
{
    char m = inMinuscula(c);

    return m == 'a' || m == 'e' || m == 'i' || m == 'o' || m == 'u';
}

void majuscule(char s[])
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i] = inMajuscula(s[i]);
    }
}

int aparitii(char s[], char c)
{
    int nr = 0;
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == c)
        {
            nr++;
        }
    }

    return nr;
}

void frecventaLitere(char s[], int f[])
{
    //  s = "banana"   ->   f[0] = 3 ('a')   f[1] = 1 ('b')   f[13] = 2 ('n')
    for (int i = 0; i < 26; i++)
    {
        f[i] = 0;
    }

    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            f[s[i] - 'a']++;
        }
    }
}

void inverseaza(char s[])
{
    //  s = "abcd"   i = 0 , j = 3  ->  "dbca"   i = 1 , j = 2  ->  "dcba"
    int i = 0;
    int n = strlen(s);
    int j = n - 1;
    while (i < j)
    {
        char aux = s[i];
        s[i] = s[j];
        s[j] = aux;
        i++;
        j--;
    }
}

bool estePalindrom(char s[])
{
    int i = 0;
    int n = strlen(s);
    int j = n - 1;
    while (i < j)
    {
        if (s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void stergeCaracter(char s[], int i)
{
    //  s = "abcd" , i = 1   ->   aux = "cd"   ->   s = "a" + "cd" = "acd"
    char aux[256];
    strcpy(aux, s + i + 1);
    strcpy(s + i, aux);
}

void insereazaCaracter(char s[], int i, char c)
{
    //  s = "abcd" , i = 1 , c = 'X'   ->   aux = "bcd"   ->   "a" + 'X' + "bcd"
    char aux[256];
    strcpy(aux, s + i);
    s[i] = c;
    strcpy(s + i + 1, aux);
}

void concateneaza(char a[], char b[], char rez[])
{
    //  a = "ana" , b = "mere"   ->   strcpy(rez, a): "ana"   ->   strcat(rez, b): "anamere"
    strcpy(rez, a);
    strcat(rez, b);
}

bool esteInainte(char a[], char b[])
{
    //  strcmp(a, b) < 0   <=>   a vine inaintea lui b in dictionar
    return strcmp(a, b) < 0;
}

void ordoneazaCuvinte(char c[][31], int n)
{
    //  c = { "pere", "ana", "mere" }   ->   { "ana", "mere", "pere" }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (strcmp(c[i], c[j]) > 0)
            {
                char aux[31];
                strcpy(aux, c[i]);
                strcpy(c[i], c[j]);
                strcpy(c[j], aux);
            }
        }
    }
}

int pozitieCaracter(char s[], char c)
{
    char* p = strchr(s, c);
    if (p == NULL)
    {
        return -1;
    }

    return p - s;
}

int pozitieSubsir(char s[], char t[])
{
    //  s = "banana" , t = "nan"   ->   strstr intoarce adresa din s unde incepe t   ->   p - s = 2
    char* p = strstr(s, t);
    if (p == NULL)
    {
        return -1;
    }

    return p - s;
}

bool inlocuiestePrima(char s[], char vechi[], char nou[])
{
    //  s = "banana" , vechi = "an" , nou = "ANT"   ->   p = "anana"   coada = "ana"   ->   "b" + "ANT" + "ana"
    char* p = strstr(s, vechi);
    if (p == NULL)
    {
        return false;
    }

    char coada[256];
    strcpy(coada, p + strlen(vechi));
    strcpy(p, nou);
    strcat(s, coada);

    return true;
}

int numarCuvinte(char s[], char sep[])
{
    //  s = "ana are, mere" , sep = " ,"   ->   "ana"  "are"  "mere"   (strtok strica sirul: lucrezi pe o copie)
    char t[256];
    strcpy(t, s);
    int nr = 0;
    char* p = strtok(t, sep);
    while (p != NULL)
    {
        nr++;
        p = strtok(NULL, sep);
    }

    return nr;
}

int imparteCuvinte(char s[], char c[][31])
{
    char t[256];
    strcpy(t, s);
    int n = 0;
    char* p = strtok(t, " ");
    while (p != NULL)
    {
        strcpy(c[n], p);
        n++;
        p = strtok(NULL, " ");
    }

    return n;
}

int lungimeMaxima(char s[])
{
    char c[50][31];
    int n = imparteCuvinte(s, c);
    int maxim = 0;
    for (int i = 0; i < n; i++)
    {
        int lg = strlen(c[i]);
        if (lg > maxim)
        {
            maxim = lg;
        }
    }

    return maxim;
}

int sirInNumar(char s[])
{
    //  s = "472"   ->   0 * 10 + 4 = 4   ->   4 * 10 + 7 = 47   ->   47 * 10 + 2 = 472
    int n = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        n = n * 10 + (s[i] - '0');
    }

    return n;
}

void numarInSir(int n, char s[])
{
    //  n = 472   ->   cifrele de la coada: "274"   ->   inversat: "472"
    if (n == 0)
    {
        strcpy(s, "0");
        return;
    }

    int k = 0;
    while (n > 0)
    {
        s[k] = '0' + n % 10;
        k++;
        n = n / 10;
    }
    s[k] = '\0';
    inverseaza(s);
}

char deplaseaza(char c, int k)
{
    //  'x' , k = 3   ->   'x' - 'a' = 23   ->   (23 + 3) % 26 = 0   ->   'a'
    if (c >= 'a' && c <= 'z')
    {
        return 'a' + (c - 'a' + k) % 26;
    }
    if (c >= 'A' && c <= 'Z')
    {
        return 'A' + (c - 'A' + k) % 26;
    }

    return c;
}

void cezar(char s[], int k)
{
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i] = deplaseaza(s[i], k);
    }
}

void citesteLinie(char s[])
{
    //  cin >> s citeste doar pana la spatiu ("ana are" -> "ana")   ->   cin.getline citeste toata linia
    cin.getline(s, 256);
}

int citesteNumar()
{
    //  intrare "3\nana\nbob"   ->   cin >> n citeste "3" si lasa '\n'   ->   cin.get() il scoate, ca getline sa citeasca "ana"
    int n = 0;
    cin >> n;
    cin.get();

    return n;
}

void exemple()
{
    cout << "--- lungime / pozitiePrimulSpatiu ---" << endl;
    char t1[][30] = { "Ana are mere", "", "a", "   ", "fara_spatiu" };
    for (int i = 0; i < 5; i++)
    {
        cout << "\"" << t1[i] << "\" : lungime " << lungime(t1[i]) << " (strlen " << strlen(t1[i]) << ") , primul spatiu " << pozitiePrimulSpatiu(t1[i]) << endl;
    }

    cout << endl << "--- esteLitera / esteCifra / esteVocala / inMajuscula ---" << endl;
    char t2[] = { 'a', 'E', 'z', 'Q', '7', ' ' };
    for (int i = 0; i < 6; i++)
    {
        cout << "'" << t2[i] << "' : litera " << esteLitera(t2[i]) << " , cifra " << esteCifra(t2[i]) << " , vocala " << esteVocala(t2[i]) << " , majuscula '" << inMajuscula(t2[i]) << "' , minuscula '" << inMinuscula(t2[i]) << "'" << endl;
    }
    char s2[256] = "Ana are 3 Mere";
    majuscule(s2);
    cout << s2 << endl;

    cout << endl << "--- aparitii / frecventaLitere ---" << endl;
    char s3[256] = "banana";
    cout << "banana , 'a' : " << aparitii(s3, 'a') << " aparitii" << endl;
    cout << "banana , 'z' : " << aparitii(s3, 'z') << " aparitii" << endl;
    int f[26];
    frecventaLitere(s3, f);
    for (int i = 0; i < 26; i++)
    {
        if (f[i] > 0)
        {
            cout << "litera " << (char)('a' + i) << " apare de " << f[i] << " ori" << endl;
        }
    }
    char gol3[256] = "";
    cout << "sirul vid : " << aparitii(gol3, 'a') << " aparitii" << endl;

    cout << endl << "--- inverseaza / estePalindrom ---" << endl;
    char t4[][30] = { "abcd", "ana", "", "x", "ab ba" };
    for (int i = 0; i < 5; i++)
    {
        bool pal = estePalindrom(t4[i]);
        inverseaza(t4[i]);
        cout << "oglindit \"" << t4[i] << "\"" << (pal ? " , palindrom" : "") << endl;
    }

    cout << endl << "--- stergeCaracter / insereazaCaracter ---" << endl;
    char s5[256] = "abcd";
    stergeCaracter(s5, 1);
    cout << "abcd fara poz 1 : " << s5 << endl;
    stergeCaracter(s5, 0);
    cout << "apoi fara poz 0 : " << s5 << endl;
    stergeCaracter(s5, 1);
    cout << "apoi fara poz 1 : " << s5 << endl;
    insereazaCaracter(s5, 1, 'X');
    cout << "apoi X pe poz 1 : " << s5 << endl;
    insereazaCaracter(s5, 0, 'Y');
    cout << "apoi Y pe poz 0 : " << s5 << endl;
    insereazaCaracter(s5, 3, 'Z');
    cout << "apoi Z la sfarsit (poz 3) : " << s5 << endl;

    cout << endl << "--- concateneaza / esteInainte / ordoneazaCuvinte ---" << endl;
    char rez6[256];
    char a6[] = "ana";
    char b6[] = "mere";
    concateneaza(a6, b6, rez6);
    cout << "ana + mere : " << rez6 << endl;
    cout << "ana inaintea lui mere : " << esteInainte(a6, b6) << " , mere inaintea lui ana : " << esteInainte(b6, a6) << endl;
    char c6[50][31] = { "pere", "ana", "mere", "an", "Zeta" };
    ordoneazaCuvinte(c6, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << c6[i] << " ";
    }
    cout << endl;

    cout << endl << "--- pozitieCaracter / pozitieSubsir / inlocuiestePrima ---" << endl;
    char s7[256] = "banana";
    char nan[] = "nan";
    char ban[] = "ban";
    char na[] = "na";
    char zz[] = "zz";
    char an[] = "an";
    char ant[] = "ANT";
    cout << "banana , 'n' : " << pozitieCaracter(s7, 'n') << " , 'z' : " << pozitieCaracter(s7, 'z') << endl;
    cout << "banana , nan : " << pozitieSubsir(s7, nan) << " , ban : " << pozitieSubsir(s7, ban) << " , na : " << pozitieSubsir(s7, na) << " , zz : " << pozitieSubsir(s7, zz) << endl;
    if (inlocuiestePrima(s7, an, ant))
    {
        cout << "dupa inlocuire : " << s7 << endl;
    }
    if (inlocuiestePrima(s7, zz, ant) == false)
    {
        cout << "zz nu apare" << endl;
    }

    cout << endl << "--- numarCuvinte / imparteCuvinte ---" << endl;
    char s8[256] = "  ana are,  mere si pere. ";
    char sep8[] = " ,.";
    char sep8b[] = " ";
    cout << "separatori \" ,.\" : " << numarCuvinte(s8, sep8) << " cuvinte" << endl;
    cout << "separator \" \" : " << numarCuvinte(s8, sep8b) << " cuvinte" << endl;
    char c8[50][31];
    int n8 = imparteCuvinte(s8, c8);
    for (int i = 0; i < n8; i++)
    {
        cout << i + 1 << ". " << c8[i] << endl;
    }
    char gol8[256] = "   ";
    cout << "doar spatii : " << numarCuvinte(gol8, sep8b) << " cuvinte" << endl;

    cout << endl << "--- lungimeMaxima ---" << endl;
    char t9[][40] = { "ana are mere multe", "", "a", "  xx  yy  ", "abc abc" };
    for (int i = 0; i < 5; i++)
    {
        cout << "\"" << t9[i] << "\" : cel mai lung cuvant are " << lungimeMaxima(t9[i]) << " litere" << endl;
    }

    cout << endl << "--- sirInNumar / numarInSir ---" << endl;
    char s10[256] = "472";
    cout << "\"472\" -> " << sirInNumar(s10) + 1 << " (472 + 1)" << endl;
    char z10[256] = "0";
    cout << "\"0\" -> " << sirInNumar(z10) << endl;
    int teste10[] = { 472, 0, 7, 1000 };
    for (int i = 0; i < 4; i++)
    {
        numarInSir(teste10[i], s10);
        cout << teste10[i] << " -> \"" << s10 << "\" (lungime " << strlen(s10) << ")" << endl;
    }

    cout << endl << "--- deplaseaza / cezar ---" << endl;
    char s11[256] = "Ana are mere, xyz!";
    cezar(s11, 3);
    cout << "cheia 3 : " << s11 << endl;
    cezar(s11, 23);
    cout << "inapoi (23 = 26 - 3) : " << s11 << endl;
    char gol11[256] = "";
    cezar(gol11, 5);
    cout << "sirul vid : \"" << gol11 << "\"" << endl;

    cout << endl << "--- citesteLinie / citesteNumar ---" << endl;
    cout << "scrie un numar n, apoi n linii" << endl;
    int n12 = citesteNumar();
    for (int i = 0; i < n12; i++)
    {
        char linie[256];
        citesteLinie(linie);
        cout << i + 1 << ". \"" << linie << "\" are " << lungime(linie) << " caractere" << endl;
    }
}

#endif // ALGORITMI_SIRURI_H_INCLUDED
