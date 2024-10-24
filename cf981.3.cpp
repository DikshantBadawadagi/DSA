#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>nums(n);
        for(int i=0;i<n;i++){
            cin>>nums[i];
        }
        if(n%2 == 1){
            for(int i=0;i<n-1;i++){
                if(nums[i] == nums[i+1]){
                    if(i == n/2){
                        continue;
                    }
                    else{
                        if((nums[i] != nums[n - i -1]) && (nums[i-1] != nums[n -i -1]) && (nums[i] != nums[n -i -2]) && (nums[i] != nums[n-i]) ){
                            swap(nums[i],nums[n-i-1]);
                        }
                    }
                }
            }
        }
        else{
            for(int i=0;i<n-1;i++){
                if(nums[i] == nums[i+1] || nums[i] == nums[i-1]){
                    if((nums[i] != nums[n - i -1]) && (nums[i-1] != nums[n -i -1]) && (nums[i] != nums[n -i -2]) && (nums[i] != nums[n-i]) ){
                            swap(nums[i],nums[n-i-1]);
                        }
                }
            }
        }
        int cnt =0;
        for(int i=0;i<n-1;i++){
            cout<<nums[i]<<" ";
            if(nums[i] == nums[i+1]){
                cnt++;
            }
        }
        cout<<endl;
        cout<<cnt<<endl;
    }
    
    }