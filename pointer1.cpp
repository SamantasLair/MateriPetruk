#include <iostream>

int main() {
    int x = 10;
    int *p = &x;
    std::cout << *p << std::endl;
    return 0;
}