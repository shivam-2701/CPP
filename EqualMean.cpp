#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getPairsCount(ll arr[], int n, ll sum)
{
    unordered_map<ll, ll> m;
    ll count = 0;
    for (int i = 0; i < n; i++) {
        if (m.find(sum - arr[i]) != m.end()) {
            count += m[sum - arr[i]];
        }
        m[arr[i]]++;
    }
    return count;
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
        sort(arr,arr+n);
        ll sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        double mean =(double)sum/n;
        double num=mean*2;
        if(floor(num)!=num){
            cout<<0<<endl;
        }else{
        ll ans=getPairsCount(arr,n,num);
        cout<<ans<<endl;
            
        }

    }


}