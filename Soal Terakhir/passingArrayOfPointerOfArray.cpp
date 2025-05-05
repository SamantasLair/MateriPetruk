#include <iostream>

using namespace std;

void func(int *p[], int n,int sizes[]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < sizes[i]; j++) {
            cout << p[i][j] << " ";
        }
    }
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5};
    int c[] = {7, 8, 9};
    int *p[] = {a, b, c};
    int sizes[] = {3, 2, 3};
    int n = 3;
    func(p, n ,sizes);
}