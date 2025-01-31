#include<iostream>
#include<time.h>
using namespace std;
int bSearch_Iterative(int arr[], int n, int key) {
    int left = 0;
    int right = n - 1;    
    while (left <= right) {
        int mid = left + (right - left) / 2;        
        if (arr[mid] == key) {
            return mid;                                /* Element found*/        } 
       else if (arr[mid] < key) {
            left = mid + 1;       } 
       else {
            right = mid - 1; }    }    
    return -1;                                         /* Element not found*/
}
int main() {
    clock_t start,end;
    start=clock();
    int n;
    cout<<"enter the size of array: ";
    cin>>n;
    int arr[n];
    cout<<"enter array elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];       }
    int key;
    cout<<"enter element to be searched: ";
    cin>>key;
    int ans= bSearch_Iterative(arr,n,key);
    if (ans != -1) {
        cout << "Element found at index " << ans << endl; }
 else {
        cout << "Element not found" << endl; }  
    end=clock();
    float clk = end-start;
    cout<<"The time taken: "<< clk / CLOCKS_PER_SEC << endl;  
    return 0;
}
