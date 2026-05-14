#include <iostream>
#include <string>
using namespace std;
class Osoba
{
    protected:
        string imie;
        string nazwisko;
    public:
        string getImie();
        string getNazwisko();
        bool setImie(string wartosc);
        bool setNazwisko(string nazwisko);
        void drukuj();

};
class Student:public Osoba
{
    private:
        int indeks;
    public:
        int getIndeks();
        bool setIndeks(int ind);
        void drukuj();

};
class Pracownik:public Osoba
{
    private:
        int id;
    public:
        int getId();
        bool setId(int i);
        void drukuj();
};
class ListaObecnosci
{
    private:
    Osoba *tabOsoby[10];
    bool tabObecnosc[10];
    int iloscOsob=0;
    public:
    ListaObecnosci()
    {
        for(int i=0;i<10;i++)
        {
            tabOsoby[i]=nullptr;
            tabObecnosc[i]=false;
        }
    }
        void dodajStudenta(string imie, string nazwisko, int indeks);
        void dodajPracownika(string imie, string nazwisko, int id);
        void ustawObecnosc(string nazwisko,bool obecnosc);
        void edytujOsobe(string nazwisko);
        void usunOsobe(string nazwisko);
        void drukujListe();

};
class Interfejs
{
    private:
        ListaObecnosci lista;
        void wyswietlMenu();
        void wybor(int choice);
    public:
    void uruchom();
};
bool Osoba::setImie(string wartosc)
{
    if(wartosc.length()>1)
    {
        imie=wartosc;
        return true;
    }
    return false;
}
string Osoba::getNazwisko()
{
    return nazwisko;
}
string Osoba::getImie()
{
    return imie;
}
bool Osoba::setNazwisko(string n)
{
    if(n.length()>1)
    {
        for(int i=0;i<n.length();i++)
        {
            char c=n[i];
            if(!((c>='A' && c<='Z') || (c>='a' && c<='z')))
            {
                cout<<"Nazwisko moze zawierac tylko litery!"<<endl;
                return false;
            }
        }
        nazwisko=n;
        return true;
    }
    return false;
} 
bool Student::setIndeks(int ind)
{
    if(ind<=999999 && ind>99999)
    {
        indeks=ind;
        return true;
    }
    else
    {
        return false;
    }
}
bool Pracownik::setId(int nr)
{
    id=nr;
    return true;
}
int Pracownik::getId()
{
    return id;
}
void Osoba::drukuj()
{
    cout<<imie<<" "<<nazwisko<<endl;
}
void Student::drukuj()
{
    cout<<"Student: "<<imie<<" "<<nazwisko<<" "<<indeks<<endl;
}

void Pracownik::drukuj()
{
    cout<< "Pracownik: "<<imie<<" "<<nazwisko<<" "<<id<<endl;
}
void ListaObecnosci::dodajStudenta(string imie, string nazwisko, int indeks)
{
    if(iloscOsob >= 10)
    {
        cout<<"Lista jest pelna!"<<endl;
        return;
    }

    Student *student = new Student();

    if(!student->setImie(imie))
    {
        cout<<"Niepoprawne imie!"<<endl;
        delete student;
        return;
    }

    if(!student->setNazwisko(nazwisko))
    {
        cout<<"Niepoprawne nazwisko!"<<endl;
        delete student;
        return;
    }

    if(!student->setIndeks(indeks))
    {
        cout<<"Niepoprawny indeks!"<<endl;
        delete student;
        return;
    }

    tabOsoby[iloscOsob] = student;
    tabObecnosc[iloscOsob] = false;
    iloscOsob++;
}
void ListaObecnosci::dodajPracownika(string imie, string nazwisko, int id)
{
    if(iloscOsob >= 10)
    {
        cout << "Lista jest pelna!" << endl;
        return;
    }

    Pracownik *pracownik = new Pracownik();

    if(!pracownik->setImie(imie))
    {
        delete pracownik;
        return;
    }

    if(!pracownik->setNazwisko(nazwisko))
    {
        delete pracownik;
        return;
    }

    pracownik->setId(id);

    tabOsoby[iloscOsob] = pracownik;
    tabObecnosc[iloscOsob] = false;

    iloscOsob++;
}
void ListaObecnosci::ustawObecnosc(string nazwisko,bool obecnosc)
{
    for(int i=0; i<iloscOsob;i++)
    {
        if(tabOsoby[i]->getNazwisko() == nazwisko)
        {
            tabObecnosc[i]=obecnosc;
            cout<<"Obecnosc pomyslnie ustawiona"<<endl;
            return;
        }
    }
    cout<<"Nie znaleziono osoby"<<endl;
}
void ListaObecnosci::edytujOsobe(string nazwisko)
{
    for(int i=0;i<iloscOsob;i++)
    {
        if(tabOsoby[i]->getNazwisko()==nazwisko)
        {
            int choice;

            cout<<"1 - Imie"<<endl;
            cout<<"2 - Nazwisko"<<endl;

            cin>>choice;

            switch(choice)
            {
                case 1:
                {
                    string noweImie;

                    cout<<"Nowe imie: ";
                    cin>>noweImie;

                    tabOsoby[i]->setImie(noweImie);

                    break;
                }

                case 2:
                {
                    string noweNazwisko;

                    cout<<"Nowe nazwisko: ";
                    cin>>noweNazwisko;

                    tabOsoby[i]->setNazwisko(noweNazwisko);

                    break;
                }

                default:
                    cout<<"Zly wybor"<<endl;
            }

            return;
        }
    }

    cout<<"Nie znaleziono osoby"<<endl;
}
void ListaObecnosci::usunOsobe(string nazwisko)
{
    for(int i=0;i<iloscOsob;i++)
    {
        if(tabOsoby[i]->getNazwisko() == nazwisko)
        {
            delete tabOsoby[i];
            for(int j=i+1;j<iloscOsob;j++)
        {
            tabOsoby[j-1]=tabOsoby[j];
            tabObecnosc[j-1]=tabObecnosc[j];
        }
        iloscOsob--;
        cout<<"Osoba usunieta"<<endl;
        return;
        }
    }
    cout<<"Nie znaleziono osoby"<<endl;
}
void ListaObecnosci::drukujListe()
{
    for(int i=0;i<iloscOsob;i++)
    {
        tabOsoby[i]->drukuj();
    }
}
void Interfejs::wyswietlMenu()
{
    cout<<"=== MENU ==="<<endl;
    cout<<"1 - Dodaj Studenta"<<endl;
    cout<<"2 - Dodaj Pracownika"<<endl;
    cout<<"3 - Zmien Obecnosc"<<endl;
    cout<<"4 - Drukuj Liste"<<endl;
    cout<<"5 - Edytuj Osobe"<<endl;
    cout<<"6 - Usun Osobe"<<endl;
    cout<<"0 - Wyjscie"<<endl;
}
void Interfejs::wybor(int choice)
{
    string nazwisko, nowe, imie;
    bool obecnosc;
    int ind,id;
    switch(choice)
    {
        case 1:
            cout<<"Podaj Imie"<<endl;
            cin>>imie;
            cout<<"Podaj Nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Podaj Indeks"<<endl;
            cin>>ind;
            lista.dodajStudenta(imie,nazwisko,ind);
            break;
        case 2:
            cout<<"Podaj Imie"<<endl;
            cin>>imie;
            cout<<"Podaj Nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Podaj ID"<<endl;
            cin>>id;
            lista.dodajPracownika(imie,nazwisko,id);
            break;
        case 3:
            cout<<"Podaj Nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Na jaka obecnosc chcesz zmienic? (0.1)"<<endl;
            cin>>obecnosc;
            lista.ustawObecnosc(nazwisko,obecnosc);
            break;
        case 4:
            lista.drukujListe();
            break;
        case 5:
            cout<<"Podaj nazwisko: "<<endl;
            cin>>nazwisko;
            lista.edytujOsobe(nazwisko);
            break;
        case 6:
            cout<<"Podaj Nazwisko: "<<endl;
            cin>>nazwisko;
            lista.usunOsobe(nazwisko);
            break;
        case 0:
            cout<<"Wychodzenie..."<<endl;
            break;
        default:
        cout<<"Zly wybor!"<<endl;
        break;
    }
}
void Interfejs::uruchom()
{
    int choice=-1;

    while(choice!=0)
    {
        wyswietlMenu();
        cin>>choice;
        wybor(choice);
    }
}
int Student::getIndeks()
{
    return indeks;
}
int main()
{
    Interfejs interfejs;
    interfejs.uruchom();
    return 0;
}