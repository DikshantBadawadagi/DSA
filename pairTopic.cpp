#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        c[i] = a[i] - b[i];
    }

    sort(c.begin(), c.end());

    long long ans = 0;
    int left = 0;
    int right = n - 1;

    while (left < right) {
        if (c[left] + c[right] > 0) {
            ans += (right - left);
            right--; 
        } else {
            left++;
        }
    }

    cout << ans << endl;

    return 0;
}