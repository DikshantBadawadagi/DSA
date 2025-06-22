#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n,x;
    cin >> n >> x;
    vector<long long> nums(n);
    for(long long i = 0; i < n; i++) {
        cin >> nums[i];
    }

    map<long long, long long> mpp;
    mpp[0] = 1;
    long long cnt =0,sum=0;

    for(long long i=0;i<n;i++){
        sum += nums[i];
        if(mpp.find(sum - x) != mpp.end()){
            cnt += mpp[sum - x];
        }
        mpp[sum]++;
    }
    cout << cnt << endl;
    return 0;
}