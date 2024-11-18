#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int p = arr[low];
    int i = low;
    int j = high;

    while (i < j) {
        while (arr[i] <= p && i <= high - 1) {
            i++;
        }
        while (arr[j] > p && j >= low + 1) {
            j--;
        }
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int arraySize;

int sortAndFindMedian(int* arr) {
    quickSort(arr, 0, arraySize - 1); 

    if (arraySize % 2 == 1) {
        return arr[arraySize / 2];
    } else {
        return (arr[arraySize / 2] + arr[(arraySize - 1) / 2]) / 2;
    }
}

int main() {
    int arr[] = {10, 3, 7, 3, 8};
    arraySize = sizeof(arr) / sizeof(arr[0]); 

    int median = sortAndFindMedian(arr);
    printf("Median is: %d\n", median);
    
    int arr1[] = {12, 4, 8, 10};
    arraySize = sizeof(arr1) / sizeof(arr1[0]); 
    int m1 = sortAndFindMedian(arr1);
    printf("Median is: %d\n",m1);
    
    int arr2[] = {6,6,6,6,6,6};
    arraySize = sizeof(arr2) / sizeof(arr2[0]); 
    int m2 = sortAndFindMedian(arr2);
    printf("Median is: %d\n",m2);
    
    int arr3[] = {-5, -10, -3, -1, -7};
    arraySize = sizeof(arr3)/sizeof(arr3[0]);
    int m3 = sortAndFindMedian(arr3);
    printf("Median is: %d\n",m3);

    return 0;
}
