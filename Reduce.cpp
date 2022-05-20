#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        if(n==1){
            cout<<0<<endl;
            continue;
        }
        
        ll srt=sqrt(n);
        if(srt*srt==n){
            cout<<1<<endl;
            continue;
        }
        if(n%2==1){
            cout<<1<<endl;
        }else{
            int count=0;
            ll n1=n;
            while(n%2==0){
                n=n>>1;
                count++;
            }
            if(count%2==0){
                if(n==1){
                    cout<<1<<endl;
                }else{
                    cout<<2<<endl;
                }
            }else{
                cout<<-1<<endl;
            }


        }
    }
}