#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int N; // number of operations
    std::cin >> N;

    unordered_map<int, string> myunordered_map;// inisialisasi
    
    for (int i = 0; i < N; i++) {
        int K; 
        std::string V; 
        std::cin >> K >> V;

        myunordered_map[K] = V;
    }

    // Print value 
    for (const auto& pair : myunordered_map) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    return 0;
}