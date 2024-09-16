#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--) {
        long long n,x;
        cin>>n>>x;
        vector<long long>v(n);
        for(long long i=0;i<n;i++) {
            cin>>v[i];
        }
        long long count=0;
        for(int i=0;i<n;++i){
            long long sum =0;
            for(int j=0;j<n;++j){
                sum+=v[j];
                if(sum<=x){
                    count++;
                }
                else{
                    sum=0;
                }
            }
        }
        cout<<count<<endl;
       

    }
}