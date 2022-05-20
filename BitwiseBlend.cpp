#include<bits/stdc++.h>
using namespace std;
#define ll long long 

void solve(ll *arr,int n){

    bool isPossible=false;
    for(int i=0;i<n;i++){
        if(arr[i]&1){
            isPossible=true;
        }
    }
    if(!isPossible){
        cout<<-1<<endl;
        return;
    }
   int op1=0;
   int op2=0;
    //first term is even
    for(int i=0;i<n;i++){
        if( ( (i&1)==1 && (arr[i]&1)==0) || ( (i&1)==0 && (arr[i]&1)==1) ){
            op1++;
        }
    }
    //first term is odd
    for(int i=0;i<n;i++){
       if( ( (i&1)==1 && (arr[i]&1)==1) || ( (i&1)==0 && (arr[i]&1)==0) ){
            op2++;
        }
    }
    // cout<<op1<<" "<<op2<<endl;
    if(op1<op2){
        int last_odd;
        for(int i=0;i<n;i++){
            if(arr[i]&1){
                last_odd = i;
            }
        }
        vector<pair<int,int>>oprtion;
        if(arr[0]&1){
            arr[0]=arr[0]^arr[last_odd];
            oprtion.push_back(make_pair(1,last_odd+1));
        }
        if( !(arr[1]&1)){
            arr[1]=arr[1]^arr[last_odd];
            oprtion.push_back(make_pair(2,last_odd+1));
        }
        last_odd=1;
        for(int i=2;i<n;i++){
            if( ( (i&1)==1 && (arr[i]&1)==0) || ( (i&1)==0 && (arr[i]&1)==1) ){
            arr[i]=arr[i+1]^arr[last_odd];
            oprtion.push_back(make_pair(i+1,last_odd+1));
            }
        }
        cout<<oprtion.size()<<endl;
        for(int i=0;i<oprtion.size();i++){
            cout<<oprtion[i].first<<" "<<oprtion[i].second<<endl;
        }
    }else{
        int last_odd;
        for(int i=0;i<n;i++){
            if(arr[i]&1){
                last_odd = i;
            }
        }
        vector<pair<int,int>>oprtion;

        if( (arr[0]&1)==0){
            arr[0]=arr[0]^arr[last_odd];
            oprtion.push_back(make_pair(0+1,last_odd+1));
        }
        if(arr[1]&1){
            arr[1]=arr[1]^arr[last_odd];
            oprtion.push_back(make_pair(2,last_odd+1));
        }
        last_odd=0;
        for(int i=2;i<n;i++){
            if( ( (i&1)==1 && (arr[i]&1)==1) || ( (i&1)==0 && (arr[i]&1)==0) ){
            arr[i]=arr[i+1]^arr[last_odd];
            oprtion.push_back(make_pair(i+1,last_odd+1));
            }
        }
        cout<<oprtion.size()<<endl;
        for(int i=0;i<oprtion.size();i++){
            cout<<oprtion[i].first<<" "<<oprtion[i].second<<endl;
        }
    }
    

}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        solve(arr,n);
    }

    
    
}