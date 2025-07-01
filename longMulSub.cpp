#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n = 7;
    vector<int>nums = {1,2,-1,0,5,7,8};
    int pref = nums[0],suff=nums[n-1];
    int ans = INT_MIN;
    for(int i=1;i<n-1;i++){
        pref = pref*nums[i];
        suff = suff*nums[n-i-1];
        ans = max({ans, pref,suff});
        if(pref < 0) pref = 1;
        if(suff < 0) suff = 1;
    }
    cout << ans << endl;
    return 0;
}