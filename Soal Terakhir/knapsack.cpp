#include <iostream>
using namespace std;

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0) {
        return 0;
    }
    //Eficient approach
    double ratio[n];
    for (int i = 0; i < n; i++) {
        ratio[i] = val[i] / wt[i];
    }

    

}


int main() {
    int wt[] = {1, 2, 4, 7};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt) / sizeof(wt[0]);
    cout << knapsack(W, wt, val, n);
    return 0;
}