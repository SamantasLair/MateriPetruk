#include <iostream>
#include <stack>
using namespace std;

class Barang {
public:
    int harga;
    string nama;
    Barang(int harga, string nama) {
        this->harga = harga;
        this->nama = nama;
    }
};

void displayBarang(Barang barang) {
    cout << barang.nama << " " << barang.harga << endl;
}

void calculateTotalHarga(stack<Barang>& stackBarang) {
    int totalHarga = 0;
    while (!stackBarang.empty()) {
        Barang barang = stackBarang.top();
        totalHarga += barang.harga;
        displayBarang(barang);
        stackBarang.pop();
    }
    cout << "Total harga: " << totalHarga << endl;
}

void addBarang(stack<Barang>& stackBarang) {
    int harga;
    string nama;
    cout << "Masukkan harga: ";
    cin >> harga;
    cout << "Masukkan nama: ";
    cin >> nama;
    stackBarang.push(Barang(harga, nama));
}

void removeBarang(stack<Barang>& stackBarang) {
    if (!stackBarang.empty()) {
        Barang barang = stackBarang.top();
        displayBarang(barang);
        stackBarang.pop();
    } else {
        cout << "Stack kosong" << endl;
    }
}

int main() {
    stack<Barang> stackBarang;
    stackBarang.push(Barang(10000, "Baju"));
    stackBarang.push(Barang(5000, "Celana"));
    stackBarang.push(Barang(2000, "Sepatu"));

    int choice;
    do {
        cout << "1. Tampilkan barang" << endl;
        cout << "2. Hitung total harga" << endl;
        cout << "3. Tambahkan barang" << endl;
        cout << "4. Hapus barang" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;

        switch (choice) {
            case 1:
                while (!stackBarang.empty()) {
                    displayBarang(stackBarang.top());
                    stackBarang.pop();
                }
                break;
            case 2:
                calculateTotalHarga(stackBarang);
                break;
            case 3:
                addBarang(stackBarang);
                break;
            case 4:
                removeBarang(stackBarang);
                break;
            case 5:
                break;
            default:
                cout << "Pilihan tidak valid" << endl;
        }
    } while (choice != 5);

    return 0;
}