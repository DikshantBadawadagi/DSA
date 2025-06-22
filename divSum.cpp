#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    unordered_map<int, long long> freq;
    freq[0] = 1;  // Empty prefix contributes to count
    long long sum = 0, count = 0;

    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int mod = ((sum % n) + n) % n;  // ensure non-negative
        count += freq[mod];
        freq[mod]++;
    }

    cout << count << endl;
    return 0;
}
