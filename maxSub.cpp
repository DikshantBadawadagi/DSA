#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum=arr[0];
    long long max_sum=arr[0];
    for(int i = 1; i < n; i++) {
        if(sum < 0) {
            sum = 0;
        }
        sum += arr[i];
        max_sum = max(max_sum, sum);
    }
    cout << max_sum << endl;
    return 0;
}