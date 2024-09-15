#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>p(k);
        for(int i=0;i<k;i++){
            cin>>p[i];
        }
        sort(p.begin(),p.end(),greater<int>());
        int count =0;
        k=k-1;
        for(int i=k;i>0;i--){
            if(p[i] == 1){
                count++;
            }
            else{
               count =  count + 2*p[i]-1;
            }
        }

        cout<<count<<endl;
      
    }
}