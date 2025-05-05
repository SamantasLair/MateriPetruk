#include <iostream>
#include <map>
using namespace std;

class Kontak {
public:
    map<string, string> kontak;

    void tambahKontak(string nama, string nomor) {
        kontak[nama] = nomor;
    }

    void hapusKontak(string nama) {
        if (kontak.find(nama) != kontak.end()) {
            kontak.erase(nama);
        } else {
            cout << "Kontak tidak ditemukan" << endl;
        }
    }

    void tampilkanKontak() {
        for (auto& pair : kontak) {
            cout << pair.first << endl;
        }
    }

    void cariKontak(string nama) {
        if (kontak.find(nama) != kontak.end()) {
            cout << "Wujud asli " << nama << ": " << kontak[nama] << endl;
        } else {
            cout << "Kontak tidak ditemukan" << endl;
        }
    }
};

int main() {
    Kontak kontak;
    kontak.tambahKontak("Tukang galon", "Ayang kantor");
    kontak.tambahKontak("Tukang bakso", "Tetangga cantik");
    kontak.tambahKontak("Tukang kayu", "Si manis kawan SMA");

    kontak.tampilkanKontak();

    kontak.cariKontak("Tukang galon");

    kontak.hapusKontak("Tukang bakso");

    kontak.tampilkanKontak();

    return 0;
}