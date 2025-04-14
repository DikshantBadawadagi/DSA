#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }
        long long sum = 0;
        for (long long value : nums) {
            sum += value;
        }
        vector<int> mpp(30, 0);
        for (long long value : nums) {
            for (int i = 0; i < 30; i++) {
                if (value & (1LL << i)) {
                    mpp[i]++;
                }
            }
        }
        long long maxi = 0;
        for (long long num : nums) {
            long long temp = sum;
            for (int i = 0; i < 30; i++) {
                if (num & (1LL << i)) {
                    int match = mpp[i];
                    long long bit = 1LL << i;
                    temp += (n - 2 * match) * bit;
                }
            }
            maxi = max(maxi, temp);
        }
        cout<<maxi<< endl;
    }
    return 0;
}