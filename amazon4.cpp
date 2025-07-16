#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isPossible(vector<int>&nums,int maxi,int extra){
    for(auto num : nums){
        extra -= maxi - num;
        if(extra <= 0)return true;
    }
    return false;
}

int main(){
    vector<int>nums = {7,5,1,9,1};
    int extra = 25;
    int n = nums.size();
    int maxi = INT_MIN;
    
    for(int n : nums)maxi = max(maxi,n);

    // for(int i=0;i<n;i++){
    //     extra -= maxi - nums[i];
    //     if(extra == 0){
    //         cout<<maxi<<endl;
    //         return 0;
    //     }
    // }
    // maxi+=extra/n;
    // extra=extra%n;
    // if(extra)maxi++;
    // cout<<maxi<<endl;
    int l = maxi,r=extra;
    int ans = 0;

    while(l <= r){
        int mid = (l+r)/2;
        if(isPossible(nums,mid,extra)){
            r = mid-1;
            ans = mid;
        }
        else{
            l= mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}