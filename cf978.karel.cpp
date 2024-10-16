#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--){
        long long n,x;
        cin>>n>>x;
        vector<int>vec(n);
        long long sum=0;
        for(int i=0;i<n;i++){
            cin>>vec[i];
            sum+=vec[i];
        }
        cout<<sum/x + sum%x<<endl;

    }
}