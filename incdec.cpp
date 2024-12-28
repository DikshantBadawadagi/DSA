#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
   long long y,k,n;
   cin>>y>>k>>n;

if(n-y == 0)cout<<-1;
else{
   for(long long i = 1;i<=n-y;i++){
    if((i+y)%k==0){
        cout<<i<<" ";
    }
    // if(k*i + y <= n){
    //     cout<<i<<" ";
    // }
    else{
        break;
    }
   }
   }
   cout<<endl;
    
}