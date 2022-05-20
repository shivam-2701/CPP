#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        ll k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        std::map<ll,ll> m;
        int count=0;
        for(int i=n-1; i>=0; i--){
            ll curr = (k-arr[i])^arr[i];
            // cout<<curr<<"i"<<endl;
            count+=m[curr];
            m[arr[i]]++;
        }
        cout<<count<<endl;

    }
}