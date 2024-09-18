
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t,k,q;
    int a[100],num[100];
    cin >> t;

    while(t--){
       cin>>k>>q;//5,3
       for(int i=0;i<k;i++){
        cin>>a[i];
       }
       for(int i=0;i<q;i++){
        cin>>num[i];
       }
       for(int i=0;i<q;i++){
        while(a[0]>num[i]){
        for(int j=k;j>0;j--){
       if(num[i]<=a[j]){
         num[i]--; }
         else{
            continue;
         }
       }
       }
       cout<<num[i]<<" ";
       }
       cout<<endl;



    }
    
    
    
    
    }