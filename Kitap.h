#pragma once
#include <iostream>
using namespace std;

class Kitap {
private:
	string kitapAdi;
	string yazar;
	int id;
public:
	Kitap(string _kitapAdi, string _yazar, int _id);
	string getKitapAdi();
	string getYazar();
	int getId();
	void goster();
};