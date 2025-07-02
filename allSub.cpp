#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void f(int ind,int sum,int n,vector<int>&nums,vector<int>&sums) {
    if(ind == n-1){
        sums.push_back(sum + nums[ind]);
        sums.push_back(sum);
        return ;
    }
    f(ind+1,sum + nums[ind],n,nums,sums);
    f(ind+1,sum,n,nums,sums);

}

int main() {
    vector<int>nums = {1, 2, 3, 4, 5};
    int n = nums.size();
    vector<int>sums;
    f(0,0,n,nums,sums);
    for(auto x : sums) {
        cout << x << " ";
    }
}