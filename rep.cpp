#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    string s;
    cin>>s;

    int n;
    n = s.length();

    char curr = s[0];
    int ans =0;
    int cnt = 1;

    for(int i=1;i<n;i++){
        if(s[i] == curr){
            cnt++;
        }
        else{
            curr = s[i];
            ans = max(ans,cnt);
            cnt = 1;
        }
    }
    ans = max(ans,cnt);
    cout<<ans;


}