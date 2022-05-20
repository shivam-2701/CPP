




#include<bits/stdc++.h>
#define vpll vector<pair<ll,ll>>
using namespace std;
const int N= 1e5+10;


#define ull         unsigned long long
#define ld          long double
#define ll          long long 
#define Setbit(n)   __builtin_popcountll(n)
#define pb          push_back
#define ff          first
#define ss          second
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define sz(x)       (int)(x).size()
#define all(x)      x.begin(), x.end()


#define loop(i,n) for(int i = 0;i < int(n);i++)


ll power(ll x,ll y,ll p)
{
ll res = 1;     // Initialize result
while (y > 0)
{
// If y is odd, multiply x with result
if (y & 1)
res = ((res%p)*(x%p))%p;
// y must be even now
y = y>>1; // y = y/2
x = ((x%p)*(x%p))%p;  // Change x to x^2
}
return res%p;
}



int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
ll t;
t=1;
ll tt=1;
cin>>t;
while(t--){
  ll n,m,p,q;
cin>>n>>m;
ll a[n+2];
loop(i,n)
cin>>a[i];
ll count=0;
ll i=0;
ll c=0;
while(i<n){
    if(a[i]==1){
        // cout<<i<<" ";
        while(a[i]==1 && i<n){
            i++;
            c++;
        }
        count++;
    }
    else i++;
}
// if()
cout<<"Case #"<<tt<<": ";
tt++;
cout<<count<<"\n";
}

  return 0;
}