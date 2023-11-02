#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Persoana {
private:
    string prenume;
    string nume;
    string adresa;
    int id;

    static int lastID;

public:
    explicit Persoana(string Prenume, string Nume, string Adresa) {
        this->prenume = Prenume;
        this->nume = Nume;
        this->adresa = Adresa;
        this->id = ++lastID;
    }

    string getPrenume() const {
        return prenume;
    }

    string getNume() const {
        return nume;
    }

    friend ostream& operator<<(ostream& out, const Persoana& persoana) {
        out << "Nume: " << persoana.prenume << " " << persoana.nume << "\n";
        out << "Adresa: " << persoana.adresa << "\n";
        out << "ID: " << persoana.id << "\n";
        return out;
    }

    friend istream& operator>>(istream& in, Persoana& persoana) {
        in >> persoana.prenume;
        in >> persoana.nume;
        in >> persoana.adresa;
        in >> persoana.id;
        return in;
    }
};

int Persoana::lastID = 0;

class Cont {
private:
    int numarCont;
    double sold;

public:
    explicit Cont(int NumarCont, double soldInitial){
        this->numarCont = NumarCont;
        this->sold = soldInitial;
    }

    int getNumarCont() const {
        return numarCont;
    }

    double getSold() const {
        return sold;
    }

    void depoziteaza(double suma) {
        sold += suma;
        inregistreazaTranzactie(suma, "Depunere");
    }

    void retrage(double suma) {
        if (sold >= suma) {
            sold -= suma;
            inregistreazaTranzactie(suma, "Retragere");
        } else {
            cout << "Fonduri insuficiente!\n";
        }
    }

    void inregistreazaTranzactie(double suma, const string& tip) const {
        ofstream fisier("tranzactii.txt", ofstream::app);
        if (fisier.is_open()) {
            fisier << "Tip: " << tip << "\n";
            fisier << "Suma: " << suma << "\n";
            fisier << "Numar cont: " << numarCont << "\n";
            fisier << "--------------------------\n";
            fisier.close();
        } else {
            cout << "Nu am putut deschide fisierul de tranzactii.\n";
        }
    }

    friend ostream& operator<<(ostream& out, const Cont& cont) {
        out << "Soldul contului " << cont.numarCont << ": " << cont.sold << "\n";
        return out;
    }

    friend istream& operator>>(istream& in, Cont& cont) {
        in >> cont.numarCont;
        double soldInitial;
        in >> soldInitial;
        cont = Cont(cont.numarCont, soldInitial);
        return in;
    }
};

class Banca {
private:
    string nume;
    vector<Cont> conturi;

public:
    explicit Banca(string numeBanca){
        this->nume = numeBanca;
    }

    void creazaCont(const Persoana& persoana, double soldInitial) {
        Cont contNou(conturi.size() + 1, soldInitial);
        conturi.push_back(contNou);
        cout << "Cont creat cu succes pentru " << persoana.getPrenume() << " " << persoana.getNume() << "!\n";
    }

    void afiseazaToateConturile() const {
        cout << "Conturile bancii " << nume << ":\n";
        for (const Cont& cont : conturi) {
            cout << "Numar cont: " << cont.getNumarCont() << "\n";
            cout << "Soldul contului " << cont.getNumarCont() << ": " << cont.getSold() << "\n";
            cout << "--------------------------\n";
        }
    }

    void depoziteaza(int numarCont, double suma) {
        for (Cont& cont : conturi) {
            if (cont.getNumarCont() == numarCont) {
                cont.depoziteaza(suma);
                return;
            }
        }
        cout << "Contul nu a fost gasit.\n";
    }

    void retrage(int numarCont, double suma) {
        for (Cont& cont : conturi) {
            if (cont.getNumarCont() == numarCont) {
                cont.retrage(suma);
                return;
            }
        }
        cout << "Contul nu a fost gasit.\n";
    }
};

int main() {
    Banca MazeBank("Maze Bank");
    Persoana client1("George", "Ionut", "Str. Acadelelor, Nr. 96");
    Persoana clientcopie(client1);
    Persoana client3("Snoop", "Dogg", "Str. Pizza, Nr. 96");
    clientcopie = client3;

    MazeBank.creazaCont(client1, 1000.0);
    MazeBank.creazaCont(clientcopie, 1000);
    MazeBank.creazaCont(client3, 2000.0);

    while (true) {
        cout << "\n\n\nMeniu:\n";
        cout << "1. Afiseaza toate conturile\n";
        cout << "2. Depunere bani\n";
        cout << "3. Retragere bani\n";
        cout << "0. Iesire\n";

        int optiune=0;
        cout << "Introdu optiunea: ";
        cin >> optiune;

        switch (optiune) {
            case 1:
                MazeBank.afiseazaToateConturile();
                break;
            case 2:
                int contDepozit;
                double sumaDepozit;
                cout << "Introduceti numarul contului pentru depunere: ";
                cin >> contDepozit;
                cout << "Introduceti suma depozitata: ";
                cin >> sumaDepozit;
                MazeBank.depoziteaza(contDepozit, sumaDepozit);
                break;
            case 3:
                int contRetragere;
                double sumaRetragere;
                cout << "Introduceti numarul contului pentru retragere: ";
                cin >> contRetragere;
                cout << "Introduceti suma retrasa: ";
                cin >> sumaRetragere;
                MazeBank.retrage(contRetragere, sumaRetragere);
                break;
            case 0:
                cout << "La revedere!";
                return 0;
            default:
                cout << "Optiune invalida. Va rugam sa reintroduceti.\n";
        }
    }
}
