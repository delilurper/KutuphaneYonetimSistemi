#include "Kitap.h"
#include <iostream>
using namespace std;

Kitap::Kitap(string _kitapAdi, string _yazar, int _id) {
	Kitap::kitapAdi = _kitapAdi;
	Kitap::yazar = _yazar;
	Kitap::id = _id;

}

string Kitap::getKitapAdi() {
	return Kitap::kitapAdi;
}

string Kitap::getYazar() {
	return Kitap::yazar;
}

int Kitap::getId() {
	return Kitap::id;
}

void Kitap::goster() {
	cout << "ID: " << getId() << " | Kitap: " << getKitapAdi() << " | Yazar: " << getYazar() << endl;
}