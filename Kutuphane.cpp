#include "Kutuphane.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

Kutuphane::Kutuphane() {
	kitapSayisi = 0;
	nextId = 1;
	dosyaOku();
}

Kutuphane::~Kutuphane() {
	for (int i = 0; i < kitapSayisi; i++) {
		delete kitaplar[i];
	}
}

void Kutuphane::kitapEkle() {
	string kitapAdi, yazar;
	cin.ignore();
	cout << "Kitap Adi: ";
	getline(cin, kitapAdi);

	cout << "Yazar Adi: ";
	getline(cin, yazar);

	kitaplar[kitapSayisi] = new Kitap(kitapAdi, yazar, nextId);
	kitapSayisi++;
	nextId++;

	dosyaYaz();
	cout << "Kitap Eklendi\n";
}

void Kutuphane::kitapListele() {
	if (kitapSayisi == 0) {
		cout << "Kutuphane bos\n";
		return;
	}

	for (int i = 0; i < kitapSayisi; i++) {
		kitaplar[i]->goster();
	}
}

void Kutuphane::kitapAra() {
	string kitapAdi;
	cin.ignore();

	cout << "Aranacak Kitap Adi: ";
	getline(cin, kitapAdi);

	bool bulundu = false;

	for (int i = 0; i < kitapSayisi; i++) {
		if (kitaplar[i]->getKitapAdi() == kitapAdi) {
			kitaplar[i]->goster();
			bulundu = true;
		}
	}

	if (!bulundu) {
		cout << "Kitap Bulunamadi\n";
	}
}

void Kutuphane::kitapSil() {
	int id;
	cout << "Silinecek Id: ";
	cin >> id;

	for (int i = 0; i < kitapSayisi; i++) {
		if (kitaplar[i]->getId() == id) {
			delete kitaplar[i];

			for (int j = i; j < kitapSayisi - 1; j++) {
				kitaplar[j] = kitaplar[j + 1];
			}
			kitaplar[kitapSayisi - 1] = nullptr;
			kitapSayisi--;

			dosyaYaz();

			cout << "Kitap Silindi\n";
			return;
		}
	}
}

void Kutuphane::dosyaYaz() {
	ofstream dosya("kitaplar.txt");

	for (int i = 0; i < kitapSayisi; i++) {
		dosya << kitaplar[i]->getId() << "|" << kitaplar[i]->getKitapAdi() << "|" << kitaplar[i]->getYazar() << endl;
	}
	dosya.close();
}

void Kutuphane::dosyaOku() {
	ifstream dosya("kitaplar.txt");
	if (!dosya.is_open()) {
		return;
	}

	string satir;

	while (getline(dosya, satir)) {
		int boru1 = satir.find("|");
		int boru2 = satir.find("|", boru1 + 1);

		int id = stoi(satir.substr(0, boru1));
		string ad = satir.substr(boru1 + 1, boru2 - boru1 - 1);
		string yazar = satir.substr(boru2 + 1);

		kitaplar[kitapSayisi] = new Kitap(ad, yazar, id);
		kitapSayisi++;
		if (id >= nextId) {
			nextId = id + 1;
		}
	}
	dosya.close();
}