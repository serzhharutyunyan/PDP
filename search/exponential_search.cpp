#include "binary_search.cpp"

#ifndef EXPONENTIAL_SEARCH_CPP
#define EXPONENTIAL_SEARCH_CPP

    int exponentialSearch(int *arr, int size, int key) {
        if(arr[0] == key) {
            return 0;
        }

        int step = 1;
        while(step < size && arr[step] <= key) {
            step = step * 2;
        }

        return binarySearch(arr, step/2, size, key);
    }

#endif