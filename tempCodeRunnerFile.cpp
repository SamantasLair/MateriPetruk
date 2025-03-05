#include <iostream>

class Asdos {
public://Specifier menunjukkan hak akses
    // Atribut
    std::string name;
    int age;

    // Method
    void catchPhrase() {
        std::cout << "P for Petruk" << std::endl;
    }
};

int main() {
    // Deklarasi objek
    Asdos myAsdos;
    myAsdos.name = "Rizky";
    myAsdos.age = 20;

    // Pointer ke object
    Asdos *AsdosPtr = &myAsdos;

    std::cout << "Asdos's name: " << AsdosPtr->name << std::endl; // Output: Rizky
    AsdosPtr->catchPhrase(); // Output: P for Petruk
    (*AsdosPtr).catchPhrase();// Alternatif

    // Alokasi objek dinamis
    Asdos *anotherAsdosPtr = new Asdos();
    anotherAsdosPtr->name = "Oryza";
    anotherAsdosPtr->age = 20;

    // Alternatif 
    // (*anotherAsdosPtr).name = "Daffa";
    // (*anotherAsdosPtr).age = 20;

    std::cout << "Another Asdos's name: " << anotherAsdosPtr->name << std::endl; // Output: Max
    anotherAsdosPtr->catchPhrase(); // Output: Woof!

    // Dealokasi 'New'
    delete anotherAsdosPtr; // Pencegahan kebocoran memori
    anotherAsdosPtr = nullptr; // Pencegahan dangling pointer

    return 0;
}