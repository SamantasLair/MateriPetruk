#include <queue>
#include <iostream>
using namespace std;

class pasien {
    string nama;
    int umur;
    string penyakit;
    string dokter;
    public:
    pasien(string nama, int umur, string penyakit, string dokter) {
        this->nama = nama;
        this->umur = umur;  
        this->penyakit = penyakit;
        this->dokter = dokter;
    }
    string getNama() {
        return this->nama;
    }
    int getUmur() {
        return this->umur;
    }
    string getPenyakit() {
        return this->penyakit;
    }
    string getDokter() {
        return this->dokter;
    }
};

int main() {
    queue<pasien> antrian;
    int n;
    cin >> n;
        string nama;
        int umur;
        string penyakit;
        string dokter;
    for (int i = 0; i < n; i++) {
        cin >> nama >> umur >> penyakit >> dokter;
        pasien p(nama, umur, penyakit, dokter);
        antrian.push(p);
    }

    while (!antrian.empty()) {
            cout << "Dokter " << antrian.front().getDokter() 
            << " akan memeriksa pasien sekarat dengan nama "<<antrian.front().getNama()<< 
            " yang berumur "<<antrian.front().getUmur()<<" tahun dan penyakitnya adalah "
            <<antrian.front().getPenyakit()<<endl;
            antrian.pop();
    }
}