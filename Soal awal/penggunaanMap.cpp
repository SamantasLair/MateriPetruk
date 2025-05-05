#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    int N; // number of operations
    std::cin >> N;

    map<int, string> myMap;// inisialisasi
    
    for (int i = 0; i < N; i++) {
        int K; 
        std::string V; 
        std::cin >> K >> V;

        myMap[K] = V;
    }

    // Print value 
    for (const auto& pair : myMap) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}