# include <iostream> 
using namespace std;

int main(){
    long long t;
    cin>>t;
    while(t--){
        long long n,a[20];
    cin>>n;
    for(long long i=0;i<n;i++){
      cin>>a[i];
    }
        int flag=1;
    for(long long i=0;i<n-1;i++){
      if(a[i]>a[i+1]){
        if(i==0 || i==1 || i==3 || i==7 || i==15 ){
            flag=1;
            continue;
        }
        flag=0;
        break;
      }
    }
    if(flag==1){
        cout<<"Yes" <<endl;
    }else{
        cout<<"No" << endl;
    }
    }
}