#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        long long k;
        cin>>k;
        vector<int>grid(k);
        for(int i=0;i<k;i++){
            cin>>grid[i];
        }
        int l=0;
        int h=k-1;
        int ans=k-2;
        sort(grid.begin(),grid.end());
        while(l<h){
            int mul = grid[l]*grid[h];
            if( mul == ans){
                cout<<grid[l]<<" "<<grid[h]<<endl;
                break;
            }
            if(mul > ans)h--;
            else l++;
        }



        
    }
}