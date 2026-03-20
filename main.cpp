#include <iostream>
#include "Kutuphane.h"

using namespace std;

int main() {
    Kutuphane k;
    int secim;

    do {
        cout << "\n--- Kutuphane Sistemi ---\n";
        cout << "1. Kitap Ekle\n";
        cout << "2. Listele\n";
        cout << "3. Ara\n";
        cout << "4. Sil\n";
        cout << "5. Cikis\n";
        cout << "Secim: ";
        cin >> secim;

        switch (secim) {
        case 1:
            k.kitapEkle();
            break;
        case 2:
            k.kitapListele();
            break;
        case 3:
            k.kitapAra();
            break;
        case 4:
            k.kitapSil();
            break;
        case 5:
            cout << "Cikis yapiliyor...\n";
            break;
        default:
            cout << "Gecersiz secim!\n";
        }

    } while (secim != 5);

    return 0;
}