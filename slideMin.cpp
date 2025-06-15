#include<iostream>
#include<deque>
#include<vector>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    long long res = -1;
    deque<pair<long long, long long>> dq; // {value, index}
    long long prev = x;

    for (long long i = 0; i < n; i++) {
        // Generate next element in sequence
        if (i > 0) {
            prev = (a * prev + b) % c;
        }

        // Maintain monotonic queue: remove back while current is smaller
        while (!dq.empty() && dq.back().first >= prev)
            dq.pop_back();

        dq.push_back({prev, i});

        // Remove elements out of window
        if (dq.front().second <= i - k)
            dq.pop_front();

        // Only start computing result once we have a full window
        if (i >= k - 1) {
            if (res == -1)
                res = dq.front().first;
            else
                res ^= dq.front().first;
        }
    }

    cout << res << endl;
    return 0;
}
