#include <iostream>
#include <queue>
using namespace std;

void barisan(queue<int> q) {
    int n = q.size();
    while (!q.empty()) {
        for (int i = 0; i < n; i++) {
            cout << q.front() << " ";
        }
        q.pop();
        cout << endl;
        n = q.size();
    }
    cout << endl;
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    barisan(q);
    return 0;
}
