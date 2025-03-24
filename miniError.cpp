#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<int> err(n);
    for(int i = 0; i < n; i++) err[i] = abs(a[i] - b[i]);

    int k = k1 + k2;
    priority_queue<int> pq;
    for(int i = 0; i < n; i++) pq.push(err[i]);

    while(k > 0) {
        int top = pq.top();
        pq.pop();
        if(top > 0) top--;  // Reduce largest error
        else top++;         // Flip the sign to minimize error
        pq.push(top);
        k--;
    }

    long long error = 0;
    while(!pq.empty()) {
        error += (long long)pq.top() * pq.top();
        pq.pop();
    }

    cout << error << endl;
}
