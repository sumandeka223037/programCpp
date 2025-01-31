#include <iostream>
#include<time.h>
using namespace std;
// Function to solve the 0/1 Knapsack problem using Dynamic Programming
int knapsack(int capacity, int weights[], int values[], int n) {
    int dp[n + 1][capacity + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0; 
            } else if (weights[i - 1] <= w) {
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }
    return dp[n][capacity];
}

int main() {
    clock_t start ,end;
    start=clock();
    int values[] = {30, 40, 120}; 
    int weights[] = {50, 20, 40};  
    int capacity = 50;             
    int n = sizeof(values) / sizeof(values[0]); 
    int maxValue = knapsack(capacity, weights, values, n);
    cout << "Maximum value in the knapsack = " << maxValue << endl;
    end=clock();
    float clk=end-start;
    cout<<"Time taken: "<<clk/CLOCKS_PER_SEC<<endl;
    return 0;
}
