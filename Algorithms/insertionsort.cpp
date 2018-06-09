/*
** In place sorting algorithm
** Create "sorted" and "unsorted" partitions. 
** When you come across an item that is smaller than sorted partition, 
** insert it to its correct spot by shuffling elements up.
** Best case: O(n) [array is already sorted]
** Worst case: O(n^2) [array in reverse order, must make n * n comparisons]
** Average case: O(n^2) 
*/
# include <iostream>

int array[10] = {2, 4, 55, 11, 40, 8, 7, 10, 83, 100};

void insertionsort(int arr[], int length) {
    for (int i = 1;i < length; i++) {
        int temp = arr[i];
        int index = i;
        while(index > 0 && arr[i - 1] > temp) {
            arr[index] = arr[i - 1];
            index--;
        }
        arr[index] = temp;
    }
}

int main() {
    std::cout << "Unsorted:" << std::endl;
    for (int i = 0; i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
    insertionsort(array, 10);
    std::cout << "Sorted:" << std::endl;
    for (int i = 0; i < 10;i++) {
        std::cout << array[i] << std::endl;
    }
}