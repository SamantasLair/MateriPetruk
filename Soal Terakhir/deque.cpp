#include <deque>
#include <iostream>
using namespace std;

void fromBackToFront(int N, deque<int> dq){
    for(int i = 0; i < N; i++){
        dq.push_front(dq.back());
        dq.pop_back();
    }

    for(int i : dq){
        std::cout<<i;
    }
}
int main() {
    deque<int> dq = {1, 2, 3, 4, 5};
    fromBackToFront(3,dq);
    return 0;
}

