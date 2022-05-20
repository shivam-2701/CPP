#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    ll arr[n];
	    ll copy[n];
	    for(int i=0;i<n;i++){
	        cin>>arr[i];
	        copy[i]=arr[i];
	    }
	    sort(copy,copy+n);
	    int count=0;
	    bool isPseudo=true;
	    for(int i=0;i<n-1;i++){
	        if(arr[i]!=copy[i]){
	            if(arr[i]==copy[i+1] and copy[i]==arr[i+1]){
	                i++;
	                count++;
	            }else{
	                isPseudo=false;
	                break;
	            }
	        }
	    }
	    if(isPseudo==true and count<=1){
	        cout<<"Yes"<<endl;
	    }else{
	        cout<<"No"<<endl;
	    }
	}
	return 0;
}
