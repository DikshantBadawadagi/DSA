#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int merge(vector<int>&nums,int l,int mid,int r){
    int left = l, right = mid + 1;
    int cnt = 0;
    while(left <= mid && right <= r){
        if(nums[left] > nums[right]){
            cnt += mid - left + 1;
            right++;
        }else{
            left++;
        }
    }
    // Merge the two halves
    vector<int>temp;
    left = l, right = mid + 1;
    while(left <= mid && right <= r){
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }else{
            temp.push_back(nums[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(nums[left]);
        left++;
    }
    while(right <= r){
        temp.push_back(nums[right]);
        right++;
    }
    for(int i=l;i<=r;i++){
        nums[i] = temp[i-l];
    }
    return cnt;
}

int mergesort(int l,int r,vector<int>&nums){
    int mid = (l+r)/2;
    int cnt = 0;
    if(l >= r) return 0; // Base case: no elements to sort
    cnt+=mergesort(l, mid, nums);
    cnt+=mergesort(mid+1, r, nums);
    cnt += merge(nums, l, mid, r);
    return cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int n = 5;
    vector<int>nums = {5,3,2,4,1};

    cout<< mergesort(0,n-1,nums)<<endl;
    return 0;
}