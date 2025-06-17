#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    long long median = arr[n / 2];  // For even n, either middle is fine for min cost

    long long ans = 0;
    for(int i = 0; i < n; i++) {
        ans += abs(arr[i] - median);
    }

    cout << ans << endl;
}
