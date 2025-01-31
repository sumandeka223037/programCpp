#include <iostream>
#include<time.h>
using namespace std;
int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; // Return -1 if the target is not found
}

int main() {
    clock_t start , end;
    start=clock();
    int arr[] = {10, 20, 30, 40, 50}; 
    int size = sizeof(arr) / sizeof(arr[0]); 
    int target;

    cout << "Enter the number to search: ";
    cin >> target;
    int result = linearSearch(arr, size, target); 
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found in the array." << endl;
    }
    end = clock();
    float clk = end-start;
    cout<<"The time taken : "<< clk / CLOCKS_PER_SEC << endl; 
    return 0;
}
