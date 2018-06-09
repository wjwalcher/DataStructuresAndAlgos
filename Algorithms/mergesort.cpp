/*
** Best case: O(nlogn) Worst case: O(nlogn) Average case: O(nlogn)
** O(n) space complexity due to temp arrays, not in place.
** Works by recursively splitting array into smaller subarrays, then sorting
** elements as the array is "reassembled" 
*/
#include <iostream>

int array[10] = {2, 4, 55, 11, 40, 8, 7, 10, 83, 100};

void mergeHalves(int array[], int low, int middle, int high) {
    int leftIndex = low;
    int leftEnd = middle+1;
    int rightIndex = middle+1;
    int size = high - low + 1;
    int temp[size];

    for (int i = 0; i < size; i++) {
        if (leftIndex < leftEnd && ((rightIndex > high) || array[leftIndex] <= array[rightIndex])) {
            temp[i] = array[leftIndex]; 
            leftIndex++;
        } else {
            temp[i] = array[rightIndex];
            rightIndex++;
        }
    }
    for (int i = low;i <= high; i++) {
       array[i] = temp[i - low];        
    }
}

void mergesort(int array[], int low, int high) {
    if (low >= high) {
        return;
    }
    int middle = (low + high) / 2;
    mergesort(array, low, middle);
    mergesort(array, middle+1, high);
    mergeHalves(array, low, middle, high);
}

int main() {
    std::cout << "Unsorted:" << std::endl;
    for (int i=0;i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
    mergesort(array, 0, 9);
    std::cout << "Sorted:" << std::endl;
    for (int i=0;i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
}