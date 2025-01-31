#include <iostream>
#include<time.h>
using namespace std;
int bSearch_Recursive(int arr[], int left, int right, int key) {
    if (left > right) {
        return -1; // Element not found
         }    
    int mid = (left + right)/ 2;
    
    if (arr[mid] == key) {
        return mid; // Element found
    } else if (arr[mid] < key) {
        return bSearch_Recursive(arr, mid + 1, right, key);
    } else {
        return bSearch_Recursive(arr, left, mid - 1, key);
    }
}

int main() {
    clock_t start,end;
    start=clock();
    int n = 8;
    int arr[n] = {21, 33, 45, 47, 59, 71, 83, 95};
    int key = 47;    
    int ans = bSearch_Recursive(arr, 0, n - 1, key);    
    if (ans != -1) {
        cout << "Element found at index " << ans << endl;
    } else {
        cout << "Element not found" << endl;
    }
    end=clock();
    float clk = end - start;
    cout<<" The time taken: "<< clk / CLOCKS_PER_SEC << endl;
    
    return 0;
}    
