#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i=0; i<n; i++) {
        cin>>arr[i];
    } 
    unordered_map<long long,long long>mpp;

    long long l=0;
    long long cnt =0;

    for(long long r=0;r<n;r++){
        while(mpp.count(arr[r])){
            mpp[arr[l]]--;
            l++;
            if(mpp[arr[l-1]] == 0) {
                mpp.erase(arr[l-1]);
            }
        }
        mpp[arr[r]]++;
        cnt += (r - l + 1);
    }
    cout<<cnt<<endl;
    return 0;
}