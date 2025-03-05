#include <iostream>
using namespace std;

int main(){
    int a[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int *ptra = &a[0][0]; // alamat dimensi 1 pada array
    int (*ptrb)[3] = &(a[0]);  // alamat dimensi 2 pada array
    
    cout<<ptra<<" = "<<ptrb<<endl;//Karena menunjuk elemen pertama
    cout<<"Nilai "<<ptra<<" = "<<*(ptra)<<endl;
    cout<<"Nilai "<<ptrb<<" = "<<**(ptrb)<<endl;
    cout<<"\n";

    cout<<ptra+1<<" != "<<ptrb+1<<endl;//Karena menunjuk elemen berbeda
    cout<<"Nilai "<<ptra+1<<" = "<<*(ptra+1)<<endl;
    cout<<"Nilai "<<ptrb+1<<" = "<<**(ptrb+1)<<endl;
    cout<<"\n";

    // Beberapa cara mengakses elemen array
    for(int i = 0; i < 9; i++){
        cout<<*(ptra+i)<<" ";//Pointer arithmetic
    }
    cout<<"\n";

    for(int* i = ptra; i != ptra + 9; i++){
        cout<<*i<<" "; //Pointer Iteration
    }
    cout<<"\n";

    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout<<*(*(ptrb+i)+j)<<" ";//Double loop
        }
    }
    cout<<"\n";

    return 0;
}