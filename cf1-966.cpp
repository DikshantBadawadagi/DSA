#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    long long t;
    cin>>t;
     while(t--){
        long long num;
        cin >> num;
        string numstr = to_string(num);

        if(numstr.size() < 3) {
            cout << "NO" << endl;
            continue;
        }

        string p1 = numstr.substr(0, 2);
        string p2 = numstr.substr(2);

        long long part1 = stoll(p1);  
        long long part2 = p2.empty() ? 0 : stoll(p2);

        if(num > 100 && part1 == 10 && numstr[2] != '0' && part2 >= 2){
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}