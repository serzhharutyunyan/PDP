#ifndef BINARY_SEARCH_CPP
#define BINARY_SEARCH_CPP

    int binarySearch(int *arr, int low, int high, int key) {
        if (high >= low) {

            if(arr[low] == key) {
                return low;
            }

            if(arr[high] == key) {
                return high;
            }

            int mid = low + (high - low) / 2;
            if (arr[mid] == key) {
            return mid;
            }

            if (arr[mid] > key) {
                return binarySearch(arr, low, mid - 1, key);
            }

            return binarySearch(arr, mid + 1, high, key);
        }

        return -1;
    }

#endif