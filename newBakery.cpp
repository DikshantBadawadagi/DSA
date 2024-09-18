#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,a,b;
        cin>>n>>a>>b;
        long long profit=0,p=0;
        for(long long i=1;i<=n;i++){
            p=b-i+1;
            if(p>a){
                profit+=p;
            }
            else{
                profit+=a;
            }
        }
        cout<<profit<<endl;
    }
}
