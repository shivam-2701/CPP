#include<bits/stdc++.h>
using namespace std;
#define ll long long
int lis(vector<int> & arr) {
  vector<int> seq;
  seq.push_back(arr[0]);
  for(int i=1;i<arr.size();i++){
      if(arr[i]>=seq.back()){
          seq.push_back(arr[i]);
      }else{
          int idx=lower_bound(seq.begin(),seq.end(),arr[i])-seq.begin();
          seq[idx]=arr[i];
      }
  }
//   for(int i=0;i<seq.size();i++){
//       cout<<seq[i]<<" ";
//   }
//   cout<<endl;
  return seq.size();
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> arr1;
        vector<int> arr2;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            arr1.push_back(temp);
        }
         for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            arr2.push_back(temp);
        }
        
        vector<int> v(n+m,0);
        // cout<<arr1.size()<<" "<<arr2.size()<<" "<<v.size()<<endl;
        int i=0,j=0,l=0;
        while(i<n and j<m){
            if(arr1[i]<=arr2[j]){
                v[l]=arr1[i];
                i++;
                l++;
            }else{
                v[l]=arr2[j];
                j++;
                l++;
            }
            
            
        }
        while(i<n){
            v[l]=arr1[i];
            i++;
            l++;
        }
        while(j<m){
            v[l]=arr2[j];
            j++;
            l++;
        }
        int ans=lis(v);
        cout<<ans<<endl;
        for(int i=0; i < n+m; i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
        cout<<lis(arr1)+lis(arr2)<<endl;
        
        
    }
    
    
}
