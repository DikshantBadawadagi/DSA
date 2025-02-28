#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); // Fast input-output
    cin.tie(NULL);
    
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        vector<int> nums(n);
        string s;
        
        // Input array
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        
        // Input binary string
        cin >> s;
        
        // Initialize prefix XOR array
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] ^ nums[i];
        }
        
        // Initialize X0 and X1
        int X0 = 0, X1 = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                X1 ^= nums[i];
            } else {
                X0 ^= nums[i];
            }
        }
        
        // Process queries
        long long q;
        cin >> q;
        while (q--) {
            int query, g, l, r;
            cin >> query;
            if (query == 2) {
                // Query Type 2: Output XOR for group g
                cin >> g;
                if (g == 0) {
                    cout << X0 << endl;
                } else {
                    cout << X1 << endl;
                }
            } else if (query == 1) {
                // Query Type 1: Invert all values from l to r
                cin >> l >> r;
                l--; r--; // Convert to 0-based index
                
                // Get XOR of subarray [l, r] using prefix XOR array
                int flip = prefix[r] ^ (l > 0 ? prefix[l-1] : 0);
                
                // Invert in both X0 and X1
                X0 ^= flip;
                X1 ^= flip;
                
                // Update the binary string in range [l, r]
                for (int i = l; i <= r; i++) {
                    if (s[i] == '1') s[i] = '0';
                    else s[i] = '1';
                }
            }
        }
    }
    return 0;
}
