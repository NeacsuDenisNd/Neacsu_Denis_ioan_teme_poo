#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;
enum Zona {SPATE=1 , FATA=2};
class CLASASTATISTICA {
private:
	const int id;
	string denumire;
	int nrlocuri;
	Zona zona;
	float* vectorStud;
public:
	static int nrCLASASTATISTICA;
	CLASASTATISTICA() :id(++nrCLASASTATISTICA) {
		this->denumire = "DEFAULT";
		this->nrlocuri = 0;
		this->zona = SPATE;
		this->vectorStud = nullptr;
	}
	CLASASTATISTICA(int id, string denumire, int nrlocuri, Zona zona, float* vectorStud) :id(id) {
		this->denumire = denumire;
		this->nrlocuri = nrlocuri;
		this->zona = zona;
		this->vectorStud = new float[nrlocuri];
		for (int i = 0;i < nrlocuri;i++) {
			this->vectorStud[i] = vectorStud[i];
		}
		nrCLASASTATISTICA++;
	}
	CLASASTATISTICA(const CLASASTATISTICA& c) :id(++nrCLASASTATISTICA) {
		this->denumire = c.denumire;
		this->nrlocuri = c.nrlocuri;
		this->zona = c.zona;
		if (c.vectorStud != nullptr) {
			this->vectorStud = new float[c.nrlocuri];
			for (int i = 0;i < c.nrlocuri;i++) {
				this->vectorStud[i] = c.vectorStud[i];
			}
		}
		else this->vectorStud = nullptr;
	}
	void operator=(const CLASASTATISTICA& c) {
		this->denumire = c.denumire;
		this->nrlocuri = c.nrlocuri;
		this->zona = c.zona;
		if (this->vectorStud != nullptr) {
			delete[] this->vectorStud;
			this->vectorStud = nullptr;
		}
		if (c.vectorStud != nullptr) {
			this->vectorStud = new float[c.nrlocuri];
			for (int i = 0;i < c.nrlocuri;i++) {
				this->vectorStud[i] = c.vectorStud[i];
			}
		}
		else this->vectorStud = nullptr;
	}
	void afisareCLASA() {
		cout << endl << " ID: " << this->id;
		cout << endl << " DENUMIRE: " << this->denumire;
		cout << endl << " NUMAR LOCURI: " << this->nrlocuri;
		cout << endl << " ZONA: ";
		if (this->zona == 1) cout << "SPATE"; else cout << "FATA";
		if (this->nrlocuri > 0) {
			cout << endl << "CATI STUDENTI: ";
			for (int i = 0;i < this->nrlocuri ;i++) {
				cout << endl << this->vectorStud[i] << " , ";
			}
			///cout << this->vectorStud[this->nrlocuri - 1] << " . ";
		}
	}
	int getNrlocuri() {
		return this->nrlocuri;
	}
	void setNrlocuri(int nrlocurinou) {
		if (nrlocurinou >= 0)
			this->nrlocuri = nrlocurinou;
	}
	float* getVectorStud() {
		float* vectorstudnou = new float[this->nrlocuri];
		for (int i = 0;i < this->nrlocuri;i++)
		{
			vectorstudnou[i] = this->vectorStud[i];
		}
		return vectorstudnou;
	}
	void setVectorStud(float* vector, int nrloc) {
		setNrlocuri(nrloc);
		if (this->vectorStud != nullptr) delete[] this->vectorStud;
		this->vectorStud = new float[this->nrlocuri];
		for (int i = 0;i < this->nrlocuri;i++) {
			this->vectorStud[i] = vector[i];
		}
		delete[] vector;
	}
	~CLASASTATISTICA() {
		if (this->vectorStud != nullptr) delete[] this->vectorStud;
	}
};
int CLASASTATISTICA::nrCLASASTATISTICA = 0;
int main()
{
	CLASASTATISTICA GRUPA1049;
	GRUPA1049.afisareCLASA();
	float* vectorStud = new float [3] {20, 17, 32};
	CLASASTATISTICA* GRUPA1001 = new CLASASTATISTICA(5, "GRUPA1001", 3, SPATE, vectorStud);
	GRUPA1001->afisareCLASA();
	CLASASTATISTICA GRUPA1002 = *GRUPA1001;
	GRUPA1002.afisareCLASA();
	GRUPA1049.setNrlocuri(5);
	cout <<endl<<"NOUL NUMAR DE LOCURI"<< GRUPA1049.getNrlocuri();
	GRUPA1049 = *GRUPA1001;
	GRUPA1049.afisareCLASA();
	cout << endl << " AVEM " << CLASASTATISTICA::nrCLASASTATISTICA << " CLASE";
	delete GRUPA1001;
}
