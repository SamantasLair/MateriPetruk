/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <string>
std::string nextPalindrome(std::string palindrome){
    bool pal = true;
    int length = palindrome.length();
    for(int i = 0; i<length/2;i++){
        if(palindrome[i]!=palindrome[length-1-i]){
            pal = false;
            break;
        }
    }
    if(pal){
        std::cout<<"True, ";
    }else std::cout<<"False, ";
    std::string cek = palindrome;
    
    for(int i = 0; i < length/2;i++){
        cek[length-i-1] = cek[i];
    }
    long intCek = std::stol(cek);
    long intPal = std::stol(palindrome);
    std::string hasil;
    if(intCek<intPal){
        long tambah = 1;
        int pangkat = (length+1)/2;
        for(int i = 1; i<pangkat; i++){
            tambah*=10;
        }
    
        intPal += tambah;
        hasil = std::to_string(intPal);
        length = hasil.length();
        for(int i = 0; i<length/2;i++){
            hasil[length-1-i]=hasil[i];
        }
    }
    else hasil = std::to_string(intCek);
    return hasil;
}

int main()
{
    std::cout<<nextPalindrome("110");

    return 0;
}