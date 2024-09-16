// Online C compiler to run C program online
#include <stdio.h>

int main(){
unsigned long long m,k,a1,ak,t;
scanf("%llu",&t);
for(int i=0 ; i<t ; i++){
    scanf("%llu",&m);
    scanf("%llu",&k);
    scanf("%llu",&a1);
    scanf("%llu",&ak);
    int count=0,count1=0,countf=0,countf1=0;
    //printf("%llu %llu % llu % llu",m,k,a1,ak);
while(m!=0){
    if(k<=m && count<ak){
        m=m-k;
        count++;
        continue;
    }
    else if (count1<a1){
        m=m-1;
        count1++;
        continue;
    }
     if(count1>=k){
            countf++;
            count1=count1-k;
        }
    //printf("h");
    if(count==ak && count1==a1){
        if(m>=k){
             m=m-k;
            countf++;
            //printf("HELLO\n");
            continue;
        }
        else{
            m=m-1;
            countf1++;
            continue;
        }
    }
}
printf("%d\n",countf+countf1);

    
}
    return 0;
}