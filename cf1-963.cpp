#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
// #include<bits/stdc++.h>

int main() {
    long long t;
    cin>> t;
    while (t--) {
        int n;
        cin>> n;
        string s;
        cin>>s;
        int a=0,b=0,c=0,d=0;

        for (size_t i = 0; i < s.size(); ++i) {
        if(s[i] == 'A'){
            a++;
        }
        else if(s[i] == 'B'){
            b++;
        }
        else if(s[i] == 'C'){
            c++;
        }
        else if(s[i] == 'D'){
            d++;
        }
        else {
            continue;
        }
    }
    cout<<min(n,a) + min(n,b) + min(n,c) + min(n,d)<<endl;
    }
    return 0;
}