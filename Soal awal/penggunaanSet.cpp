#include <iostream>
#include <set>

int main() {
    int N;
    std::cout << "Enter the number of operations: ";
    std::cin >> N;

    std::set<int> mySet;

    for (int i = 0; i < N; i++) {
        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                int value;
                std::cin >> value;
                mySet.insert(value);
                break;
            }
            case 2: {
                int value;
                std::cin >> value;
                mySet.erase(value);
                break;
            }
            case 3: {
                for (const auto& value : mySet) {
                    std::cout << value << " ";
                }
                std::cout << std::endl;
                break;
            }
        }
    }

    return 0;
}