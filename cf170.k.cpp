#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Step 1: Create a frequency map
        unordered_map<int, int> freqMap;
        for (int num : a) {
            freqMap[num]++;
        }

        // Step 2: Store pairs in a set to maintain order
        set<pair<int, int>> freqSet; 
        for (const auto& entry : freqMap) {
            freqSet.insert({entry.first, entry.second});
        }

        int maxSum = 0;     // Holds the maximum frequency count
        int currentSum = 0; // Holds the sum of current distinct numbers
        int distinctCount = 0; // Count of distinct numbers in the current window

        auto it = freqSet.begin();
        while (it != freqSet.end()) {
            currentSum += it->second; // Add frequency of the current number
            distinctCount++; // Increment distinct count

            // If we exceed k distinct numbers, move the window
            while (distinctCount > k) {
                currentSum -= prev(it)->second; // Remove frequency of the first number in the window
                distinctCount--; // Decrement the distinct count
                it--; // Move the iterator back
            }

            // Update the max sum if we are within the limit of k distinct numbers
            maxSum = max(maxSum, currentSum);

            // Move to the next element
            it++;
        }

        cout << maxSum << endl; // Output the result for the current test case
    }

    return 0;
}
