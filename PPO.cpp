#include <iostream>
#include <string>
using namespace std;
class Student
{
    public:
        int indeks;
        string imie;
        string nazwisko;
        int wzrost;
        string dataUrodzenia;
        string getImie();
        string getNazwisko();
        int getIndeks();
        int getWzrost();
        string getDataUrodzenia();
        void ustawDane(int wzr,string data, string im, string naz, int ind);
    private:
        void setImie(string wartosc);
        void setNazwisko(string n);
        void setIndeks(int ind);
        void setWzrost(int wzr);
        void setDataUrodzenia(string data);
};
void Student::setImie(string wartosc)
{
    if(wartosc.length()>1)
    {
        imie=wartosc;
    }
}
void Student::setNazwisko(string n)
{
    if(n.length()>1)
    {
        for(int i=0;i<n.length();i++)
        {
            char c=n[i];
            if(!((c>='A' && c<='Z') || (c>='a' && c<='z')))
            {
                cout<<"Nazwisko moze zawierac tylko litery!"<<endl;
                return;
            }
        }
        nazwisko=n;
    }
} 
void Student::setIndeks(int ind)
{
    if(ind<=999999)
    {
        indeks=ind;
    }
    else
    {
        cout<<"Indeks moze miec tylko 6 cyfr!";
    }
}
void Student::setWzrost(int wzr)
{
    if(wzr<=250)
    {
        wzrost=wzr;
    }
}
void Student::setDataUrodzenia(string data)
{
    if(data.length()==10)
    {
        dataUrodzenia=data;
    }
    else
    cout<<"Upewnij sie, ze wprowadziles poprawna date urodzenia!"<<endl;
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
string Student::getDataUrodzenia()
{
    return dataUrodzenia;
}
void Student::ustawDane(int wzr,string data,string im, string naz, int ind)
{
    setWzrost(wzr);
    setDataUrodzenia(data);
    setImie(im);
    setNazwisko(naz);
    setIndeks(ind);
}
void dodajOsobe(Student *tabStudent, Student student)
{
    for(int i=0;i<10;i++)
    {
        if(tabStudent[i].getNazwisko()=="")
        {
            tabStudent[i]=student;
            return;
        }
    }
    
}
void ustawObecnosc(Student *tabStudent,bool *tabObecnosc, bool obecnosc, string nazwisko)
{
    for(int i=0;i<10;i++)
    {
        if(tabStudent[i].getNazwisko()!="" && tabStudent[i].getNazwisko()==nazwisko)
        {
            tabObecnosc[i]=obecnosc;
        }
    }
    
}
void drukujListe(Student *tabStudent,bool *tabObecnosc)
{
    for (int i = 0; i < 10; i++)
    {
        if (tabStudent[i].getNazwisko()!= "")
        {
            cout <<tabStudent[i].getWzrost()<<"cm"<<" "<<tabStudent[i].getDataUrodzenia()<<" "<<tabStudent[i].getIndeks()<< " " <<tabStudent[i].getImie()<< " " <<tabStudent[i].getNazwisko()<< " " << tabObecnosc[i] << endl;
        }
        else break;
    }
}
void edytujOsobe(Student *tabStudent, string nazwisko)
{
    for(int i = 0; i < 10; i++)
    {
        if(tabStudent[i].getNazwisko() == nazwisko)
        {
            int wybor;
            cout << "Co chcesz edytowac?" << endl;
            cout << "1 - Nazwisko" << endl;
            cout << "2 - Imie" << endl;
            cout << "3 - Indeks" << endl;
            cout << "4 - Wzrost" << endl;
            cout << "5 - Date Urodzenia" << endl;
            cin >> wybor;
            string im,naz,data;
            int ind,wzr;
            switch(wybor)
            {
                case 1:
                    cout << "Podaj nowe nazwisko: ";
                    cin>>naz;
                    tabStudent[i].ustawDane(tabStudent[i].getWzrost(),tabStudent[i].getDataUrodzenia(),tabStudent[i].getImie(),naz,tabStudent[i].getIndeks());
                    break;
                case 2:
                    cout << "Podaj nowe imie: ";
                    cin >> im;
                    tabStudent[i].ustawDane(tabStudent[i].getWzrost(),tabStudent[i].getDataUrodzenia(),im,tabStudent[i].getNazwisko(),tabStudent[i].getIndeks());
                    break;
                case 3:
                    cout << "Podaj nowy indeks: ";
                    cin >> ind;
                    tabStudent[i].ustawDane(tabStudent[i].getWzrost(),tabStudent[i].getDataUrodzenia(),tabStudent[i].getImie(),tabStudent[i].getNazwisko(),ind);
                    break;
                case 4:
                    cout<<"Podaj nowy wzrost: ";
                    cin>>wzr;
                    tabStudent[i].ustawDane(wzr,tabStudent[i].getDataUrodzenia(),tabStudent[i].getImie(),tabStudent[i].getNazwisko(),tabStudent[i].getIndeks());
            }
            return;
        }
    }
    cout << "Nie znaleziono osoby o nazwisku: " << nazwisko << endl;
}
void usunOsobe(Student *tabStudent, bool *tabObecnosc, string nazwisko)
{
    for (int i = 0; i < 10; i++)
    {
        if (tabStudent[i].getNazwisko() == nazwisko)
        {
            for (int j = i; j < 9; j++)
            {
                tabStudent[j] = tabStudent[j + 1];
                tabObecnosc[j] = tabObecnosc[j + 1];
            }

            tabStudent[9] = Student();
            tabObecnosc[9] = false;
            return;
        }
    }
}
int main()
{
    Student tabStudent[10];
    Student student;
    string imie;
    int indeks;
    int wzrost;
    string data;
    string nazwisko;
    bool tabObecnosc[10];
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
        {
        cout<<"Podaj Wzrost do dodania (cm)"<<endl;
        cin>>wzrost;
        cout<<"Podaj Date Urodzenia do dodania"<<endl;
        cin>>data;
        cout<<"Podaj Nazwisko do dodania"<<endl;
        cin >> nazwisko;
        cout<<"Podaj Imie do dodania"<<endl;
        cin >> imie; 
        cout<<"Podaj Indeks do dodania"<<endl;
        cin >> indeks;
        Student student;
        student.ustawDane(wzrost,data,imie,nazwisko,indeks);
        dodajOsobe(tabStudent,student);
        break;
        }
    case 2:
        cout<<"Podaj nazwisko osoby, ktorej zmienic obecnosc"<<endl;
        cin>>nazwisko;
        cout<<"Na jaką obecnosc chcesz zmienic? (0,1)"<<endl;
        cin>>obecnosc;
        ustawObecnosc(tabStudent, tabObecnosc, obecnosc, nazwisko);
        break;
    case 3:
        drukujListe(tabStudent,tabObecnosc);
        break;
    case 4:
        cout<<"Wprowadz nazwisko studenta, ktorego chcesz edytowac"<<endl;
        cin>>nazwisko;
        edytujOsobe(tabStudent, nazwisko);
        break;
    case 5:
        cout<<"Wprowadz nazwisko studenta, ktorego chcesz usunac"<<endl;
        cin>>nazwisko;
        usunOsobe(tabStudent,tabObecnosc,nazwisko);
        break;
    default:
        break;
    }
}
    while(choice!=6);
}