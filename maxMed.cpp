#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(long long x, int n, long long k, const vector<long long>& a) {
    long long cost = 0;
    for (int i = n / 2; i < n; i++) {
        if (x > a[i]) {
            cost += (x - a[i]);
        }
        if (cost > k) return false; 
    }
    return cost <= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());


    long long low = a[n / 2];
    long long high = a[n / 2] + k; 
    long long ans = low;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (check(mid, n, k, a)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}