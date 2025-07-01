#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>freq(1e6+1,0);
    while(n--){
        int a;
        cin>>a;
        freq[a]++;
    }

    for(int i=1e6;i>=0;i--){
        int cnt=0;
        for(int j=i;j<=1e6;j+=i){
            cnt += freq[j];
        }
        if(cnt >= 2) {
            cout << i << "\n";
           return 0;
        }
    }
}
