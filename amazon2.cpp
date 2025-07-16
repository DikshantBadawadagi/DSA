#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int>nums = {3,5,2,3};
    int n = nums.size();
    int diff = 0;

    for(int i=1;i<n;i++) {
        if(nums[i] >= nums[i-1]){
            continue;
        }
        else{
            diff += nums[i-1] - nums[i];
        }
    }  

    cout<<diff<<endl;
}