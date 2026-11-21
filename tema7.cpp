#include<iostream>
#include<string>
using namespace std;
class ExceptieCustom : public exception {
public:
	ExceptieCustom(const char* mesaj) : exception(mesaj) {}
};

class Produs {
protected:
	const int id;
	string denumire;
	float pret;
public:
	static const float Pret_minim;
	Produs() :id(0), denumire("Carte"), pret(40) {}
	Produs(int idP, string denumireP, float pretP) : id(idP), denumire(denumireP), pret(pretP) {
		if (pret < pretP) throw ExceptieCustom("PRET PREA MIC");
	}
	virtual void afisare() {
		cout << endl << "ID: " << this->id;
		cout << endl << "Denumire: " << this->denumire;
		cout << endl << "Pret: " << this->pret;
	}
	~Produs() {}
	virtual float getProcentReducere() = 0;
};
const float Produs::Pret_minim = 1;
class ProdusRedus : public Produs {
private:
	float procentReducere;
public:
	ProdusRedus() :  Produs(){
		this->procentReducere = 0;
	}

	ProdusRedus(int idP, string denumireP, float pretP, float procentReducereP) : Produs(idP, denumireP, pretP) {
		this->procentReducere = procentReducereP;
	}

	void afisare() {
		Produs::afisare();
		cout << endl << "Procent reducere: " << this->procentReducere;
	}

	float getProcentReducere() {
		return this->procentReducere;
	}
};
class Operatie {
public:
	virtual int adunare(int a, int b) = 0;
	virtual int scadere(int a, int b) = 0;
};
class Calculator : public Operatie {
public:
	Calculator() {}
	int adunare(int a, int b) { return a + b; }
	int scadere(int a, int b) { return a - b; }
};
int main() {
	Produs* vectorproduse[3];
	vectorproduse[0] = new ProdusRedus(1, "Pagini", 20, 10);
	vectorproduse[1] = new ProdusRedus(2, "Pix", 10, 5);
	vectorproduse[2] = new ProdusRedus(3, "Cotor", 5, 2);

	for (int i = 0;i < 3;i++) {
		vectorproduse[i]->afisare();
		delete vectorproduse[i];
	}

	Produs* pProdus = new ProdusRedus();
	pProdus->afisare();
	delete pProdus;

	Operatie* calcul = new Calculator();
	cout << endl << "Scadere: " << calcul->scadere(7, 3);
	delete calcul;
}
