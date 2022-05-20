#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--){
	  int n;
      cin>>n;
      ll r;
      cin>>r;
      ll ans=0;
      vector<ll> cost,cb;
      vector<pair<ll,pair<ll,ll>>>v;
      for(int i=0;i<n;i++){
          ll x;
          cin>>x;
          cost.push_back(x);
      }
      for(int i=0;i<n;i++){
          ll x;
          cin>>x;
          cb.push_back(x);
      }
      for(int i=0;i<n;i++){
          v.push_back(make_pair(cost[i]-cb[i],make_pair(cost[i],cb[i])));
      }
      sort(v.begin(),v.end());
      for(int i=0;i<n;i++){
          while(r>=v[i].second.first){
              int curr=r/v[i].second.first;
            
              ans+=curr;
            
              r-=(curr*v[i].second.first);
            
              r+=(curr*v[i].second.second);
            
          }
      }
      cout<<ans<<endl;
      
	}
	return 0;
}
