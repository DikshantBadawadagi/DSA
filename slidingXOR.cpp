#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    long long x, a, b, c;
    cin >> x >> a >> b >> c;

    long long numWindows = n - k + 1;
    long long result = 0;

    if (numWindows % 2 == 0) {
        // Even number of windows
        long long curr = x;
        vector<long long> firstElements(numWindows / 2);
        vector<long long> lastElements(numWindows / 2);

        // Generate first elements of each pair
        for (long long i = 1; i <= n; i++) {
            if (i <= numWindows && (i - 1) % 2 == 0) {
                firstElements[(i - 1) / 2] = curr;
            }
            curr = (a * curr + b) % c;
        }

        // Generate last elements of each pair
        curr = x;
        for (long long i = 1; i <= n; i++) {
            if (i > k && (i - k - 1) % 2 == 0) {
                lastElements[(i - k - 1) / 2] = curr;
            }
            curr = (a * curr + b) % c;
        }

        // Compute XOR
        for (long long i = 0; i < numWindows / 2; i++) {
            result ^= (firstElements[i] ^ lastElements[i]);
        }
    } else {
        // Odd number of windows
        long long curr = x;
        vector<long long> firstWindow(k);
        for (long long i = 0; i < k; i++) {
            firstWindow[i] = curr;
            curr = (a * curr + b) % c;
        }

        long long firstWindowXor = 0;
        for (long long i = 0; i < k; i++) {
            firstWindowXor ^= firstWindow[i];
        }
        result = firstWindowXor;

        // Generate first elements of pairs (windows 2, 4, ...)
        vector<long long> firstElements((numWindows - 1) / 2);
        vector<long long> lastElements((numWindows - 1) / 2);
        curr = x;
        for (long long i = 1; i <= n; i++) {
            if (i > 1 && i <= numWindows && (i - 1) % 2 == 1) {
                firstElements[(i - 2) / 2] = curr;
            }
            curr = (a * curr + b) % c;
        }

        // Generate last elements of pairs (windows 3, 5, ...)
        curr = x;
        for (long long i = 1; i <= n; i++) {
            if (i > k && (i - k - 1) % 2 == 1) {
                lastElements[(i - k - 1) / 2] = curr;
            }
            curr = (a * curr + b) % c;
        }

        // Compute XOR
        for (long long i = 0; i < (numWindows - 1) / 2; i++) {
            result ^= (firstElements[i] ^ lastElements[i]);
        }
    }

    cout << result << endl;
    return 0;
}