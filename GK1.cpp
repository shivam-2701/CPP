#include<bits/stdc++.h>
#define vpll vector<pair<ll,ll>>
using namespace std;
const int N= 1e5+10;


#define ull         unsigned long long
#define ld          long double
#define ll          long long 
#define Setbit(n)   __builtin_popcccll(n)
#define pb          push_back
#define ff          first
#define ss          second
#define b_s         binary_search
#define l_b         lower_bound
#define u_b         upper_bound
#define sz(x)       (int)(x).size()
#define all(x)      x.begin(), x.end()





int main(){
ios_base::sync_with_stdio(false); 
cin.tie(NULL); 
ll t;
t=1;
ll tt=1;
cin>>t;
while(t--){
  ll n,m,p,q;
cin>>n;

ll ccc=0;
ll k;
ll traverse=0;
ll d22=0;
for(ll i=1;i*i<=n;i++)
{

        k=i;
        if(n%i==0){

             traverse = 0;
     do
     {
         d22 = k % 10;
         traverse = (traverse * 10) + d22;
         k = k / 10;
     } while (k!=0);

     if (i==traverse){

     ccc++;
     }

        double gtre=((1.0)*n)/i;
        ll gtrex=n/i;
        k=gtre;
        if(gtre==gtrex && gtre!=i){

          traverse = 0;
          d22=0;
     do
     {
         d22 = gtrex % 10;
         traverse = (traverse * 10) + d22;
         gtrex = gtrex / 10;
     } while (gtrex!=0);
     if (k==traverse)
     ccc++;
        }
        }
    }
cout<<"Case #"<<tt<<": ";
tt++;
cout<<ccc<<"\n";
}

  return 0;
}