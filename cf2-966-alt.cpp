#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> seats(n);
        vector<int> freq(n+1, 0);

        bool valid = true; 
        if(n == 1){
            cin>>n;
            cout << "YES" << endl;
            continue;
        }

        for(int i = 0; i < n; i++) {
            cin >> seats[i];
            freq[seats[i]] = 1;

            if(i > 0 && i!=n-1) {
                
                if(freq[seats[i] - 1] == 0 && freq[seats[i] + 1] == 0) {
                    valid = false;
                }
            }
        }

        if(valid) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}