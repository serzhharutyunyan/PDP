#include <iostream>
#include <algorithm>

int displayArray(int *, int);
void swap(int &, int &);
int inputNumber();
int *cinArray (int);
void coutArray(int *, int);

void insertionSort(int *, int);
void selectionSort(int *, int);
void shellSort(int *, int);

void merge(int *, int, int, int);
void mergeSort(int *, int, int);

int partitionQuick (int *, int, int);
void quickSort (int *, int, int);

int main() {
    unsigned int size = 0;
    std::cout << "Please enter size of array: ";
    std::cin >> size;
    std::cout << "Please enter elements of array" << std::endl;
    int *array = cinArray(size);
    std::cout << std::endl << "Our array is:" << std::endl;
    coutArray(array, size);

    std::cout << "Enter i for insertion sort" << std::endl;
    std::cout << "Enter m for marge sort" << std::endl;
    std::cout << "Enter S for selection sort" << std::endl;
    std::cout << "Enter s for shell sort" << std::endl;
    std::cout << "Enter q for quick sort" << std::endl;

    char symbol = '\0';
    std::cout << "Enter a symbol: ";
    std::cin >> symbol;

    switch(symbol) {
    case 'm':
        mergeSort(array, 0, size - 1);
        coutArray(array, size);
        break;
    case 'i':
        insertionSort(array, size);
        coutArray(array, size);
        break;
    case 's':
        shellSort(array, size);
        coutArray(array, size);
        break;
    case 'S':
        selectionSort(array, size);
        coutArray(array, size);
        break;
    case 'q':
        quickSort(array, 0, size);
        coutArray(array, size);
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

int displayArray(int *arr, int size) {
    for(int i=0; i < size; i++) {
        std::cout << arr[i] << '\t';
    }

    std::cout << std::endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void insertionSort(int *arr, int size) {
    int i, j, tmp;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}

void selectionSort(int *array, int size) {
    int temp;
    int min;

    for (int i = 0; i < size; ++i) {
        min = i;
        for (int j = i + 1; j < size; ++j) {
            if (array[j] < array[min]) {
                min = j;
            }
        }

        if (min != i) {
            swap(array[i],array[min]);
        }
    }
}

void shellSort(int *arr, int size) {
    for (int i = size / 2; i > 0; i /= 2) {
        for (int j = i; j < size; j++) {
            int k = j;
            while (arr[k] < arr[k - i] && k >= i) {
                swap(arr[k], arr[k - i]);
                k -= i;
            }
        }
    }

}

void merge(int *array, int low, int mid, int high) {
    int newArr[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= high) {
        (array[i] <= array[j]) ? newArr[k++] = array[i++] : newArr[k++] = array[j++];
    }

    while (i <= mid) {
        newArr[k++] = array[i++];
    }

    while (j <= high) {
        newArr[k++] = array[j++];
    }

    k--;
    while (0 <= k) {
        array[k + low] = newArr[k];
        k--;
    }
}

void mergeSort(int *array, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        mergeSort(array, low, mid);
        mergeSort(array, mid + 1, high);
        merge(array, low, mid, high);
    }
}

int partitionQuick (int *arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
   	for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(int *arr, int low, int high) {
    if(low < high) {
	    int pos = partitionQuick(arr, low, high);
        quickSort(arr, low, pos - 1);
        quickSort(arr, pos + 1, high);
    }
}