#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    ll m;
	    cin>>n>>m;
	    ll arr[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	    }
	    sort(arr,arr+n);
	    ll maxl=arr[n-1];
        // cout<<maxl<<endl;
	    ll maxm=INT_MIN;
	    for(int i=0;i<n;i++){
	        ll mod = (maxl -arr[i])%m;
            ll temp =0;
            if(arr[i]!=maxl)
             temp = m - abs((arr[i]-maxl)%m);
             
            maxm =max(maxm, arr[i] + maxl + mod);
            maxm =max(maxm, arr[i] + maxl + temp);
            // cout<<mod<<" "<<temp<<" "<<maxm<<endl;
	       
	    }
	    cout<<maxm<<endl;
	}
	return 0;
}
