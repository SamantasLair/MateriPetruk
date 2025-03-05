#include <iostream>

using namespace std;
int main() {
    // Alokasi Memori Dinamis untuk Array of Pointers ke Integer
    int** arr = new int*[5]; 

    // Alokasi Memori Dinamis untuk Setiap Integer
    for (int i = 0; i < 5; i++) {
        arr[i] = new int;
        *arr[i] = i * 10; // Inisialisasi nilai
    }

    cout << "Array :\n";
    for (int i = 0; i < 5; i++) {
        cout << *arr[i] << " ";
    }
    cout << endl;

    // Dealokasi Memori (Mencegah Memory Leak)
    for (int i = 0; i < 5; i++) {
        delete arr[i]; // Membebaskan memori integer
        arr[i] = nullptr; // Mencegah dangling pointer
    }
    delete[] arr; // Membebaskan memori array of pointers
    arr = nullptr; // Mencegah dangling pointer

    // Contoh Dangling Pointer, menyebabkan error karena arr sudah dibebaskan 
    // cout << *arr[0] << endl; 

    // Memeriksa Pointer Sebelum Digunakan (Setelah Dealokasi)
    if (arr != nullptr) {
        cout << "arr masih ada (ini tidak akan dicetak)\n";
    } else cout << "arr sudah dihapus\n";

    return 0;
}