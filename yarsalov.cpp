#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin>>n;
    vector<int>nums(n);
    long long cnt=0;
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
sort(nums.begin(),nums.end());
    if(n == 1){
        cout<<"YES"<<endl;
        return 0;
    }
    int num;
    cnt++;
    num = nums[0];
    for(int i=1;i<n;i++){
        if(nums[i] == num){
            cnt++;
        }
        else{
            if(cnt>(n+1)/2){
                cout<<"NO"<<endl;
                return 0;
            }
            cnt=1;
            num = nums[i];
        }

    }
if(cnt>(n+1)/2){
    cout<<"NO"<<endl;
}
else cout<<"YES"<<endl;

}