#include <iostream>

using namespace std;

void dodajOsobe(string *tabNazwisk, string nazwisko,string *tabImion, string imie, int *tabIndeks, int indeks)
{
    for(int i=0;i<10;i++)
    {
        if(tabNazwisk[i]=="")
        {
            tabNazwisk[i]=nazwisko;
            tabImion[i]=imie;
            tabIndeks[i]=indeks;
            return;
        }
    }
    
}
void ustawObecnosc(string *tabNazwisk, bool *tabObecnosc, string nazwisko, bool obecnosc)
{
    for(int i=0;i<10;i++)
    {
        if(tabNazwisk[i]!="" && tabNazwisk[i]==nazwisko)
        {
            tabObecnosc[i]=obecnosc;
            return;
        }
    }
    
}
void drukujListe(string *tabNazwisk, bool *tabObecnosc, string *tabImion, int *tabIndeks)
{
    for (int i = 0; i < 10; i++)
    {
        if (tabNazwisk[i] != "")
        {
            cout << tabIndeks[i] << " " << tabImion[i] << " " << tabNazwisk[i] << " " << tabObecnosc[i] << endl;
        }
        else break;
    }
}
void edytujOsobe(string *tabNazwisk, string *tabImion, int *tabIndeks, string nazwisko)
{
    for(int i = 0; i < 10; i++)
    {
        if(tabNazwisk[i] == nazwisko)
        {
            int wybor;
            cout << "Co chcesz edytowac?" << endl;
            cout << "1 - Nazwisko" << endl;
            cout << "2 - Imie" << endl;
            cout << "3 - Indeks" << endl;
            cin >> wybor;
            
            switch(wybor)
            {
                case 1:
                    cout << "Podaj nowe nazwisko: ";
                    cin >> tabNazwisk[i];
                    break;
                case 2:
                    cout << "Podaj nowe imie: ";
                    cin >> tabImion[i];
                    break;
                case 3:
                    cout << "Podaj nowy indeks: ";
                    cin >> tabIndeks[i];
                    break;
            }
            return;
        }
    }
    cout << "Nie znaleziono osoby o nazwisku: " << nazwisko << endl;
}
void usunOsobe(string *tabNazwisk, string *tabImion, int *tabIndeks, string nazwisko) {
    for (int i = 0; i < 10; i++) {
        if (tabNazwisk[i] == nazwisko) 
        {
            for (int j = i; j < 9; j++) 
            {
                tabNazwisk[j] = tabNazwisk[j + 1];
                tabImion[j]   = tabImion[j + 1];
                tabIndeks[j]  = tabIndeks[j + 1];
            }
            tabNazwisk[9] = "";
            tabImion[9]   = "";
            tabIndeks[9]  = 0;
            return;
        }
    }
    cout << "Nie znaleziono osoby o nazwisku: " << nazwisko << endl;
}
int main()
{
    string tabNazwisk[10];
    bool tabObecnosc[10];
    string tabImion[10];
    int tabIndeks[10];
    int indeks;
    string nazwisko;
    string imie;
    bool obecnosc;
    int choice;
    do{
    cout<<"===Menu==="<<endl;
    cout<<"1 - Dodaj Osobe"<<endl;
    cout<<"2 - Zmien obecnosc"<<endl;
    cout<<"3 - Wyswietl Liste"<<endl;
    cout<<"4 - Edytuj Studenta"<<endl;
    cout<<"5 - Usun Studenta"<<endl;
    cout<<"6 - Wyjscie"<<endl;
    cin>>choice;
    
    switch (choice)
    {
    case 1:
        cout<<"Podaj Nazwisko do dodania"<<endl;
        cin>>nazwisko;
        cout<<"Podaj Imie do dodania"<<endl;
        cin>>imie;
        cout<<"Podaj Indeks do dodania"<<endl;
        cin>>indeks;
        dodajOsobe(tabNazwisk, nazwisko,tabImion,imie,tabIndeks,indeks);
        break;
    case 2:
        cout<<"Podaj nazwisko osoby, ktorej zmienic obecnosc"<<endl;
        cin>>nazwisko;
        cout<<"Na jaką obecnosc chcesz zmienic? (0,1)"<<endl;
        cin>>obecnosc;
        ustawObecnosc(tabNazwisk,tabObecnosc, nazwisko, obecnosc);
        break;
    case 3:
        drukujListe(tabNazwisk,tabObecnosc,tabImion,tabIndeks);
        break;
    case 4:
        cout<<"Wprowadz nazwisko studenta, ktorego chcesz edytowac"<<endl;
        cin>>nazwisko;
        edytujOsobe(tabNazwisk,tabImion,tabIndeks,nazwisko);
        break;
    case 5:
        cout<<"Wprowadz nazwisko studenta, ktorego chcesz usunac"<<endl;
        cin>>nazwisko;
        usunOsobe(tabNazwisk,tabImion,tabIndeks,nazwisko);
        break;
    default:
        break;
    }
}
    while(choice!=6);
}