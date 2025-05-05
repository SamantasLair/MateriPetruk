#include <iostream>

int tambah(int a, int b) {
    return a + b;
}

int kurang(int a, int b) {
    return a - b;
}

long kali(int a, int b) {
    return a * b;
}

double bagi(int a, int b) {
    return (double)a / b;
}

double kuadratkan(int (*func)(int,int), int x, int y){
    return (double)(func(x,y))*(func(x,y));
}

int main() {
    int (*ptr)(int, int) = tambah;
    int hasil = ptr(5, 3);
    std::cout << "Hasil tambah: " << hasil << std::endl;
    ptr = kurang;
    hasil = ptr(5, 3);
    std::cout << "Hasil kurang: " << hasil << "\n\n";

    //Kudraktan dengan pointer ke fungsi lain
    std::cout<<"Hasil dengan fungsi tambah :\n";
    std::cout<<kuadratkan(tambah,15,2)<<'\n';
    std::cout<<"Hasil dengan fungsi kurang :\n";
    std::cout<<kuadratkan(kurang,15,2)<<'\n';

    return 0;
}