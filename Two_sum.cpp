#include <iostream>
#include <unordered_map> // Required for the map
#include <utility>       // Required for pair

using namespace std;

pair<int, int> two_sum(int arr[], int n, int target) {
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++) {
        int complement = target - arr[i];
        
        // Check if complement exists in map
        if (map.find(complement) != map.end()) {
            return {map[complement], i};
        }
        
        // Add current element and index to map
        map[arr[i]] = i;
    }
    return {-1, -1};
}

int main() {
    cout << "Enter the array size: ";
    int n, target;
    cin >> n;
    
    // Using a pointer for dynamic array allocation (Standard C++)
    int* arr = new int[n]; 
    
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "Enter the target sum: ";
    cin >> target;
    
    // FIX: Store the return value in a pair, not an int
    pair<int, int> result = two_sum(arr, n, target);
    
    // FIX: Access pair using .first and .second
    if (result.first != -1) {
        cout << "Indices found: " << result.first << " and " << result.second << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    // Clean up memory
    delete[] arr; 
    
    return 0;
}