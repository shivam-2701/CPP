#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int moves[4][2]={{0,-1},{0,1},{1,0},{-1,0}};
bool isValid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }else{
        return true;
    }
}
ll getConnectedSize(vector<string> &v,vector<vector<int> > &visited,int i,int j){
   
    int n=visited.size();
    int m=visited[i].size();
    visited[i][j]=1;
    ll count =1;
    for(int k=0;k<4;k++){
        int movex=i+moves[k][0];
        int movey=j+moves[k][1];
        if(isValid(movex,movey,n,m)){
        if(visited[movex][movey]==0 && v[movex][movey]=='1'){
            count+=getConnectedSize(v,visited,movex,movey);
        }
        }
    }
    return count;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<string>v;
        vector<vector<int>>visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            string temp;
            cin>>temp;
            v.push_back(temp);
        }

        



        priority_queue<ll> pq;
        for(int i=0;i<n;i++){
            // string temp=v[i];
            for(int j=0;j<m;j++){
                if(visited[i][j]==0 && v[i][j]=='1'){
                    ll count= getConnectedSize(v,visited,i,j);
                    if(count>0)
                    pq.push(count);
                }
            }
            
        }
        ll ans=0;
        ll op =1;
        // cout<<pq.size()<<endl;
        while(pq.size()!=0){
            ll curr = pq.top();
            if(op%2==0){
                ans+=curr;
            }
            op++;
            pq.pop();
        }
        cout<<ans<<endl;
        
        
    }
}