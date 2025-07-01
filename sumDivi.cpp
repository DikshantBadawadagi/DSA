#include<bits/stdc++.h>
using namespace std;

#define ll long long int

const int MOD=1000000007;
long long int inverse(long long int i){
    if(i==1) return 1;
    return (MOD - ((MOD/i)*inverse(MOD%i))%MOD+MOD)%MOD;
}
ll POW(ll a,ll b)
{
    if(b==0) return 1;
    if(b==1) return a%MOD;
    ll temp=POW(a,b/2);
    if(b%2==0) return (temp*temp)%MOD;
    else return (((temp*temp)%MOD)*a)%MOD;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    cin>>n;
/**
 * @brief      Main function
 *
 * @details    This program takes a long long integer n as input and outputs
 *             the sum of all divisors of n as output.
 *
 * @param      n     The input number.
 *
 * @return     0 if the program runs successfully.
 */

/*************  ✨ Windsurf Command ⭐  *************/
/*******  404b4d30-5d7d-48ec-af05-78d871d9ee3e  *******/
    ll ans=0;
    for(ll i=1;i*i<=n;i++)
    {
        ans+=((n/i)*i)%MOD;
        ans%=MOD;
    }
    ll l=(ll)sqrt(n);
    for(ll i=sqrt(n);i>=1;i--)
    {
        ll r=n/i;
        ll sum=0;
        sum+=((((r%MOD)*((r+1)%MOD))%MOD)*inverse(2))%MOD;
        sum%=MOD;
        sum-=((((l%MOD)*((l+1)%MOD))%MOD)*inverse(2))%MOD;
        sum=(sum+MOD)%MOD;
        sum=(sum*i)%MOD;
        l=r;
        ans=(ans+sum)%MOD;
        //cout<<sum<<" ";
    }
    cout<<ans;
}
