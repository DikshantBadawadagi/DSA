#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main () {
    int m,s;
    cin>>m>>s;

    if( s == 0 && m!= 1){
        cout<<"-1 -1"<<endl;
        return 0;
    }
    if( s > 9*m){
        cout<<"-1 -1"<<endl;
        return 0;
    }

    string maxi="";

    int sum  =s;
    for(int i=0;i<m;i++){
        if( sum >=9){
            maxi.push_back('9');
            sum -=9;
        }
        else{
            maxi.push_back( char( '0' + sum) );
            sum =0;
        }
    }
    string mini =maxi;
    reverse(mini.begin(), mini.end());
    if( mini[0] == '0'){
        for(int i=1;i<m;i++){
            if( mini[i] != '0'){
                mini[i]--;
                mini[0]='1';
                break;
            }
        }
    }
    cout<<mini<<" ";
    cout<<maxi<<" ";
}