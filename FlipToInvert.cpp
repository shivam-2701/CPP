#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int zeroes[n]={0};
        int ones[n]={0};
        int one=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                ones[i]=one;

            }else{
                one++;
            }
        }
        int zero=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]=='1'){
                zeroes[i]=zero;
                
            }else{
                zero++;
            }
        }
        int pairs=0;
        for(int i=0;i<n;i++){
            pairs+=zeroes[i];
        }
        int pair2=pairs;
        int k1=k;
        for(int i=0;i<n and k>0;i++){

            if(s[i]=='1'){
                pairs-=zeroes[i];
                k--;
            }
        }
        k=k1;
        for(int i=n;i>=0 and k>0;i--){
            if(s[i]=='0'){
                pair2-=ones[i];
                k--;
            }
        }
        cout<<min(pairs,pair2)<<endl;



    }


}