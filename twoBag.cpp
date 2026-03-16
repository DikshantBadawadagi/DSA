#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long y,k,n;
    cin >> y >> k >> n;

    long long start = ((y + k - 1) / k) * k; // First multiple of k greater than y
    vector<long long> results;
    for (long long i = start; i <= n; i += k) {
        if(i - y > 0)
        results.push_back(i - y);
    }
    if (results.size() == 0) {
        cout << -1 << endl;
    } else {
        for (size_t i = 0; i < results.size(); i++) {
            cout << results[i];
            if (i != results.size() - 1) {
                cout << " ";
            }
        }
        cout << endl;
    }
}
