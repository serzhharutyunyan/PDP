#include <iostream>
#include <algorithm>

#include "liner_search.cpp"
#include "jump_search.cpp"
#include "binary_search.cpp"
#include "exponential_search.cpp"
#include "interpolation_search.cpp"
#include "ternary_search.cpp"

int inputNumber();
int *cinArray (int);
void coutArray(int *, int);

int main() {
    unsigned int size = 0;
    std::cout << "Please enter size of array: ";
    std::cin >> size;
    std::cout << "Please enter elements of array" << std::endl;
    int *array = cinArray(size);
    std::cout << std::endl << "Our array is:" << std::endl;
    coutArray(array, size);
    std::sort(array, array + size);
    std::cout << "Our sorted array is:" << std::endl;
    coutArray(array, size);

    std::cout << std::endl << "Enter l for liner sort" << std::endl;
    std::cout << "Enter b for binary sort" << std::endl;
    std::cout << "Enter j for jump sort" << std::endl;
    std::cout << "Enter t for ternary sort" << std::endl;
    std::cout << "Enter e for exponential sort" << std::endl;
    std::cout << "Enter i for interpolation sort" << std::endl;

    char symbol = '\0';
    std::cout << "Enter a symbol: ";
    std::cin >> symbol;

    int found = 0;
    std::cout << std::endl << "Enter the founded element: ";
    found = inputNumber();

    switch(symbol) {
    case 'b':
        std::cout << "Index of searching element is: ";
        std::cout << binarySearch(array, 0, size - 1, found) << std::endl;
        break;
    case 'l':
        std::cout << "Index of searching element is: ";
        std::cout << linerSearch(array, size, found) << std::endl;
        break;
    case 'j':
        std::cout << "Index of searching element is: ";
        std::cout << jumpSearch(array, size, found) << std::endl;
        break;
    case 'e':
        std::cout << "Index of searching element is: ";
        std::cout << exponentialSearch(array, size, found) << std::endl;
        break;
    case 'i':
        std::cout << "Index of searching element is: ";
        std::cout << interpolationSearch(array, size, found) << std::endl;
        break;
    case 't':
        std::cout << "Index of searching element is: ";
        std::cout << ternarySearch(array, 0, size - 1, found) << std::endl;
        break;
    default:
        std::cout << "Not exist that sort algorithm: ";
        break;
    }

    delete [] array;
    return 0;
}

int inputNumber() {
    int intNumber = 0;
    do {
        std::cin.clear();
        std::cin.ignore(100,'\n');
        std::cout << "Enter only number: ";
        std::cin >> intNumber;
    } while (std::cin.fail());

    return intNumber;
}

int *cinArray(int size) {
    int *array = new int[size];
    for(int i = 0; i < size; i++) {
        array[i] = inputNumber();
    }

    return array;
}

void coutArray(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << "\t";
    }

    std::cout << std::endl;
}