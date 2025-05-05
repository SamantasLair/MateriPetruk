#include<iostream>
#include<stack>
using namespace std;

void pushAndPrint(stack<int>& num, int n){ 
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        num.push(temp); // Menambahkan elemen
    }

    cout << num.top(); // Menampilkan elemen paling atas

    while (!num.empty()){ // Selama stack tidak kosong 
        cout << num.top() << " ";
        num.pop(); // Menghapus elemen
    }
}

int main(){
    stack<int> num;
    num.push(1);
    num.push(2);
    num.push(3);
    num.push(1);
    num.push(2);
    num.push(3);
    pushAndPrint(num);
    return 0;
}