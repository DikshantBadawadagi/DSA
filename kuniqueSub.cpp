#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a) cin >> x;

    long long ans = 0;
    unordered_map<int, int> freq;
    int left = 0;

    for (int right = 0; right < n; ++right) {
        freq[a[right]]++;

        // Shrink window if we have more than k distinct elements
        while (freq.size() > k) {
            freq[a[left]]--;
            if (freq[a[left]] == 0)
                freq.erase(a[left]);
            left++;
        }

        // All subarrays ending at `right` with valid `left`
        ans += (right - left + 1);
    }

    cout << ans << endl;
    return 0;
}
