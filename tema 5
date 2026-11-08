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
};
int Hotel::nrHoteluri = 0;

void main() {
    Hotel hDefault;
    hDefault.afisareHotel();
    float* vectorPreturi = new float[3] {250, 300, 400};
    Hotel* pHotel = new Hotel(7, "Continental", TREI_STELE, 3, vectorPreturi);
    pHotel->afisareHotel();
    Hotel hCopie = *pHotel;
    hCopie.afisareHotel();
    hDefault = *pHotel;
    hDefault.afisareHotel();
    cout << endl << "Am construit " << Hotel::nrHoteluri << " hoteluri!";
    if (hDefault < hCopie) {
        cout << endl << "Hotelul Default are mai putine camere!";
    }
    else {
        cout << endl << "Hotelul copie are mai putine camere!";
    }
    delete pHotel;
}
