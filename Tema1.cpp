#include <iostream>
#include <cstring>
using namespace std;

class Angajat
{
    int varsta;
    char nume[20];
    char CNP[14];
    int salariu;

public:
    Angajat();
    Angajat(int v, char n[], char C[], int s);
    void afisare();                               // afiseaza atributele clasei
    void modif(int v, char n[], char C[], int s); // modifica atributele clasei
    int getVarsta();                              // returneaza varsta
    char *getNume();                              // returneaza numele
    char *getCNP();                               // returneaza CNP-ul
    int getSalariu();                             // returneaza salariul
    void sortare(int l);                          // sorteaza vectorul
    void SaralariuMaxim(int l);                   // Salariul maxim
};

Angajat::Angajat()
{
    varsta = 0;
    strcpy(nume, "");
    strcpy(CNP, "");
    salariu = 0;
}

Angajat::Angajat(int v, char n[], char C[], int s)
{
    varsta = v;
    strcpy(nume, n);
    strcpy(CNP, C);
    salariu = s;
}

void Angajat::afisare()
{
    cout << "Varsta este de " << varsta << endl;
    cout << "Numele angajatului este: " << nume << endl;
    cout << "CNP-ul angajatului: " << CNP << endl;
    cout << "Salariul este de " << salariu << " euro" << endl;
}

void Angajat::modif(int v, char n[], char C[], int s)
{
    varsta = v;
    strcpy(nume, n);
    strcpy(CNP, C);
    salariu = s;
}

int Angajat::getVarsta()
{
    return varsta;
}

char* Angajat::getNume()
{
    return nume;
}

char* Angajat::getCNP()
{
    return CNP;
}

int Angajat::getSalariu()
{
    return salariu;
}

void Angajat::sortare(int l)
{
    for(int i=0 ; i < l-1 ; i++ )
        for(int j=i+1 ; j < l ; j++ )
            if(strcmp(this[i].nume,this[j].nume) > 0)
                {
                     Angajat aux;
                     aux=this[i];
                     this[i]=this[j];
                     this[j]=aux;

                }


}

void Angajat::SaralariuMaxim(int l)
{       int mx=this[0].getSalariu();
        for(int i=1 ; i < l ; i++ )
            if( this[i].salariu > mx )
               {
                    mx=this[i].salariu;
               }
        for(int i=0 ; i < l ; i++ )
            if( mx==this[i].salariu)
                this[i].afisare();
}



int main()
{   
    Angajat obj1;
    char nume[30]="Mirela";
    char CNP[] = "2961016449138";
    int v,s;
    Angajat obj2(25, nume, CNP, 2500);
    obj1.afisare();
    obj2.afisare();
    obj1.modif(30, nume, CNP, 3500);
    obj1.afisare();

    cout << "Numele angajatului este: " << obj1.getNume() << endl;
    cout << "Salariul este: " << obj1.getSalariu() << " euro " << endl; //Exercitiu 1

//Exercitiu 2
    Angajat ang[10];
    int i, n;
    cout << "Numarul de angajati este ";
    cin >> n;

    for(i=0; i<n; i++)
    {
        cout << "Varsta angajatului cu numarul " << i << " este: ";
        cin >> v;
        cin.get();
        cout << "Numele angajatului cu numarul " << i << " este: ";
        cin.getline(nume, 31);
        cout << "CNP-ul angajatului cu numarul " << i << " este: ";
        cin >> CNP;
        cout << "Salariul angajatului cu numarul " << i << " este: ";
        cin >> s;
        
        ang[i].modif(v, nume, CNP, s);
    }

    for(i=0; i<n; i++)
    {
        ang[i].afisare();

    }

//Exercitiu 3

    ang->sortare(n);
    for(i=0; i<n ; i++)
    {
       ang[i].afisare();

    }

//Exercitiu 4

    ang->SaralariuMaxim(n);

    return 0;
}