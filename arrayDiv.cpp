#include <iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &nums, int k, long long maxSum) {
    long long currSum = 0;
    int parts = 1;

    for (int x : nums) {
        if (x > maxSum) return false; // single element too large
        if (currSum + x > maxSum) {
            parts++;
            currSum = x;
        } else {
            currSum += x;
        }
    }

    return parts <= k;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    long long low = *max_element(nums.begin(), nums.end());
    long long high = accumulate(nums.begin(), nums.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = (low + high) / 2;
        if (isPossible(nums, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << ans << endl;
    return 0;
}
