#include<bits/stdc++.h>
#include<iostream>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>freq(101,0);
        vector<int>arr(101,0);
        vector<int>ans;
        ans.push_back(1);
        freq[0]++;
        arr[1]=1;
        // for(int i=2;i<=n;i++){
        //     for(int j=1;j<=100;j++){
        //         if(freq[j%i] == 0 && arr[j]==0){
        //             ans.push_back(j);
        //             freq[j%i]++;
        //             arr[j]=1;
        //             break;
        //         }
        //     }
        // }
                for (int i = 2; i <= n; i++) {
            bool found = false;
            for (int j = 1; j <= 100; j++) { 
                if (freq[j % i] == 0 && arr[j] == 0 && j>ans[ans.size()-1]) {
                    ans.push_back(j);       
                    freq[j % i]++;          
                    arr[j] = 1;             
                    found = true;
                    break;
                }
            }
                }
        // sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }
}