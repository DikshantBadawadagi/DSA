#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;

    vector<int>nums(n);
    for(int i=0;i<n;i++){
        nums[i] = 3*n + i;
    }
    for(int i=0;i<n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}