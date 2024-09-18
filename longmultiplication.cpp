#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t,i;
    cin >> t;

    while(t--){
        string  s1,s2,t2;
        cin>>s1>>s2;
        if(s1==s2){ 
            cout<<s1<<endl<<s2<<endl;
            continue;
        }
        if(s1<s2){
            t2=s1;
            s1=s2;
            s2=t2;
        }
        if(s1>s2){
        for(i=0;i<s1.length();i++){
            if(s1[i]==s2[i]){
                continue;
            }
            break;
        }
        long j=i+1;  // swap selectively from j to n-1
        for(i=j;i<s1.length();i++){
            if(s1[i]>s2[i]){
                int temp;
                temp=s1[i];
                s1[i] = s2[i];
                s2[i]=temp;
            }
        }
        cout<<s1<<endl<<s2<<endl;
        }
       
        

    }
}