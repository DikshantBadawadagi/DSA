#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;

    vector<int> dp; // dp[i] = smallest tail of LIS of length i+1

    for(int x : arr) {
        auto it = lower_bound(dp.begin(), dp.end(), x);
        if(it == dp.end()) {
            dp.push_back(x); // extend LIS
        } else {
            *it = x; // replace to keep dp optimized
        }
    }

    cout << dp.size() << endl;
}
