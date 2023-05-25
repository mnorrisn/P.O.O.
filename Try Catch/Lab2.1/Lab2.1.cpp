#include "pch.h"
#include <iostream>
using namespace System; //pentru Visual C++/CLI
using namespace std;
struct Persoana
{
    unsigned vs;
    char nume[20];
    char prenume[20];
};
//Clasa este pers si este o structura care defineste datele si comportamentul
//obiectelor
class Pers
{
private:
    unsigned vs;
    char nume[20];
    char prenume[20];
public:
    //Vom folosi 2 metode cu acelasi nume cu cel al clasei, adica Pers
    //o metoda cu params si una fara params
    Pers(unsigned vs1, char* num1, char* prenum1)
    {
        vs = vs1;
        strcpy_s(nume, 20, num1);
        strcpy_s(prenume, 20, prenum1);
    }
    Pers() {}
    unsigned arata_vs() { return this->vs; }
    //Returneaza valoarea atributului VS al obiectului curent.
    char* arata_nume() { return this->nume; }

};
int main()
{
    unsigned int a1 = 0;
    a1 = 17;
    Persoana p1;
    p1.vs = 20;
    strcpy_s(p1.nume, 4, "Ion");
    strcpy_s(p1.prenume, 7, "George");
    Console::WriteLine("Hello C++.NET");
    cout << p1.nume << "\t" << p1.prenume << "\t" << p1.vs << endl;
    cout << "Hello C++.NET (cout)" << endl;
    Console::WriteLine("Utilizam clasa Pers");
    Pers p2(20, "Ionescu", "George");
    Pers* p3 = new Pers(21, "Ionescu", "Adina");
    cout << p2.arata_nume() << "\t" << p2.arata_vs() << endl;
    cout << p3->arata_nume() << "\t" << p3->arata_vs() << endl;

   unsigned int persoane;
    int i;

    cout << "Dati numarul de persoane: ";
    cin >> persoane;

    for (i = 0; i < persoane; i++)
        {
        Persoana i;
        cin >> nume;
        cin >> prenume;
        cin >> i.vs;
        strcpy_s(i.nume,10,nume);
        strcpy_s(i.prenume,10,prenume);
        }

    for (i = 0; i < persoane; i++)
    {
        Persoana i;
        cout << i.nume<<" "<<i.prenume<<" "<<i.vs<<endl;
        
    }
    

   /* int nr_persoane;
    cin >> nr_persoane;
    Persoana* persoane = new Persoana[nr_persoane];

    for (int i = 0; i < nr_persoane; i++)
    {
        Console::WriteLine("Introduceti nr de persoane {0}: ", i + 1);
        char nume[20];
        cin >> nume;
        strcpy_s(persoane[i].nume, 20, nume);

        Console::WriteLine("Introduceti varsta persoanei{0}: ", i + 1);
        unsigned vs;
        cin >> vs;
        persoana[i].vs = vs;
        }

    for (i = 0; i < nr_persoane; i++)
    {
        cout << persoane[i].nume << "\t" << persoana[i].vs << endl;
    }
    */

    Console::ReadKey();
    //Este specific Visual C++/CLI are ca si echivalent getchar();
    return 0;
}