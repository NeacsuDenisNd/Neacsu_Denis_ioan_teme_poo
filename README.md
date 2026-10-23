#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

class PensiuneMontana
{
private:
    const int cod_pensiune;
    string denumire_pensiune;
    int nr_camere;
    float* vector_tarife;

public:
    static int nr_pensiuni;

    PensiuneMontana() : cod_pensiune(++nr_pensiuni)
    {
        this->denumire_pensiune = "Default";
        this->nr_camere = 0;
        this->vector_tarife = nullptr;
    }

    PensiuneMontana(int cod, string denumire_pensiune,
                    int nr_camere, float* vector_tarife)
        : cod_pensiune(++nr_pensiuni)
    {
        this->denumire_pensiune = denumire_pensiune;
        this->nr_camere = nr_camere;
        this->vector_tarife = new float[nr_camere];

        for (int i = 0; i < this->nr_camere; i++)
        {
            this->vector_tarife[i] = vector_tarife[i];
        }
    }

    void afisare_pensiune()
    {
        cout << endl << "Cod: " << this->cod_pensiune;
        cout << endl << "Denumire: " << this->denumire_pensiune;
        cout << endl << "Numar de camere: " << this->nr_camere;
        if (this->nr_camere > 0)
        {
            cout << endl << "Tarife per camera: ";

            for (int i = 0; i < this->nr_camere - 1; i++)
            {
                cout << this->vector_tarife[i] << " lei, ";
            }

            cout << this->vector_tarife[this->nr_camere - 1]
                 << " lei.";
        }

        cout << endl;
    }
    int getNrCamere()
    {
        return this->nr_camere;
    }

    void setNrCamere(int nrCamereNou)
    {
        if (nrCamereNou >= 0)
        {
            this->nr_camere = nrCamereNou;
        }
    }
    float* getVectorTarife()
    {
        float* vectorTarifeNou = new float[this->nr_camere];

        for (int i = 0; i < this->nr_camere; i++)
        {
            vectorTarifeNou[i] = this->vector_tarife[i];
        }

        return vectorTarifeNou;
    }

    void setVectorTarife(float* vector, int nrCamereNou)
    {
        if (nrCamereNou >= 0)
        {
            if (this->vector_tarife != nullptr)
            {
                delete[] this->vector_tarife;
            }

            this->nr_camere = nrCamereNou;
            this->vector_tarife = new float[this->nr_camere];

            for (int i = 0; i < this->nr_camere; i++)
            {
                this->vector_tarife[i] = vector[i];
            }

            delete[] vector;
        }
    }

    ~PensiuneMontana()
    {
        if (this->vector_tarife != nullptr)
        {
            delete[] this->vector_tarife;
        }
    }
};

int PensiuneMontana::nr_pensiuni = 0;

int main()
{
    PensiuneMontana pensiuneStandard;
    pensiuneStandard.afisare_pensiune();

    pensiuneStandard.setNrCamere(2);

    cout << endl << "Noul numar de camere este: "
         << pensiuneStandard.getNrCamere();

    pensiuneStandard.setVectorTarife(
        new float[3] {280, 320, 400}, 3
    );

    float* tarifeNoi = pensiuneStandard.getVectorTarife();

    cout << endl << "Noile tarife sunt: ";

    for (int i = 0; i < 3; i++)
    {
        cout << tarifeNoi[i] << " lei, ";
    }

    cout << endl;
    pensiuneStandard.afisare_pensiune();

    delete[] tarifeNoi;

    float* tarife = new float[3] {350, 270, 410};

    PensiuneMontana* pensiuneCarpati =
        new PensiuneMontana(2, "Pensiunea Carpati", 3, tarife);

    delete[] tarife;

    pensiuneCarpati->afisare_pensiune();

    delete pensiuneCarpati;

    cout << endl << "Am construit "
         << PensiuneMontana::nr_pensiuni
         << " pensiuni!" << endl;

    return 0;
}
