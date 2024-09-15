#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> seats(n);
        for(int i=0;i<n;i++){
            cin>>seats[i];
        }
        bool valid = true;

        for(int i = 1; i < n; i++) {
            bool flag = false;
            for(int j = 0; j < i; j++) {
                if(seats[j] == seats[i] - 1 || seats[j] == seats[i] + 1) {
                    flag = true;
                    break;
                }
            }
            if(flag == false) {
                valid = false;
                break;
            }
        }

        if(valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}