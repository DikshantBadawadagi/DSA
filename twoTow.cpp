#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
    long long a,b,c,d;
    cin>>a>>b>>c>>d;

    set<long long> st;

    for(int i=a;i<=c;i++){
        st.insert(i);
    }
    for(int i=b;i<=d;i++){
        st.insert(i);
    }
    cout<<st.size()<<endl;
}
    return 0;
}