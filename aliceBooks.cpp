#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
       long long t,n;
    cin >> t;

    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;
        if(k>=n){
           cout<<("no")<<endl;
        }
        else if(n-(n/m + (n%m!=0))<=k){
            cout<<("no")<<endl;
        }
        else{
            cout<<("yes")<<endl;
        }
    }
}