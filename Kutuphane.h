#pragma once
#include "Kitap.h"

class Kutuphane {
private:
	Kitap* kitaplar[100];
	int kitapSayisi;
	int nextId;

	void dosyaYaz();
	void dosyaOku();
public:
	Kutuphane();
	void kitapEkle();
	void kitapListele();
	void kitapAra();
	void kitapSil();

	~Kutuphane();
};