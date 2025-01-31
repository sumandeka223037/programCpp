#include <iostream>
using namespace std;

// void quickSort(int arr[], int low, int high) {
//     if (low < high) {
//         // Partition the array and get the pivot index
//         int pivotIndex = partition(arr, low, high);
//         // Recursively sortING
//         quickSort(arr, low, pivotIndex - 1);
//         quickSort(arr, pivotIndex + 1, high);
//     }
// }

// // Function to partition the array
// int partition(int arr[], int low, int high) {
//     int pivot = arr[high]; // Choosing the last element as pivot
//     int i = (low - 1); // Index of smaller element

//     for (int j = low; j < high; j++) {
//         // If current element is smaller than or equal to pivot
//         if (arr[j] <= pivot) {
//             i++; // Increment index of smaller element
//             swap(arr[i], arr[j]); // Swap
//         }
//     }
//     swap(arr[i + 1], arr[high]); // Swap the pivot element with the element at i + 1
//     return i + 1; // Return the partition index
// }

// // Function to print the array
// void printArray(int arr[], int size) {
//     for (int i = 0; i < size; i++) {
//         cout << arr[i] << " ";
//     }
//     cout << endl;
// }

// int main() {
//     int arr[] = {10, 7, 8, 9, 1, 5}; // Sample array
//     int size = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     printArray(arr, size);

//     quickSort(arr, 0, size - 1); // Perform Quick Sort

//     cout << "Sorted array: ";
//     printArray(arr, size); // Print sorted array

//     return 0;
// }


#include <iostream>
#include<time.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = (low - 1); 

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++; 
            swap(arr[i], arr[j]); // Swap
        }
    }
    swap(arr[i + 1], arr[high]); 
    return i + 1; 
}
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    clock_t start,end;
    start= clock();
    int arr[] = {11, 17, 8, 9, 1, 15}; 
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, size);

    quickSort(arr, 0, size - 1); 

    cout << "Sorted array: ";
    printArray(arr, size);
    end=clock();
    float clk = end - start;
    cout<<"The time taken: "<< clk / CLOCKS_PER_SEC << endl;
    return 0;
}

