#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n,k;
        cin >> n >> k;
        vector<long long> nums(n);
        long long maxi = LONG_LONG_MIN,mini = LONG_LONG_MAX,sum=0,cnt=0;
        for (long long i =0; i <n;i++) {
            cin >> nums[i];
            sum += nums[i];
            maxi = max(maxi, nums[i]);
            mini = min(mini, nums[i]);
        }

        for(auto i: nums){
            if( i == maxi){
                cnt++;
            }
        }

        if(maxi - mini - 1 > k || (maxi -mini == k+1 && cnt > 1)){
            cout<<"Jerry"<<endl;
        }
        else{
            if((sum%2 != 0))
            cout<<"Tom"<<endl;
            else{
                cout<<"Jerry"<<endl;
            }
        }

    }

}