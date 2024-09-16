#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    
        int x1,x2,x3;
        cin>>x1>>x2>>x3;

        int avg = (x1+x2+x3)/3;
        int mini = INT_MAX;
        mini = min(abs(avg-x1),mini);
        mini = min(abs(avg-x2),mini);
        mini = min(abs(avg-x3),mini);

        if(mini == abs(avg-x1)){ cout<<abs(x3-x1) + abs(x2-x1);
        return 0;}
        if(mini == abs(avg-x2)) {cout<<abs(x3-x2) + abs(x2-x1);
        return 0 ;}
        if(mini == abs(avg-x3)) {cout<<abs(x3-x1) + abs(x2-x3);
        return 0;}


        
    }
