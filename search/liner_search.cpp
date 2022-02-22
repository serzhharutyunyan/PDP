#ifndef LINER_SEARCH_CPP
#define LINER_SEARCH_CPP

    int linerSearch(int *arr, int size, int key) {
        for (int i = 0; i < size; i++) {
            if(arr[i] == key) {
                return i;
            }
        }
        return -1;
    }

#endif