#ifndef TERNARY_SEARCH_CPP
#define TERNARY_SEARCH_CPP

	int ternarySearch(int *arr, int low, int high, int key){
		if (low < high){
			int mid1 = (low + high) / 3 + 1;
			int mid2 = 2 * (low + high) / 3 + 1;

			if(key == arr[mid1]) {
				return mid1;
			}

			if(key == arr[mid2]) {
				return mid2;
			}

			if(key == arr[low]) {
				return low;
			}

			if(key == arr[high]) {
				return high;
			}

			if(key < arr[mid1]) {
				return ternarySearch(arr, key, low, mid1 - 1);
			} else if(key < arr[mid2]) {
				return ternarySearch(arr, key, mid1 + 1, mid2 - 1);
			} else if(key > arr[mid2]) {
				return ternarySearch(arr, key, mid2 + 1, high);
			}
		}

		return -1;
	}

#endif