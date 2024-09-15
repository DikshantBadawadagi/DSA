#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool isSubsequence(string X, string Y, int m, int n)
{
    int j = 0; 

    for (int i = 0; i < m && j < n; i++)
    {
        if (X[i] == Y[j])
        {
            j++;
        }
    }

    return (j == n);
}
int main(){
    long long t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        string t;
        cin>>t;
        int count=0;
        int j=0;
        int n = t.size();
        int m = s.size();
        for(int i=0;i<m;i++){
            for(int j=i%m;j<n;j++){
            if(s[i] == '?'){
                s[i] = t[j];
            }
          }
        }



        if(isSubsequence(s,t,m,n)){
            cout<<"YES"<<endl;
            cout<<s<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}