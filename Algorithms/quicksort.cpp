/*
** Quick sort using Bentley's Algorithm
** Worst case: O(n^2) Best case: O(nlogn) Average case: O(nlogn)
** In place, not necessarily stable.
** Works by selecting the first element of array as pivot, 
** checking if each element is less than the pivot.
** if an element is less than the pivot, it is swapped with the element occupying the 
** next space in the "sorted" partition. When the current pointer runs off the end 
** of the list, the pointer to the last element of the sorted partition swaps with the pivot, and
** the algorithm continues until the list is sorted.
*/

#include <iostream>

int array[10] = {2, 4, 55, 11, 40, 8, 7, 10, 83, 100};

void quicksort(int array[], int low, int high) {
    int temp;
    if (low < high) {
        int p = low;
        for (int i = low+1; i <= high; i++) {
            if (array[i] < array[low]) {
                temp = array[++p];
                array[p] = array[i];
                array[i] = temp;
            }
        }
        temp = array[low];
        array[low] = array[p];
        array[p] = temp;

        quicksort(array, low, p-1);
        quicksort(array, p+1, high);
    }
}


int main() {
     std::cout << "Unsorted:" << std::endl;
    for (int i=0;i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
    quicksort(array, 1, 9);
    std::cout << "Sorted:" << std::endl;
    for (int i=0;i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
}