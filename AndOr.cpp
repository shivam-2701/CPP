#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void fill(int* arrA,int *arrB,int n){
    
    int temp=n;
    int idx=0;
    int check[32]={0};
    while(temp){
        
        if(temp&1){
            check[idx]=1;
        }
        arrB[idx]=(temp&1);
        arrA[idx]=(temp&1);
        temp=temp>>1;
        idx++;
    }
    for(int i=0;i<31;i++){
        if(check[i]==0){
            if(i%2==0){
                arrA[i]=0;
                arrB[i]=1;
            }else{
                arrA[i]=1;
                arrB[i]=0;
            }
        }
    }
    
}
ll buildNum(int *arrA){
    
    int curr=1;
    int num=0;
    for(int i=0;i<32;i++){
        num+=(arrA[i]*curr);
        curr*=2;
    }
    return num;
    
}



int main(){
    
    for(int i=0;i<=1 ;i++){
        int n=i;
        
        int arrA[32]={0};
        int arrB[32]={0};
        
        fill(arrA,arrB,n);
        
        int a=buildNum(arrA);
        int b=buildNum(arrB);
        int c=0;
        int ans=(a|b);
        ans&=(b|c);
        ans&=(c|a);
        if(ans!=n){
            cout<<n<<" "<<ans<<endl; 
        }
        
    }
    
    
}
