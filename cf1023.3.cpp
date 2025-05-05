#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;

    while (t--) {
        long long n,k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<long long> nums(n);
        for (long long i =0; i <n;i++) {
            cin >> nums[i];
        }
        long long i=0,cnt=0;
        for(auto c : s){
            if(c == '0'){
                cnt++;
                nums[i] == int(-1e7);
            }
            i++;
        }

        long long sum=0,maxi=0;

        for(int i =0; i <n;i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(maxi >k){
            cout<<"NO"<<endl;
            continue;
        }

        for(auto c : s){
            if(c == '0'){
                cnt++;
                nums[i] == int(1e7);
            }
            i++;
        }

        for(int i =0; i <n;i++) {
            sum += nums[i];
            maxi = max(maxi, sum);
            if(sum < 0){
                sum = 0;
            }
        }
        if(maxi < k){
            cout<<"NO"<<endl;
            continue;
        }

        if(cnt ==0 && maxi !=k){
            cout<<"NO"<<endl;
            continue;
        }

        cout<<"YES"<<endl;
        bool flag = false;
        for(long long i=0;i<n;i++){
            if(s[i] == '0' && !flag){
                nums[i] = k;
                flag = true;
            }
            else if(s[i] == '0'){
                nums[i] = 0;
            }
        }
        for(long long i=0;i<n;i++){
            cout<<nums[i]<<" ";
        }
        cout<<endl;

    }
}