#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void f(int ind,int t,int n, vector<int>&nums, vector<int>&ds, vector<vector<int>>&ans) {
    if(t == 0){
        ans.push_back(ds);
        return;
    }   
    if(ind == n || nums[ind] > t) 
        return; 
    for(int i=ind;i<n;i++){
        if(nums[i] > t)break;
        if(i > ind && nums[i] == nums[i-1]) continue; 
        ds.push_back(nums[i]);
        f(i+1, t - nums[i], n, nums, ds, ans);
        ds.pop_back(); 
    } 
}

int main() {
    vector<int> nums = {1,1,1,2,2,3,3,4,5};
    int target = 5;
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    int n = nums.size();
    vector<int>ds;
    f(0, target, n , nums, ds, ans);
    for(auto x : ans) {
        cout << "[";
        for(auto y : x) {
            cout << y << " ";
        }
        cout << "] ";
    }
}