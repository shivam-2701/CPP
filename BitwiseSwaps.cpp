#include<bits/stdc++.h>
using namespace std;
#define ll long long
void addEdge(int v,int w,vector<vector<int> >&adj)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
bool isReachable(int s,int d,vector<vector<int> >&adj)
{
    // Base case
    if(s == d)
        return true;
 
    int n= (int)adj.size();
     
    // Mark all the vertices as not visited
    vector<bool> visited(n,false);
 
    // Create a queue for BFS
    queue<int> q;
 
    // Mark the current node as visited and enqueue it
    visited[s]= true;
    q.push(s);
 
    while(!q.empty())
    {
        // Dequeue a vertex from queue and print it
        s=q.front();
        q.pop();
 
        // Get all adjacent vertices of the dequeued vertex s
        // If a adjacent has not been visited, then mark it
        // visited  and enqueue it       
        for(auto x:adj[s])
        {
 
            // If this adjacent node is the destination node,
            // then return true
            if(x == d)
                return true;
 
            // Else, continue to do BFS           
            if(!visited[x])
            {
                visited[x] = true;
                q.push(x);
            }
        }
    }
 
 // If BFS is complete without visiting d
    return false;
}
bool solve(vector<ll>& arr,vector<ll> & crt,int n){
vector<vector<int>>edges(n);

for(int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        if(arr[i]&arr[j]){
            addEdge(i,j,edges);
        }
    }
}

for(int i=0;i<n;i++){
    int idx=lower_bound(crt.begin(),crt.end(),arr[i])-crt.begin();
    if(i!=idx and !isReachable(i,idx,edges)){
        // cout<<i<<" "<<idx<<endl;
        return false;
    }

}
return true;



}


int main(){
int t;
cin >> t;
while(t--){
int n;
cin >> n;
vector<ll> arr(n,-1),crt(n,-1);
for(int i=0;i<n;i++){
    cin>>arr[i];
    crt[i] = arr[i];
}
sort(crt.begin(),crt.end());
bool ans=solve(arr,crt,n);
if(ans){
    cout<<"YES"<<endl;
}else{
    cout<<"NO"<<endl;
}


}


}