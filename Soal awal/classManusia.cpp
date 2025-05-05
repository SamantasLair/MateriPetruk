#include <iostream>

class Manusia {
public:
    int umur;
    std::string nama;
    std::string alamat;
    std::string pekerjaan;

    Manusia(int umur, std::string nama, std::string alamat, std::string pekerjaan) {
        this->umur = umur;
        this->nama = nama;
        this->alamat = alamat;
        this->pekerjaan = pekerjaan;
    }

    void perkenalan() {
        std::cout << "Halo, nama saya " << this->nama << " dan umur saya " << this->umur << std::endl;
        std::cout << "Saya tinggal di " << this->alamat << std::endl;
        std::cout << "Saya bekerja sebagai " << this->pekerjaan << std::endl;
    }

    void ubahAlamat(std::string alamatBaru) {
        this->alamat = alamatBaru;
    }

    void ubahPekerjaan(std::string pekerjaanBaru) {
        this->pekerjaan = pekerjaanBaru;
    }
};

int main() {
    Manusia man(20, "Rizky", "Jalan Raya", "Mahasiswa");
    man.perkenalan();

    man.ubahAlamat("Jalan Baru");
    man.ubahPekerjaan("Pekerja");

    man.perkenalan();

    return 0;
}