#include<iostream>
#include<bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;
const int MAX_N = 40000;

vector<int> generatePalindromes() {
    vector<int> P;
    for (int i = 1; i <= MAX_N; i++) {
        string s = to_string(i);
        string rev = s;
        reverse(rev.begin(), rev.end());
        if (s == rev) P.push_back(i);
    }
    return P;
}


int main () {
    vector<int>pali = generatePalindromes();
    long long t;
    cin>>t;

    vector<vector<int>>dp(40004, vector<int>(504,-1));
    while(t--){
        long long n;
        cin>>n;

        for(int ind=0;ind<pali.size();ind++){
            dp[ind][0] = 1;
        }

        for(int ind=0;ind<pali.size();ind++){
            for(int tar=1;tar<=n;tar++){
                int not_pick = 0; if(ind>0) not_pick = dp[ind-1][tar];
                int pick = 0;
                if(tar >= pali[ind]){
                    pick = dp[ind][tar-pali[ind]];
                }
                dp[ind][tar] = (not_pick + pick)%MOD;
            }
        }
        cout<<dp[pali.size()-1][n]<<endl;
    }
}