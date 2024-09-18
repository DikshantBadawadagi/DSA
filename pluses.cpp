#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int smallest(int x, int y, int z)
{
    int c = 0;
    while (x && y && z) {
        x--;
        y--;
        z--;
        c++;
    }
    return c;
}
int main() {
    long long t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        for(int i=0;i<5;i++){
            if(min({a,b,c}) == a){
                a++;
            }
            else if(min({a,b,c}) == b){
                b++;
            }
            else{
                c++;
            }
        }
        cout<<a*b*c<<endl;
    }
}