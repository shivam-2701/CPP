#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        ll arr[n];
        ll finalAnd =(1<<30)-1;
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        for(int i=0;i<n;i++){
            finalAnd&=arr[i];
        }
        ll groups=0;
        ll currAnd= ((ll)1<<31)-1;
        // cout<<finalAnd<<endl;
        for(int i=0;i<n;i++){
            currAnd&=arr[i];
          
            if(currAnd==finalAnd){
                groups++;
                currAnd= ((ll)1<<31)-1;
            }
        }
        
        ll ans = n-groups;
        cout<<ans<<endl;
        
    }

}