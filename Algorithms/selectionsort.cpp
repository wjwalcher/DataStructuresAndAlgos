/*
** In place sorting algorithm
** Find smallest unsorted element and add it to end of sorted list.
** Repeat until no unsorted elements remain.
** Search for smallest value in array, swap with smallest index of unsorted part.
** Worst case: O(n^2) Best case: O(n^2) Average case: O(n^2)
*/

int array[10] = {2, 4, 55, 11, 40, 8, 7, 10, 83, 100};

void selectionsort(int arr[], int startIndex, int length) {
    int smallest = 0;
    for (int i = startIndex;i < length; i++) {
        if (arr[smallest] > arr[i]) {
            smallest = i;
        }
    }
    int temp = arr[startIndex];
    arr[startIndex] = arr[smallest];
    arr[smallest] = temp;
    if (startIndex+1 < length) {
        selectionSort(arr, startIndex+1, length);
    }
}

int main() {
    cout << "Unsorted:" << endl;
    for (int i = 0; i < 10;i++) {
        cout << array[i] << endl;
    }
    selectionsort(array, 0, 10);
    cout << "Sorted:" << endl;
    for (int i = 0; i < 10;i++) {
        cout << array[i] << endl;
    }
}
