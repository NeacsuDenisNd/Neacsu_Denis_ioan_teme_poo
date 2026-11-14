#include<iostream>
#include<string>
using namespace std;
enum Categorie { TREI_STELE = 1, PATRU_STELE = 2 };
class Hotel {
private:
    const int cod;
    string denumire;
    Categorie categorie;
    int nrCamere;
    float* vectorPreturi;
public:
    static int nrHoteluri;
    Hotel() :cod(++nrHoteluri) {
        //cod = 0;
        //denumire = "Default";
        this->denumire = "Default";
        this->nrCamere = 0;
        this->categorie = TREI_STELE;
        this->vectorPreturi = nullptr;
    }
    Hotel(int cod, string denumire, Categorie categorie, int nrCamere, float* vectorPreturi)
        :cod(cod) {
        this->denumire = denumire;
        this->categorie = categorie;
        this->nrCamere = nrCamere;
        this->vectorPreturi = new float[nrCamere];
        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i] = vectorPreturi[i];
        }
        nrHoteluri++;
    }
    Hotel(const Hotel& h) :cod(++nrHoteluri) {
        this->denumire = h.denumire;
        this->nrCamere = h.nrCamere;
        this->categorie = h.categorie;
        if (h.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[h.nrCamere];
            for (int i = 0; i < h.nrCamere; i++) {
                this->vectorPreturi[i] = h.vectorPreturi[i];
            }
        }
        else {
            this->vectorPreturi = nullptr;
        }
    }
    void operator=(const Hotel& h) {
        this->denumire = h.denumire;
        this->nrCamere = h.nrCamere;
        this->categorie = h.categorie;
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
            this->vectorPreturi = nullptr;
        }
        if (h.vectorPreturi != nullptr) {
            this->vectorPreturi = new float[h.nrCamere];
            for (int i = 0; i < h.nrCamere; i++) {
                this->vectorPreturi[i] = h.vectorPreturi[i];
            }
        }
        else {
            this->vectorPreturi = nullptr;
        }
    }
    void afisareHotel() {
        cout << endl << "Cod: " << this->cod;
        cout << endl << "Denumire: " << this->denumire;
        cout << endl << "Nr camere: " << this->nrCamere;
        cout << endl << "Categorie: ";
        if (this->categorie == 1) {
            cout << "TREI STELE";
        }
        else {
            cout << "PATRU STELE";
        }
        if (this->nrCamere > 0) {
            cout << endl << "Preturi per camera: ";
            for (int i = 0; i < this->nrCamere - 1; i++) {
                cout << this->vectorPreturi[i] << ", ";
            }
            cout << this->vectorPreturi[this->nrCamere - 1] << ".";
        }
    }
    int getNrCamere() {
        return this->nrCamere;
    }
    void setNrCamere(int nrCamereNou) {
        if (nrCamereNou >= 0) {
            this->nrCamere = nrCamereNou;
        }
        else {
            throw "Valoare negativa";
        }
    }
    float* getVectorPreturi() {
        //return this->vectorPreturi; --ASA NU
        float* vectorPreturiNou = new float[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
        {
            vectorPreturiNou[i] = this->vectorPreturi[i];
        }
        return vectorPreturiNou;
    }
    void setVectorPreturi(float* vector, int nrC) {
        setNrCamere(nrC);
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }
        this->vectorPreturi = new float[this->nrCamere];
        for (int i = 0; i < this->nrCamere; i++)
        {
            this->vectorPreturi[i] = vector[i];
        }
        delete[] vector;
    }
    ~Hotel() {
        if (this->vectorPreturi != nullptr) {
            delete[] this->vectorPreturi;
        }
    }
    bool operator<(const Hotel& h) {
        return this->nrCamere < h.nrCamere;
    }
    void operator+=(float pretDeAdaugat) {
        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i] += pretDeAdaugat;
        }
    }
    bool operator!() {
        return this->nrCamere > 0;
    }
    float operator()(float valoareDeAdaugat)
    {
        if (this->nrCamere > 0) {
            return this->vectorPreturi[0] + valoareDeAdaugat;
        }
        return valoareDeAdaugat;
    }
    float& operator[](int index) {
        if (index >= 0 && index < this->nrCamere) {
            return this->vectorPreturi[index];
        }
        else {
            throw exception();
        }
    }
    friend void operator<<(ostream& out, Hotel h) {
        out << endl << "Operator de afisare: ";
        out << endl << "Cod: " << h.cod;
        out << endl << "Denumire: " << h.denumire;
        out << endl << "Categorie: ";
        if (h.categorie == TREI_STELE) out << "TREI STELE";
        if (h.categorie == PATRU_STELE) out << "PATRU STELE";
        out << endl << "Nr camere: " << h.nrCamere;
        if (h.vectorPreturi != nullptr && h.nrCamere > 0) {
            out << endl << "Vector preturi: ";
            for (int i = 0; i < h.nrCamere - 1; i++) {
                out << h.vectorPreturi[i] << " euro, ";
            }
            out << h.vectorPreturi[h.nrCamere - 1] << " euro.";
        }
    }
    friend void operator>>(istream& in, Hotel& h);
    Hotel operator++(int) {
        Hotel copie = *this;
        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i]++;
        }
        return copie;
    }
    Hotel operator++() {
        for (int i = 0; i < this->nrCamere; i++) {
            this->vectorPreturi[i]++;
        }
        return *this;
    }
    explicit operator int() {
        return this->nrCamere;
    }
};

int Hotel::nrHoteluri = 0;

void operator>>(istream& in, Hotel& h) {
    cout << endl << "Denumire: ";
    in >> h.denumire;
    cout << endl << "Categorie: ";
    int categorie;
    in >> categorie;
    if (categorie == 1) h.categorie = TREI_STELE;
    if (categorie == 2) h.categorie = PATRU_STELE;
    cout << endl << "Nr camere: ";
    in >> h.nrCamere;
    cout << endl << "Vector preturi: ";
    if (h.vectorPreturi != nullptr) {
        delete[] h.vectorPreturi;
        h.vectorPreturi = nullptr;
    }
    h.vectorPreturi = new float[h.nrCamere];
    for (int i = 0; i < h.nrCamere; i++) {
        cout << endl << "vectorPreturi[" << i << "]: ";
        in >> h.vectorPreturi[i];
    }
}
int main() {
    Hotel hDefault;
   hDefault += 50;
    if (!hDefault) {
        cout << endl << "Hotelul are camere!";
    }
    else {
        cout << endl << "Hotelul nu are camere!";
    }
    cout << endl << "Apel operator functie: " << hDefault(75);
    cout << hDefault;
    Hotel h1 = hDefault++;
    cout << h1;
    cout << hDefault;
    Hotel h2 = ++hDefault;
    cout << h2;
    cout << hDefault;
    float* vectorPreturi = new float[4] {320, 450, 380, 520};
    Hotel* pHotel = new Hotel(12, "Radisson", PATRU_STELE, 4, vectorPreturi);
    pHotel->afisareHotel();
    if (hDefault < *pHotel) {
        cout << endl << "Hotelul Default are mai putine camere!";
    }
    else {
        cout << endl << "Hotelul Radisson are mai putine camere!";
    }
    (*pHotel)[1] = 475;
    cout << endl << "Apel operator index: " << (*pHotel)[1];
    cout << endl << "Am construit " << Hotel::nrHoteluri << " hoteluri!";
    cout << (int)(*pHotel);
    delete pHotel;
}
