#include <iostream>
#include <string>
using namespace std;
class Student
{
    public:
        string getImie();
        string getNazwisko();
        int getIndeks();
        int getWzrost();
        void ustawDane(int wzr,string data, string im, string naz, int ind);
        bool setImie(string wartosc);
        bool setNazwisko(string n);
        bool setIndeks(int ind);
        bool setWzrost(int wzr);
    private:
        int indeks;
        string imie;
        string nazwisko;
        int wzrost;
        string dataUrodzenia;
};
class ListaObecnosci
{
    private:
    Student *tabStudent[10];
    bool tabObecnosc[10];
    int iloscOsob=0;
    public:
    ListaObecnosci()
    {
        for(int i=0;i<10;i++)
        {
            tabStudent[i]=nullptr;
            tabObecnosc[i]=false;
        }
    }
        bool getTabObecnosc();
        void dodajOsobe(string imie, string nazwisko, int indeks, int wzr);
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
bool Student::setImie(string wartosc)
{
    if(wartosc.length()>1)
    {
        imie=wartosc;
        return true;
    }
    return false;
}
bool Student::setNazwisko(string n)
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
bool Student::setWzrost(int wzr)
{
    if(wzr<=250)
    {
        wzrost=wzr;
        return true;
    }
    return false;
}
void ListaObecnosci::dodajOsobe(string imie, string nazwisko, int indeks, int wzr)
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
    if(!student->setWzrost(wzr))
    {
        cout<<"Niepoprawny wzrost"<<endl;
        return;
    }

    tabStudent[iloscOsob] = student;
    tabObecnosc[iloscOsob] = false;
    iloscOsob++;
}
void ListaObecnosci::ustawObecnosc(string nazwisko,bool obecnosc)
{
    for(int i=0; i<iloscOsob;i++)
    {
        if(tabStudent[i]->getNazwisko() == nazwisko)
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
    for(int i = 0; i < iloscOsob; i++)
    {
        if(tabStudent[i]->getNazwisko() == nazwisko)
        {
            int choice;
            cout << "Co chcesz zmienic?"<<endl;
            cout << "1 - Imie"<<endl;
            cout << "2 - Nazwisko"<<endl;
            cout << "3 - Indeks"<<endl;
            cout << "4 - Wzrost"<<endl;
            cin >> choice;

            string noweImie, noweNazwisko;
            int nowyIndeks,nowyWzrost;

            switch(choice)
            {
                case 1:
                    cout << "Podaj nowe imie: ";
                    cin >> noweImie;
                    if(tabStudent[i]->setImie(noweImie))
                        cout << "Imie zmienione"<<endl;
                    else
                        cout << "Niepoprawne imie"<<endl;
                    break;

                case 2:
                    cout << "Podaj nowe nazwisko: "<<endl;
                    cin >> noweNazwisko;
                    if(tabStudent[i]->setNazwisko(noweNazwisko))
                        cout << "Nazwisko zmienione"<<endl;
                    else
                        cout << "Niepoprawne nazwisko"<<endl;
                    break;

                case 3:
                    cout << "Podaj nowy indeks: "<<endl;
                    cin >> nowyIndeks;
                    if(tabStudent[i]->setIndeks(nowyIndeks))
                        cout << "Indeks zmieniony"<<endl;
                    else
                        cout << "Niepoprawny indeks"<<endl;
                    break;
                case 4:
                    cout<< "Podaj nowy wzrost: "<<endl;
                    cin>>nowyWzrost;
                    if(tabStudent[i]->setWzrost(nowyWzrost))
                        cout<<"Wzrost zmieniony"<<endl;
                    else
                        cout<<"Niepoprawny wzrost"<<endl;
                        break;
                default:
                    cout << "Zly wybor"<<endl;
            }
            return;
        }
    }
    cout << "Nie znaleziono osoby"<<endl;
}
void ListaObecnosci::usunOsobe(string nazwisko)
{
    for(int i=0;i<iloscOsob;i++)
    {
        if(tabStudent[i]->getNazwisko() == nazwisko)
        {
            delete tabStudent[i];
            for(int j=i+1;j<iloscOsob;j++)
        {
            tabStudent[j-1]=tabStudent[j];
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
        cout<<tabStudent[i]->getWzrost()<<" "<<tabStudent[i]->getIndeks() << " "<<tabStudent[i]->getImie() << " "<<tabStudent[i]->getNazwisko()<<" "<< tabObecnosc[i]<<endl;
    }
}
void Interfejs::wyswietlMenu()
{
    cout<<"=== MENU ==="<<endl;
    cout<<"1 - Dodaj Studenta"<<endl;
    cout<<"2 - Zmien Obecnosc"<<endl;
    cout<<"3 - Drukuj Liste"<<endl;
    cout<<"4 - Edytuj Studenta"<<endl;
    cout<<"5 - Usun Studenta"<<endl;
    cout<<"0 - Wyjscie"<<endl;
}
void Interfejs::wybor(int choice)
{
    string nazwisko, nowe, imie;
    bool obecnosc;
    int ind,wzr;
    switch(choice)
    {
        case 1:
            cout<<"Podaj wzrost: "<<endl;
            cin>>wzr;
            cout<<"Podaj Imie"<<endl;
            cin>>imie;
            cout<<"Podaj Nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Podaj Indeks"<<endl;
            cin>>ind;
            lista.dodajOsobe(imie,nazwisko,ind,wzr);
            break;
        case 2:
            cout<<"Podaj Nazwisko"<<endl;
            cin>>nazwisko;
            cout<<"Na jaka obecnosc chcesz zmienic? (0.1)"<<endl;
            cin>>obecnosc;
            lista.ustawObecnosc(nazwisko,obecnosc);
            break;
        case 3:
            lista.drukujListe();
            break;
        case 4:
            cout<<"Podaj nazwisko: "<<endl;
            cin>>nazwisko;
            lista.edytujOsobe(nazwisko);
            break;
        case 5:
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
string Student::getImie(){
    return imie;
}
string Student::getNazwisko()
{
    return nazwisko;
}
int Student::getIndeks()
{
    return indeks;
}
int Student::getWzrost()
{
    return wzrost;
}
bool ListaObecnosci::getTabObecnosc()
{
    return tabObecnosc;
}
int main()
{
    Interfejs interfejs;
    interfejs.uruchom();
    return 0;
}