#include<bits/stdc++.h>
using namespace std;

int main() {
    string str = "abcabcbb";
    vector<int> mpp(256,-1);
    int n = str.size();
    int left=0,right=0,len=0;
    while(right<n){
        if(mpp[str[right] !=-1]){
            left = max(left,mpp[str[right]]+1);
        }
    
            mpp[str[right]] = right;
            len = max(len,right-left+1);
        
        right++;
    }
    cout<<"Length :"<<len;

}