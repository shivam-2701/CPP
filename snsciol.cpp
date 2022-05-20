#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int movesx[]={1,-1,0,0,1,1,-1,-1};
int movesy[]={0,0,1,-1,-1,1,-1,1};
bool isValid(int i,int j,int n,int m){
    if(i<0 || i>=n || j<0 || j>=m){
        return false;
    }else{
        return true;
    }
}

pair<int,int> getMax(vector<vector<ll>>& mat,int n,int m) {
    int idx=-1,idy=-1;
    ll maxm=INT_MIN;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]>maxm){
                idx=i;
                idy=j;
            }
        }
    }
    return {idx,idy};
}

ll countPlaces(vector<vector<ll>> &mat,int n,int m){
    
    vector<vector<ll>> visited(n,vector<ll>(m,0));
    vector<vector<ll>> moves(n,vector<ll>(m,1e9));
    queue<pair<ll,ll>> q;

    pair<int,int> pos=getMax(mat,n,m);
    int i=pos.first,j=pos.second;
    
    for(int x=0;x<n;x++){
        for(int y=0;y<m;y++){
            if(mat[x][y]==mat[i][j]){
                q.push(make_pair(x,y));
                visited[x][y]=1;
                moves[x][y]=0;

            }
        }
    }
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        for(int i = 0; i <8; i++){
            int currX=it.first+movesx[i];
            int currY=it.second+movesy[i];
            if(isValid(currX,currY,n,m) and visited[currX][currY]==0){
            moves[currX][currY]=(1+moves[it.first][it.second]);
            q.push(make_pair(currX,currY));
            visited[currX][currY]=1;
            }
        }
    }
    ll count=0;
    ll maxm=mat[pos.first][pos.second];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            // cout<<moves[i][j]<<" ";
            if(mat[i][j]<maxm){
                count=max(count,moves[i][j]);
            }
            
        }
        // cout<<endl;
       
        
    }
    return count;
    
    

}
int main(){
    int t;
    cin>>t;
    while(t--){
       int n,m;
       cin>>n>>m;
       vector<vector<ll>>mat(n,vector<ll>(m,0));
       for(int i=0;i<n;i++){
           for(int j=0;j<m;j++){
               cin>>mat[i][j];
           }
       }
       ll ans=countPlaces(mat,n,m);
       cout<<ans<<endl;
        

        
    }
}