#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    // Edge case: k == n (one window)
    if (k == n) {
        long long windowOr = x;
        long long curr = x;
        for (long long i = 2; i <= n; i++) {
            curr = (a * curr + b) % c;
            windowOr |= curr;
        }
        cout << windowOr << endl;
        return 0;
    }

    // Step 1: Generate the first k elements and compute the first window OR
    vector<long long> elements(k);  // Circular buffer for the window
    vector<long long> bitCount(32, 0);  // Count of elements with each bit set
    long long curr = x;
    elements[0] = curr;

    // Process the first element's bits
    for (int j = 0; j < 32; j++) {
        if (curr & (1LL << j)) {
            bitCount[j]++;
        }
    }

    // Generate the rest of the first window
    for (long long i = 1; i < k; i++) {
        curr = (a * curr + b) % c;
        elements[i] = curr;
        for (int j = 0; j < 32; j++) {
            if (curr & (1LL << j)) {
                bitCount[j]++;
            }
        }
    }

    // Compute the first window OR
    long long windowOr = 0;
    for (int j = 0; j < 32; j++) {
        if (bitCount[j] > 0) {
            windowOr |= (1LL << j);
        }
    }

    long long result = windowOr;
    long long prev = curr;

    // Step 2: Slide the window
    for (long long i = 0; i < n - k; i++) {
        // Remove the leftmost element (elements[i % k])
        long long leaving = elements[i % k];
        for (int j = 0; j < 32; j++) {
            if (leaving & (1LL << j)) {
                bitCount[j]--;
                if (bitCount[j] == 0) {
                    // Clear this bit in windowOr
                    windowOr &= ~(1LL << j);
                }
            }
        }

        // Add the new element
        long long nextElement = (a * prev + b) % c;
        elements[i % k] = nextElement;
        prev = nextElement;
        for (int j = 0; j < 32; j++) {
            if (nextElement & (1LL << j)) {
                bitCount[j]++;
                if (bitCount[j] == 1) {
                    // Set this bit in windowOr
                    windowOr |= (1LL << j);
                }
            }
        }

        // Update the XOR result
        result ^= windowOr;
    }

    cout << result << endl;
    return 0;
}