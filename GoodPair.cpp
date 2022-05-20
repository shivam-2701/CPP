#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        map<pair<ll,ll>,int> m;
        ll count=0;
        for(int i=0;i<n;i++){
            pair<ll,ll> temp ={b[i],a[i]};
            if(m.find(temp)!=m.end()){
                count+=m[temp];
            }
            pair<ll,ll> curr=make_pair(a[i],b[i]);
            m[curr]++;
        }
        cout<<count<<endl;
        
    }
    
    
}
