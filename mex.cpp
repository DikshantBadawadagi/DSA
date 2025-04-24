#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,x;
        cin>>n>>x;

        vector<int>ans;

        for(int i=0;i<n;i++){
            if(i !=x)ans.push_back(i);
        }
        ans.push_back(x);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

    }
}