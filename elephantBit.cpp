#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    string binary;
    cin>>binary;

        if (binary.find('0') == string::npos) {
        binary.erase(binary.begin());
    } else {
        size_t firstZeroPos = binary.find('0');
        binary.erase(binary.begin() + firstZeroPos);
    }
    cout<<binary<<endl;
}