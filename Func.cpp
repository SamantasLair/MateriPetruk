#include <iostream>

using namespace std;

//Fungsi yang akan ditunjuk
void func1 (){cout<<"Func1 terpanggil\n";}
void func2 (){cout<<"Func2 terpanggil\n";}
void func3 (){cout<<"Func3 terpanggil\n";}
int main(){
    //Pointer ke function harus memiliki tipe data return yang sama
    void (*ptr1)() = func1;
    void (*ptr2)() = func2;
    void (*ptr3)() = func3;

    //Dalam array
    void (*ptrArr[3])() = {func1,func2,func3};
    
    //Memanggil pointer
    (*ptr1)();
    cout<<'\n';

    //Looping
    for(int i = 0; i<3; i++){
        (*(ptrArr[i]))();
    }
    
    
    return 0;
}