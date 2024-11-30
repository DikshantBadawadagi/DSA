#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;

    vector<int>pg(7);
    for(int i=0;i<7;i++) cin>>pg[i];
    int t = pg[0];
int i(0);
    while (t < n)
    {
        i++;
        i %= 7;
        t += pg[i];
    }

    cout << i + 1 << endl;

}
