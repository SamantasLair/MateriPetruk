#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <chrono> // For measuring time

int main() {
    // Number of elements to insert
    const int numElements = 100000;

    // Create a map
    std::map<std::string, int> myMap;

    // Create an unordered_map
    std::unordered_map<std::string, int> myUnorderedMap;

    // --- Insertion ---
    auto startMapInsert = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        myMap["key_" + std::to_string(i)] = i;
    }
    auto endMapInsert = std::chrono::high_resolution_clock::now();
    auto mapInsertDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMapInsert - startMapInsert);

    auto startUnorderedMapInsert = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < numElements; ++i) {
        myUnorderedMap["key_" + std::to_string(i)] = i;
    }
    auto endUnorderedMapInsert = std::chrono::high_resolution_clock::now();
    auto unorderedMapInsertDuration = std::chrono::duration_cast<std::chrono::microseconds>(endUnorderedMapInsert - startUnorderedMapInsert);

    std::cout << "--- Insertion Time ---" << std::endl;
    std::cout << "map:          " << mapInsertDuration.count() << " microseconds" << std::endl;
    std::cout << "unordered_map: " << unorderedMapInsertDuration.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    // --- Iteration (Order) ---
    std::cout << "--- Iteration Order (First 10 Elements) ---" << std::endl;
    std::cout << "map (ordered):" << std::endl;
    int count = 0;
    for (const auto& pair : myMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        if (++count == 10) break;
    }

    std::cout << "\nunordered_map (unordered):" << std::endl;
    count = 0;
    for (const auto& pair : myUnorderedMap) {
        std::cout << pair.first << ": " << pair.second << std::endl;
        if (++count == 10) break;
    }
    std::cout << std::endl;

    // --- Search (Access) ---
    auto startMapSearch = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        myMap.find("key_" + std::to_string(i * 100));
    }
    auto endMapSearch = std::chrono::high_resolution_clock::now();
    auto mapSearchDuration = std::chrono::duration_cast<std::chrono::microseconds>(endMapSearch - startMapSearch);

    auto startUnorderedMapSearch = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < 1000; ++i) {
        myUnorderedMap.find("key_" + std::to_string(i * 100));
    }
    auto endUnorderedMapSearch = std::chrono::high_resolution_clock::now();
    auto unorderedMapSearchDuration = std::chrono::duration_cast<std::chrono::microseconds>(endUnorderedMapSearch - startUnorderedMapSearch);

    std::cout << "--- Search Time (1000 Lookups) ---" << std::endl;
    std::cout << "map:          " << mapSearchDuration.count() << " microseconds" << std::endl;
    std::cout << "unordered_map: " << unorderedMapSearchDuration.count() << " microseconds" << std::endl;
    std::cout << std::endl;

    return 0;
}