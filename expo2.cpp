#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b, ll mod)
{
    if(b==0) return 1;
    if(b==1) return a%mod;
    ll temp=POW(a,b/2,mod);
    if(b%2==0) return (temp*temp)%mod;
    else return (((temp*temp)%mod)*a)%mod;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n,a,b,c;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a>>b>>c;
        ll pw=POW(b,c,MOD-1);
        cout<<POW(a,pw,MOD)<<"\n";
    }
}
