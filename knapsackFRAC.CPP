#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
    int value;
    int weight;
    double cost; // Cost per weight

    // Constructor
    Item(int v, int w) : value(v), weight(w), cost((double)v / w) {}
};

// Comparison function to sort items by cost in descending order
bool comparison(Item a, Item b) {
    return a.cost > b.cost;
}

// Function to perform the fractional knapsack
double fractionalKnapsack(int capacity, vector<Item>& items) {
    // Sort items by cost
    sort(items.begin(), items.end(), comparison);

    double totalValue = 0.0; // Total value accumulated

    for (const auto& item : items) {
        if (capacity <= 0) {
            break; // No more capacity in the knapsack
        }

        if (item.weight <= capacity) {
            // Take the whole item
            capacity -= item.weight;
            totalValue += item.value;
        } else {
            // Take the fraction of the remaining item
            totalValue += item.cost * capacity;
            capacity = 0; // Knapsack is now full
        }
    }

    return totalValue;
}

// Main function
int main() {
    // Create items (value, weight)
    vector<Item> items = {Item(60, 10), Item(100, 20), Item(120, 30)};
    int capacity = 50;

    double maxValue = fractionalKnapsack(capacity, items);
    cout << "Maximum value in Knapsack = " << maxValue << endl;

    return 0;
}


