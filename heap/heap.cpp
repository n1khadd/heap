#include <iostream>
#include <cstdlib>
#include <ctime>

int* allocateArray(int size) {
    if (size <= 0) {
        std::cerr << "Massivin ölçüsü mənfi və ya sıfır ola bilməz!" << std::endl;
        return nullptr;
    }
    return new int[size];
}

void fillArrayWithRandom(int* arr, int size) {
    if (arr == nullptr) {
        std::cerr << "Massiv pointeri nullptr ola bilməz!" << std::endl;
        return;
    }
    std::srand(std::time(nullptr));
    for (int i = 0; i < size; i++) {
        arr[i] = std::rand() % 100;
    }
}

void printArray(const int* arr, int size) {
    if (arr == nullptr) {
        std::cerr << "Massiv pointeri nullptr ola bilməz!" << std::endl;
        return;
    }
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int* appendToArray(int* arr, int& size, int value) {
    if (size < 0) {
        std::cerr << "Massivin ölçüsü mənfi ola bilməz!" << std::endl;
        return nullptr;
    }
    int* newArr = new int[size + 1];
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i];
    }
    newArr[size] = value;
    size++;
    delete[] arr;
    return newArr;
}

int* insertToArray(int* arr, int& size, int index, int value) {
    if (index < 0 || index > size) {
        std::cerr << "Yanlış indeks!" << std::endl;
        return nullptr;
    }
    int* newArr = new int[size + 1];
    for (int i = 0, j = 0; i < size + 1; i++) {
        if (i == index) {
            newArr[i] = value;
        }
        else {
            newArr[i] = arr[j++];
        }
    }
    size++;
    delete[] arr;
    return newArr;
}

int main() {
    int size;
    std::cout << "Massivin ölçüsünü daxil edin: ";
    std::cin >> size;

    int* myArray = allocateArray(size);
    if (myArray == nullptr) return -1;

    fillArrayWithRandom(myArray, size);
    std::cout << "Massivin ilkin vəziyyəti: ";
    printArray(myArray, size);

    int newElement;
    std::cout << "Sonuna əlavə etmək istədiyiniz elementi daxil edin: ";
    std::cin >> newElement;
    myArray = appendToArray(myArray, size, newElement);
    std::cout << "Massivə element əlavə edildikdən sonra: ";
    printArray(myArray, size);

    int index, value;
    std::cout << "Əlavə etmək istədiyiniz elementin indeksini və dəyərini daxil edin: ";
    std::cin >> index >> value;
    myArray = insertToArray(myArray, size, index, value);
    std::cout << "Element əlavə edildikdən sonra: ";
    printArray(myArray, size);

    delete[] myArray;
    return 0;
}
