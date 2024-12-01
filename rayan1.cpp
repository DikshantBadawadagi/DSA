#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0), cin.tie(0);

    long long t;
    cin>>t;
    while(t--){
        long long a,b;
        cin>>a>>b;
long long gc =  __gcd(a, b);
if (gc == 1){
    long long ans = a*b;
    cout<<ans<<endl;
}
else{
        long long lcm = (a /gc) * b;
        if(lcm>= min(a,b)){
            cout<<lcm<<endl;
        }
        else{
            int k=1;
            while(lcm<min(a,b)){
                lcm = lcm*k;
                k++;
            }
            cout<<lcm<<endl;
        }
        }
    }
    
    }