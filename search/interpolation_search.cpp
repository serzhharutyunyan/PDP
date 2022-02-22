#ifndef INTERPOLATION_SEARCH_CPP
#define INTERPOLATION_SEARCH_CPP

    int interpolationSearch(int *arr, int size, int key) {
        int low = 0;
        int high = size - 1;
        while(low <= high && key >= arr[low] && key <= arr[high]) {
            if(low == high) {
                if (arr[low] == key) {
                    return low;
                }

                return -1;
            }

            int pos = low + (((high - low) / (arr[high] - arr[low])) * (key - arr[low]));
            if(arr[pos] == key){
                return pos;
            }

            if(arr[pos] < key) {
                low = pos + 1;
            } else {
                high = pos - 1;
            }
        }

        return -1;
    }

#endif