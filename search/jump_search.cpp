#include <cmath>

#ifndef JUMP_SEARCH_CPP
#define JUMP_SEARCH_CPP

    int jumpSearch(int *arr, int size, int key) {
        int step = sqrt(size);
        int it = 0;
        if (arr[0] == key) {
            return 0;
        }

        while(arr[step] < key && step < size) {
            it = step;
            step += sqrt(size);
        }

        for (it; it < it + sqrt(size); it++) {
            if(arr[it] == key) {
                return it;
            }
        }

        return -1;
    }

#endif