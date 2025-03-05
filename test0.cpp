#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int b = 20;
    int c = 30;
    int d = 40;

    //Pointer dapat dideklarasikan seperti ini
    int *ptra = &a;
    int *ptrb = &b;
    int *ptrc = &c;
    int *ptrd = &d;

    //Atau dengan array 
    int* arr[4] = {&a, &b, &c, &d};

    cout << *ptra << " " << *ptrb << " " << *ptrc << " " << *ptrd << endl; //Akan sama dengan
    for (int* i : arr){
        cout<<*i<<" ";
    }
}