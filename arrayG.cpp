#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, k;
        cin >> n >> k;
        vector<long long> arr(n);

        for (long long i = 0; i < n; i++) {
            cin >> arr[i];
        }

        sort(arr.begin(), arr.end());

        if (k >= 3) {
            cout << 0 << endl;
            continue;
        } 
        else if (k == 1) {
            long long ans = arr[0];
            for (long long i = 1; i < n; i++) {
                ans = min(ans, arr[i] - arr[i - 1]);
            }
            cout << ans << endl;
            continue;
        } 
        else { // k == 2
            long long ans = arr[0];
            for (long long i = 1; i < n; i++) {
                ans = min(ans, arr[i] - arr[i - 1]);
            }

            // Try all pairs to create new elements
            for (long long i = 0; i < n; i++) {
                for (long long j = i + 1; j < n; j++) {
                    long long v = abs(arr[i] - arr[j]);

                    // Find closest element to v using lower_bound
                    auto it = lower_bound(arr.begin(), arr.end(), v);

                    if (it != arr.end()) {
                        ans = min(ans, abs(*it - v));
                    }
                    if (it != arr.begin()) {
                        --it;
                        ans = min(ans, abs(*it - v));
                    }

                    // Also compare the value itself
                    ans = min(ans, v);
                }
            }

            cout << ans << endl;
        }
    }
}
