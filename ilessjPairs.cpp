#include<bits/stdc++.h>
using namespace std;

int main() {
    vector<int> a = {5, 4, 3, 2, 1};
    int n = 5;
    vector<int> b(a.begin() + n/2,a.end());
    a.erase(a.begin() + n/2,a.end());
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    
   
    
}