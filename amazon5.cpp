#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n = 3;
    vector<int>nums = {2,2,2};
    vector<int>prefix(n,0);
    prefix[0] = nums[0];
    for(int i=1;i<n;i++){
        prefix[i] = min(prefix[i-1],nums[i]);
    }
    int cnt =0;
    for(int i=0;i<n;i++){
        if(nums[i] - prefix[i] == 0){
            cnt++;
        }
    }
    for(int i=0;i<n;i++){
        cout<<prefix[i]<<" ";
    }
    cout<<endl;
    cout<<cnt<<endl;
    return 0;
} 