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
        sort(nums.begin(),nums.end());
        int cnt=0;

                if (n == 1) {
            cout << 0 << endl;  
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    cnt++;
                    i++;  
                }
            }
            cout << cnt << endl;  
        }
    }
}