#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        int l,r,L,R;
        cin>>l>>r>>L>>R;
        if((l<L && r > R) || (L<l && R>r)){
            cout<<(abs(max(l,L) - min(r,R)) + 2)<<endl;
        }
        else if((l<L && r<R) || (L<l && R<r)){
            if(max(l,L) > min(r,R)){
                cout<<1<<endl;
            }
            else if(max(l,L) < min(r,R)){
                cout<<abs(min(r,R) - max(l,L) + 2)<<endl;
            }
             else if(max(l,L) == min(r,R)){
                cout<<2<<endl;
            }
        }
        else if ((l>L && r>R) || (L>l && R>r)){
            if(min(r,R) > max(l,L))
              {cout<<abs(max(l,L) - min(r,R)) + 2<<endl;}
            
            else if(min(r,R) < max(l,L)){
                cout<<1<<endl;
            }
            else if(max(l,L) == min(r,R)){
                cout<<2<<endl;
            }
           
        }
        else if(l<L && r == R || L<l && r == R){
            cout<<abs(max(l,L) - R) + 1<<endl;
        }
        else if(r<R && l == L || R<r && l == L){
            cout<<abs(max(r,R) - L) + 1<<endl;
        }
        else if(l==L && r==R){
            cout<<abs(R-L)<<endl;
        }


    }
}