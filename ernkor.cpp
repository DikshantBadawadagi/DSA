#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long n,m,k;
        cin>>n>>m>>k;

        string s;
        cin>>s;
        vector<int> positions;
        
        int diff = INT_MIN;
          for (int i = 0; i < n; ++i) {
        if (s[i] == 'L') {
            positions.push_back(i);
        }
    }
    
    int max_diff = 0;
    for (int i = 1; i < positions.size(); ++i) {
        max_diff = max(max_diff, positions[i] - positions[i-1]);
    }

    if(max_diff>m){
        if(max_diff<= m+k){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
    else{
        cout<<"YES"<<endl;
    }
    



    }
}