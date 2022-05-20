#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int movesx[]={1,-1,0,0,1,1,-1,-1};
int movesy[]={0,0,1,-1,-1,1,-1,1};
bool isValid(int i,int j){
    if(i<0 || i>=8 || j<0 || j>=8){
        return false;
    }else{
        return true;
    }
}

ll countPlaces(int i,int j,int move){
    
    vector<vector<int>> visited(8,vector<int>(8,0));
    vector<vector<int>> moves(8,vector<int>(8,0));
    queue<pair<int,int>> q;
    visited[i][j]=1;
    q.push(make_pair(i,j));
    while (!q.empty()){
        auto it = q.front();
        q.pop();
        for(int i = 0; i <8; i++){
            int currX=it.first+movesx[i];
            int currY=it.second+movesy[i];
            if(isValid(currX,currY) and visited[currX][currY]==0){
            if(moves[currX][currY]==0)
            moves[currX][currY]=(1+moves[it.first][it.second]);
            else{
              moves[currX][currY]=min(moves[currX][currY],1+moves[it.first][it.second]);  
            }
            q.push(make_pair(currX,currY));
            visited[currX][currY]=1;
            }
        }
    }
    int count=0;
    for(i=0;i<8;i++){
        for(j=0;j<8;j++){
            if(moves[i][j]<=move){
                count++;
            }
        }
    }
    return count;
    
    

}

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y,move;
        cin>>x>>y>>move;
        x-=1;
        y-=1;
       cout<<countPlaces(x,y,move)<<endl;
        

        
    }
}