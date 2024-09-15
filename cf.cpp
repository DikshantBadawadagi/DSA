#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        vector<int>a(3);
        for(int i=0;i<3;i++) cin>>a[i];
        sort(a.begin(),a.end());
        int f=5;
       while(f>0){
        if(a[2]-a[0] >=f && a[2]-a[0] > 0){
            cout<<(a[0]+5)*a[1]*a[2];
            cout<<"yes";
            return 0;
        }
        if(a[2]-a[0] <f && a[2]-a[0] > 0 ){
           a[0] = a[2];
           f = f -a[2]+a[0];
        }
        if(a[2] - a[1] < f && a[2] - a[1] > 0 ){
            a[1] = a[2];
            f = f - a[2] + a[1];
        }
        a[2]++;
        f--;
       }
       cout<<a[0]<<a[1]<<a[2]<<endl;
       cout<<a[0]*a[1]*a[2]<<endl;
       
    }
}