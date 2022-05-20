#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
      string s;
      cin>>s;
      int cnt0=0,cnt1=0;
      for(int i=0;i<n;i++){
          if(s[i]=='0'){
              cnt0++;
          }else{
              cnt1++;
          }
      }
      bool isPossible=false;
      
      if(n%2==1){
          if(cnt1%2==0 || cnt0%2==0){
             isPossible=true;
          }else{
              isPossible=false;
          }
          
      }else{
          
          if(cnt1==cnt0){
              isPossible=true;
          }else if(cnt1==0 || cnt0==0){
              isPossible=true;
          }else{
              isPossible=false;
          }
          
      }
      if(isPossible){
          cout<<"YES"<<endl;
      }else{
          cout<<"NO"<<endl;
      }
      
        
    }
    
    
}
