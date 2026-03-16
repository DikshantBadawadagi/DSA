#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());


    int l = 0;
    int r = (n + 1) / 2; 
    int pairs = 0;

    while (l < n / 2 && r < n) {
        if (a[l] * 2 <= a[r]) {
            pairs++;
            l++;
            r++;
        } else {
            r++;
        }
    }

    cout << n - pairs << endl;

    return 0;
}