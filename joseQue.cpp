#include<bits/stdc++.h>
using namespace std;

long long f(long long n,long long k)
{
    if(n==1) return 1;
    if(k<=(n+1)/2) 
    {
        if(2*k>n) return (2*k)%n;
        else return 2*k;
    }
    long long temp=f(n/2,k-(n+1)/2);
    if(n%2==1) return 2*temp+1;
    return 2*temp-1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long q;
    cin>>q;
    for(int i=0;i<q;i++)
    {
        long long n,k;
        cin>>n>>k;
        cout<<f(n,k)<<"\n";
    }
}